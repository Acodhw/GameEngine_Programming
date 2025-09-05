#include "PEAudioListener.h"
#include "PETransform.h"
#include "PEGameObject.h"
#include "PEFmod.h"


namespace PracticeEngine
{
	AudioListener::AudioListener()
		: Component(eComponentType::AudioListener)
	{
	}

	AudioListener::~AudioListener()
	{
	}

	void AudioListener::Initialize()
	{
	}

	void AudioListener::Update()
	{
	}

	void AudioListener::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Fmod::Set3DListenerAttributes(&pos);
	}

	void AudioListener::Render(HDC hdc)
	{
	}
}