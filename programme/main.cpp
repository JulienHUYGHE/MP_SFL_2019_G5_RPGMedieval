#include <QCoreApplication>
#include "cgame.h"
#include "cpersonnage.h"
#include "CArcher.h"
#include "CMage.h"
#include "CSorcier.h"
#include "CGuerrier.h"

int main(int argc, char *argv[])
{
    CGame game;
//    CPersonnage p1;
//    CPersonnage p2;

    CMage Player1;
    CMage Player2;

//    p1.EstMage();
//    p1.EstArcher();

    cout<<"Bienvenu dans le jeu \n"<<endl;

    int choix1;
    int choix2;
    int num_joueur = 1;

    /*************************************/
    /**************Joueur1****************/
    /*************************************/

    cout<<"choisissez votre combattant (joueur "<<num_joueur<<"): \n"<<endl;
    cout<<"1. Mage"<<endl;
    cout<<"2. Sorcier"<<endl;
    cout<<"3. Archer"<<endl;
    cout<<"4. Guerrier"<<endl;

    do{
        cout<<"tapez 1 , 2 , 3 , 4 pour faire votre choix"<<endl;
        cin>>choix1;
    }while(choix1 < 1 || choix1 > 4);

    if(choix1 == 1)
    {
        CMage Player1;
    } else if(choix1 == 2)
    {
        CSorcier Player1;
    } else if(choix1 == 3)
    {
        CArcher Player1;
    } else if(choix1 == 4)
    {
        CGuerrier Player1;
    }
    cout<<"le joueur 1 a choisi : "<<Player1.get_Nom()<<endl;

    /*************************************/
    /**************Joueur2****************/
    /*************************************/


    cout<<"choisissez votre combattant (joueur "<<num_joueur+1<<"): \n"<<endl;
    cout<<"1. Mage"<<endl;
    cout<<"2. Sorcier"<<endl;
    cout<<"3. Archer"<<endl;
    cout<<"4. Guerrier"<<endl;

    do{
        cout<<"tapez 1 , 2 , 3 , 4 pour faire votre choix"<<endl;
        cin>>choix2;
    }while(choix1 < 1 || choix1 > 4);


    if(choix1 == 1)
    {
        CMage Player2;
        cout<<"je choisi "<<Player2.get_Nom()<<endl;
    } else if(choix1 == 2)
    {
        CSorcier Player2;
        cout<<"je choisi "<<Player2.get_Nom()<<endl;
    } else if(choix1 == 3)
    {
        CArcher Player2;
        cout<<"je choisi "<<Player2.get_Nom()<<endl;
    } else if(choix1 == 4)
    {
        CGuerrier Player2;
        cout<<"je choisi "<<Player2.get_Nom()<<endl;
    }


    cout<<"le joueur 2 a choisi : "<<Player2.get_Nom()<<endl;


    cout<<"****************************"<<endl;

//    game.ChoisirPersonnage(&p1, &p2);
//    cout<<"joueur 1 a choisi ===="<<p1.get_Nom()<<endl;
//    cout<<"joueur 2 a choisi ===="<<p2.get_Nom()<<endl;



    game.LauchGame(&Player1, &Player2);
    game.PlayTurn(&Player1, &Player2);
}



