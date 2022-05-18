#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"define.h"
#include"utility.h"

void printMonsterName(Monster monster)
{
	printf("\x1b[3%dm%c%s%c\x1b[0m",ELEMENT_COLORS[monster.iElement], ELEMENT_SYMBOLS[monster.iElement], monster.strName, ELEMENT_SYMBOLS[monster.iElement]);
}
void showBattleField(BattleField* field)
{
	printf("-----------------------------\n");
	printf("\n");
	printf("   ");
	printMonsterName(field->enemyMonster);
	printf("\n");
	printf("   HP= %d / %d\n", field->enemyMonster.iHitpoint, field->enemyMonster.iMaxHitpoint);
	printf("\n");
	
	for (int i = 0; i < field->party.iMonsterNum; i++) {
		printMonsterName(field->party.pMonster[i]);
		printf(" ");
	}
	printf("\n");
	printf("   HP= %d / %d\n", field->party.iAllHitpoint, field->party.iAllMaxHitpoint);
	printf("-----------------------------\n");
	printf(" A B C D E F G H I J K L M N \n");
	printGems(field);
	printf("-----------------------------\n");

}
int checkValidCommand(char src, char dest)
{
	if ('A' <= src && src <= 'N' && 'A' <= dest && dest <= 'N') {
		return 0;
	} else {
		return 1;
	}
}

int blurDamage(int damage, int min_damage, int max_damage)
{
	srand((unsigned)time(NULL));
	int iBlurMinDamage = (min_damage - max_damage)/2;
	int iBlurMaxDamage = (max_damage - min_damage)/2;
	int randDamage = 0;
	if (iBlurMaxDamage != 0) {
		int randDamage = iBlurMinDamage + (rand() % iBlurMaxDamage + 1);
	}
	return damage + randDamage;
}

int calcEnemyAttackDamage(int enemyAttack, int partyDefence)
{
	int recvDamage = enemyAttack - partyDefence;
	return blurDamage(recvDamage, recvDamage*0.9, recvDamage*1.1);
}

int calcAttackDamage(int playerAttack, int enemyDefence, double boost, int gems, int combo)
{
	int attackDamage = (playerAttack - enemyDefence) * boost * pow(gems - 3 + combo, 1.5);
	return blurDamage(attackDamage, attackDamage * 0.9, attackDamage * 1.1);
}
