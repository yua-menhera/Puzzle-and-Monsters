#pragma once

/**
 * @brief �퓬���̏������s���֐�
 * @param monster �G�����X�^�[
 * @param party �����p�[�e�B�[
 * @param returnNowHitpoint �����p�[�e�B�[�̌��݂̗̑�
 * @return int �����Ȃ�0, �s�k�Ȃ�1���o��
 */
int doBattle(Monster monster, Party* party, int* returnNowHitpoint);
void onPlayerTurn(BattleField* field, int* nowHitPoint);
void doAttack(Party* party, Monster* enemyMonster, Element selectElement, int deletedGems, int combo);
void doRecover(Party* party, int deletedGems, int combo);

void onEnemyTurn(BattleField* field);
void doEnemyAttack(Party* party, Monster* monster);
