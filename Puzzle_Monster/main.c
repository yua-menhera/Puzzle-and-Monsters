#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"define.h"
#include"dungeon.h"
#include"party.h"

const int MAX_GEMS = 14;
int main(int argc, char** argv)
{
	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD consoleMode = 0;
	GetConsoleMode(stdOut, &consoleMode);
	consoleMode |= 0x0004;
	SetConsoleMode(stdOut, consoleMode);

	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);

	SetConsoleTitle("Puzzle & Monsters");
	if (argc != 2) {
		printf("エラー:プレイヤー名を指定して起動してください");
		return 1;
	}
	printf("*** Puzzle & Monsters ***\n");
	printf("\n---操作方法---\n");
	printf("A~N A~N:1番目に選択した宝石を2番目の場所に移動する\n");
	printf("SKILL:スキルを発動する\n\n");
	Monster *EnemyMonsters;
	Monster *PlayerMonsters;
	Skill *skills;
	Dungeon dungeon;
	Party party;
	EnemyMonsters = (Monster*)calloc(100, sizeof(Monster));
	PlayerMonsters = (Monster*)calloc(100, sizeof(Monster));
	skills = (Skill*)calloc(100, sizeof(Skill));

	if (EnemyMonsters == NULL || PlayerMonsters == NULL) {
		printf("メモリ確保エラー");
		return 1;
	}

	initialize(EnemyMonsters, PlayerMonsters, skills, &dungeon);
	party = organizeParty(argv[1], PlayerMonsters, 4);

	int defeatMonster = goDungeon(party, dungeon);

	printf("***GAME CLEARED!***\n");
	printf("倒したモンスター数=%d\n", defeatMonster);

	free(EnemyMonsters);
	free(PlayerMonsters);
	return 0;
}
