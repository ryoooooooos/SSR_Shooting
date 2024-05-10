#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../Math/Math.h"
#include <cmath>
#include <cassert>
//
// �l�[���X�y�[�X
namespace furukawa {
	// �񎟌��x�N�g���N���X
	class Vector2 {
	public:
		/* �R���X�g���N�^�E�f�X�g���N�^ */
		Vector2(); // �R���X�g���N�^�i�l�w��Ȃ��j
		Vector2(float x, float y); // �R���X�g���N�^�i�l�w�肠��j
		~Vector2() = default; // �f�X�g���N�^
		/* �֐� */
		// ���l��r
		// 2�̃x�N�g������������
		bool operator==(const Vector2& rhs)const;
		// �[���x�N�g���Ɠ�������
		bool isZeroStrict()const;
		// 2�̃x�N�g�����덷�͈͓̔��œ�������
		bool equals(const Vector2& vec)const;
		//
		// �l�����Z
		// �����𔽓]�������̂�Ԃ�
		Vector2 operator-()const;
		// �x�N�g�������Z�����ʂ���
		Vector2& operator+=(const Vector2& rhs);
		// �x�N�g�������Z�����ʂ���
		Vector2& operator-=(const Vector2& rhs);
		// �x�N�g���̎����{���v�Z�����ʂ���
		Vector2& operator*=(float rhs);
		// �x�N�g���������Ŋ��������ʂ���
		Vector2& operator/=(float rhs);
		// 2�̃x�N�g���̘a��Ԃ�
		Vector2 operator+(const Vector2& rhs)const;
		// 2�̃x�N�g���̍���Ԃ�
		Vector2 operator-(const Vector2& rhs)const;
		// �x�N�g���̎����{��Ԃ�
		Vector2 operator*(float rhs)const;
		// �x�N�g���������Ŋ������l��Ԃ�
		Vector2 operator/(float rhs)const;
		//
		// ���̑��̋@�\
		// ���ς����߂�
		float dot(const Vector2& vec)const;
		// �O�ς����߂�i���w�I�ɂ�2�����x�N�g���ɊO�ς͂Ȃ����A���̊֐��̎g�����͂���̂ŁE�E�E�j
		float cross(const Vector2& vec)const;
		// �]�������߂�
		float cos(const Vector2& vec)const;
		// �Ȃ��p�����߂�(�P�ʂ̓��W�A��)
		float angle(const Vector2& vec)const;
		// �x�N�g���̒��������߂�
		float length()const;
		// �x�N�g���̒����̓������߂�
		float squareLength()const;
		// �ʒu�x�N�g���Ƃ̋��������߂�
		float dist(const Vector2& point)const;
		// �ʒu�x�N�g���Ƃ̋����̓������߂�
		float squareDist(const Vector2& point)const;
		// ���̒����ɐ��K��
		void unitAssign(float len = 1.0f);
		// ���̒����ɐ��K�����ꂽ�x�N�g����Ԃ�
		Vector2 unit(float len = 1.0f)const;
		// �x�N�g�����w�肳�ꂽ�p�x(���W�A��)�����v���ɉ�]
		void rotateRadAssign(float rad);
		// �w�肳�ꂽ�p�x(���W�A��)�����v���ɉ�]�������x�N�g����Ԃ�
		Vector2 rotateRad(float rad)const;
		// �x�N�g���������Ŏw�肳�ꂽ�x�N�g���Ɏˉe
		// (���ʁA���߂��x�N�g���ƈ����Ŏw�肳�ꂽ�x�N�g���͕��s�ɂȂ�A���̑傫����菬�����Ȃ�)
		void projectAssign(const Vector2& vec);
		// �����Ŏw�肳�ꂽ�x�N�g���Ɏˉe�����x�N�g����Ԃ�
		// (���ʁA�Ԃ��ꂽ�x�N�g���ƈ����Ŏw�肳�ꂽ�x�N�g���͕��s�ɂȂ�A���̑傫����菬�����Ȃ�)
		Vector2 project(const Vector2& vec)const;
		/* �ϐ� */
		// �����o�ϐ���private�ɂ��Apublic�ȃA�N�Z�T���\�b�h��p�ӂ��邱�Ƃ�
		// ���S����UP���邪�A���s���x���ቺ����B����̃P�[�X�͑��x�d���ł�����public
		// �����炭�AVector2�N���X�̏ꍇ��public�̕��������b�g���傫���Ǝv��
		float mX;    // �x�N�g���� x �v�f�@������public
		float mY;    // �x�N�g���� y �v�f   ������public
	};
}