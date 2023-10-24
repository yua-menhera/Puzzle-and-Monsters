#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"define.h"
#include"skill.h"
#include"utility.h"

void initialize(Monster* enemymonster,Monster* playermonster,Skill* skill, Dungeon* dungeon)
{
	enemymonster[slime].strName = "スライム";
	enemymonster[slime].iHitpoint = 100;
	enemymonster[slime].iMaxHitpoint = 100;
	enemymonster[slime].iElement = fire;
	enemymonster[slime].iAttack = 10;
	enemymonster[slime].iDefence = 5;

	enemymonster[goblin].strName = "ゴブリン";
	enemymonster[goblin].iHitpoint = 200;
	enemymonster[goblin].iMaxHitpoint = 200;
	enemymonster[goblin].iElement = earth;
	enemymonster[goblin].iAttack = 20;
	enemymonster[goblin].iDefence = 15;

	enemymonster[bigbat].strName = "オオコウモリ";
	enemymonster[bigbat].iHitpoint = 300;
	enemymonster[bigbat].iMaxHitpoint = 300;
	enemymonster[bigbat].iElement = wind;
	enemymonster[bigbat].iAttack = 30;
	enemymonster[bigbat].iDefence = 25;

	enemymonster[werewolf].strName = "ウェアウルフ";
	enemymonster[werewolf].iHitpoint = 400;
	enemymonster[werewolf].iMaxHitpoint = 400;
	enemymonster[werewolf].iElement = wind;
	enemymonster[werewolf].iAttack = 40;
	enemymonster[werewolf].iDefence = 30;

	enemymonster[dragon].strName = "ドラゴン";
	enemymonster[dragon].iHitpoint = 800;
	enemymonster[dragon].iMaxHitpoint = 800;
	enemymonster[dragon].iElement = fire;
	enemymonster[dragon].iAttack = 50;
	enemymonster[dragon].iDefence = 40;

	playermonster[suzaku].strName = "朱雀";
	playermonster[suzaku].iHitpoint = 150;
	playermonster[suzaku].iMaxHitpoint = 150;
	playermonster[suzaku].iElement = fire;
	playermonster[suzaku].iAttack = 25;
	playermonster[suzaku].iDefence = 10;

	playermonster[seiryu].strName = "青龍";
	playermonster[seiryu].iHitpoint = 150;
	playermonster[seiryu].iMaxHitpoint = 150;
	playermonster[seiryu].iElement = wind;
	playermonster[seiryu].iAttack = 15;
	playermonster[seiryu].iDefence = 10;

	playermonster[byakko].strName = "白虎";
	playermonster[byakko].iHitpoint = 150;
	playermonster[byakko].iMaxHitpoint = 150;
	playermonster[byakko].iElement = earth;
	playermonster[byakko].iAttack = 20;
	playermonster[byakko].iDefence = 5;

	playermonster[genbu].strName = "玄武";
	playermonster[genbu].iHitpoint = 150;
	playermonster[genbu].iMaxHitpoint = 150;
	playermonster[genbu].iElement = water;
	playermonster[genbu].iAttack = 20;
	playermonster[genbu].iDefence = 15;

	dungeon->pMonster = enemymonster;
	dungeon->iMonsterNum = 5;

	skill[SKILL_ALL_FIRE].strName = "全体攻撃(火)";
	skill[SKILL_ALL_FIRE].strDetail = "宝石を全て火属性に置き換える";
	skill[SKILL_ALL_FIRE].iUsingSkillPoint = 10;
	skill[SKILL_ALL_WATER].strName = "全体攻撃(水)";
	skill[SKILL_ALL_WATER].strDetail = "宝石を全て水属性に置き換える";
	skill[SKILL_ALL_WATER].iUsingSkillPoint = 10;
	skill[SKILL_ALL_WIND].strName = "全体攻撃(風)";
	skill[SKILL_ALL_WIND].strDetail = "宝石を全て風属性に置き換える";
	skill[SKILL_ALL_WIND].iUsingSkillPoint = 10;
	skill[SKILL_ALL_EARTH].strName = "全体攻撃(地)";
	skill[SKILL_ALL_EARTH].strDetail = "宝石を全て地属性に置き換える";
	skill[SKILL_ALL_EARTH].iUsingSkillPoint = 10;
	skill[SKILL_SUPER_GEM].strName = "圧倒的コンボ生成";
	skill[SKILL_SUPER_GEM].strDetail = "宝石を3連鎖で生成する";
	skill[SKILL_SUPER_GEM].iUsingSkillPoint = 20;

	skill[SKILL_MAX].strName = "なし";
	skill[SKILL_MAX].strDetail = "";
	skill[SKILL_MAX].iUsingSkillPoint = 0;
}
BattleField initField(Party party, Monster monster)
{
	BattleField field;
	field.party = party;
	field.enemyMonster = monster;
	fillGems(&field);
	return field;
}