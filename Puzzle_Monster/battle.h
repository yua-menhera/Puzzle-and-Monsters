#pragma once

int doBattle(Monster monster, Party* party, int* returnNowHitpoint);
void onPlayerTurn(BattleField* field, int* nowHitPoint);
void doAttack(Party* party, Monster* enemyMonster, Element selectElement, int deletedGems, int combo);
void doRecover(Party* party, int deletedGems, int combo);

void onEnemyTurn(BattleField* field);
void doEnemyAttack(Party* party, Monster* monster);
