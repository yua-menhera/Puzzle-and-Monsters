#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"define.h"
#include"utility.h"

void initialize(Monster* enemymonster,Monster* playermonster, Dungeon* dungeon)
{
	enemymonster[slime].strName = "�X���C��";
	enemymonster[slime].iHitpoint = 100;
	enemymonster[slime].iMaxHitpoint = 100;
	enemymonster[slime].iElement = fire;
	enemymonster[slime].iAttack = 10;
	enemymonster[slime].iDefence = 5;

	enemymonster[goblin].strName = "�S�u����";
	enemymonster[goblin].iHitpoint = 200;
	enemymonster[goblin].iMaxHitpoint = 200;
	enemymonster[goblin].iElement = earth;
	enemymonster[goblin].iAttack = 20;
	enemymonster[goblin].iDefence = 15;

	enemymonster[bigbat].strName = "�I�I�R�E����";
	enemymonster[bigbat].iHitpoint = 300;
	enemymonster[bigbat].iMaxHitpoint = 300;
	enemymonster[bigbat].iElement = wind;
	enemymonster[bigbat].iAttack = 30;
	enemymonster[bigbat].iDefence = 25;

	enemymonster[werewolf].strName = "�E�F�A�E���t";
	enemymonster[werewolf].iHitpoint = 400;
	enemymonster[werewolf].iMaxHitpoint = 400;
	enemymonster[werewolf].iElement = wind;
	enemymonster[werewolf].iAttack = 40;
	enemymonster[werewolf].iDefence = 30;

	enemymonster[dragon].strName = "�h���S��";
	enemymonster[dragon].iHitpoint = 800;
	enemymonster[dragon].iMaxHitpoint = 800;
	enemymonster[dragon].iElement = fire;
	enemymonster[dragon].iAttack = 50;
	enemymonster[dragon].iDefence = 40;

	playermonster[suzaku].strName = "�鐝";
	playermonster[suzaku].iHitpoint = 150;
	playermonster[suzaku].iMaxHitpoint = 150;
	playermonster[suzaku].iElement = fire;
	playermonster[suzaku].iAttack = 25;
	playermonster[suzaku].iDefence = 10;

	playermonster[seiryu].strName = "��";
	playermonster[seiryu].iHitpoint = 150;
	playermonster[seiryu].iMaxHitpoint = 150;
	playermonster[seiryu].iElement = wind;
	playermonster[seiryu].iAttack = 15;
	playermonster[seiryu].iDefence = 10;

	playermonster[byakko].strName = "����";
	playermonster[byakko].iHitpoint = 150;
	playermonster[byakko].iMaxHitpoint = 150;
	playermonster[byakko].iElement = earth;
	playermonster[byakko].iAttack = 20;
	playermonster[byakko].iDefence = 5;

	playermonster[genbu].strName = "����";
	playermonster[genbu].iHitpoint = 150;
	playermonster[genbu].iMaxHitpoint = 150;
	playermonster[genbu].iElement = water;
	playermonster[genbu].iAttack = 20;
	playermonster[genbu].iDefence = 15;

	dungeon->pMonster = enemymonster;
	dungeon->iMonsterNum = 5;

}
BattleField initField(Party party, Monster monster)
{
	BattleField field;
	field.party = party;
	field.enemyMonster = monster;
	fillGems(&field);
	return field;
}