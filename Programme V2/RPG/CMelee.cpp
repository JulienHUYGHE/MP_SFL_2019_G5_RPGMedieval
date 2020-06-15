#include "CMelee.h"
#include <string>


CMelee::CMelee(std::string p_name, int p_damage, float p_crit, int p_duration)
{
    m_name = p_name;
    m_damage = p_damage;
    m_crit = p_crit;
    m_duration = p_duration;
}

bool CMelee::IsBroken()
{
    if (m_duration <= 0)
        return true;
    else
        return false;
}

void CMelee::Attack()
{
    return;
}

int CMelee::Get_Duration()
{
    return m_duration;
}

int CMelee::Get_Damage()
{
    if (m_duration > 0)
        return m_damage;
    else
        return m_damage / 10;
}

void CMelee::Set_Duration(int value)
{
    m_duration = value;
    return;
}

bool CMelee::IsWeaponMelee()
{
    return true;
}

bool CMelee::IsWeaponRanged()
{
    return false;
}


bool CMelee::IsWeaponBow()
{
    return false;
}

bool CMelee::IsWeaponDagger()
{
    return false;
}

bool CMelee::IsWeaponStaff()
{
    return false;
}

bool CMelee::IsWeaponSword()
{
    return false;
}
