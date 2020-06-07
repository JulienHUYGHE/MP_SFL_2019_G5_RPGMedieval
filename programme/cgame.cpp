
#include "cgame.h"
#include "cpersonnage.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "cmage.h"


using namespace std;


CGame::CGame()
{
    m_nbtour = 0;
}
CGame::~CGame()
{

}


void CGame::Sort(int joueur,CPersonnage * personnage1, CPersonnage * personnage2 )
{
    CMage  mage1(personnage1);
    CMage  mage2(personnage2);


        if(joueur == 1) {
            if(mage1.sort(personnage2,personnage1) == false) {
                PlayTurn(personnage1,personnage2);
            }
        }
        else {
            if(mage2.sort(personnage1,personnage2) == false) {
               PlayTurn(personnage1,personnage2);
           }
        }
}


void CGame::LauchGame(CPersonnage * personnage1, CPersonnage * personnage2)
{
    cout<<"Le combat va commencer"<<endl;
    cout << personnage1->get_Nom() << " va affronter " << personnage2->get_Nom() <<" dans ce combat \n\n\n"<<endl;
}
void CGame::PlayTurn(CPersonnage * personnage1, CPersonnage * personnage2)
{
    m_nbtour = 1;
    int J1 = 1;
    int J2 = 0;
    int Choix;

    do{
        if(J1 > J2)
        {
            do{
                cout<<"***************************************"<<endl;
                cout<<"         tour du joueur 1"<<endl;
                cout<<"***************************************\n"<<endl;
                afficherChoixActions(personnage1, personnage2);
                cin>>Choix;
            }while(Choix < 1 || Choix > 2);

            if(Choix == 1)
            {
                attaquer(personnage1, personnage2);
                J1 = J1 - 1;
                J2 = J2 + 1;
            } else
            {
                cout<<"tour "<<m_nbtour<<" termine\n\n"<<endl;
                m_nbtour++;
                J1 = J1 - 1;
                J2 = J2 + 1;
            }
        } else {
            do{
                cout<<"***************************************"<<endl;
                cout<<"         tour du joueur 2"<<endl;
                cout<<"***************************************\n"<<endl;
                afficherChoixActions(personnage2, personnage1);
                cin>>Choix;
            }while(Choix < 1 || Choix > 2);

            if(Choix == 1)
            {
                attaquer(personnage2, personnage1);
                J1 = J1 + 1;
                J2 = J2 - 1;

            } else
            {
                cout<<"tour "<<m_nbtour<<" termine \n\n"<<endl;
                m_nbtour++;
                J1 = J1 + 1;
                J2 = J2 - 1;
            }
        }
    }while(personnage1->estDead() == false || personnage2->estDead() ==false);
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
bool CGame::Esquive(CPersonnage * Attaquant, CPersonnage * receveur)
{
    int max, random_number;
    max = 100;

    srand(time(0));
    random_number = (rand () % max) +1;
    int chanceEsquive = random_number;

    if(chanceEsquive <= receveur->Get_Esquive())
    {
        return true;
    }

}

void CGame::attaquer(CPersonnage * Attaquant, CPersonnage * receveur)
{
    int ATK = Attaquant->Get_Atk();
    int PVop;

    if(Esquive(Attaquant, receveur) == true)
    {
        cout<<"votre adverssaire a esquive l'attaque"<<endl;

    } else
    {
        PVop = receveur->Get_Pdv() - ATK; //op pour opponent
        receveur->Set_Pdv(PVop);
    }

    cout<<"les points de vie de votre advetrsaire sont de : "<<receveur->Get_Pdv()<<endl;
    cout<<"tour "<<m_nbtour<<" termine\n\n"<<endl;
    m_nbtour++;
    if(Attaquant->Get_Pdv() <= 0)
    {
        cout<<"le joueur 2 ("<<receveur->get_Nom()<<")  est le vainqueur"<<endl;
    }else if(receveur->Get_Pdv() <= 0){

        cout<<"le joueur 1 ("<<Attaquant->get_Nom()<<")  est le vainqueur"<<endl;
    }
}

void CGame::afficherChoixActions(CPersonnage * Attaquant, CPersonnage * receveur)
{
    cout<<"Vos Stats  ->  Type : "<<Attaquant->get_Nom()<<" | Attaque : "<<Attaquant->Get_Atk()<<" | PdV : "<< Attaquant->Get_Pdv()<<endl;
    cout<<"Stats  Ennemi ->  Type : "<<receveur->get_Nom()<<" | Attaque : "<<receveur->Get_Atk()<<" | PdV : "<< receveur->Get_Pdv()<<endl;
    cout<<"    - tapez 1 pour attaquer"<<endl;
    cout<<"    - tapez 2 pour passer votre tour\n"<<endl;
}


void CGame::ChoisirPersonnage(CPersonnage * personnage1, CPersonnage * personnage2)
{
    int choix1;
    int choix2;
    int num_joueur = 1;

    cout<<"Bienvenu dans le jeu \n"<<endl;

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

    switch (choix1){
    case 1:
        personnage1->setNom("Mage");
        break;
    case 2:
        personnage1->setNom("Sorcier");
        break;
    case 3:
        personnage1->setNom("Archer");
        break;
    case 4:
        personnage1->setNom("Guerrier");
        break;
    }


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


    switch (choix2){
    case 1:
        personnage2->setNom("Mage");
        break;
    case 2:
        personnage2->setNom("Sorcier");
        break;
    case 3:
        personnage2->setNom("Archer");
        break;
    case 4:
        personnage2->setNom("Guerrier");
        break;
    }
}













