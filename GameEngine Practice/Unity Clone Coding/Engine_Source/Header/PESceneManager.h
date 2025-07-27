#pragma once
#include "PEScene.h"

namespace PracticeEngine {
	class SceneManager
	{
	public:
		template <typename T> // ªÛº”πﬁ¥¬ æ¿ø° ¥Î«— ≈∆«√∑ø
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize(); // æ¿ √ ±‚»≠

			mScene.insert(std::make_pair(name, scene)); // æ¿¿ª æ¿ mapø° ≥÷¿Ω

			return scene; // æ¿ ∏Æ≈œ
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name); // æ¿ mapø°º≠ «ÿ¥Á ¿Ã∏ß æ¿¿ª √£±‚
			if (iter == mScene.end()) // æ¿¿Ã æ¯¿∏∏È
				return nullptr; // nullptr ¡¶∞¯

			mActiveScene = iter->second; // «ˆ¿Á »∞º∫»≠ æ¿¿ª ¡ˆ±› æ¿¿∏∑Œ ∫Ø∞Ê

			return iter->second; // √£¿∫ æ¿ ∏Æ≈œ
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

