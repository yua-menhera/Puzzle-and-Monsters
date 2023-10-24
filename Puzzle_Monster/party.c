#include <stdio.h>
#include"define.h"
#include"party.h"
#include"utility.h"

Party organizeParty(char* strName, Monster* pPlayerMonster , int iMonsterNumbers,Skill* pSkill)
{
	Party party;
	party.iAllMaxHitpoint = 0;
	party.iAllHitpoint = 0;
	party.iAllDefence = 0;
	party.iSkillPoint = 0;
	party.strPlayerName = strName;
	party.iMonsterNum = iMonsterNumbers;
	party.pMonster = pPlayerMonster;
	for (int i = 0; i < iMonsterNumbers; i++) {
		party.iAllMaxHitpoint += pPlayerMonster[i].iMaxHitpoint;
		party.iAllHitpoint += pPlayerMonster[i].iHitpoint;
		party.iAllDefence += pPlayerMonster[i].iDefence;
	}
	party.pSkill = pSkill;
	return party;
}
void showParty(Party party)
{
	printf("<ƒp[ƒeƒB•Ò¬>----------\n");
	for (int i = 0; i < party.iMonsterNum; i++) {
		printMonsterName(party.pMonster[i]);
		printf(" HP= %d UŒ‚= %d –hŒä= %d\n", party.pMonster[i].iHitpoint, party.pMonster[i].iAttack, party.pMonster[i].iDefence);
	}
	printf("------------------------\n");
}

