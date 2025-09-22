#pragma once
#include "PEGraphicsDevice_DX11.h"

namespace PracticeEngine::Graphics {
	class InputLayout
	{
	public:
		InputLayout();
		~InputLayout();

		void CreateInputLayout(UINT vertexCount, D3D11_INPUT_ELEMENT_DESC* layout, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength);
		void Bind();

	private:
		Microsoft::WRL::ComPtr<ID3D11InputLayout> mInputLayout;

	};
}

