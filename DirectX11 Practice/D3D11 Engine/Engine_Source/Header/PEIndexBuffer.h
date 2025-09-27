#pragma once
#include "PEGraphicsDevice_DX11.h"

namespace PracticeEngine::Graphics {
    class IndexBuffer : public GpuBuffer
    {
	public:
		IndexBuffer();
		virtual ~IndexBuffer();

		bool Create(const std::vector<UINT>& indices);
		void Bind() const;

		UINT GetIndexCount() const { return mIndexCount; }

	private:
		UINT mIndexCount;
    };
}

