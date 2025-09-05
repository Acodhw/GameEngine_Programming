#pragma once
#include "PEUIBase.h"
#include "PETexture.h"

namespace PracticeEngine {
    class UIHUD : public UIBase
    {
	public:
	public:
		UIHUD();
		~UIHUD();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender() override;
		virtual void OnClear() override;

	private:
		Graphics::Texture* mTexture;
    };
}

