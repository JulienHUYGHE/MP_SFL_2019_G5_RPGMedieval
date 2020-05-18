#ifndef MELEE_H
#define MELEE_H
#include "CWeapon.h"
#include <string>


class CMelee : public CWeapon
{
protected:
    int m_duration;
public:

    CMelee() { m_duration = 0; };
    CMelee(std::string p_name, int p_damage, float p_crit, int p_duration);

    /*****************************/

    bool IsBroken();
    bool IsAbleToFire() { return true; };
    virtual void Attack();


    /*****************************/

    int Get_Damage();
    int Get_Duration();

    /*****************************/

    virtual bool IsWeaponBow();
    virtual bool IsWeaponDagger();
    virtual bool IsWeaponStaff();
    virtual bool IsWeaponSword();
    bool IsWeaponMelee();
    bool IsWeaponRanged();

    /*****************************/

    void Set_Duration(int value);
};


#endif
