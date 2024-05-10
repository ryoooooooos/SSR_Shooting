#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../../Object/Player/Player.h"
#include "../../Object/Enemy/Enemy.h"
#include "../../EnemyManagement/EnemyManagement.h"
#include "../GameResult/GameResult.h"
#include "../Base/Scene.h"
#include "../../Parameter/Parameter.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �Q�[���N���X
	class PlayGame : public Scene
	{
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		PlayGame(GameManager* pGameManager); // �R���X�g���N�^
		~PlayGame(); // �f�X�g���N�^
		/* �֐� */
		HRESULT init()override; // ������
		Scene* run()override; // ���s
	private:
		/* �֐� */
		void input(); // ����
		void update(); // �X�V
		void updateEnemy(); // �G�̍X�V
		void HitCheck(); // �����蔻��
		bool isHit(const Vector2& v1, const Vector2& v2, const int r1, const int r2); // �����蔻��`�F�b�N
		void UpdateScore(); // �X�R�A�̍X�V
		void draw()const; // �`��
		void MyDrawLine()const; // ��؂���̕`��
		void DrawLife()const; // ���C�t�֘A�̕`��
		void DrawWeapon()const; // ����֘A�̕`��
		void DrawInstruction()const; // ��������̕`��
		void DrawScore()const; // �X�R�A�̕`��
		/* �ϐ� */
		int NormalFontHandle; // �t�H���g�T�C�Y(��)
		Player* mpPlayer; // �v���C���[
		Enemy** mppEnemy; // �G
		EnemyManagement* mpEnemyManagement; // �G�̃��x���Ǘ�
		Image* mpLifeImage; // ���C�t�摜
		Image* mpWeaponImage; // 
	};
}