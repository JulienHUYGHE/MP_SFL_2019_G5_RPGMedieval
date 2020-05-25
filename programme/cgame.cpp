#include "cgame.h"
#include "cpersonnage.h"
#include <cstdlib>
#include <algorithm>


using namespace std;


CGame::CGame()
{
    m_nbtour = 0;
}



CGame::~CGame()
{

}

void CGame::LauchGame(CPersonnage * personnage1, CPersonnage * personnage2)
{
    cout<<"Le combat va commencer"<<endl;
    cout << personnage1->get_Nom() << " va affronter " << personnage2->get_Nom() <<" dans ce combat"<<endl;
}


void CGame::PlayTurn(CPersonnage * personnage1, CPersonnage * personnage2)
{
    m_nbtour = 1;
    int J1 = 2;
    int J2 = 0;
    int Choix;

    do{
        if(J1 > J2)
        {
            do{
                cout<<"le joueur 1 commence"<<endl;
                cout<<"tapez 1 pour attaquer"<<endl;
                cout<<"tapez 2 pour passer votre tour"<<endl;
                cin>>Choix;
            }while(Choix < 1 || Choix > 2);

            if(Choix == 1)
            {
                int ATK = personnage1->Get_Atk();
                int PVop = personnage2->Get_Pdv() - ATK; //op pour opponent
                personnage2->Set_Pdv(PVop);
                cout<<"vous affligés "<<ATK<<"de degats"<<endl;
                cout<<"les points de vie de votre advetrsaire sont de : "<<PVop<<endl;
                cout<<"tour "<<m_nbtour<<"termine"<<endl;
                m_nbtour++;
                J1 = J1 - 1;
                J2 = J2 + 3;
            } else {
                cout<<"tour "<<m_nbtour<<"termine"<<endl;
                m_nbtour++;
                J1 = J1 - 1;
                J2 = J2 + 3;
            }
        } else {
            do{
                cout<<"le joueur 2 commence"<<endl;
                cout<<"tapez 1 pour attaquer"<<endl;
                cout<<"tapez 2 pour passer votre tour"<<endl;
                cin>>Choix;
            }while(Choix < 1 || Choix > 2);

            if(Choix == 1)
            {
                int ATK = personnage2->Get_Atk();
                int PVop = personnage1->Get_Pdv() - ATK; //op pour opponent
                personnage1->Set_Pdv(PVop);
                cout<<"vous affligés "<<ATK<<"de degats"<<endl;
                cout<<"les points de vie de votre advetrsaire sont de : "<<PVop<<endl;
                cout<<"tour "<<m_nbtour<<"termine"<<endl;
                m_nbtour++;
                J1 = J1 + 1;
                J2 = J2 - 3;
            } else {
                cout<<"tour "<<m_nbtour<<"termine"<<endl;
                m_nbtour++;
                J1 = J1 + 1;
                J2 = J2 - 3;
            }
        }
    }while(personnage1->estDead() == false || personnage2->estDead() ==false);
    IsGameOver(personnage1, personnage2);


}



bool CGame::IsGameOver(CPersonnage * personnage1, CPersonnage * personnage2)
{
    if(personnage1->estDead())
    {
        cout<<"le joueur 2 ("<<personnage2->get_Nom()<<")  est le vainqueur"<<endl;
    }else{
        cout<<"le joueur 1 ("<<personnage1->get_Nom()<<")  est le vainqueur"<<endl;
    }
}

bool CGame::QuelJoueur(int nombreTour)
{
    if(nombreTour%2 == 0)
    {
        return true;//donc joueur 2
    } else{
        return false;//donc joueur 1
    }

}
