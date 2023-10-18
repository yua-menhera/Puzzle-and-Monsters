#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"define.h"
#include"utility.h"
#include"gems.h"

void fillGems(BattleField* field)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_GEMS; i++) {
		field->element[i] = rand() % 5;
	}
}
void printGems(BattleField* field)
{
	printf(" ");
	for (int i = 0; i < MAX_GEMS; i++) {
		printf("\x1b[4%dm%c\x1b[0m ", ELEMENT_COLORS[field->element[i]], ELEMENT_SYMBOLS[field->element[i]]);
	}
	printf("\n");
}

void moveGem(BattleField* field, char src, char dest,int mode)
{
	src -= 'A';
	dest -= 'A';

	// srcを操作してdestに近づけるイメージ？
	int* ptrElement = field->element;
	int iMove = abs(dest - src);
	for (int i = 0; i < iMove; i++) {
		if (src < dest) {
			// Right
			swapGem(field, src, 1,mode);
			src++;
		} else {
			swapGem(field, src, 0,mode);
			src--;
			// Left
		}
	}
}

void swapGem(BattleField* field, int src, int move,int mode)
{
	char cMoveTemp;
	if (move) {
		// srcをRight側に移動
		// 1 2 3 4 → 1 3 2 4
		cMoveTemp = field->element[src];
		field->element[src] = field->element[src + 1];
		field->element[src + 1] = cMoveTemp;

	} else {
		// srcをLeft側に移動
		cMoveTemp = field->element[src];
		field->element[src] = field->element[src - 1];
		field->element[src - 1] = cMoveTemp;
	}
	if (mode == 1) {
		printGems(field);
	}
}

void evaluteGems(BattleField* field,BanishInfo* banishInfo)
{
	int combo = 0;
	do{
		*banishInfo = checkBanishable(field);
		if (banishInfo->iElement != -1) {
			combo++;
			banishGems(field, *banishInfo, combo);
			printGems(field);
			shiftGems(field, *banishInfo);
			spawnGems(field);
		}
	} while (banishInfo->iElement!= -1);
}

BanishInfo checkBanishable(BattleField* field)
{
	int length = 0;
	int max_length = -1;
	int Position = 0;
	int checkPosition = 0;
	Element thisElement = field->element[0];
	Element returnElement = -1;
	BanishInfo banish;
	banish.iElement = -1;
	banish.iNumber = -1;
	banish.iStart = -1;
	for (int i = 0; i < MAX_GEMS; i++) {
		if (thisElement == field->element[i]) {
			length++;
			if (max_length < length) {
				returnElement = thisElement;
				max_length = length;
				Position = checkPosition;
			}
		} else {
			checkPosition = i;
			length = 1;
			thisElement = field->element[i];
		}
	}
	if (max_length >= 3) {
		banish.iElement = returnElement;
		banish.iStart = Position;
		banish.iNumber = max_length;
	}
	return banish;
}

void banishGems(BattleField* field, BanishInfo banish,int combo)
{
	for (int i = 0; i < banish.iNumber; i++) {
		field->element[banish.iStart + i] = empty;
	}
	if (banish.iElement == life) {
		doRecover(&field->party, banish.iNumber,combo);
	} else {
		doAttack(&field->party, &field->enemyMonster, banish.iElement,banish.iNumber,combo);
	}
}

void shiftGems(BattleField* field, BanishInfo banish)
{
	int iStartShiftPosition = banish.iStart + banish.iNumber;
	for (int i = 0; i < banish.iNumber; i++) {
		for (int j = iStartShiftPosition; j < MAX_GEMS; j++) {
			moveGem(field, 'A' + j, 'A' + j - 1,0);
		}
		iStartShiftPosition--;
		printGems(field);
	}
}

void spawnGems(BattleField* field)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_GEMS; i++) {
		if (field->element[i] == empty) {
			field->element[i] = rand() % 5;
		}
	}
}

/*
* 0101
* 1111
*/