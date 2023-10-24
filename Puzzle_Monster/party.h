/**
 * @file party.h
 * @brief パーティー関連関数ヘッダー
 */
#pragma once

/**
 * @brief パーティーの編成を行う関数
 *
 * @return Party	編成されたパーティー
 */
Party organizeParty(char*,Monster*, int);

/**
 * @brief パーティ情報を表示する関数
 *
 * @param party 表示するパーティー
 */
void showParty(Party party);
