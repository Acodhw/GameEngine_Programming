#include "PEGameObject.h"
#include "PEInput.h"
#include "PETime.h"

namespace PracticeEngine
{
	GameObject::GameObject()
	{

	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Initialize() {
		for (Component* c : mComponents) c->Initialize();
	}

	void GameObject::Update() {
		for (Component* c : mComponents) c->Update();
	}

	void GameObject::LateUpdate() {
		for (Component* c : mComponents) c->LateUpdate();
	}

	void GameObject::Render(HDC hdc) 
	{ 
		for (Component* c : mComponents) c->Render(hdc);
	}

}
