#include "Common/d3dApp.h"
#include "Common/MathHelper.h"
#include "Common/UploadBuffer.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

struct Vertex {
	XMFLOAT3 pos; // 위치
	XMFLOAT3 normal; // 정점 법선벡터
	XMFLOAT2 Tex0; // 텍스쳐 좌표
	XMFLOAT2 Tex1;
}; // 정점 구조체

/*
* typedef struct D3D12_INPUT_ELEMENT_DESC
* {
*	LPCSTR SemanticName;						// 성분 문자열 이름
*	UINT semanticIndex;							// 성분 인덱스
*	DXGI_FORMAT Format;							// 정점 성분의 자료형
*	UINT InputSlot;								// 정점 버퍼 슬롯 인덱스
*	UINT ALignedByteOffset;						// 정점 성분의 위치 오프셋
*	D3D12_INPUT_CLASSIFICATION InputSlotClass;	// D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA
*	UINT InstanceDataStepRate;					// 0
* } D3D12_INPUT_ELEMENT_DESC;
*/
D3D12_INPUT_ELEMENT_DESC vertexDesc[] = {
	{" POSITION ", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
	{" NORMAL ", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
	{" TEXCOORD ", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
	{" TEXCOORD ", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 32, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
};


