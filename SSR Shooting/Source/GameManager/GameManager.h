#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include <cstdlib>
#include <ctime>
#include "DxLib.h"
#include "../../System/Keyboard/Keyboard.h"
#include "../Parameter/Parameter.h"
#include "../Scene/Base/Scene.h"
#include "../Scene/Title/Title.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	//
	// �ēN���X
	class GameManager {
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		GameManager(); // �R���X�g���N�^
		~GameManager(); // �f�X�g���N�^
		// GameManager�̓R�s�[�s��
		GameManager(const GameManager& scene) = delete;
		const GameManager& operator= (const GameManager& rhs) = delete;
		/* �֐� */
		void run();// ���s
		/* �A�N�Z�T */
		void setScore(const int s); // �X�R�A���Z�b�g
		int getScore()const; // �X�R�A��Ԃ�
	private:
		/* �֐� */
		HRESULT init(); // ������
		void final(); // �I��
		HRESULT gameLoop(); // �Q�[�����[�v
		/* �ϐ� */
		Scene* mpScene; // �V�[���N���X
		int Score; // �X�R�A
	};
}