// �K�v�t�@�C���̃C���N���[�h
#include "keyboard.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^
	Keyboard::Keyboard()
		: mKeyToVK{
			KEY_INPUT_W,
			KEY_INPUT_S,
			KEY_INPUT_E,
			KEY_INPUT_R,
			KEY_INPUT_SPACE
		}
		, mPreKeyStat(0U)
		, mNowKeyStat(0U)
	{
	}
	// �C���X�^���X�̎擾
	Keyboard& Keyboard::getInstance() {
		static Keyboard inst;
		return inst;
	}
	//
	// ���t���[���ŏ��ɌĂяo��
	HRESULT Keyboard::keyUpdate() {
		char Buf[256];
		if (GetHitKeyStateAll(Buf) == -1) {
			FUNC_ERR("GetHitKeyStateAll");
			return E_FAIL;
		}
		mPreKeyStat = mNowKeyStat;
		mNowKeyStat = 0;
		for (auto i = 0; i < static_cast <int>(KeyType::MAX); i++) {
			if (Buf[mKeyToVK[i]] == 1) {
				mNowKeyStat |= (1U << i);
			}
		}

		return S_OK;
	}
	//
	// �L�[�{�[�h���������ꂽ�u�Ԃ����^�A���̑��͋U��Ԃ��B
	// ����g�p�ł���L�[�{�[�h�̎�ނ�8��ނ܂łł��B
	bool Keyboard::isKeyPush(KeyType keyNo) const {
		auto pre = (mPreKeyStat & (1U << static_cast <int>(keyNo))) > 0;
		auto now = (mNowKeyStat & (1U << static_cast <int>(keyNo))) > 0;
		return !pre && now;
	}
	//
	// �L�[�������ꂽ�u�Ԃ����^�A���̑��͋U��Ԃ��B
	// ����g�p�ł���L�[�{�[�h�̎�ނ͂W��ނ܂łł��B
	bool Keyboard::isKeyRelease(KeyType keyNo) const {
		auto pre = (mPreKeyStat & (1U << static_cast <int>(keyNo))) > 0;
		auto now = (mNowKeyStat & (1U << static_cast <int>(keyNo))) > 0;
		return pre && !now;
	}
}