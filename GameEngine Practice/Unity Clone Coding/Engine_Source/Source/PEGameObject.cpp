#include "PEGameObject.h"
#include "PEInput.h"
#include "PETime.h"
#include "PETransform.h"

namespace PracticeEngine
{
	GameObject::GameObject()
	{
		initializeTransform();
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

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}

}
