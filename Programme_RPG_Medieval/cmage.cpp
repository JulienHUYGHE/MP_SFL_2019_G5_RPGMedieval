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
