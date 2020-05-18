#ifndef RANGED_H
#define RANGED_H

#include "CCharacters.h"
#include "CWeapon.h"

class CCharacter;


class CRanged : public CWeapon
{
public:
    CRanged() {};
    CRanged(std::string p_name, int p_damage, short p_crit);
    virtual int Get_NbAmmo(CCharacter p_character);
    virtual int Get_Damage();
    virtual bool IsAbleToFire()=0;

    /*****************************/

    virtual bool IsWeaponBow();
    virtual bool IsWeaponDagger();
    virtual bool IsWeaponStaff();
    virtual bool IsWeaponSword();
    bool IsWeaponMelee();
    bool IsWeaponRanged();

    /*****************************/

};

#endif
