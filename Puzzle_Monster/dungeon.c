#include<stdio.h>
#include"define.h"
#include"battle.h"
#include"dungeon.h"
#include"party.h"
#include"utility.h"

int goDungeon(Party party,Dungeon dungeon)
{
	printf("%sはのパーティ(HP=%d)ダンジョンに到達した\n", party.strPlayerName, party.iAllHitpoint);
	showParty(party);
	int countDeletedEnemy = 0;
	int nowHitPoint = party.iAllHitpoint;
	for (int i = 0; i < dungeon.iMonsterNum; i++) {
		party.iAllHitpoint = nowHitPoint;
		int result = doBattle(dungeon.pMonster[i],&party, &nowHitPoint);
		if (result == 0) {
			printMonsterName(dungeon.pMonster[i]);
			printf("を倒した!\n");
			countDeletedEnemy++;
			party.iAllHitpoint = nowHitPoint;
			if (dungeon.iMonsterNum == countDeletedEnemy) {
				break;
			} else {
				printf("%sはさらに奥へと進んだ\n\n", party.strPlayerName);
			}
		} else if (result == 1) {
			printf("%sは倒れた\n", party.strPlayerName);
		}
	}

	printf("%sはダンジョンを制覇した！\n", party.strPlayerName);
	return countDeletedEnemy;
}