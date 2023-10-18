#pragma once
void fillGems(BattleField* field);
void printGems(BattleField* field);
void moveGem(BattleField* field, char src, char dest,int mode);
void swapGem(BattleField* field, int src, int move, int mode);
void evaluteGems(BattleField* field, BanishInfo* banishInfo);
BanishInfo checkBanishable(BattleField* field);
void banishGems(BattleField* field, BanishInfo banish,int combo);
void shiftGems(BattleField* field,BanishInfo banish);
void spawnGems(BattleField* field);
