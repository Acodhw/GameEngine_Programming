#include "PEComponent.h"

namespace PracticeEngine {
	Component::Component() 
	{
	
	}

	Component::~Component()
	{
	
	}

	void Component::Initialize() {
	
	}
	void Component::Update() {
	
	}
	void Component::LateUpdate() {
	
	}
	void Component::Render(HDC hdc) {
	
	}
}

/*
// ���� ������Ʈ�� �Ҵ�� �������� ó��
HBRUSH br = CreateSolidBrush(RGB(255, 0, 255)); // �귯�� ����(� �귯���� �׸��� �׷�����)
HBRUSH oldbr = (HBRUSH)SelectObject(hdc, br); // hdc���� �귯�� ���� ���� ������(������) �귯�� ����
Rectangle(hdc, 100 + mx, 100 + my, 200 + mx, 200 + my); // �簢�� �׸��� �Լ�
(HBRUSH)SelectObject(hdc, oldbr); // ������ �귯���� ��������
DeleteObject(br); // ������ �귯���� ����
// DC = ȭ�� ��¿� �ʿ��� ��� �����͸� ������ ����ü
// GDI ��⿡ ���� ����
*/