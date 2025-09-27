#pragma once
#include "PEGraphicsDevice_DX11.h"
namespace PracticeEngine::Graphics {
    class ConstantBuffer : public GpuBuffer
    {
	public:
		ConstantBuffer(eCBType type);
		virtual ~ConstantBuffer();

		bool Create(UINT size, void* data = NULL);

		[[noreturn]] void SetData(void* data) const;
		[[noreturn]] void Bind(eShaderStage stage) const;

	private:
		UINT mSize;
		eCBType mType;
	};
}

