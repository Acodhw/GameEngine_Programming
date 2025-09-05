#pragma once
#include "PEGraphicsDevice_DX11.h"

namespace PracticeEngine::Graphics {
	class VertexBuffer : public GpuBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		bool Create(const std::vector<Vertex>& vertexes);
		void Bind();

	private:
	};
}

