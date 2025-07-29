#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"
#include "PELayer.h"
#include "PEScene.h"
#include "PESceneManager.h"

namespace PracticeEngine {
	
	namespace Object {
		// 탬플릿 타입의 게임오브젝트를 해당 위치에 생성합니다
		template<typename T>
		static T* Instantiate(eLayerType layer, Math::Vector2 pos) 
		{
			T* gObj = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* sceneLayer = activeScene->GetLayer(layer);
			sceneLayer->AddGameObject(gObj);

			Transform* tr = gObj->GetComponent<Transform>();
			tr->SetPos(pos);

			return gObj;
		}

		// 탬플릿 타입의 게임오브젝트를 생성합니다
		template<typename T>
		static T* Instantiate(eLayerType layer)
		{
			T* gObj = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* sceneLayer = activeScene->GetLayer(layer);
			sceneLayer->AddGameObject(gObj);

			return gObj;
		}
	}
}