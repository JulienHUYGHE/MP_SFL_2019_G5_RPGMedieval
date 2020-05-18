#include "CStaff.h"
#include <string>

CStaff::CStaff(std::string p_name, int p_damage, float p_crit, std::string p_type, int p_cost)
{
    m_name = p_name;
    m_damage = p_damage;
    m_crit = p_crit;
    m_weapontype = p_type;
    m_cost = p_cost;
}

bool CStaff::IsAbleToFire(CCharacter* p_character)
{
    if (p_character->Get_Mana() > m_cost)
        return true;
    else
        return false;
}

bool CStaff::IsAbleToFire()
{
    return true;
}

int CStaff::Get_NbAmmo(CMage p_character)
{
    return p_character.Get_Mana();
}


bool CStaff::IsWeaponBow()
{
    return false;
}

bool CStaff::IsWeaponDagger()
{
    return false;
}

bool CStaff::IsWeaponStaff()
{
    return true;
}

bool CStaff::IsWeaponSword()
{
    return false;
}
