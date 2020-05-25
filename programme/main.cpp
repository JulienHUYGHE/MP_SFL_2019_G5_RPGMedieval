#include <QCoreApplication>
#include "cgame.h"
#include "cmage.h"

int main(int argc, char *argv[])
{
    CGame game;
    CMage P1;
    CMage P2;

    game.LauchGame(&P1, &P2);
}
