#include "CSword.h"

CSword::CSword()
{

}

CSword::CSword(std::string p_name, int p_damage, float p_crit, std::string p_type, int p_duration)
{
    m_name = p_name;
    m_damage = p_damage;
    m_crit = p_crit;
    m_weapontype = p_type;
    m_duration = p_duration;
}

/*****************************/

void CSword::Attack()
{
    m_duration -= rand() % 3 + 2;
}

/*****************************/

bool CSword::IsWeaponBow()
{
    return false;
}

bool CSword::IsWeaponDagger()
{
    return false;
}

bool CSword::IsWeaponStaff()
{
    return false;
}

bool CSword::IsWeaponSword()
{
    return true;
}