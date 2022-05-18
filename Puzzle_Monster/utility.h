#pragma once
void printMonsterName(Monster monster);
void showBattleField(BattleField* field);
void fillGems(BattleField* field);
void printGems(BattleField* field);
int checkValidCommand(char src, char dest);
int blurDamage(int damage, int min_damage, int max_damage);
int calcEnemyAttackDamage(int enemyAttack, int partyDefence);
int calcAttackDamage(int playerAttack, int enemyDefence, double boost, int gems, int combo);
int calcRecoverDamage();
void printCombo();