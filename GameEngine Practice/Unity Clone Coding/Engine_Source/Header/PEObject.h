#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"
#include "PELayer.h"
#include "PEScene.h"
#include "PESceneManager.h"

namespace PracticeEngine {
	
	namespace Object {
		// ���ø� Ÿ���� ���ӿ�����Ʈ�� �ش� ��ġ�� �����մϴ�
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

		// ���ø� Ÿ���� ���ӿ�����Ʈ�� �����մϴ�
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