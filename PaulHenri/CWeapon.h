#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class CWeapon
{
protected:
    std::string m_name;
    int         m_damage;
    float       m_crit;
    int         m_enchant;
    std::string m_weapontype;
public:
    CWeapon();
    CWeapon(std::string p_name, int p_damage, short p_crit);
    ~CWeapon();

    /*****************************/

    std::string Get_Type();
    std::string Get_Name();
    virtual int Get_Damage();
    float Get_Crit();
    int  Get_Enchant();
    virtual int Get_Duration() { return 0xFF; };
    virtual int Get_NbAmmo() { return 0; };

    /*****************************/

    void Set_Type(std::string value);
    void Set_Name(std::string value);
    void Set_Damage(int value);
    void Set_Crit(float value);
    void Set_Enchant(int value);
    virtual void Set_Duration(int value) { return; };

    /*****************************/

    virtual bool IsWeaponBow();
    virtual bool IsWeaponDagger();
    virtual bool IsWeaponStaff();
    virtual bool IsWeaponSword();
    virtual bool IsWeaponMelee();
    virtual bool IsWeaponRanged();


    /*****************************/

    virtual bool IsAbleToFire();
    virtual void Attack();
};


#endif
