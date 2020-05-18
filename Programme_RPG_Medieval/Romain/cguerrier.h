#ifndef CGuerrier_H
#define CGuerrier_H
#include "cpersonnage.h"
#include <string>

class CGuerrier : CPersonnage
{
private:
    int m_parade;

public:
    CGuerrier();
    CGuerrier(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel);
    ~CGuerrier();



    bool EstArcher() { return false; };
    bool EstMage() { return false; };
    bool EstSorcier() { return false; };
    bool EstGuerrier() { return true; };



    void Set_Parade(int parade);
    int  Get_Parade();
};

#endif // CGuerrier_H
