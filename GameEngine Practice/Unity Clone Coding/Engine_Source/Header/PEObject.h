#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"
#include "PELayer.h"
#include "PEScene.h"
#include "PESceneManager.h"
#include "PETransform.h"


namespace PracticeEngine::Object {
	 
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
	// ���ø� Ÿ���� ���ӿ�����Ʈ�� �ش� ��ġ, �ش� ȸ���� �����մϴ�
	template<typename T>
	static T* Instantiate(eLayerType layer, Math::Vector2 pos, float rot)
	{
		T* gObj = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* sceneLayer = activeScene->GetLayer(layer);
		sceneLayer->AddGameObject(gObj);

		Transform* tr = gObj->GetComponent<Transform>();

		tr->SetPos(pos);
		tr->SetRot(rot);

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

	// ���� ������Ʈ�� �����մϴ�
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
