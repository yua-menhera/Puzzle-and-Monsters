/**
 * @file battle.h
 * @brief �o�g�������֐��w�b�_�[
 */
#pragma once

/**
 * @brief �퓬���̏������s���֐�
 * @param monster �G�����X�^�[
 * @param party �����p�[�e�B�[
 * @param returnNowHitpoint �����p�[�e�B�[�̌��݂̗̑�
 * @return int �����Ȃ�0, �s�k�Ȃ�1���o��
 */
int doBattle(Monster monster, Party* party, int* returnNowHitpoint);

/**
 * @brief �����^�[���̏������s���֐�
 *
 * @param field �퓬�t�B�[���h
 * @param nowHitPoint ���݂̗̑�
 */
void onPlayerTurn(BattleField* field, int* nowHitPoint);

/**
 * @brief �����̍U�����s���֐�
 *
 * @param party �����p�[�e�B�[
 * @param enemyMonster �G�����X�^�[
 * @param selectElement �I�����ꂽ����
 * @param deletedGems ��������΂̐�
 * @param combo �R���{��
 */
void doAttack(Party* party, Monster* enemyMonster, Element selectElement, int deletedGems, int combo);

/**
 * @brief �����̉񕜂��s���֐�
 *
 * @param party �����p�[�e�B�[
 * @param deletedGems ��������΂̐�
 * @param combo �R���{��
 */
void doRecover(Party* party, int deletedGems, int combo);

/**
 * @brief �G�^�[���̏������s���֐�
 *
 * @param field �퓬�t�B�[���h
 */
void onEnemyTurn(BattleField* field);

/**
 * @brief �G�̍U�����s���֐�
 *
 * @param party �U�������p�[�e�B�[
 * @param monster �U�����s�������X�^�[
 */
void doEnemyAttack(Party* party, Monster* monster);
