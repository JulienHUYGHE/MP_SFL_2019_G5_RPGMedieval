#ifndef CMAGE_H
#define CMAGE_H
#include "cpersonnage.h"
#include <string>

class CMage: public CPersonnage
{
private:
    int m_mana;



public:
    CMage();
    CMage(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel);
    ~CMage();

    void RegenMana(int valeur);


    bool EstArcher() { return false; };
    bool EstMage() { return true; };
    bool EstSorcier() { return false; };
    bool EstGuerrier() { return false; };


    int Get_Mana();
    void Set_Mana(int valeur);
};

#endif // CMAGE_H