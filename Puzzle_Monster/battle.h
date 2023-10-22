#pragma once

/**
 * @brief 戦闘時の処理を行う関数
 * @param monster 敵モンスター
 * @param party 味方パーティー
 * @param returnNowHitpoint 味方パーティーの現在の体力
 * @return int 勝利なら0, 敗北なら1を出力
 */
int doBattle(Monster monster, Party* party, int* returnNowHitpoint);
void onPlayerTurn(BattleField* field, int* nowHitPoint);
void doAttack(Party* party, Monster* enemyMonster, Element selectElement, int deletedGems, int combo);
void doRecover(Party* party, int deletedGems, int combo);

void onEnemyTurn(BattleField* field);
void doEnemyAttack(Party* party, Monster* monster);
