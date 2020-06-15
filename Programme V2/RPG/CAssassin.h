#ifndef CAssassin_H
#define CAssassin_H

#include "cpersonnage.h"
class CAssassin : public CPersonnage
{
private:
    int m_NbInvis;

public:
    CAssassin();
    CAssassin(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel);
    CAssassin(CPersonnage * personnage1);
    ~CAssassin();

    void Set_Invis(int nbtour);
    int Get_Invis();


    bool EstArcher() { return false; };
    bool EstMage() { return false; };
    bool EstSorcier() { return true; };
    bool EstGuerrier() { return false; };
};

#endif // CAssassin_H
