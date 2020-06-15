#ifndef RANGED_H
#define RANGED_H

#include "cpersonnage.h"
#include "CWeapon.h"

class CCharacter;


class CRanged : public CWeapon
{
public:
    CRanged() {};
    CRanged(std::string p_name, int p_damage, short p_crit);
    virtual int Get_NbAmmo(CPersonnage p_character);
    virtual int Get_Damage();
    virtual bool IsAbleToFire()=0;

    /*****************************/

    virtual bool IsWeaponBow() {return false;};
    virtual bool IsWeaponDagger(){return false;};
    virtual bool IsWeaponStaff(){return false;};
    virtual bool IsWeaponSword(){return false;};
    bool IsWeaponMelee();
    bool IsWeaponRanged();

    /*****************************/

};

#endif
