#include "CDagger.h"

CDagger::CDagger(std::string p_name, int p_damage, float p_crit, std::string p_type, int p_duration)
{
    m_name = p_name;
    m_damage = p_damage;
    m_crit = p_crit;
    m_weapontype = p_type;
    m_duration = p_duration;
}

int CDagger::Get_PoisonChance()
{
    return m_PoisonChance;
}

void CDagger::Set_PoisonChance(int value)
{
    m_PoisonChance = value;
}

void CDagger::Attack()
{
    m_duration -= 1;
}


bool CDagger::IsWeaponBow()
{
    return false;
}

bool CDagger::IsWeaponDagger()
{
    return true;
}

bool CDagger::IsWeaponStaff()
{
    return false;
}

bool CDagger::IsWeaponSword()
{
    return false;
}

