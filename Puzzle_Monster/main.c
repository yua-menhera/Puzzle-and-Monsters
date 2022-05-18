#include<stdio.h>
#include<Windows.h>
#include"define.h"
#include"dungeon.h"
#include"party.h"

const int MAX_GEMS = 14;
int main(int argc, char** argv)
{
	SetConsoleTitle(L"Puzzle & Monsters");
	if (argc != 2) {
		printf("�G���[:�v���C���[�����w�肵�ċN�����Ă�������");
		return 1;
	}
	printf("*** Puzzle & Monsters ***\n");

	Monster *EnemyMonsters;
	Monster *PlayerMonsters;
	Dungeon dungeon;
	Party party;
	EnemyMonsters = (Monster*)calloc(100, sizeof(Monster));
	PlayerMonsters = (Monster*)calloc(100, sizeof(Monster));

	if (EnemyMonsters == NULL || PlayerMonsters == NULL) {
		printf("�������m�ۃG���[");
		return 1;
	}

	initialize(EnemyMonsters, PlayerMonsters, &dungeon);
	party = organizeParty(argv[1], PlayerMonsters, 4);

	int defeatMonster = goDungeon(party, dungeon);

	printf("***GAME CLEARED!***\n");
	printf("�|���������X�^�[��=%d\n", defeatMonster);

	free(EnemyMonsters);
	free(PlayerMonsters);
	return 0;
}