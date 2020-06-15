
#include "cgame.h"
#include "cpersonnage.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "cmage.h"
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


/*void CGame::Sort(int joueur,CPersonnage * personnage1, CPersonnage * personnage2 )
{
    CMage  mage1(personnage1);
    CMage  mage2(personnage2);


        if(joueur == 1) {
            if(mage1.sort(personnage2) == false) {
                PlayTurn(personnage1,personnage2);
            }
        }
        else {
            if(joueur == 2) {
                if(mage2.sort(personnage1,personnage2) == false) {
                   PlayTurn(personnage1,personnage2);
            }

           }
        }
}
*/




void CGame::LauchGame()
{
    cout<<"Le combat va commencer"<<endl;

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
        std::cout << personnage2.get_Nom() << "is playing\n";
        std::cout << "Action 1 : Attaquer\n" << "Action 2 : Attaquer main nues\n" << "Action 3 : Lancer un sort(Uniquement pour les mages)\n" << "Action 4 : Passer son tour\n";
        cin >> Choix;

        switch (Choix) {
          case 1:
            personnage2.Set_Pdv(personnage2.Get_Pdv()-(personnage1.Get_Atk()+personnage1.Get_Weapon()->Get_Damage()));
            std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk() << "degats!\n";
            break;
          case 2:
            personnage2.Set_Pdv(personnage2.Get_Pdv()-personnage1.Get_Atk());
            std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage() << "degats!\n";
            break;
          case 3:
            if(personnage2.EstMage())
            {
              personnage2.sort(&personnage1);
            }
            else
            {
              personnage2.Set_Pdv(personnage2.Get_Pdv()-personnage1.Get_Atk());
              std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage() << "degats!\n";
            }
            break;
          default:
            std::cout << "Vous avez passé votre tour";
        }
      }
      else if(nbtour%2==0)
      {
        std::cout << personnage1.get_Nom() << " is playing\n";
        std::cout << "Action 1 : Attaquer\n" << "Action 2 : Attaquer main nues\n" << "Action 3 : Lancer un sort(Uniquement pour les mages)\n" << "Action 4 : Passer son tour\n";
        cin >> Choix;
        switch (Choix) {
          case 1:
            personnage1.Set_Pdv(personnage1.Get_Pdv()-(personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage()));
            std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage() << "degats!\n";
            break;
          case 2:
            personnage1.Set_Pdv(personnage1.Get_Pdv()-personnage2.Get_Atk());
            std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk() << "degats!\n";
            break;
          case 3:
            if(personnage1.EstMage())
            {
              personnage1.sort(personnage1);
            }
            else
              {
                personnage2.Set_Pdv(personnage2.Get_Pdv()-personnage1.Get_Atk());
                std::cout << personnage1.get_Nom() << "a pris " <<personnage2.Get_Atk()+personnage2.Get_Weapon()->Get_Damage() << "degats!\n";
              }
            break;
          default:
            std::cout << "\nVous avez passé votre tour\n";
        }
      }
      std::cout << personnage1.get_Nom() << " a " << personnage1.Get_Pdv() << " PV restants\n";
      std::cout << personnage2.get_Nom() << " a " << personnage2.Get_Pdv() << " PV restants\n";
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
        cout<<"le joueur 2 ("<<personnage2.get_Nom()<<")  est le vainqueur"<<endl;
        return true;
    }else if(personnage2.Get_Pdv() <= 0)
    {
        cout<<"le joueur 1 ("<<personnage1.get_Nom()<<")  est le vainqueur"<<endl;
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
        cout<<"votre adverssaire a esquive l'attaque"<<endl;

    } else
    {
        PVop = receveur->Get_Pdv() - ATK; //op pour opponent
        receveur->Set_Pdv(PVop);
    }

    cout<<"les points de vie de votre advetrsaire sont de : "<<receveur->Get_Pdv()<<endl;
    cout<<"tour "<<m_nbtour<<" termine\n\n"<<endl;
    m_nbtour++;



}

void CGame::afficherChoixActions(CPersonnage * Attaquant, CPersonnage * receveur)
{
    cout<<"Vos Stats  ->  Type : "<<Attaquant->get_Nom()<<" | Attaque : "<<Attaquant->Get_Atk()<<" | PdV : "<< Attaquant->Get_Pdv()<<endl;
    cout<<"Stats  Ennemi ->  Type : "<<receveur->get_Nom()<<" | Attaque : "<<receveur->Get_Atk()<<" | PdV : "<< receveur->Get_Pdv()<<endl;
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
    std::cout << "Nom\tClasse\n";
    for(int i=0; i< AllChar.size(); i++) //pres des persos
    {
      std::cout << i << AllChar[i]->get_Nom() << "\t";
      if(AllChar[i]->EstArcher())
        std::cout << "Archer";
      if(AllChar[i]->EstMage())
        std::cout << "Mage";
      if(AllChar[i]->EstAssassin())
        std::cout << "Assasin";
      if(AllChar[i]->EstGuerrier())
        std::cout << "Guerrier";
      std::cout << std::endl;
    }
    std::cout << "Choix perso1\n";
    std::cin >> choix;
    personnage1 = new CPersonnage(AllChar[choix]);
    std::cout << "Choix perso2\n";
    std::cin >> choix;
    personnage2 = new CPersonnage(AllChar[choix]);
    std::cout << "Nom\tType\n";

    std::cout << "p1 "<<personnage1.get_Nom() << std::endl;
    std::cout << "p2 "<<personnage2.get_Nom() << std::endl;



    for(int i=0; i<AllWeap.size(); i++)
    {
      std::cout << AllWeap[i]->Get_Name() << "\t" << AllWeap[i]->Get_Type() << std::endl;
    }
    std::cout << "Player 1 choisis ton arme : ";
    std::cin >> choix;
    personnage1.Set_Weapon(new CWeapon(AllWeap[choix]));
    std::cout << "Player 2 choisis ton arme : ";
    std::cin >> choix;
    personnage2.Set_Weapon(new CWeapon(AllWeap[choix]));


}
