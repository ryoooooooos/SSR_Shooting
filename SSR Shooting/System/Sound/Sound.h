#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include <string>
#include "DxLib.h"
#include "../Macro/Macro.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// ���y�N���X
	class Sound
	{
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		Sound(const char* FileName); // �R���X�g���N�^
		~Sound(); // �f�X�g���N�^
		/* �֐� */
		HRESULT init(); // ���y�t�@�C���̃��[�h
		void play()const; // ���y�̒ʏ�Đ�
		void loop()const; // ���y�̃��[�v�Đ�
	private:
		/* �ϐ� */
		std::string mpFileName; // ���y�t�@�C����
		int mHandle; // ���y�n���h��
	};
}