 #pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "DxLib.h"
#include "../Macro/Macro.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// isKeyPush(�L�[�������ꂽ�u��)�AisKeyRelease(�L�[�������ꂽ�u��)���\�b�h�̈����Ɏg�p���܂��B
	// mKeyToVk�z��(�{�N���X��private�����o,�R���X�g���N�^�ŏ�����)�ƑΉ������āA�w�肵�Ă��������B
	// �ő�8��ނ܂Ł{�Ō��KEY_MAX�����Ă����Ă�������
	enum class KeyType {
		W,
		S,
		E,
		R,
		SPACE,
		MAX
	};

	// Keyboard�N���X��singleton�ł��B
	class Keyboard {
	public:
		/* �R���X�g���N�^ */
		Keyboard(const Keyboard&) = delete;	// �R�s�[�R���X�g���N�^delete�w��
		Keyboard& operator= (const Keyboard&) = delete;	// �R�s�[������Z�qdelete�w��
		Keyboard(Keyboard&&) = delete;	// ���[�u�R���X�g���N�^delete�w��
		Keyboard& operator= (Keyboard&&) = delete; // ���[�u������Z�qdelete�w��
		/* �֐� */
		static Keyboard& getInstance(); // �C���X�^���X�̎擾
		//
		// ���t���[���ŏ��ɌĂяo��
		HRESULT keyUpdate();
		//
		// �L�[�{�[�h���������ꂽ�u�Ԃ����^�A���̑��͋U��Ԃ��B
		// ����g�p�ł���L�[�{�[�h�̎�ނ�8��ނ܂łł��B
		bool isKeyPush(KeyType keyNo) const;
		//
		// �L�[�������ꂽ�u�Ԃ����^�A���̑��͋U��Ԃ��B
		// ����g�p�ł���L�[�{�[�h�̎�ނ͂W��ނ܂łł��B
		bool isKeyRelease(KeyType keyNo) const;
		//
		//�L�[�������ꑱ���Ă���Ԃɂ��ẮADXLIB�̊֐�(int CheckHitKey( int KeyCode ))���g�p�̂���
	private:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		Keyboard(); // �R���X�g���N�^
		~Keyboard() = default; // �f�X�g���N�^
		/* �ϐ� */
		const BYTE mKeyToVK[8];	//�L�[�R�[�h�ϊ��e�[�u��
		BYTE mPreKeyStat; //���O�t���[���̃L�[���
		BYTE mNowKeyStat; //���t���[���̃L�[���
	};
}