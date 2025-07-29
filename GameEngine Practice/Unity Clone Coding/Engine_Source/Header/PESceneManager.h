#pragma once
#include "PEScene.h"

namespace PracticeEngine {
	// ���� ������ �����ϴ� Ŭ����
	class SceneManager
	{
	public:
		// Ư�� ���� �� �޴������� �����մϴ�
		template <typename T> // ��ӹ޴� ���� ���� ���÷�
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize(); // �� �ʱ�ȭ

			mScene.insert(std::make_pair(name, scene)); // ���� �� map�� ����

			return scene; // �� ����
		}

		// �� �����డ ������ �ִ� �� ������ �����մϴ�
		static Scene* LoadScene(const std::wstring& name)
		{
			if(mActiveScene)
				mActiveScene->OnExit();
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name); // �� map���� �ش� �̸� ���� ã��
			if (iter == mScene.end()) // ���� ������
				return nullptr; // nullptr ����

			mActiveScene = iter->second; // ���� Ȱ��ȭ ���� ���� ������ ����

			mActiveScene->OnEnter();

			return iter->second; // ã�� �� ����
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		static std::map<std::wstring, Scene*> mScene; // �� �޴����� �ε� �� �� ����
		static Scene* mActiveScene; // ���� Ȱ��ȭ�� ��
	};
}

