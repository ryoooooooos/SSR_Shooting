#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../../../System/Image/Image.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �v���C���[�摜�̎��
	enum class ENEMY_IMG_TYPE {
		KORONESUKI,
		MATSURISU,
		MINIORUYANKE,
		ONIGIRYA,
		ORUYANKE,
		PEKORA,
		ROBOKOARM,
		SUBARUDODUCK,
		MAX
	};
	// �v���C���[�摜�N���X
	class EnemyImages {
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		EnemyImages(); // �R���X�g���N�^
		~EnemyImages(); // �f�X�g���N�^				 
		//�@getImagePointer���Ăяo���O�ɕK�����s���邱��
		HRESULT loadImages()const;
		//�@�e�X�e�[�W���Ɏg���܂킷�摜��Image�|�C���^��Ԃ�
		Image* getImagePointer(ENEMY_IMG_TYPE n)const;
	private:
		ENEMY_IMG_TYPE mNumOfImage;
		Image** mppImages;
	};
}