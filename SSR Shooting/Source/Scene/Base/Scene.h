#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "DxLib.h"
#include "../../../System/Keyboard/Keyboard.h"
#include "../../../System/Sound/Sound.h"
#include "../../BackGround/BackGround.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// GameManager.h���C���N���[�h����Əz�C���N���[�h�ɂȂ��Ă��܂����߁A�s���S�^�Œ�`
	class GameManager;
	// �V�[���̊��N���X
	class Scene
	{
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		Scene(GameManager* pGameManager); // �R���X�g���N�^
		virtual ~Scene(); // �f�X�g���N�^
		// Scene�̓R�s�[�s��
		Scene(const Scene& scene) = delete;
		const Scene& operator= (const Scene& rhs) = delete;
		/* �֐� */
		virtual HRESULT init() = 0; // �V�[�����̏�����
		virtual Scene* run() = 0; // �V�[���̎��s
	protected:
		/* �ϐ� */
		Scene* mpNextScene; //���̃t���[���Ŏ��s����Scene�N���X�ւ̃|�C���^
		BackGround* mpBackground;//�w�i�摜
		Sound* mpSound; // ���y
		//�e�V�[���ŋ��ʂɎg�����̂� GameManager�N���X�o�R�ŎQ�Ɓ��X�V
		GameManager* mpGameManager;
		//Keyboard�N���X��Mouse�N���X��singleton�Ȃ̂ŁA�e�N���X�Ŏ����Ă�OK�B
		//GameManager�N���X�o�R�ł��ǂ����A���֐�����̂��߁A�����ɂ���`
		Keyboard& mKey;
	};
}