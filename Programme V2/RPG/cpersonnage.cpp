#include "cpersonnage.h"


string CPersonnage::get_Nom()
{
    return m_nom;
}

void CPersonnage::setNom( string nom)
{
    m_nom = nom;
}

CPersonnage::CPersonnage()
{
    m_nom = "Personnage non défini";
    m_pdv = m_maxpdv = -1;
    m_esquive = 50;
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

CPersonnage::CPersonnage(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel)
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

CPersonnage::CPersonnage(CPersonnage* copy)
{
	m_estPoison = false;

	m_nom = copy->m_nom;
	m_weapon = NULL;
	m_pdv = copy->Get_Pdv();
	m_maxpdv = copy->Get_Maxpdv();
	m_esquive = copy->Get_Esquive();
	m_atk = copy->Get_Atk();
	m_intel = copy->Get_Intel();
	m_vitesse = copy->Get_Vitesse();
  m_def = copy->Get_Def();
  m_agi = copy->Get_Agi();
  m_estPoison = false;
  m_estInvis = false;
  m_estMort = false;
  for(int i=0; i<5;i++)
    m_CDSort[i] = 0;
  return;
}

CPersonnage::~CPersonnage()
{

}

int CPersonnage::Get_Pdv()
{
    return m_pdv;
}

void CPersonnage::Set_Pdv(int pdv)
{
    m_pdv = pdv;
}

int CPersonnage::Get_Maxpdv()
{
    return m_maxpdv;
}

void CPersonnage::Set_Maxpdv(int maxpdv)
{
    m_maxpdv = maxpdv;
}

int CPersonnage::Get_Esquive()
{
    return m_esquive;
}

void CPersonnage::Set_Esquive(int esquive)
{
    m_esquive = esquive;
}

int CPersonnage::Get_Vitesse()
{
    return m_vitesse;
}

void CPersonnage::Set_Vitesse(int vitesse)
{
    m_vitesse = vitesse;
}

int CPersonnage::Get_Atk()
{
    return m_atk;
}

void CPersonnage::Set_Atk(int atk)
{
    m_atk = atk;
}

int CPersonnage::Get_Def()
{
    return m_def;
}

void CPersonnage::Set_Def(int def)
{
    m_def = def;
}

int CPersonnage::Get_Agi()
{
    return m_agi;
}

void CPersonnage::Set_Agi(int agi)
{
    m_agi = agi;
}

int CPersonnage::Get_Intel()
{
    return m_intel;
}

void CPersonnage::Set_Intel(int intel)
{
    m_intel = intel;
}

bool CPersonnage::Get_Poison()
{
    return m_estPoison;
}

void CPersonnage::Set_Poison(bool estPoison)
{
    m_estPoison = estPoison;
}


void CPersonnage::Set_Mort()
{
    m_estMort = true;
}
