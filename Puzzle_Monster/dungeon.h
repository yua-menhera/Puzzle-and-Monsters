/**
 * @file dungeon.h
 * @brief ダンジョン関連関数ヘッダー
 */

#pragma once

/**
 * @brief ダンジョンを生成し、パーティーを戦闘に送り出す関数
 *
 * @param party 味方パーティー
 * @param dungeon 生成するダンジョン
 * @return int 倒した敵の数
 */
int goDungeon(Party party, Dungeon dungeon);