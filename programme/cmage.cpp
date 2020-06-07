#include "cmage.h"
using namespace std;


CMage::CMage()
{
    m_nom = "Mage";
    m_pdv = m_maxpdv = 100;
    m_esquive = -1;
    m_vitesse = -1;
    m_atk = 50;
    m_def = -1;
    m_agi = -1;
    m_intel = -1;
    m_estPoison = false;
    m_estInvis = false;
    m_estMort = false;
    m_CDSort[0] = { 0 };
    m_mana = -1;

}

CMage::CMage(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel)
{
    m_nom = nom;
    m_pdv = m_maxpdv = maxpdv;
    m_esquive = esquive;
    m_vitesse = vitesse;
    m_atk = atk;
    m_def = def;
    m_agi = agi;
    m_intel = intel;
    m_estPoison = false;
    m_estInvis = false;
    m_CDSort[0] = { 0 };
    m_mana = 10 * m_intel;
}
CMage::CMage(CPersonnage * personnage1)
{
  m_nom = personnage1->get_Nom();
  m_pdv = personnage1->Get_Maxpdv();
  m_maxpdv= personnage1->Get_Maxpdv();
  m_esquive = personnage1->Get_Esquive();
  m_vitesse = personnage1->Get_Vitesse();
  m_atk = personnage1->Get_Atk();
  m_def = personnage1->Get_Def();
  m_agi = personnage1->Get_Agi();
  m_intel = personnage1->Get_Intel();
  m_estPoison = personnage1->Get_Poison();
  m_estInvis = false;
  m_CDSort[0] = { 0 };
  m_mana = 10 * m_intel;
}



CMage::~CMage()
{

}

void CMage::RegenMana(int valeur)
{
    m_mana += valeur;
    cout << m_nom << " a + " << valeur << " Mana";
    m_CDSort[0] = 4;
}

int CMage::Get_Mana()
{
    return m_mana;
}

void CMage::Set_Mana(int valeur)
{
    m_mana = valeur;

}

bool sort(CPersonnage * cible , CPersonnage * lanceur)
{
    CMage mageCible(cible);
    CMage mageLanceur(lanceur);

    if(mageLanceur.Get_Mana() >= 5) {
        int pdvRestant =  mageCible.Get_Pdv() - 50;
        mageCible.Set_Pdv(pdvRestant);
        int manaRestant = mageLanceur.Get_Mana() - 5;
        mageLanceur.Set_Mana(manaRestant);
        cout << "L'attaque a bien fonctionné, le personnage"<< mageCible.get_Nom()<< "a perdu 50 points de vie" <<endl;
        return true;
    }
    else {
        cout << "Vous n'avez pas assez de mana"<< endl;
        return false;
    }

}
