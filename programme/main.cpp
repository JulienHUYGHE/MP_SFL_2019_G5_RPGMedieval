#include <QCoreApplication>
#include "cgame.h"
#include "cpersonnage.h"
#include "CArcher.h"
#include "cmage.h"
#include "csorcier.h"
#include "cguerrier.h"

int main(int argc, char *argv[])
{
    CGame game;


    CPersonnage p1;
    CPersonnage p2;

    game.ChoisirPersonnage(&p1, &p2);

    if(p1.get_Nom() == "Mage")
    {
        CMage Player1;
        p1 = Player1;
    }
    if(p1.get_Nom() == "Archer")
    {
        CArcher Player1;
        p1 = Player1;
    }
    if(p1.get_Nom() == "Sorcier")
    {
        CSorcier Player1;
        p1 = Player1;
    }
    if(p1.get_Nom() == "Guerrier")
    {
        CGuerrier Player1;
        p1 = Player1;
    }

    //**********************************//
    //**********************************//

    if(p2.get_Nom() == "Mage")
    {
        CMage Player2;
        p2 = Player2;
    }
    if(p2.get_Nom() == "Archer")
    {
        CArcher Player2;
        p2 = Player2;
    }
    if(p2.get_Nom() == "Sorcier")
    {
        CSorcier Player2;
        p2 = Player2;
    }
    if(p2.get_Nom() == "Guerrier")
    {
        CGuerrier Player2;
        p2 = Player2;
    }


    game.LauchGame(&p1, &p2);
    game.PlayTurn(&p1, &p2);
}



