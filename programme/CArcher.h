#ifndef CARCHER_H
#define CARCHER_H
#include "cpersonnage.h"



class CArcher : public CPersonnage
{
private :
    bool Vise;   //Augmente les dégats quand c'est true

public:
    CArcher();
    CArcher(string nom, int maxpdv, int esquive, int vitesse, int atk, int def, int agi, int intel);
    ~CArcher();


    bool EstArcher() { return true; };
    bool EstMage() { return false; };
    bool EstSorcier() { return false; };
    bool EstGuerrier() { return false; };



    //Rajouter une fonction pour se soigner du poison

    void  Viser();

    bool Get_Vise();

     int est_entrain_de_viser();  //Retourne la valeur des degats si il vise
};

#endif // CARCHER_H
