#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"
#include "PELayer.h"
#include "PEScene.h"
#include "PESceneManager.h"
#include "PETransform.h"


namespace PracticeEngine::Object {
	 
	// 탬플릿 타입의 게임오브젝트를 해당 위치에 생성합니다
	template<typename T>
	static T* Instantiate(eLayerType layer, Math::Vector3 pos, Math::Quaternion rot = Quaternion::Identity)
	{
		T* gObj = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* sceneLayer = activeScene->GetLayer(layer);
		sceneLayer->AddGameObject(gObj);

		Transform* tr = gObj->GetComponent<Transform>();
		tr->SetPosition(pos);

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

	// 게임 오브젝트를 삭제합니다
	static void Destroy(PracticeEngine::GameObject* obj) {
		obj->Death();
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->EraseGameObject(gameObject);
		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}
