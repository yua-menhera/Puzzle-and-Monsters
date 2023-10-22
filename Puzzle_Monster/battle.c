#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include"define.h"
#include"battle.h"
#include"utility.h"
#include"gems.h"

int doBattle(Monster monster, Party* party, int* returnNowHitpoint)
{
	printMonsterName(monster);
	printf("が現れた！\n");
	BattleField field = initField(*party, monster);

	while (true) {
		onPlayerTurn(&field,returnNowHitpoint);
		if (field.enemyMonster.iHitpoint <= 0) {
			return 0;
		}
		onEnemyTurn(&field);
		if (field.party.iAllHitpoint <= 0) {
			return 1;
		}
	}
}

void onPlayerTurn(BattleField* field,int* nowHitPoint)
{
	char* strInputKeyboard = (char*)malloc(sizeof(char)*1024);
	BanishInfo turnBanishInfo;
	printf("【%sのターン】\n", field->party.strPlayerName);
	showBattleField(field);
	int keys = 0;
	printf("コマンド?>");
	do {
		keys = scanf_s("%s", strInputKeyboard, 1024);
		if (checkValidCommand(strInputKeyboard[0], strInputKeyboard[1])) {
			keys = 0;
		}
	} while (!keys);
	moveGem(field, strInputKeyboard[0], strInputKeyboard[1],1);

	evaluteGems(field, &turnBanishInfo);
	*nowHitPoint = field->party.iAllHitpoint;
	free(strInputKeyboard);
}
void doAttack(Party* party, Monster* enemyMonster,Element selectElement, int deletedGems, int combo)
{
	// int iAttackDamage = (party->pMonster[PARTY_MONSTER_ELEMENT[selectElement]].iAttack - enemyMonster->iDefence)*ELEMENT_BOOST[selectElement][enemyMonster->iElement]*pow((double)(deletedGems-3+combo),1.5);
	int iAttackDamage = ((party->pMonster[PARTY_MONSTER_ELEMENT[selectElement]].iAttack *
					pow((double)(deletedGems - 3 + combo),1.5)/2) - (enemyMonster->iDefence / 4));
	iAttackDamage = iAttackDamage * ELEMENT_BOOST[selectElement][enemyMonster->iElement];
	iAttackDamage = blurDamage(iAttackDamage, iAttackDamage * 0.9, iAttackDamage * 1.1);
	if (iAttackDamage <= 0) {
		iAttackDamage = 1;
	}
	enemyMonster->iHitpoint -= iAttackDamage;
	if(combo>1){
		printf("\x1b[0m%dコンボ！\n",combo);
	}
	printMonsterName(party->pMonster[PARTY_MONSTER_ELEMENT[selectElement]]);
	printf("で%dのダメージを与えた\n\n",iAttackDamage);
}
void doRecover(Party* party, int deletedGems, int combo)
{
	int iRecoveryLife = 20 * pow((double)(deletedGems - 3 + combo), 1.5);
	iRecoveryLife = blurDamage(iRecoveryLife, iRecoveryLife * 0.9, iRecoveryLife * 1.1);
	if(combo>1){
		printf("\x1b[0m%dコンボ！\n",combo);
	}
	party->iAllHitpoint += iRecoveryLife;
	if (party->iAllHitpoint > party->iAllMaxHitpoint) {
		party->iAllHitpoint = party->iAllMaxHitpoint;
		printf("パーティーは体力を最大まで回復した\n\n");
	} else {
		printf("パーティーは体力を%d回復した\n\n", iRecoveryLife);
	}
}
void onEnemyTurn(BattleField* field)
{
	printf("【%s】のターン\n",field->enemyMonster.strName);
	doEnemyAttack(&field->party, &field->enemyMonster);
}
void doEnemyAttack(Party* party, Monster* monster)
{
	int receiveDamage;
	srand((unsigned)time(NULL));
	if(rand() % 24 == 0){
		printf("急所に当たった！\n");
		receiveDamage = calcEnemyAttackDamage(monster->iAttack, party->iAllDefence,1);
	}else{
		receiveDamage = calcEnemyAttackDamage(monster->iAttack, party->iAllDefence,0);
	}
	party->iAllHitpoint -= receiveDamage;
	printf("%dのダメージを受けた\n\n",receiveDamage);

}
