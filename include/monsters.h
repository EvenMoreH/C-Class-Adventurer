#ifndef monsters_H_
#define monsters_H_

//put your function headers here

// Monsters //////////////////////////////////////////////////////////
void monsterHP(int monsterDmgTaken, int monsterID);
int monsterMaxHP(int monsterID);
int monsterDamage1(int monsterID);
int monsterDamage2(int monsterID);
int monsterDamage3(int monsterID);
int monsterDamageOpportunity(int monsterID);    // NEW
void monsterAction(int monsterID);  // NEW

#endif