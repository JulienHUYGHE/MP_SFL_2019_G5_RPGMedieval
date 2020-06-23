
#include "cgame.h"
#include "cpersonnage.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Cmage.h"
#include "CArcher.h"
#include "cguerrier.h"
#include "CAssassin.h"
#include "CParse.h"



using namespace std;


CGame::CGame()
{
    m_nbtour = 0;

}
CGame::~CGame()
{

}

void CGame::LauchGame()
{
    cout<<"*********************************\n";
    cout<<"C'est l'heure du DUDUDUDUDEL !!!!\n";
    cout<<"*********************************\n";

    cout << personnage1.get_Nom() << " va affronter " << personnage2.get_Nom() <<" dans ce combat \n\n\n"<<endl;
}

void CGame::PlayTurn()
{
    int nbtour = 1;
    int Choix;




    while(!IsGameOver(personnage1, personnage2))
    {

      if(nbtour%2==1)
      {
        std::cout << personnage2.get_Nom() << "is playing (joueur 1)\n";
        std::cout <<"Degats de l'arme : "<<personnage2.Get_Weapon()->Get_Damage();

        std::cout << "\n\nAction 1 : Attaquer\n" << "Action 2 : Attaquer main nues\n" << "Action 3 : Lancer un sort(Uniquement pour les mages)\n" << "Action 4 : Passer son tour\n";
        cin >> Choix;
        std::cout <<"\n\n";

        switch (Choix) {
          case 1:
            personnage2.Set_Pdv(personnage2.Get_Pdv()-(personnage1.Get_Atk()+personnage1.Get_Weapon()->Get_Damage()));
            std::cout << personnage1.get_Nom() << " a pris " <<personnage2.Get_Atk() << "degats!";
            break;
          case 2:
            personnage2.Set_Pdv(personnage2.Get_Pdv()-personnage1.Get_Atk());
            std::cout << personnage1.get_Nom() << " a pris " <<personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage() << "degats!";
            break;
          case 3:
            if(personnage2.EstMage())
            {
              personnage2.sort(&personnage1);
            }
            else
            {
              personnage2.Set_Pdv(personnage2.Get_Pdv()-personnage1.Get_Atk());
              std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage() << "degats!";
            }
            break;
          default:
            std::cout << "Vous avez passé votre tour";
        }
      }
      else if(nbtour%2==0)
      {
        std::cout << personnage1.get_Nom() << " is playing (joueur 2)\n";
        std::cout <<"Degats de l'arme : "<<personnage1.Get_Weapon()->Get_Damage();
        std::cout << "\n\nAction 1 : Attaquer\n" << "Action 2 : Attaquer main nues\n" << "Action 3 : Lancer un sort(Uniquement pour les mages)\n" << "Action 4 : Passer son tour\n";
        cin >> Choix;
        std::cout <<"\n";
        switch (Choix) {
          case 1:
            personnage1.Set_Pdv(personnage1.Get_Pdv()-(personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage()));
            std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage() << " degats!";
            break;
          case 2:
            personnage1.Set_Pdv(personnage1.Get_Pdv()-personnage2.Get_Atk());
            std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk() << "degats!";
            break;
          case 3:
            if(personnage1.EstMage())
            {
              personnage1.sort(personnage1);
            }
            else
              {
                personnage2.Set_Pdv(personnage2.Get_Pdv()-personnage1.Get_Atk());
                std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage() << "degats!";
              }
            break;
          default:
            std::cout << "\nVous avez passé votre tour\n\n\n------------------------------------------\n";
        }
      }

      std::cout << personnage1.get_Nom() << " a " << personnage1.Get_Pdv() << " PV restants\n";
      std::cout << personnage2.get_Nom() << " a " << personnage2.Get_Pdv() << " PV restants\n";
      std::cout <<"\n-----------------------------------------\n\n";
      nbtour++;
    }

    return;

}

bool CGame::Esquive(CPersonnage * Attaquant, CPersonnage * receveur)
{
    int max, random_number;
    max = 70;

    srand(time(0));

    if(Attaquant->get_Nom() == "Guerrier") {
        random_number = (rand () % max-1) +1;
        int chanceEsquive = random_number;
        if(chanceEsquive>=receveur->Get_Esquive()) {
            return true;
        }
    }
    else {
        max=60;
        random_number = (rand () % max-1) +1;
        int chanceEsquive = random_number;
        if(chanceEsquive >= receveur->Get_Esquive())
        {
            return true;
        }
    }
    return false;
}

