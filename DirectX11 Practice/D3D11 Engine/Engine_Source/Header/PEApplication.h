#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"
#include "PEGraphicsDevice_DX11.h"
#include "PEEvent.h"
#include "PEWindow.h"

namespace PracticeEngine {
	// 애플리케이션 기본 클래스
	class Application
	{
	public:

		Application();
		~Application();
		void Initialize(HWND hwnd, int width, int height);
		void InitializeWindow(HWND hwnd);
		void AdjustWindowRect(HWND hwnd, int width, int height);
		void ReszieGraphicDevice(UINT width, UINT height);
		void InitializeEtc();

		void OnEvent(Event& e);
		void Run();
		void Close();
		void Update();
		void LateUpdate();

		void Render();
		void Present();
		void Release();

		void Destroy();

		Window& GetWindow() { return mWindow; }
		bool IsLoaded() const { return mbLoaded; }
		void IsLoaded(bool load) { mbLoaded = load; }
		bool IsRunning() const { return mbRunning; }

	private:
		bool mbLoaded;
		bool mbRunning;
		std::unique_ptr<Graphics::GraphicsDevice_DX11> mGraphicDevice; // 그래픽 디바이스

		wchar_t* title; // 타이틀 저장
		
		//std::vector<Scene*> mScene;
		Window mWindow;
	};
}

