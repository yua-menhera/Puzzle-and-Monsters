/**
 * @file define.h
 * @brief グローバル変数・列挙体・構造体の宣言をするヘッダ
 * @date 2022/05/19
 */
#pragma once

extern char ELEMENT_SYMBOLS[];
extern int ELEMENT_COLORS[];
extern double ELEMENT_BOOST[][6];
extern int PARTY_MONSTER_ELEMENT[];
extern const int MAX_GEMS;

/**
 * @enum Element
 * @brief 属性を定義
 */
typedef enum Element {
	fire,	/**< 火属性 = 0 */
	water,	/**< 水属性 = 1 */
	wind,	/**< 風属性 = 2 */
	earth,	/**< 地属性 = 3 */
	life,	/**< 回復 = 4 */
	empty	/**< 無属性 = 5 */
}Element;

/**
 * @enum EnemyMonsterID
 * @brief 敵モンスターのIDを指定
 */
typedef enum EnemyMonsterID {
	slime,		/**< スライム = 0 */
	goblin,		/**< ゴブリン = 1 */
	bigbat,		/**< コウモリ = 2 */
	werewolf,	/**< ウェアウルフ = 3 */
	dragon		/**< ドラゴン = 4 */

}EnemyMonsterID;

/**
 * @enum PlayerMonsterID
 * @brief 味方モンスターのIDを指定
 */
typedef enum PlayerMonsterID {
	suzaku,	/**< 朱雀 = 0 */
	seiryu,	/**< 青龍 = 1 */
	byakko,	/**< 白虎 = 2 */
	genbu	/**< 玄武 = 3 */
}PlayerMonsterID;

/**
 * @struct monster
 * @brief 構造体の説明
 */
typedef struct monster {
	char* strName;		/**< 名称 */
	int iHitpoint;		/**< 現在の体力 */
	int iMaxHitpoint;	/**< 体力の最大値 */
	int iElement;		/**< 属性 */
	int iAttack;		/**< 攻撃力 */
	int iDefence;		/**< 防御力 */
}Monster;

typedef struct dungeon {
	Monster *pMonster;
	int iMonsterNum;
}Dungeon;

typedef struct party {
	Monster* pMonster;
	int iMonsterNum;
	char* strPlayerName;
	int iAllMaxHitpoint;
	int iAllHitpoint;
	int iAllDefence;
}Party;

typedef struct BattleField {
	Party party;
	Monster enemyMonster;
	Element element[14];
}BattleField;
typedef struct banishInfo {
	Element iElement;
	int iStart;
	int iNumber;
}BanishInfo;

typedef char* string;

void initialize(Monster*, Monster*, Dungeon*);
BattleField initField(Party party, Monster monster);