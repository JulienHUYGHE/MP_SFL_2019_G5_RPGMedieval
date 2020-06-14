#include "cpersonnage.h"


string CPersonnage::get_Nom() const
{
    return m_nom;
}

void CPersonnage::setNom(const string & nom)
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

CPersonnage::~CPersonnage()
{

}

int CPersonnage::Get_Pdv() const
{
    return m_pdv;
}

void CPersonnage::Set_Pdv(int pdv)
{
    m_pdv = pdv;
}

int CPersonnage::Get_Maxpdv() const
{
    return m_maxpdv;
}

void CPersonnage::Set_Maxpdv(int maxpdv)
{
    m_maxpdv = maxpdv;
}

int CPersonnage::Get_Esquive() const
{
    return m_esquive;
}

void CPersonnage::Set_Esquive(int esquive)
{
    m_esquive = esquive;
}

int CPersonnage::Get_Vitesse() const
{
    return m_vitesse;
}

void CPersonnage::Set_Vitesse(int vitesse)
{
    m_vitesse = vitesse;
}

int CPersonnage::Get_Atk() const
{
    return m_atk;
}

void CPersonnage::Set_Atk(int atk)
{
    m_atk = atk;
}

int CPersonnage::Get_Def() const
{
    return m_def;
}

void CPersonnage::Set_Def(int def)
{
    m_def = def;
}

int CPersonnage::Get_Agi() const
{
    return m_agi;
}

void CPersonnage::Set_Agi(int agi)
{
    m_agi = agi;
}

int CPersonnage::Get_Intel() const
{
    return m_intel;
}

void CPersonnage::Set_Intel(int intel)
{
    m_intel = intel;
}

bool CPersonnage::Get_Poison() const
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


