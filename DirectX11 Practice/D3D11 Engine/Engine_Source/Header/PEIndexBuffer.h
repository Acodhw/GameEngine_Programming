#pragma once
#include "PEGraphicsDevice_DX11.h"

namespace PracticeEngine::Graphics {
    class IndexBuffer : public GpuBuffer
    {
	public:
		IndexBuffer();
		~IndexBuffer();

		bool Create(const std::vector<UINT>& indices);
		void Bind() const;

	private:
    };
}

