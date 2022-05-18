#include"define.h"

char ELEMENT_SYMBOLS[] = { '$','~','@','#','&',' ' };
int ELEMENT_COLORS[] = { 1,6,2,3,5,0 };
double ELEMENT_BOOST[][6] = { { 1.0, 0.5, 2.0, 1.0, 1.0, 1.0},	//FIRE
							  { 2.0, 1.0, 1.0, 0.5, 1.0, 1.0},	//WATER
							  { 0.5, 1.0, 1.0, 2.0, 1.0, 1.0},	//WIND
							  { 1.0, 2.0, 0.5, 1.0, 1.0, 1.0},	//EARTH
							  { 1.0, 1.0, 2.0, 1.0, 1.0, 1.0},	//LIFE
							  { 1.0, 1.0, 2.0, 1.0, 1.0, 1.0} };//EMPTY
int PARTY_MONSTER_ELEMENT[] = { suzaku,genbu,seiryu,byakko }; // 指定された属性から呼び出すモンスター