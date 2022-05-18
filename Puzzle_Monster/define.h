#pragma once

extern char ELEMENT_SYMBOLS[];
extern int ELEMENT_COLORS[];
extern double ELEMENT_BOOST[][6];
extern int PARTY_MONSTER_ELEMENT[];
extern const int MAX_GEMS;
typedef enum Element {
	fire,
	water,
	wind,
	earth,
	life,
	empty
}Element;

typedef enum EnemyMonsterID {
	slime,
	goblin,
	bigbat,
	werewolf,
	dragon

}EnemyMonsterID;

typedef enum PlayerMonsterID {
	suzaku,
	seiryu,
	byakko,
	genbu
}PlayerMonsterID;

typedef struct monster {
	char* strName;
	int iHitpoint;
	int iMaxHitpoint;
	int iElement;
	int iAttack;
	int iDefence;
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