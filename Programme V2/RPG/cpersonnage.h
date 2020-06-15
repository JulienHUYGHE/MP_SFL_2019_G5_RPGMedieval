#ifndef CPERSONNAGE_H
#define CPERSONNAGE_H
#include <iostream>
#include <string>
#include "CWeapon.h"
using namespace std;

class CPersonnage
{
protected :
    string m_nom;
    int         m_pdv;
    int         m_maxpdv;

    int         m_esquive;
    int         m_vitesse;
    int         m_atk;
    int         m_def;
    int         m_agi;
    int         m_intel;       //à enlever ?
    bool        m_estPoison;   //Si il est empoisonné
    bool        m_estInvis;    //Si il est invisible
    bool        m_estMort;     //Si il est mort
    int         m_CDSort[5];   //Cooldown des sorts (temps de relance entre chaque utilisation)
    CWeapon*    m_weapon;      //Arme du joueur




public:
    CPersonnage();
    CPersonnage(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel);
    CPersonnage(CPersonnage* copy);
    ~CPersonnage();


    virtual bool EstArcher() { return false; };
    virtual bool EstMage() { return false; };
    virtual bool EstAssassin() { return false; };
    virtual bool EstGuerrier() { return false; };

    bool estInvis() { return m_estInvis; };
    bool estDead()  { return m_estMort;  };

    string get_Nom();
    int Get_Pdv();
    int Get_Maxpdv();
    int Get_Esquive();
    int Get_Vitesse();
    int Get_Atk();
    int Get_Def();
    int Get_Agi();
    int Get_Intel();
    bool Get_Poison();
    CWeapon* Get_Weapon(){return m_weapon;};
    virtual int Get_Mana() {return 0;};


    void Set_Pdv(int valeur);
    void Set_Maxpdv(int valeur);
    void Set_Esquive(int valeur);
    void Set_Vitesse(int valeur);
    void Set_Atk(int valeur);
    void Set_Def(int valeur);
    void Set_Agi(int valeur);
    void Set_Intel(int valeur);
    void Set_Poison(bool valeur);
    void Set_Mort();
    void setNom(std::string nom);
    void Set_Weapon(CWeapon* valeur){m_weapon=valeur;};

    virtual bool sort(CPersonnage cible){std::cout << "Vous n'etes pas un mage...\n"; return false;};

};

#endif // CPERSONNAGE_H
