#ifndef CSORCIER_H
#define CSORCIER_H

#include "cpersonnage.h"
class CSorcier : CPersonnage
{
private:
    int m_NbInvis;

public:
    CSorcier();
    CSorcier(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel);
    ~CSorcier();

    void Set_Invis(int nbtour);
    int Get_Invis();


    bool EstArcher() { return false; };
    bool EstMage() { return false; };
    bool EstSorcier() { return true; };
    bool EstGuerrier() { return false; };
};

#endif // CSORCIER_H
