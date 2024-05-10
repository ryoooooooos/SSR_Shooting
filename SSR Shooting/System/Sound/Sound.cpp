// �K�v�t�@�C���̃C���N���[�h
#include "Sound.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	Sound::Sound(const char* FileName)
		: mpFileName(std::string(FileName))
		, mHandle(-1)
	{
	}
	// �f�X�g���N�^
	Sound::~Sound() {
		if (mHandle >= 0) {
			DeleteSoundMem(mHandle);
		}
	}
	// ���y�t�@�C���̃��[�h
	HRESULT Sound::init() {
		auto str = mpFileName.data();
		if ((mHandle = LoadSoundMem(str)) == -1) {
			FILE_NOT_FOUND(str);
			return E_FAIL;
		}
		return S_OK;
	}
	// ���y�̒ʏ�Đ�
	void Sound::play()const {
		// �ʏ�Đ����Ǝ��s��ʂ��~�܂邽�߃o�b�N�O���E���h�Đ�
		PlaySoundMem(mHandle, DX_PLAYTYPE_BACK);
	}
	// ���y�̃��[�v�Đ�
	void Sound::loop()const {
		if (CheckSoundMem(mHandle) == 0) {
			PlaySoundMem(mHandle, DX_PLAYTYPE_LOOP);
		}
	}
}