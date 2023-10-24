/**
 * @file define.h
 * @brief �O���[�o���ϐ��E�񋓑́E�\���̂̐錾������w�b�_
 * @date 2022/05/19
 */
#pragma once

extern char ELEMENT_SYMBOLS[];
extern int ELEMENT_COLORS[];
extern double ELEMENT_BOOST[][6];
extern int PARTY_MONSTER_ELEMENT[];
extern const int MAX_GEMS;

/**
 * @enum Element
 * @brief �������`
 */
typedef enum Element {
	fire,	/**< �Α��� = 0 */
	water,	/**< ������ = 1 */
	wind,	/**< ������ = 2 */
	earth,	/**< �n���� = 3 */
	life,	/**< �� = 4 */
	empty	/**< ������ = 5 */
}Element;

/**
 * @enum EnemyMonsterID
 * @brief �G�����X�^�[��ID���w��
 */
typedef enum EnemyMonsterID {
	slime,		/**< �X���C�� = 0 */
	goblin,		/**< �S�u���� = 1 */
	bigbat,		/**< �R�E���� = 2 */
	werewolf,	/**< �E�F�A�E���t = 3 */
	dragon		/**< �h���S�� = 4 */

}EnemyMonsterID;

/**
 * @enum PlayerMonsterID
 * @brief ���������X�^�[��ID���w��
 */
typedef enum PlayerMonsterID {
	suzaku,	/**< �鐝 = 0 */
	seiryu,	/**< �� = 1 */
	byakko,	/**< ���� = 2 */
	genbu	/**< ���� = 3 */
}PlayerMonsterID;

typedef enum SkillID{
	SKILL_MIN,
	SKILL_ALL_FIRE,
	SKILL_ALL_WATER,
	SKILL_ALL_WIND,
	SKILL_ALL_EARTH,
	SKILL_SUPER_GEM,
	SKILL_MAX
}SkillID;

/**
 * @struct monster
 * @brief �\���̂̐���
 */
typedef struct monster {
	char* strName;		/**< ���� */
	int iHitpoint;		/**< ���݂̗̑� */
	int iMaxHitpoint;	/**< �̗͂̍ő�l */
	int iElement;		/**< ���� */
	int iAttack;		/**< �U���� */
	int iDefence;		/**< �h��� */
}Monster;

typedef struct dungeon {
	Monster *pMonster;
	int iMonsterNum;
}Dungeon;
typedef struct skill {
	char* strName;
	char* strDetail;
	int iUsingSkillPoint;
}Skill;
typedef struct party {
	Monster* pMonster;
	Skill* pSkill;
	int iMonsterNum;
	char* strPlayerName;
	int iAllMaxHitpoint;
	int iAllHitpoint;
	int iAllDefence;
	int iSkillPoint;
}Party;

typedef struct BattleField {
	Party party;
	Monster enemyMonster;
	Element element[14];
	Element elementQueue[14];
}BattleField;

typedef struct banishInfo {
	Element iElement;
	int iStart;
	int iNumber;
}BanishInfo;

typedef char* string;

void initialize(Monster*, Monster*, Dungeon*);
BattleField initField(Party party, Monster monster);