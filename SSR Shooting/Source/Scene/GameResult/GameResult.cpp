// �K�v�t�@�C���̃C���N���[�h
#include "GameResult.h"
// Scene.h �� GameManager�N���X ��s���S�^�Œ�`���Ă��邽�߁A���g���킩��Ȃ�
// ���̂��߁A���ꂼ��̃V�[���� Gamemanager.h ���C���N���[�h��
// GameManager�N���X �̒��g��c���ł���悤�ɂ���B
#include "../../GameManager/GameManager.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	GameResult::GameResult(GameManager* pGameManager)
		: Scene(pGameManager)
		, SceneChangeTimer(-1)
		, BigFontHandle(-1)
		, SmallFontHandle(-1)
	{
	}
	// �f�X�g���N�^
	GameResult::~GameResult() {

	}
	// ������
	HRESULT GameResult::init() {
		// �w�i
		mpBackground = new BackGround("Images/BackGround.jpg");
		if (FAILED(mpBackground->init())) {
			return E_FAIL;
		}

		// ��ʑJ�ڌ�o�߂�������
		SceneChangeTimer = 0;

		// �t�H���g�T�C�Y
		BigFontHandle = CreateFontToHandle(NULL, Parameter::BigFontSize, Parameter::FontThick);
		SmallFontHandle = CreateFontToHandle(NULL, Parameter::SmallFontSize, Parameter::FontThick);


		return S_OK;
	}
	// ���s
	Scene* GameResult::run() {
		input();
		update();
		draw();
		return mpNextScene;
	}
	// ����
	void GameResult::input() {
		// SPACE�L�[�������ꂽ���ʑJ�ځB�������A�ȉ��̃p�^�[��������B
		// �@���s��P��ڂ̃v���C�̏ꍇ�A�^�C�g���ł̌o�ߎ��ԂɊ֌W�Ȃ�����
		// �A���s��Q��ڈȍ~�̃v���C�̏ꍇ�A�^�C�g����40�t���[�����o�߂����玟��
		if (mKey.isKeyPush(KeyType::SPACE)) {
			if (SceneChangeTimer >= Parameter::MinSceneChangeTimer) {
				mpNextScene = new Title(mpGameManager);
			}
		}
	}
	// �X�V
	void GameResult::update() {
		// �o�ߎ��Ԃ��C���N�������g
		SceneChangeTimer++;
	}
	// �`��
	void GameResult::draw() {
		ClearDrawScreen(); // ����ʂ��N���A

		mpBackground->draw(); // �w�i

		// �X�R�A�̕\��
		DrawFormatStringToHandle(Parameter::WindowWidth / 4, Parameter::WindowHeight / 2 - 100, ColorParameter::Black, BigFontHandle, "�X�R�A�F%d", mpGameManager->getScore());
		MyDrawString(Parameter::WindowWidth / 2 - 100, Parameter::WindowHeight / 2 + 50, "SPACE�������Ă�������", ColorParameter::Black, SmallFontHandle);

		ScreenFlip(); // ����ʂƕ\��ʂ����ւ���
	}
	//
	// ������̕`��
	void GameResult::MyDrawString(int drawX, int drawY, const char* string, int color, int FontHandle) {
		DrawStringToHandle(drawX, drawY, string, color, FontHandle);
	}
}
