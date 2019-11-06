#include <Arduino.h>
#include <WString.h>
#include "nav.h"

int obs_map[MAP_W][MAP_H];
int bb_map[MAP_W][MAP_H];

void setup() {
    Serial.begin(9600);

    // Serial.println("starting obs_map init");

    // Init obstacle map
    for (int i = 0; i < MAP_W; i++) {
        for (int j = 0; j < MAP_H; j++) {
            obs_map[i][j] = 0;
            bb_map[i][j] = 0;
        }
    }

    // Serial.println("finished obs_map init");
}

void loop() {
    Serial.println(F("Starting loop!"));
    unsigned long ts = millis();

    std::vector<v2d_s> route = a_star(2, 2, MAP_W - 2, MAP_H - 2, &obs_map);

    Serial.print(F("Free Memory Available: "));
    Serial.println(freeMemory());
    Serial.println(F("\n\n"));

    delay(1000);
}
