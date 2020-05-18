#ifndef BOW_H
#define BOW_H
#include "CRanged.h"

class CCharacter;

class CBow : public CRanged
{
private:
    int m_nbarrow;
public:
    CBow(std::string p_name, int p_damage, float p_crit, std::string p_type, int p_arrow);
    CBow(CBow* src);
    bool IsAbleToFire();
    int Get_NbAmmo();

    bool IsWeaponBow();
    bool IsWeaponDagger();
    bool IsWeaponStaff();
    bool IsWeaponSword();

};
#endif
