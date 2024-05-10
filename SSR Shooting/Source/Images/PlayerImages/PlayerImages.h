#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../../../System/Image/Image.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �v���C���[�摜�̎��
	enum class PLAYER_IMG_TYPE {
		BOTAN,
		LAMY,
		NENE,
		POLKA,
		MAX
	};
	// �v���C���[�摜�N���X
	class PlayerImages {
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		PlayerImages(); // �R���X�g���N�^
		~PlayerImages(); // �f�X�g���N�^				 
		//�@getImagePointer���Ăяo���O�ɕK�����s���邱��
		HRESULT loadImages()const;
		//�@�e�X�e�[�W���Ɏg���܂킷�摜��Image�|�C���^��Ԃ�
		Image* getImagePointer(PLAYER_IMG_TYPE n)const;
	private:
		PLAYER_IMG_TYPE mNumOfImage;
		Image** mppImages;
	};
}