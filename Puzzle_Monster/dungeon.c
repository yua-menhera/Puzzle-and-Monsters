#include<stdio.h>
#include"define.h"
#include"battle.h"
#include"dungeon.h"
#include"party.h"
#include"utility.h"

int goDungeon(Party party,Dungeon dungeon)
{
	printf("%s�͂̃p�[�e�B(HP=%d)�_���W�����ɓ��B����\n", party.strPlayerName, party.iAllHitpoint);
	showParty(party);
	int countDeletedEnemy = 0;
	int nowHitPoint = party.iAllHitpoint;
	for (int i = 0; i < dungeon.iMonsterNum; i++) {
		party.iAllHitpoint = nowHitPoint;
		int result = doBattle(dungeon.pMonster[i],&party, &nowHitPoint);
		if (result == 0) {
			printMonsterName(dungeon.pMonster[i]);
			printf("��|����!\n");
			countDeletedEnemy++;
			party.iAllHitpoint = nowHitPoint;
			if (dungeon.iMonsterNum == countDeletedEnemy) {
				break;
			} else {
				printf("%s�͂���ɉ��ւƐi��\n\n", party.strPlayerName);
			}
		} else if (result == 1) {
			printf("%s�͓|�ꂽ\n", party.strPlayerName);
		}
	}

	printf("%s�̓_���W�����𐧔e�����I\n", party.strPlayerName);
	return countDeletedEnemy;
}