#include "Common/d3dApp.h"
#include "Common/MathHelper.h"
#include "Common/UploadBuffer.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

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

struct Vertex {
	XMFLOAT3 Pos; // 위치
	XMFLOAT4 Color; // 색
}; // 정점 구조체

struct ObjectConstants {
	XMFLOAT4X4 WorldViewProj = MathHelper::Identity4x4(); //월드 변환 행렬(초기값 : 기본행렬)
};

// DirectX 초기화 클래스 선언부
class PointApp : public D3DApp {
public:
	PointApp(HINSTANCE hInstance);
	PointApp(const PointApp& rhs) = delete;
	PointApp& operator=(const PointApp& rhs) = delete;
	~PointApp();

	virtual bool Initialize()override;

private:
	virtual void OnResize()override; // 화면의 크키가 바뀔 때 실행
	virtual void Update(const GameTimer& gt)override; // 1프레임당 실행
	virtual void Draw(const GameTimer& gt)override; // 화면에 무언가를 그릴 때 실행

	virtual void OnMouseDown(WPARAM btnState, int x, int y)override; // Event : 마우스 클릭
	virtual void OnMouseUp(WPARAM btnState, int x, int y)override; // Event : 마우스 버튼 떼기
	virtual void OnMouseMove(WPARAM btnState, int x, int y)override; // Event : 마우스 음직임

	void BuildDescriptorHeaps(); 
	void BuildConstantBuffers();
	void BuildRootSignature();
	void BuildShadersAndInputLayout();
	void BuildBoxGeometry();
	void BuildPSO();

	/////////////////////////////////////////////////////////////
private:
	ComPtr<ID3D12RootSignature> mRootSignature = nullptr;
	ComPtr<ID3D12DescriptorHeap> mCbvHeap = nullptr;

	std::unique_ptr<UploadBuffer<ObjectConstants>> mObjectCB = nullptr;

	std::unique_ptr<MeshGeometry> mBoxGeo = nullptr;

	ComPtr<ID3DBlob> mvsByteCode = nullptr;
	ComPtr<ID3DBlob> mpsByteCode = nullptr;

	std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;

	ComPtr<ID3D12PipelineState> mPSO = nullptr;

	XMFLOAT4X4 mWorld = MathHelper::Identity4x4();
	XMFLOAT4X4 mView = MathHelper::Identity4x4();
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();

	float mTheta = 1.5f * XM_PI;
	float mPhi = XM_PIDIV4;
	float mRadius = 5.0f;

	POINT mLastMousePos;
};