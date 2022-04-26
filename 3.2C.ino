// This #include statement was automatically added by the Particle IDE.
#include <BH1750Lib.h>

bool light = false;
BH1750Lib bh1750;
void setup() {
    bh1750.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
}

void loop() {
    if (light && bh1750.lightLevel() < 1000)
    {
        light = false;
        Particle.publish("light", "dim");
        
    }
    else if (!light && bh1750.lightLevel() > 1000)
    {
        light = true;
        Particle.publish("light", "bright");
    }
    delay(5000);
}