#pragma once
#include "CWeapon.h"
#include <string>
#include "CBow.h"
#include "CDagger.h"
#include "CStaff.h"
#include "CSword.h"

#include "cpersonnage.h"
#include "CArcher.h"
#include "CMage.h"
#include "cguerrier.h"
#include "CAssassin.h"

#include <vector>

class CParse
{
private:

public:
	CParse();
	~CParse();
	std::vector<CPersonnage*> CharacterParse(std::string path);
	std::vector<CWeapon*> WeaponParse(std::string path);
};
