#include "cgame.h"
#include "cpersonnage.h"
#include "CArcher.h"
#include "cmage.h"
#include "CAssassin.h"
#include "cguerrier.h"

int main(int argc, char *argv[])
{
    CGame game;


    game.ChoisirPersonnage();
    game.LauchGame();
    game.PlayTurn();
    return 0;
}
