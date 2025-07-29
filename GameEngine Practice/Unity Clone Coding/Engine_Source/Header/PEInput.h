#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	// Ű ����
	enum class eKeyState {
		Down, 
		Pressed,
		Up,
		None
	}; // Ű Ȱ��ȭ ���¸� ������ ����

	// ������ Ű
	enum class eKeyCode {
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	}; // Ű �ڵ带 ������ ����
	// ������ �Է� ���¸� �����ϴ� Ŭ����
	class Input
	{
	public:
		// Ű�� ����
		struct Key {
			eKeyState state; // Ű Ȱ��ȭ ����
			eKeyCode keyCode; // Ű �ڵ�
			bool bPressed; // ���ȴ��� Ȯ��
		}; // ���� Ű ������ ������ ����ü�� ������ ����

		static void Initailze();
		static void Update();

		// Ű�� ���� ������ True�� �����մϴ�
		static bool GetKeyDown(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Down; }
		// Ű�� ���� ������ True�� �����մϴ�
		static bool GetKeyUp(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Up; }
		// Ű�� ������ ������ True�� �����մϴ�
		static bool GetKey(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Pressed; }

		//static : �� ���� ���ǵǸ�, ���� ���� ��ü ���ǿ��� �ұ��ϰ� ������

	private:
		static std::vector<Key> mKeys; // Ű�� ����
	};

}