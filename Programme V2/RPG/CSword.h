#ifndef SWORD_H
#define SWORD_H

#include "CMelee.h"

class CSword : public CMelee
{
public:
    CSword();
    CSword(std::string p_name, int p_damage, float p_crit, std::string p_type, int p_duration);

    /*****************************/

    void Attack();

    /*****************************/

    bool IsWeaponBow();
    bool IsWeaponDagger();
    bool IsWeaponStaff();
    bool IsWeaponSword();
};
#endif
