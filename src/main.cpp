#include "robotka.h"

#include "SmartServoBus.hpp"

using namespace lx16a;

static int n = 0;
static SmartServoBus servoBus;

void setup() {
    rkConfig cfg;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);

    // Sem patří váš kód
    // Servos on the bus must have sequential IDs, starting from 0 (not 1)!
    servoBus.begin(1, UART_NUM_1, GPIO_NUM_27); // prvni cislo je pocet serv, druhy parametr nemenit 
                                                // IO27 na DevKitV4 odpovida GPIO5 na RBCX  
                                                // napajeni serva pripojit na StepDown !!
    
    // Set servo Id (must be only one servo connected to the bus)
    // servoBus.setId(0);
    // while (true) {
    //     printf("GetId: %d\n", servoBus.getId());
    //     delay(1000);
    // }

    // kdyz servo 0 pri pohybu na neco narazi, tak se zastavi a nepojede dal
    servoBus.setAutoStop(0, true);

    while (true) {
            
        // uint16_t angle = (n % 240);

        // servoBus.set(0, Angle::deg(angle));
        // printf("Move to %d \n", angle);

        // delay(500);

        // auto curPos = servoBus.pos(0);
        // printf("Position at %f \n", curPos.deg());

        // n += 15;
        // delay(1000);

        //servoBus.set(0, 0_deg);
        servoBus.set(0, 0_deg, 200.f, 1.f);
        printf("Move to %d \n", 0);
        delay(3000);
        auto curPos = servoBus.pos(0);
        printf("Position at %f \n", curPos.deg());
        
        //servoBus.set(0, 239_deg);
        servoBus.set(0, 240_deg, 200.f, 1.f);
        printf("Move to %d \n", 239);
        delay(3000);
        auto cur2Pos = servoBus.pos(0);
        printf("Position at %f \n", cur2Pos.deg());

    }
}

