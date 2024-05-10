#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../../../System/Image/Image.h"
#include "../../../System/Vector2/Vector2.h"
#include "../../../System/Keyboard/Keyboard.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �L�����N�^�[�N���X
	class Object {
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		Object(); // �R���X�g���N�^
		virtual ~Object(); // �f�X�g���N�^
		/* �֐� */
		virtual HRESULT init() = 0; // ������
		virtual void draw()const = 0; // �`��
	protected:
		/* �ϐ� */
		Vector2 pos;
	};
}