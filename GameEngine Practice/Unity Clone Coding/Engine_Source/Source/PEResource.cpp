#include "PEResource.h"

namespace PracticeEngine {
	Resource::Resource(eResourceType type)
		: mType(type)
		, mPath(L"")
	{
	}

	Resource::~Resource()
	{
	}

}