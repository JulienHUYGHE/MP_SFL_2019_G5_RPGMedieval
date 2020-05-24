#include <QCoreApplication>
#include "cgame.h"
#include "cpersonnage.h"

int main(int argc, char *argv[])
{
    cgame game();
    CPersonnage P1;
    CPersonnage P2;

    P1.EstMage();
    P2.EstMage();

    game().LauchGame(&P1, &P2);




}
