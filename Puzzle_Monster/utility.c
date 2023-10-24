/**
 * @file utility.c
 * @brief ユーティリティ関数ソースコード
 * @author yuuka-overdose
 * @date 2022/05/19
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
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
	printf("   SP= %d\n", field->party.iSkillPoint);
	printf("-----------------------------\n");
	printf(" A B C D E F G H I J K L M N \n");
	printGems(field);
	printf("-----------------------------\n");

}
int checkValidCommand(char* src, int* command)
{
	if (('A' <= src[0] && src[0] <= 'N') && ('A' <= src[1] && src[1] <= 'N') && (src[2] == '\0')) {
		*command = 1;
		return 0;
	} else if(strcmp(src,"SKILL") == 0){
		*command = 2;
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

int calcEnemyAttackDamage(int enemyAttack, int partyDefence, int isCritical)
{
	int recvDamage = (enemyAttack / 2) - (partyDefence / 4);
	recvDamage = blurDamage(recvDamage, recvDamage*0.9, recvDamage*1.1);
	if(recvDamage < 0) {
		recvDamage = 1;
    }
	if (isCritical) {
        recvDamage = recvDamage * 2;
    }
	return recvDamage;
}

int calcAttackDamage(int playerAttack, int enemyDefence, double boost, int gems, int combo, int isCritical)
{
	int attackDamage = (playerAttack - enemyDefence) * boost * pow(gems - 3 + combo, 1.5);
	int adjustPlayerAttack = playerAttack * pow(gems - 3 + combo, 1.5) / 2;
	int adjustEnemyDefence = enemyDefence / 4;
	attackDamage = adjustPlayerAttack - adjustEnemyDefence;
	if(attackDamage < 0) {
		attackDamage = 1;
	}
	attackDamage = attackDamage * boost;
	if(isCritical){
		attackDamage = attackDamage * 2;
	}
	return blurDamage(attackDamage, attackDamage * 0.9, attackDamage * 1.1);
}

void printSkill(Party party) {
	printf("*** スキル一覧 ***\n");
	for(int i = 1;i < SKILL_MAX; i++){
		printf("%d:%s\n",i,party.pSkill[i].strName);
		printf("消費SP:%d\n",party.pSkill[i].iUsingSkillPoint);
		printf("効果:%s\n",party.pSkill[i].strDetail);
		printf("\n");
	}
}
