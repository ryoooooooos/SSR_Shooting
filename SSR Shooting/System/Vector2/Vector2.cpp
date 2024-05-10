// �K�v�t�@�C���̃C���N���[�h
#include "Vector2.h"
//
// �l�[���X�y�[�X
namespace furukawa {
	// �R���X�g���N�^�i�l�w��Ȃ��j
	Vector2::Vector2()
		: mX(0.0f)
		, mY(0.0f)
	{
	}
	// �R���X�g���N�^�i�l�w�肠��j
	Vector2::Vector2(float x, float y)
		: mX(x)
		, mY(y)
	{
	}
	// ���l��r
	bool Vector2::operator==(const Vector2& rhs)const {
		return (mX == rhs.mX) && (mY == rhs.mY);
	}
	// �[���x�N�g���Ɠ�������
	bool Vector2::isZeroStrict()const {
		return (mX == 0.0f) && (mY == 0.0f);
	}
	// 2�̃x�N�g�����덷�͈͓̔��œ�������
	bool Vector2::equals(const Vector2& vec)const {
		return Math::Equal(mX, vec.mX) && Math::Equal(mY, vec.mY);
	}
	//
	// �l�����Z
	// �����𔽓]�������̂�Ԃ�
	Vector2 Vector2::operator-()const {
		return Vector2(-mX, -mY);
	}
	// �x�N�g�������Z�����ʂ���
	Vector2& Vector2::operator+=(const Vector2& rhs) {
		mX += rhs.mX;
		mY += rhs.mY;
		return *this;
	}
	// �x�N�g�������Z�����ʂ���
	Vector2& Vector2::operator-=(const Vector2& rhs) {
		return *this += (-rhs);
	}
	// �x�N�g���̎����{���v�Z�����ʂ���
	Vector2& Vector2::operator*=(float rhs) {
		mX *= rhs;
		mY *= rhs;
		return *this;
	}
	// �x�N�g���������Ŋ��������ʂ���
	Vector2& Vector2::operator/=(float rhs) {
		mX /= rhs;
		mY /= rhs;
		return *this;
	}
	// 2�̃x�N�g���̘a��Ԃ�
	Vector2 Vector2::operator+(const Vector2& rhs)const {
		auto vec(*this);
		vec += rhs;
		return vec;
	}
	// 2�̃x�N�g���̍���Ԃ�
	Vector2 Vector2::operator-(const Vector2& rhs)const {
		return *this + (-rhs);
	}
	// �x�N�g���̎����{��Ԃ�
	Vector2 Vector2::operator*(float rhs)const {
		auto vec(*this);
		vec *= rhs;
		return vec;
	}
	// �x�N�g���������Ŋ������l��Ԃ�
	Vector2 Vector2::operator/(float rhs)const {
		auto vec(*this);
		vec /= rhs;
		return vec;
	}
	//
	// ���̑��̋@�\
	// ���ς����߂�
	float Vector2::dot(const Vector2& vec)const {
		return (mX * vec.mX) + (mY * vec.mY);
	}
	// �O�ς����߂�
	float Vector2::cross(const Vector2& vec)const {
		return (mX * vec.mY) - (mY * vec.mX);
	}
	// �]�������߂�(���w�I�ɂ�2�����x�N�g���ɊO�ς͂Ȃ����A���̊֐��̎g�����͂���̂ŁE�E�E�j
	float Vector2::cos(const Vector2& vec)const {
		auto d = dot(vec);
		auto l = length() * vec.length();
		assert(l > 0.0f); // �[���x�N�g���΍�
		auto result = d / l;	// ���ς̌��ʂ�傫�����傫���Ŋ��邱�Ƃ�cos�Ƃ����܂�
		// �덷�΍�(-1 <= cos�� <= 1 �͈̔͂Ȃ̂�)
		if (result > 1.0f) {
			result = 1.0f;
		}
		else if (result < -1.0f) {
			result = -1.0f;
		}
		return result;
	}
	// �Ȃ��p�����߂�(�P�ʂ̓��W�A��)
	float Vector2::angle(const Vector2& vec)const {
		return std::acos(cos(vec));  // cos��Vector2::cos
	}
	// �x�N�g���̒��������߂�
	float Vector2::length()const {
		return std::sqrt(squareLength());
	}
	// �x�N�g���̒����̓������߂�
	float Vector2::squareLength()const {
		return (mX * mX) + (mY * mY);
	}
	// �ʒu�x�N�g���Ƃ̋��������߂�
	float Vector2::dist(const Vector2& point)const {
		return std::sqrt(squareDist(point));
	}
	// �ʒu�x�N�g���Ƃ̋����̓������߂�
	float Vector2::squareDist(const Vector2& point)const {
		auto x2 = (mX - point.mX) * (mX - point.mX);
		auto y2 = (mY - point.mY) * (mY - point.mY);
		return x2 + y2;
	}
	// ���̒����ɐ��K���Blen�ȗ�����1.0f�ivoid unitAssign(float len = 1.0f);�j
	void Vector2::unitAssign(float len) {
		assert(len > 0.0f); // ������0�ȉ��̓_����
		*this /= length(); // �܂��͑傫���P�Ő��K��
		*this *= len;
	}
	// ���̒����ɐ��K�����ꂽ�x�N�g����Ԃ��B len�ȗ�����1.0f�iVector2 unit(float len = 1.0f)const;�j
	Vector2 Vector2::unit(float len)const {
		assert(len > 0.0f); // ������0�ȉ��̓_����
		auto vec(*this);
		vec.unitAssign(len);
		return vec;
	}
	// �x�N�g�����w�肳�ꂽ�p�x(���W�A��)�����v���ɉ�]
	void Vector2::rotateRadAssign(float rad) {
		auto newX = std::cos(rad) * mX - std::sin(rad) * mY;
		auto newY = std::sin(rad) * mX + std::cos(rad) * mY;
		mX = newX;
		mY = newY;
	}
	// �w�肳�ꂽ�p�x(���W�A��)�����v���ɉ�]�������x�N�g����Ԃ�
	Vector2 Vector2::rotateRad(float rad)const {
		auto vec(*this);
		vec.rotateRadAssign(rad);
		return vec;
	}
	// �x�N�g���������Ŏw�肳�ꂽ�x�N�g���Ɏˉe
	// (���ʁA���߂��x�N�g���ƈ����Ŏw�肳�ꂽ�x�N�g���͕��s�ɂȂ�A���̑傫����菬�����Ȃ�)
	void Vector2::projectAssign(const Vector2& vec) {
		auto l = vec.length();
		assert(l > 0.0f); // �[���x�N�g���΍�
		l = this->dot(vec) / l; // ���ς̌��ʂ������Ɏw�肳�ꂽ�x�N�g���̑傫���Ŋ��邱�ƂŁA�ˉe�����̒������킩��
		auto result = vec.unit() * l; // �����Ɏw�肳�ꂽ�x�N�g����傫���P�ɐ��K�����A��ŋ��߂�����(l)���|����΂��ꂪ����
		mX = result.mX;
		mY = result.mY;
	}
	// �����Ŏw�肳�ꂽ�x�N�g���Ɏˉe�����x�N�g����Ԃ�
	// (���ʁA�Ԃ��ꂽ�x�N�g���ƈ����Ŏw�肳�ꂽ�x�N�g���͕��s�ɂȂ�A���̑傫����菬�����Ȃ�)
	Vector2 Vector2::project(const Vector2& vec)const {
		auto v(*this);
		v.projectAssign(vec);
		return v;
	}
}