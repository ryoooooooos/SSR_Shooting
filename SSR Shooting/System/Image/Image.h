#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include <Windows.h>
#include <string>
#include "DxLib.h"
#include "../Vector2/Vector2.h"
#include "../Macro/Macro.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �摜�N���X
	class Image {
	public:
		// �R���X�g���N�^
		Image(const char* fileName);
		// �f�X�g���N�^
		~Image();
		// �摜�t�@�C���̃��[�h
		// draw���\�b�h���Ăяo���O�ɕK���Ăяo�����ƁB
		HRESULT load();
		// �摜No��Ԃ�
		int getImgNo()const;
	private:
		// �摜�t�@�C�����@
		// �|�C���^�ɂ���ƁA
		// ���_�F�������ߖ�
		// ���_�F2�d����΍�����Ȃ��Ă͂����Ȃ�
		// ���_�����_�����邽�߁A���̂ŕێ�
		std::string mpFileName;
		// �摜No�iDxlib��LoadGraph�֐��̖߂�l)
		int mImgNo;
	};
}//furukawa
//EOF