/**
 * @file utility.h
 * @brief ���[�e�B���e�B�֐��w�b�_
 * @author yuuka-overdose
 * @date 2022/05/18
 */
#pragma once

/**
 * @brief �����X�^�[�����p�̌`���ŕ\������֐�
 * @param monster �\�������郂���X�^�[�̍\����
 */
void printMonsterName(Monster monster);

/**
 * @brief �o�g���t�B�[���h�̏󋵂�\������֐�
 * @param field �\�����������o�g���t�B�[���h
 * @details �G�E�����̗̑́A��΃X���b�g�̏�Ԃ�\������
 */
void showBattleField(BattleField* field);

/**
 * @brief ��΃X���b�g��S�Ė��߂�֐�
 * @param field �Ώۂ̃o�g���t�B�[���h
 */
void fillGems(BattleField* field);

/**
 * @brief ��΃X���b�g�̏�Ԃ�\������֐�
 * @param field �\���Ώۂ̃o�g���t�B�[���h
 */
void printGems(BattleField* field);

/**
 * @brief ���͂��ꂽ�R�}���h���L�����ǂ����𔻒肷��֐�
 * @param src �Ώۂ̕��
 * @param dest �ړ���
 * @return int �L���ł����0, �����ł����1���o��
 */
int checkValidCommand(char src, char dest);

/**
 * @brief �_���[�W�E�񕜗ʂ��w�肳�ꂽ�͈͓��ŕύX����
 * @param damage �_���[�W�E�񕜗�
 * @param min_damage �ŏ��l
 * @param max_damage �ő�l
 * @return int �����_���ɂԂꂽ���Ƃ̃_���[�W�񕜗ʂ��o��
 */
int blurDamage(int damage, int min_damage, int max_damage);

/**
 * @brief �G�����X�^�[����󂯂�_���[�W���o�͂���֐�
 * @param enemyAttack �G�̍U����
 * @param partyDefence �p�[�e�B�[�̖h���
 * @return int �󂯂�_���[�W�ʂ��o��
 */
int calcEnemyAttackDamage(int enemyAttack, int partyDefence);

/**
 * @brief �G�����X�^�[�ɗ^����_���[�W���o�͂���֐�
 * @param partyAttack ���������X�^�[�̍U����
 * @param enemyDefence �G�����X�^�[�̖h���
 * @param boost �{��
 * @param gems ����
 * @param combo �R���{��
 * @return int �^����_���[�W�ʂ��o��
 */
int calcAttackDamage(int playerAttack, int enemyDefence, double boost, int gems, int combo);
int calcRecoverDamage();
void printCombo();
