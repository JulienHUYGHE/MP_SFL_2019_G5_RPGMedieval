#ifndef CPERSONNAGE_H
#define CPERSONNAGE_H
#include <iostream>
#include <string>
using namespace std;

class CPersonnage
{
protected :
    string m_nom;
    int         m_pdv;
    int         m_maxpdv;
   //arme ??

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




public:
    CPersonnage();
    CPersonnage(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel);
    ~CPersonnage();


    virtual bool EstArcher() { return false; };
    virtual bool EstMage() { return false; };
    virtual bool EstSorcier() { return false; };
    virtual bool EstGuerrier() { return false; };

    bool estInvis() { return m_estInvis; };
    bool estDead()  { return m_estMort;  };

    string get_Nom() const;
    int Get_Pdv() const;
    int Get_Maxpdv()const;
    int Get_Esquive()const;
    int Get_Vitesse()const;
    int Get_Atk()const;
    int Get_Def()const;
    int Get_Agi()const;
    int Get_Intel()const;
    bool Get_Poison()const;


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
    void setNom(const string & nom);
};

#endif // CPERSONNAGE_H
