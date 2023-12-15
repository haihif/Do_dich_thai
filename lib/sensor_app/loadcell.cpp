#include "HX711.h"
#include "loadcell.h"
#include "app_config.h"

HX711 loadcell;

const int LOADCELL_DOUT_PIN = LOADCELL_DOUT_PIN_CFG;
const int LOADCELL_SCK_PIN = LOADCELL_SCK_PIN_CFG;

void loadcell_init();
void loadcell_tare();
void loadcell_calib();
int loadcell_get_mass();

void loadcell_init(){
    loadcell.begin(LOADCELL_DOUT_PIN,LOADCELL_SCK_PIN);
    loadcell_calib();
    loadcell_tare();
}

void loadcell_tare(){
    loadcell.tare();
}

void loadcell_calib(){
    loadcell.set_scale(437); 
}

int loadcell_get_mass(){
    if(!loadcell.is_ready())
        return 0;
    int mass = (int) loadcell.get_units(1);
    return mass;
}