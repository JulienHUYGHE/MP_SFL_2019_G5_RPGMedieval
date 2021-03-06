#include "CArcher.h"

CArcher::CArcher()
{
    m_nom = "Archer";
    m_pdv = m_maxpdv = 90;
    m_esquive = 50;
    m_vitesse = -1;
    m_atk = 25;
    m_def = -1;
    m_agi = -1;
    m_intel = -1;
    m_estPoison = false;
    m_estInvis = false;
    m_estMort = false;
    m_CDSort[0] = { 0 };

}


CArcher::CArcher(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel)
{
    m_nom = nom;
    m_pdv = m_maxpdv = maxpdv;
    m_esquive = 50;
    m_vitesse = vitesse;
    m_atk = atk;
    m_def = def;
    m_agi = agi;
    m_intel = intel;
    m_estPoison = false;
    m_estInvis = false;
    m_CDSort[0] = { 0 };

}

CArcher::CArcher(CPersonnage * personnage1)
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
}

CArcher::~CArcher()
{

}

void CArcher::Viser()
{
    Vise = true;

}

bool CArcher::Get_Vise()
{
    return Vise;
}

int CArcher::est_entrain_de_viser()  //Retourne la valeur du bonus d'agi
{
    return int(m_agi * 1.33);
}
