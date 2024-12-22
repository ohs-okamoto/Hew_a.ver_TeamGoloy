#pragma once
#include"Direct3d.h"
#include"Object.h"
#include"Game.h"

#include <iostream>

// �v���C���[�̏��
enum class PlayerState { Normal, Gliding, Falling };

// �v���C���[�\����
struct Player {
    double mass;       // ���� (kg)
    double posX;       // X���W
    double posY;       // Y���W
    double velX;       // X�������x
    double velY;       // Y�������x
    int glideCount;    // �c�芊���
    PlayerState state; // �v���C���[�̏��
};

// ���͍\����
struct Input {
    bool glide;      // ����{�^���������ꂽ��
    bool cancel;     // ����L�����Z���{�^���������ꂽ��
    double stickX;   // �X�e�B�b�N��X�������� (-1.0 ~ 1.0)
};

// �萔
const double GRAVITY = 9.81;      // �d�͉����x (m/s^2)
const double DELTA_TIME = 0.016;  // 1�t���[���̎��� (��60FPS)

// �֐��v���g�^�C�v
void updatePlayer(Player& player, const Input& input);  // �v���C���[��Ԃ̍X�V
void startGlide(Player& player);                        // ����J�n
bool checkCollision(double posX, double posY);          // ��Q���̏Փ˃`�F�b�N
