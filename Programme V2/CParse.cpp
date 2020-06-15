#include "CParse.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


CParse::CParse()
{

}

CParse::~CParse()
{
}

std::vector<CPersonnage*> CParse::CharacterParse(std::string path)
{
	//Open file
	std::ifstream characterfile(path);

	if(!characterfile.is_open())
		std::cout << "Character not open";
	//Initialize
	std::string var, champ, value;
	std::string classe, name;
	int speed, dodge, dmg, hp, intel, atk, def, agi;
	std::vector<CPersonnage*> AllChar;


	int pos = 0; //Position du s�parateur
	if (characterfile.is_open())
	{
		//On r�cup�re les diff�rents personnages dans le fichier characterfile
		while (getline(characterfile, var))
		{
			atk = def = agi = dmg = hp = dodge = speed = intel = 0; //Initialisation � 0 avec de lire le fichier
			if (var == "Character")
			{
				getline(characterfile, var);
				while (var != "EndCharacter")
				{
					//Division du champ et de la valeur
					pos = var.find(":");
					value = var.substr(pos+1, var.back());
					champ = var.substr(0, pos);
					//On rempli les differents champs en fonction de la ligne lu
					if (champ.compare("Classe") == 0) {
						classe = value;
					}
					if (champ == "Nom") {
						name = value;
					}
					if (champ == "Attaque") {
						atk = strtof(value.c_str(), 0);
					}
					if (champ == "HP") {
						hp = strtof(value.c_str(), 0);
					}
					if (champ == "Defense") {
						def = strtof(value.c_str(), 0);
					}
					if (champ == "Intelligence") {
						intel = strtof(value.c_str(), 0);
					}
					if (champ == "Dodge") {
						dodge = std::stoi(value.c_str(), 0);
					}
					if (champ == "Agilite") {
						agi = strtof(value.c_str(), 0);
					}
					if (champ == "Vitesse") {
						speed = std::stoi(value.c_str(), 0);
					}
					var ="";
					getline(characterfile, var);
				}
				//Create character
				if (classe == "Mage")
				{
					AllChar.push_back(new CMage(name, hp, dodge, speed, atk, def, agi, intel));

				}
				if (classe == "Archer")
				{
					AllChar.push_back(new CArcher(name, hp, dodge, speed, atk, def, agi, intel));

				}
				if (classe == "Guerrier")
				{
					AllChar.push_back(new CGuerrier(name, hp, dodge, speed, atk, def, agi, intel));

				}
				if (classe == "Assassin")
				{
					AllChar.push_back(new CAssassin(name, hp, dodge, speed, atk, def, agi, intel));
				}
			}
		}
		//Close file
		characterfile.close();
	}
	else
		{
			std::cout << "ERROR : Can't open character config file....\n";
		}
	return AllChar;
}


std::vector<CWeapon*> CParse::WeaponParse(std::string path)
{
		int nbtour=0;
		//Open file
		std::ifstream config(path);
		if(!config.is_open())
			std::cout << "Weap file error...\n";
		//Initialize
		std::string var, champ, value;
		std::string type, name;
		float dmg, hp, attack, intelligence, critique;
		int nb_fleches, mana_cost, durabilite;
		std::vector<CWeapon*> weapon_list;

		int pos;
		if (config.is_open())
		{
			//On r�cup�re les diff�rents personnages dans le fichier config
			while (getline(config, var))
			{
				//On remet les champs � 0
				nbtour++;
				dmg = 0, hp = 0, durabilite = 0, attack = 0, hp = 0, nb_fleches = 0, mana_cost = 0, intelligence = 0, critique = 0;
				if (var == "Weapon")
				{
					getline(config, var);
					while (var != "EndWeapon")
					{
						//Division du champ et de la valeur
						pos = var.find(":");
						value = var.substr(pos + 1, var.back());
						champ = var.substr(0, pos);
						//On rempli les diff�rentes variables en fonction du fichier de config weapon
						if (champ == "Type") {
							type = value;
						}
						if (champ == "Nom") {
							name = value;
						}

						if (champ == "Critique") {
							critique = strtof(value.c_str(), 0);
						}
						if (champ == "Degat") {
							dmg = strtof(value.c_str(), 0);
						}

						if (champ == "Durabilite") {
							durabilite = std::stoi(value.c_str(), 0);
						}
						if (champ == "Fleche") {
							nb_fleches = (int)strtof(value.c_str(), 0);
						}

						if (champ == "Intelligence") {
							intelligence = strtof(value.c_str(), 0);
						}
						if (champ == "Cout") {
							mana_cost = std::stoi(value.c_str(), 0);
						}
						getline(config, var);
					}

					//Creation de la liste des armes
					if (type == "Baton")
					{
						weapon_list.push_back(new CStaff(name, dmg, critique, type, mana_cost));
					}
					else if (type == "Arc")
					{
						weapon_list.push_back(new CBow(name, dmg, critique, type, nb_fleches));

					}
					else if (type == "Epee")
					{
						weapon_list.push_back(new CSword(name, dmg, critique, type, durabilite));
					}
					else if (type == "Dague")
					{
						weapon_list.push_back(new CDagger(name, dmg, critique, type, durabilite));
					}
				}
			}
			config.close();
		}
		return weapon_list;
}
