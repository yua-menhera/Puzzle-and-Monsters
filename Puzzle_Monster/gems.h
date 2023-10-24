/**
 * @file gems.h
 * @brief 宝石処理関数ヘッダ
 */
#pragma once

/**
 * @brief 宝石スロットを全て埋める関数
 *
 * @param field 戦闘フィールド
 */
void fillGems(BattleField* field);

/**
 * @brief 宝石スロットを表示する関数
 *
 * @param field 戦闘フィールド
 */
void printGems(BattleField* field);

/**
 * @brief 宝石を移動させる関数
 *
 * @param field 戦闘フィールド
 * @param src 移動元の宝石
 * @param dest 移動先の宝石
 * @param mode 移動後の宝石スロットを表示するかどうか(0:表示しない,1:表示する)
 */
void moveGem(BattleField* field, char src, char dest,int mode);

/**
 * @brief 宝石を入れ替える関数
 *
 * @param field 戦闘フィールド
 * @param src 移動する宝石
 * @param move 移動方向(0:左,1:右)
 * @param mode 移動後の宝石スロットを表示するかどうか(0:表示しない,1:表示する)
 */
void swapGem(BattleField* field, int src, int move, int mode);

/**
 * @brief 宝石の評価を行う関数
 *
 * @param field
 * @param banishInfo
 */
void evaluteGems(BattleField* field, BanishInfo* banishInfo);

/**
 * @brief 宝石の消去が可能かどうかを判定する関数
 *
 * @param field 戦闘フィールド
 * @return BanishInfo 宝石の消去情報
 */
BanishInfo checkBanishable(BattleField* field);

/**
 * @brief 宝石を消去する関数
 *
 * @param field 戦闘フィールド
 * @param banish 宝石の消去情報
 * @param combo コンボ数
 */
void banishGems(BattleField* field, BanishInfo banish,int combo);

/**
 * @brief 宝石の消去後、宝石を左にシフトする関数
 *
 * @param field 戦闘フィールド
 * @param banish 宝石の消去情報
 */
void shiftGems(BattleField* field,BanishInfo banish);

/**
 * @brief 宝石を生成する関数
 *
 * @param field 戦闘フィールド
 */
void spawnGems(BattleField* field);
