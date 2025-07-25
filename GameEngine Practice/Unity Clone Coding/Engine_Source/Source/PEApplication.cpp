#include "PEApplication.h"

namespace PracticeEngine {

	Application::Application()
		: mHwmd(nullptr)
		, mHdc(nullptr)
	{

	}

	
	Application::~Application() {
	
	}
	void Application::Initialize(HWND hwmd) {
		mHwmd = hwmd;
		mHdc = GetDC(mHwmd);
	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {
		mPlayer.Update();
	}
	
	void Application::LateUpdate() {
		mPlayer.LateUpdate();
	}

	void Application::Render() {
		mPlayer.Render(mHdc);
	}
}