#include "PEGameObject.h"
#include "PEInput.h"
#include "PETime.h"
#include "PETransform.h"

namespace PracticeEngine
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
		mComponents.resize((UINT)eComponentType::End);
		initializeTransform();
	}
	GameObject::~GameObject()
	{
		for (Component* c : mComponents) {
			if (c == nullptr)
				continue;

			delete c;
			c = nullptr;
		}
	}

	void GameObject::Initialize() {
		for (Component* c : mComponents) {
			if (c == nullptr) continue;
			c->Initialize();
		}
	}

	void GameObject::Update() {
		for (Component* c : mComponents) {
			if (c == nullptr) continue;
			c->Update();
		}
	}

	void GameObject::LateUpdate() {
		for (Component* c : mComponents) {
			if (c == nullptr) continue;
			c->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* c : mComponents) {
			if (c == nullptr) continue;
			c->Render(hdc);
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}

}
