#include <iostream>
#include "buttons/Button.h"
#include "Simulator.h"
/*

Ufuk Göktaş 040140036
Barış Yumak 040190055
Barış Yılmaz 040160095
                                    BLG252E Term Project
 */
int main() {
    Simulator *simulator = new Simulator();
    simulator->handleEvents();

    return 0;
}
