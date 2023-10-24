/**
 * @file gems.h
 * @brief ��Ώ����֐��w�b�_
 */
#pragma once

/**
 * @brief ��΃X���b�g��S�Ė��߂�֐�
 *
 * @param field �퓬�t�B�[���h
 */
void fillGems(BattleField* field);

/**
 * @brief ��΃X���b�g��\������֐�
 *
 * @param field �퓬�t�B�[���h
 */
void printGems(BattleField* field);

/**
 * @brief ��΂��ړ�������֐�
 *
 * @param field �퓬�t�B�[���h
 * @param src �ړ����̕��
 * @param dest �ړ���̕��
 * @param mode �ړ���̕�΃X���b�g��\�����邩�ǂ���(0:�\�����Ȃ�,1:�\������)
 */
void moveGem(BattleField* field, char src, char dest,int mode);

/**
 * @brief ��΂����ւ���֐�
 *
 * @param field �퓬�t�B�[���h
 * @param src �ړ�������
 * @param move �ړ�����(0:��,1:�E)
 * @param mode �ړ���̕�΃X���b�g��\�����邩�ǂ���(0:�\�����Ȃ�,1:�\������)
 */
void swapGem(BattleField* field, int src, int move, int mode);

/**
 * @brief ��΂̕]�����s���֐�
 *
 * @param field
 * @param banishInfo
 */
void evaluteGems(BattleField* field, BanishInfo* banishInfo);

/**
 * @brief ��΂̏������\���ǂ����𔻒肷��֐�
 *
 * @param field �퓬�t�B�[���h
 * @return BanishInfo ��΂̏������
 */
BanishInfo checkBanishable(BattleField* field);

/**
 * @brief ��΂���������֐�
 *
 * @param field �퓬�t�B�[���h
 * @param banish ��΂̏������
 * @param combo �R���{��
 */
void banishGems(BattleField* field, BanishInfo banish,int combo);

/**
 * @brief ��΂̏�����A��΂����ɃV�t�g����֐�
 *
 * @param field �퓬�t�B�[���h
 * @param banish ��΂̏������
 */
void shiftGems(BattleField* field,BanishInfo banish);

/**
 * @brief ��΂𐶐�����֐�
 *
 * @param field �퓬�t�B�[���h
 */
void spawnGems(BattleField* field);
