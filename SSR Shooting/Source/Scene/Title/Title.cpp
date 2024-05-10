// �K�v�t�@�C���̃C���N���[�h
#include "Title.h"
// Scene.h �� GameManager�N���X ��s���S�^�Œ�`���Ă��邽�߁A���g���킩��Ȃ�
// ���̂��߁A���ꂼ��̃V�[���� Gamemanager.h ���C���N���[�h��
// GameManager�N���X �̒��g��c���ł���悤�ɂ���B
#include "../../GameManager/GameManager.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	Title::Title(GameManager* pGameManager)
		: Scene(pGameManager)
		, GamePlayCount(-1)
		, SceneChangeTimer(-1)
		, BigFontHandle(-1)
		, SmallFontHandle(-1)
	{
	}
	// �f�X�g���N�^
	Title::~Title() {
	}
	//
	// �V�[�����̏�����
	HRESULT Title::init() {
		// �w�i
		mpBackground = new BackGround("Images/BackGround.jpg");	// ���̒��x��new�ł��Ȃ��ƂȂɂ��ł��Ȃ��̂ŁA���s�͍l���Ȃ�
		if (FAILED(mpBackground->init())) {
			return E_FAIL;
		}

		// ���y
		mpSound = new Sound("Sounds/TitleBGM.wav");
		if (FAILED(mpSound->init())) {
			return E_FAIL;
		}

		// �Q�[���v���C��, �^�C�g���J�ڌ�o�߂�������
		GamePlayCount = 0;
		SceneChangeTimer = 0;

		// �t�H���g�T�C�Y
		BigFontHandle = CreateFontToHandle(NULL, Parameter::BigFontSize, Parameter::FontThick);
		SmallFontHandle = CreateFontToHandle(NULL, Parameter::SmallFontSize, Parameter::FontThick);

		return S_OK;
	}
	//
	// �V�[���̎��s
	Scene* Title::run() {
		input();
		update();
		draw();
		return mpNextScene;
	}
	//
	// ����
	void Title::input() {
		// SPACE�L�[�������ꂽ���ʑJ�ځB�������A�ȉ��̃p�^�[��������B
		// �@���s��P��ڂ̃v���C�̏ꍇ�A�^�C�g���ł̌o�ߎ��ԂɊ֌W�Ȃ�����
		// �A���s��Q��ڈȍ~�̃v���C�̏ꍇ�A�^�C�g����40�t���[�����o�߂����玟��
		if (mKey.isKeyPush(KeyType::SPACE)) {
			if (GamePlayCount == 0 || SceneChangeTimer >= Parameter::MinSceneChangeTimer) {
				mpNextScene = new PlayGame(mpGameManager);
			}
		}
	}
	//
	// �X�V
	void Title::update() {
		// �o�ߎ��Ԃ��C���N�������g
		SceneChangeTimer++;

		// ���y�̍Đ�
		mpSound->loop();
	}
	//
	// �`��
	void Title::draw() {
		ClearDrawScreen(); // ����ʂ��N���A

		mpBackground->draw(); // �w�i

		MyDrawString(Parameter::WindowWidth / 10, Parameter::WindowHeight / 2 - 100, "������V���[�e�B���O", ColorParameter::Black, BigFontHandle);
		MyDrawString(Parameter::WindowWidth / 2 - 100, Parameter::WindowHeight / 2 + 50, "SPACE�������Ă�������", ColorParameter::Black, SmallFontHandle);

		ScreenFlip(); // ����ʂƕ\��ʂ����ւ���
	}
	//
	// ������̕`��
	void Title::MyDrawString(int drawX, int drawY, const char* string, int color, int FontHandle) {
		DrawStringToHandle(drawX, drawY, string, color, FontHandle);
	}
}