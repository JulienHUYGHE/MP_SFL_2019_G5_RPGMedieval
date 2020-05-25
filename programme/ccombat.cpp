#include "ccombat.h"

CCombat::CCombat()
{

}

CCombat::CCombat(CMage * personnage1 , CMage * personnage2)
{

    m_personnage1 = personnage1;
    m_personnage2 = personnage2;

    cout << "Début d'un combat entre "<< personnage1->Get_Nom() << " et "<< personnage2->Get_Nom()<< " !"<<  endl;

    int m_joueur = 1;
}



void CCombat::Attaque(int joueur)
{
    int choix;
    cout<<"Veuillez choisir une action"<<endl<<"[1] Sort"<<endl<<"[2] Attaque normale"<<endl;
    cin >> choix;
    switch(choix) {
    case 1 : //Sort
        if(joueur == 1) {
            while(m_personnage1->sort(m_personnage2,m_personnage1) == false) {
                Attaque(joueur);
            }
        }
        else {
            while(m_personnage2->sort(m_personnage1,m_personnage2) == false) {
                Attaque(joueur);
            }
        }
    }

    //case 2: //Attaque normale

}





void CCombat::IsDead()
{
    if(m_personnage1->Get_Pdv() == 0) {
        m_personnage1->Set_Mort();
    }
    else if(m_personnage2->Get_Pdv() == 0) {
        m_personnage2->Set_Mort();
    }
}


bool CCombat::IsGameOver()
{
    IsDead();
    if(m_personnage1->estDead()) {
        return true;
    }
    else if(m_personnage2->estDead()) {
        return true;
    }
    else {
        return false;
    }
}
