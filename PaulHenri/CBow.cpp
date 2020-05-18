#include "CBow.h"

/*****************************/

CBow::CBow(std::string p_name, int p_damage, float p_crit, std::string p_type, int p_arrow)
{
    m_name = p_name;
    m_damage = p_damage;
    m_crit = p_crit;
    m_weapontype = p_type;
    m_nbarrow = p_arrow;
}


int CBow::Get_NbAmmo()
{
    return m_nbarrow;
}

bool CBow::IsAbleToFire()
{
    if (m_nbarrow > 0)
        return true;
    else
        return false;
}

/*****************************/

bool CBow::IsWeaponBow()
{
    return true;
}

bool CBow::IsWeaponDagger()
{
    return false;
}

bool CBow::IsWeaponStaff()
{
    return false;
}

bool CBow::IsWeaponSword()
{
    return false;
}

