/**
 * @file utility.h
 * @brief ユーティリティ関数ヘッダ
 * @author yuuka-overdose
 * @date 2022/05/18
 */
#pragma once

/**
 * @brief モンスター名を専用の形式で表示する関数
 * @param monster 表示させるモンスターの構造体
 */
void printMonsterName(Monster monster);

/**
 * @brief バトルフィールドの状況を表示する関数
 * @param field 表示させたいバトルフィールド
 * @details 敵・味方の体力、宝石スロットの状態を表示する
 */
void showBattleField(BattleField* field);

/**
 * @brief 宝石スロットを全て埋める関数
 * @param field 対象のバトルフィールド
 */
void fillGems(BattleField* field);

/**
 * @brief 宝石スロットの状態を表示する関数
 * @param field 表示対象のバトルフィールド
 */
void printGems(BattleField* field);

/**
 * @brief 入力されたコマンドが有効かどうかを判定する関数
 * @param src 対象の宝石
 * @param dest 移動先
 * @return int 有効であれば0, 無効であれば1を出力
 */
int checkValidCommand(char src, char dest);

/**
 * @brief ダメージ・回復量を指定された範囲内で変更する
 * @param damage ダメージ・回復量
 * @param min_damage 最小値
 * @param max_damage 最大値
 * @return int ランダムにぶれたあとのダメージ回復量を出力
 */
int blurDamage(int damage, int min_damage, int max_damage);

/**
 * @brief 敵モンスターから受けるダメージを出力する関数
 * @param enemyAttack 敵の攻撃力
 * @param partyDefence パーティーの防御力
 * @return int 受けるダメージ量を出力
 */
int calcEnemyAttackDamage(int enemyAttack, int partyDefence);

/**
 * @brief 敵モンスターに与えるダメージを出力する関数
 * @param partyAttack 味方モンスターの攻撃力
 * @param enemyDefence 敵モンスターの防御力
 * @param boost 倍率
 * @param gems 属性
 * @param combo コンボ数
 * @return int 与えるダメージ量を出力
 */
int calcAttackDamage(int playerAttack, int enemyDefence, double boost, int gems, int combo);
int calcRecoverDamage();
void printCombo();
