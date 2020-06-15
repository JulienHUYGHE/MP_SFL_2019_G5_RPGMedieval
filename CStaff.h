#ifndef STAFF_H
#define STAFF_H
#include "CRanged.h"
#include "CMage.h"

class CCharacter;


class CStaff : public CRanged
{
private:
    int m_cost;
public:

    CStaff(std::string p_name, int p_damage, float p_crit, std::string p_type, int p_cost);

    /*****************************/

    bool IsAbleToFire(CPersonnage* p_character);
    bool IsAbleToFire();
    int Get_NbAmmo(CMage p_character);
    
    /*****************************/

    bool IsWeaponBow();
    bool IsWeaponDagger();
    bool IsWeaponStaff();
    bool IsWeaponSword();

};

#endif
#pragma once
