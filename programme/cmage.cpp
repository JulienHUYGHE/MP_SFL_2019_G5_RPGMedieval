#include "cmage.h"
using namespace std;


CMage::CMage()
{
    m_nom = "Mage non défini";
    m_pdv = m_maxpdv = -1;
    m_esquive = -1;
    m_vitesse = -1;
    m_atk = -1;
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

bool sort(CMage cible , CMage lanceur)
{
    if(lanceur.Get_Mana() >= 5) {
        int pdvRestant =  cible.Get_Pdv() - 50;
        cible.Set_Pdv(pdvRestant);
        int manaRestant = lanceur.Get_Mana() - 5;
        lanceur.Set_Mana(manaRestant);
        cout << "L'attaque a bien fonctionné, le personnage"<< cible.Get_Nom()<< "a perdu 50 points de vie" <<endl;
        return true;
    }
    else {
        cout << "Vous n'avez pas assez de mana"<< endl;
        return false;
    }

}
