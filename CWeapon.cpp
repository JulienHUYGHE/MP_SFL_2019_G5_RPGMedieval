#include "CWeapon.h"
#include <string>


CWeapon::CWeapon()
{
    m_name = "Unnamed";
    m_damage = -1;
    m_crit = 0;
    m_enchant = 0;
}


CWeapon::CWeapon(std::string p_name, int p_damage, short p_crit)
{
    m_name = p_name;
    m_damage = p_damage;
    if (p_crit <= 100)
        m_crit = p_crit;
    else
        p_crit = 100;
}

CWeapon::CWeapon(CWeapon * copy)
{
  m_name = copy->Get_Name();
  m_damage = copy->Get_Damage();
  m_crit = copy->Get_Crit();
  m_enchant = copy->Get_Enchant();
  m_weapontype= copy->Get_Type();
}

CWeapon::~CWeapon()
{

}

/*****************************/

std::string CWeapon::Get_Type()
{
    return m_weapontype;
}

std::string CWeapon::Get_Name()
{
    return m_name;
}

int CWeapon::Get_Damage()
{
    return m_damage;
}

float CWeapon::Get_Crit()
{
    return m_crit;
}

int CWeapon::Get_Enchant()
{
    return m_enchant;
}

/*****************************/

void CWeapon::Set_Type(std::string value)
{
    m_weapontype = value;
    return;
}

void CWeapon::Set_Name(std::string value)
{
    m_name = value;
    return;
}

void CWeapon::Set_Damage(int value)
{
    m_damage = value;
    return;
}

void CWeapon::Set_Crit(float value)
{
    m_crit = value;
}

void CWeapon::Set_Enchant(int value)
{
    m_enchant = value;
}
/*****************************/

bool CWeapon::IsAbleToFire()
{
    return true;
}


bool CWeapon::IsWeaponBow()
{
    return false;
}

bool CWeapon::IsWeaponDagger()
{
    return false;
}

bool CWeapon::IsWeaponStaff()
{
    return false;
}

bool CWeapon::IsWeaponSword()
{
    return false;
}

bool CWeapon::IsWeaponMelee()
{
    return false;
}

bool CWeapon::IsWeaponRanged()
{
    return false;
}

void CWeapon::Attack()
{
    return;
}
