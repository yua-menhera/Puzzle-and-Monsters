/**
 * @file battle.h
 * @brief バトル処理関数ヘッダー
 */
#pragma once

/**
 * @brief 戦闘時の処理を行う関数
 * @param monster 敵モンスター
 * @param party 味方パーティー
 * @param returnNowHitpoint 味方パーティーの現在の体力
 * @return int 勝利なら0, 敗北なら1を出力
 */
int doBattle(Monster monster, Party* party, int* returnNowHitpoint);

/**
 * @brief 味方ターンの処理を行う関数
 *
 * @param field 戦闘フィールド
 * @param nowHitPoint 現在の体力
 */
void onPlayerTurn(BattleField* field, int* nowHitPoint);

/**
 * @brief 味方の攻撃を行う関数
 *
 * @param party 味方パーティー
 * @param enemyMonster 敵モンスター
 * @param selectElement 選択された属性
 * @param deletedGems 消した宝石の数
 * @param combo コンボ数
 */
void doAttack(Party* party, Monster* enemyMonster, Element selectElement, int deletedGems, int combo);

/**
 * @brief 味方の回復を行う関数
 *
 * @param party 味方パーティー
 * @param deletedGems 消した宝石の数
 * @param combo コンボ数
 */
void doRecover(Party* party, int deletedGems, int combo);

/**
 * @brief 敵ターンの処理を行う関数
 *
 * @param field 戦闘フィールド
 */
void onEnemyTurn(BattleField* field);

/**
 * @brief 敵の攻撃を行う関数
 *
 * @param party 攻撃されるパーティー
 * @param monster 攻撃を行うモンスター
 */
void doEnemyAttack(Party* party, Monster* monster);
