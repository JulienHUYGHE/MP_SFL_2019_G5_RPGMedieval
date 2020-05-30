#include <QCoreApplication>
#include "cgame.h"
#include "cpersonnage.h"
#include "CArcher.h";
#include "CMage.h";
#include "CSorcier.h";
#include "CGuerrier.h";

int main(int argc, char *argv[])
{
    CGame game;
    CPersonnage p1;
    CPersonnage p2;

    CMage Player1;
    CMage Player2;


    cout<<"****************************"<<endl;

//    game.ChoisirPersonnage(&p1, &p2);
//    cout<<"joueur 1 a choisi ===="<<p1.get_Nom()<<endl;
//    cout<<"joueur 2 a choisi ===="<<p2.get_Nom()<<endl;

    game.LauchGame(&Player1, &Player2);
    game.PlayTurn(&Player1, &Player2);
}



