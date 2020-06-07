#include <QCoreApplication>
#include "cgame.h"
#include "cpersonnage.h"
#include "CArcher.h"
#include "cmage.h"
#include "csorcier.h"
#include "cguerrier.h"

int main(int argc, char *argv[])
{
    CGame game;


    CMage Player1;
    CMage Player2;




    game.LauchGame(&Player1, &Player2);
    game.PlayTurn(&Player1, &Player2);
}



