#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../../System/Image/Image.h"
#include "../../System/Vector2/Vector2.h"
#include "../Parameter/Parameter.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �w�i�N���X
	class BackGround
	{
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		BackGround(const char* fileName);
		~BackGround();
		// BackGround�̓R�s�[�s��
		BackGround(const BackGround& scene) = delete;
		const BackGround& operator= (const BackGround& rhs) = delete;
		/* �֐� */
		void draw()const; // �`��
		HRESULT init(); // ������
	private:
		/* �ϐ� */
		Image* mpImage; // �摜�N���X
		Vector2 mPos; // ���W
	};
}