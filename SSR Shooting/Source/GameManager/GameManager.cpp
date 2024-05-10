// �K�v�t�@�C���̃C���N���[�h
#include "GameManager.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	GameManager::GameManager() 
		: mpScene(nullptr)
		, Score(-1)
	{
	}
	// �f�X�g���N�^
	GameManager::~GameManager() {
		delete mpScene;
	}
	// ���s
	void GameManager::run() {
		// �C���X�^���X���擾
		auto& key = Keyboard::getInstance();
		// �����������������烋�[�v
		if (SUCCEEDED(init())) {
			while (1) {	// ESC�L�[���������܂Ŗ������[�v
				if (ProcessMessage() == -1) break; // �~�{�^���������ꂽ�烋�[�v�𔲂���
				if (CheckHitKey(KEY_INPUT_ESCAPE)) break; // ESC�L�[�������ꂽ�烋�[�v�𔲂���
				if (FAILED(key.keyUpdate())) break; // �L�[���͏�����
				if (FAILED(gameLoop())) break; // �Q�[������
			}
		}

		// �I��
		final();
	}
	// ������
	HRESULT GameManager::init() {
		ChangeWindowMode(TRUE); // �E�C���h�E���[�h�ɐݒ�
		SetGraphMode(Parameter::WindowWidth, Parameter::WindowHeight, Parameter::ColorBit); // 800�~600�A32�r�b�g�J���[
		SetBackgroundColor(65, 105, 225); // GetColor�̖߂�l���w�肷�邷�ׂ��Ȃ��̂ŁA�����̓}�W�b�N�i���o�[
		SetDrawScreen(DX_SCREEN_BACK); // �W����DX_SCREEN_FRONT���Ƃ͒m��Ȃ������B���߂�Ȃ���
		//SetWaitVSyncFlag(0); // ����������OFF
		if (DxLib_Init() == -1) {	// �c�w���C�u��������������
			return E_FAIL;			// �G���[���N�����璼���ɏI��
		}
		// �����̎�����
		std::srand(static_cast <unsigned int>(time(NULL)));
		// �ŏ��̓^�C�g������
		mpScene = new Title(this);
		// ������
		if (FAILED(mpScene->init())) return E_FAIL;

		return S_OK;
	}
	// �I��
	void GameManager::final() {
		DxLib_End();
	}
	// �Q�[�����[�v
	HRESULT GameManager::gameLoop() {
		// ���̃V�[�������s
		Scene* pNext = mpScene->run();
		// �Ⴄ�V�[����������V�������
		if (pNext != mpScene) {
			delete mpScene;
			mpScene = pNext;
			// ������
			if (FAILED(mpScene->init())) {
				return E_FAIL;
			}
		}
		return S_OK;
	}
	// �X�R�A���Z�b�g
	void GameManager::setScore(const int s) {
		Score = s;
	}
	// �X�R�A��Ԃ�
	int GameManager::getScore()const {
		return Score;
	}
}