#pragma once
// �K�v�t�@�C���̃C���N���[�h
#include "../Base/Object.h"
#include "../../Parameter/Parameter.h"
//
// �l�[���X�y�[�X
namespace furukawa {
    // �e�N���X
    class Bullet : public Object {
    public:
        /* �R���X�g���N�^�E�f�X�g���N�^ */
        Bullet(const char* FileName); // �R���X�g���N�^
        ~Bullet(); // �f�X�g���N�^
        /* �֐� */
        HRESULT init()override; // ������
        void update(); // �X�V
        void appear(const Vector2& v); // �o��
        void draw()const override; // �`��
        /* �A�N�Z�T */
        Vector2 getPos()const; // ���W��Ԃ�
        void setIsVisible(const bool t_or_f); // �o���t���O���Z�b�g
        bool getIsVisible()const; // �o���t���O��Ԃ�
    private:
        /* �ϐ� */
        Image* mpImage; // �摜�N���X
        Vector2 pos; // ���W
        bool isVisible; // �o���t���O
    };
}