#ifndef CGAME_H
#define CGAME_H
#include "cpersonnage.h"

#endif // CGAME_H

class CGame
{
private:
    int m_nbtour;

public:
    CGame();
    ~CGame();

    /*****************************/

//	void InitGame(int gold_limit, std::string path);
    void PlayTurn(CPersonnage * personnage1, CPersonnage * personnage2);
    bool IsGameOver(CPersonnage * personnage1, CPersonnage * personnage2);
    void LauchGame(CPersonnage * personnage1, CPersonnage * personnage2);
    bool QuelJoueur(int nombreTour);
    void ChoisirPersonnage(CPersonnage * personnage1, CPersonnage * personnage2);
    void Sort(int joueur,CPersonnage * personnage1, CPersonnage * personnage2 );
};
