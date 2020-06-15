#ifndef CGAME_H
#define CGAME_H
#include "cpersonnage.h"
#include "CParse.h"

#endif // CGAME_H

class CGame
{
private:
    int m_nbtour;
    CPersonnage personnage1;
    CPersonnage personnage2;
public:
    CGame();
    ~CGame();

    /*****************************/

//	void InitGame(int gold_limit, std::string path);
    void PlayTurn();
    bool IsGameOver(CPersonnage personnage1, CPersonnage personnage2);
    void LauchGame();
    void ChoisirPersonnage();
    //void Sort(int joueur,CPersonnage * personnage1, CPersonnage * personnage2 );
    void attaquer(CPersonnage * Attaquant,CPersonnage * receveur);
    void afficherChoixActions(CPersonnage * Attaquant, CPersonnage * receveur);
    bool Esquive(CPersonnage * Attaquant, CPersonnage * receveur);
    void PrintWeapon(CWeapon* weap);
};
