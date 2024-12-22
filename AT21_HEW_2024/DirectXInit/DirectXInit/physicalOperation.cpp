#include"PhysicalOperationh.h"


// ��Q���̏Փ˂��`�F�b�N
bool checkCollision(double posX, double posY) {
    // �V���v���ȏՓ˔���: X, Y���W������͈͂ɓ�������Փ�
    return (posX >= 50.0 && posX <= 60.0 && posY <= 10.0);
}

// �v���C���[�̏�Ԃ��X�V
void updatePlayer(Player& player, const Input& input) {
    // ��Ԃ��Ƃɋ���������
    if (player.state == PlayerState::Gliding) {
        // ����
        player.velY += GRAVITY * DELTA_TIME * 0.5; // �������x���y��
        player.velX += input.stickX * 5.0 * DELTA_TIME; // �X�e�B�b�N���͂ŕ����]��

        if (input.cancel) {
            // �L�����Z���Œʏ헎���Ɉڍs
            player.state = PlayerState::Falling;
            std::cout << "Glide canceled!" << std::endl;
        }
    }
    else if (player.state == PlayerState::Falling) {
        // �ʏ�̎��R����
        player.velY += GRAVITY * DELTA_TIME;
    }

    // �v���C���[�ʒu�̍X�V
    player.posX += player.velX * DELTA_TIME;
    player.posY += player.velY * DELTA_TIME;

    // �Փ˔���
    if (checkCollision(player.posX, player.posY)) {
        player.velX = 0.0;
        player.velY = 0.0;
        std::cout << "Collision detected!" << std::endl;
    }

    // �n�ʓ��B���̏���
    if (player.posY <= 0.0) {
        player.posY = 0.0;
        player.velY = 0.0;
        player.state = PlayerState::Normal;
        player.glideCount = 2; // ����񐔂����Z�b�g
        std::cout << "Player landed!" << std::endl;
    }
}

// ����J�n
void startGlide(Player& player) {
    if (player.state != PlayerState::Gliding && player.glideCount > 0) {
        player.state = PlayerState::Gliding;
        player.velY = -5.0; // ����J�n���Ɍy���㏸��t�^
        player.glideCount--;
        std::cout << "Gliding started! Remaining glides: " << player.glideCount << std::endl;
    }
}