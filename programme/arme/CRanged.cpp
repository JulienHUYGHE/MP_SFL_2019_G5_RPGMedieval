#include "CRanged.h"
#include <string>


CRanged::CRanged(std::string p_name, int p_damage, short p_crit)
{
    m_name = p_name;
    m_damage = p_damage;
    m_crit = p_crit;
}

int CRanged::Get_NbAmmo(CCharacter p_character)
{
    return -1;
}

int CRanged::Get_Damage()
{
    return m_damage;
}

bool CRanged::IsWeaponMelee()
{
    return false;
}

bool CRanged::IsWeaponRanged()
{
    return true;
}