bool CGame::IsGameOver(CPersonnage personnage1, CPersonnage personnage2)
{
    if(personnage1.Get_Pdv() <= 0)
    {
        cout<<"\nle joueur 2 ("<<personnage2.get_Nom()<<")  est le vainqueur"<<endl;
        return true;
    }else if(personnage2.Get_Pdv() <= 0)
    {
        cout<<"\nle joueur 1 ("<<personnage1.get_Nom()<<")  est le vainqueur"<<endl;
        return true;
    }
    return false;
}
void CGame::attaquer(CPersonnage * Attaquant, CPersonnage * receveur)
{
    int ATK = Attaquant->Get_Atk();
    int PVop;

    if(Esquive(Attaquant, receveur) == true)
    {
        cout<<"votre adverssaire a esquive l'attaque\n\n------------------------------------------\n"<<endl;

    } else
    {
        PVop = receveur->Get_Pdv() - ATK; //op pour opponent
        receveur->Set_Pdv(PVop);
    }

    cout<<"les points de vie de votre advetrsaire sont de : "<<receveur->Get_Pdv()<<endl;
    cout<<"\n\ntour "<<m_nbtour<<" termine\n\n"<<endl;
    m_nbtour++;



}

void CGame::afficherChoixActions(CPersonnage * Attaquant, CPersonnage * receveur)
{
    cout<<"Vos Stats  ->  Type : "<<Attaquant->get_Nom()<<" | Attaque : "<<Attaquant->Get_Atk()<<" | PdV : "<< Attaquant->Get_Pdv()<<endl;
    cout<<"\nStats  Ennemi ->  Type : "<<receveur->get_Nom()<<" | Attaque : "<<receveur->Get_Atk()<<" | PdV : "<< receveur->Get_Pdv()<<endl;
    cout<<"    - tapez 1 pour attaquer"<<endl;
    cout<<"    - tapez 2 pour passer votre tour\n";
    if(Attaquant->get_Nom() == "Mage") {
        cout<<"    - tapez 3 pour lancer un sort\n"<<endl;
    }

}


void CGame::ChoisirPersonnage()
{
    int choix;
    int num_joueur = 1;
    std::vector<CPersonnage*> AllChar;
    std::vector<CWeapon*> AllWeap;
    CParse parser;
    AllChar = parser.CharacterParse("characters.jdc");
    AllWeap = parser.WeaponParse("weapons.jdc");
    std::cout << "Nom\t\tClasse\t\tDegats\tPdV\tDefense\tAgilite\n\n";
    for(int i=0; i< AllChar.size(); i++) //pres des persos
    {
      std::cout << i <<" - "<< AllChar[i]->get_Nom() << " \t";
      if(AllChar[i]->EstArcher())
        std::cout << "Archer"<<"\t\t"<<AllChar[i]->Get_Atk()<<"\t"<<AllChar[i]->Get_Pdv()<<"\t"<<AllChar[i]->Get_Def()<<"\t"<<AllChar[i]->Get_Agi();
      if(AllChar[i]->EstMage())
        std::cout << "Mage"<<"\t\t"<<AllChar[i]->Get_Atk()<<"\t"<<AllChar[i]->Get_Pdv()<<"\t"<<AllChar[i]->Get_Def()<<"\t"<<AllChar[i]->Get_Agi();
      if(AllChar[i]->EstAssassin())
        std::cout << "Assasin"<<"\t\t"<<AllChar[i]->Get_Atk()<<"\t"<<AllChar[i]->Get_Pdv()<<"\t"<<AllChar[i]->Get_Def()<<"\t"<<AllChar[i]->Get_Agi();
      if(AllChar[i]->EstGuerrier())
        std::cout << "Guerrier"<<"\t"<<AllChar[i]->Get_Atk()<<"\t"<<AllChar[i]->Get_Pdv()<<"\t"<<AllChar[i]->Get_Def()<<"\t"<<AllChar[i]->Get_Agi();
      std::cout << std::endl;
    }
    do
    {
        std::cout << "\nChoix pour le joueur 1\n";
        std::cin >> choix;
    }while(choix < 0 || choix > 5);
    personnage1 = new CPersonnage(AllChar[choix]);
    do
    {
        std::cout << "\nChoix pour le joueur 2\n";
        std::cin >> choix;
    }while(choix < 0 || choix > 5);
    personnage2 = new CPersonnage(AllChar[choix]);

    std::cout << "joueur 1 : "<<personnage1.get_Nom() << std::endl;
    std::cout << "joueur 2 : "<<personnage2.get_Nom() << std::endl;

    std::cout << "\nNom\t\tType\tdegats\n\n";



    for(int i=0; i<AllWeap.size(); i++)
    {
      std::cout << i <<" - "<< AllWeap[i]->Get_Name() << "\t" << AllWeap[i]->Get_Type() << "\t" << AllWeap[i]->Get_Damage() <<std::endl;
    }
    do
    {
        std::cout << "\nJoueur 1 choisis ton arme : \n";
        std::cin >> choix;
    }while(choix < 0 || choix > 8);
    personnage1.Set_Weapon(new CWeapon(AllWeap[choix]));
    do
    {
        std::cout << "Player 2 choisis ton arme : \n\n";
        std::cin >> choix;
    }while(choix < 0 || choix > 8);
    personnage2.Set_Weapon(new CWeapon(AllWeap[choix]));

    system("CLS");
}
