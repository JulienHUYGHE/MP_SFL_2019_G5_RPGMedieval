#ifndef DAGGER_H
#define DAGGER_H

#include "CMelee.h"


class CDagger : public CMelee
{
private:
    int m_PoisonChance;
public:
    CDagger(std::string p_name, int p_damage, float p_crit, std::string p_type, int p_duration);
    int Get_PoisonChance();
    void Set_PoisonChance(int value);
    void Attack();

    /*****************************/

    bool IsWeaponBow();
    bool IsWeaponDagger();
    bool IsWeaponStaff();
    bool IsWeaponSword();

};


#endif
