// ================= HX711 LOAD CELL =================
#include "HX711.h"

HX711 balanza;

void initWeight() {
  balanza.begin(HX711_DT, HX711_SCK);
  balanza.set_scale(factorCalibracion);
  balanza.tare();
}

void setCalibration(float factor) {
  factorCalibracion = factor;
  balanza.set_scale(factorCalibracion);
}

float getCalibration() {
  return factorCalibracion;
}

float leerPeso() {
  if (balanza.is_ready()) {
    return balanza.get_units(5);
  }
  return NAN;
}
