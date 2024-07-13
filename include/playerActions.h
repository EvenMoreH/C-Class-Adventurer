#ifndef playerActions_H_
#define playerActions_H_

//put your function headers here

//  Player Actions in Combat  ////////////////////////////////////////
void combatAction(int monsterID);
void combatActionAmbush(int monsterID);
void attackRollMain(int mainWeapon, int bonusDMG);
void attackRollOff(int equippedWeaponOff, int bonusDMG);
void attackRollSpell(int bonusDMGspell);
void itemSelect();
void healingPotion();
// if player founds a potion and has less than full HP it asks if drink immediately
void instantHealingPotion();
// asks if potion should be used after combat
void regenerate();

//  Player HP & Damage Roll  /////////////////////////////////////////
int playerDamage(int itemID, int bonusDMG);
int playerSpellDamage(int SelectedSpellMinDMG, int SelectedSpellMaxDMG, int bonusDMGspell);
int damageConsumable(int itemID);
void playerHP(int playerDmgTaken);
int playerMaxHealth(int vitality, int classHPX);

#endif