#include "config.h"

unsigned long tiempoAnterior = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  sendStatus("Iniciando sistema...");

  initRFID();
  sendStatus("RFID listo");

  initIR();
  sendStatus("IR listo");

  initWeight();
  sendStatus("Balanza lista");

  sendCalibration(getCalibration());
  sendStatus("Sistema iniciado");
}

void loop() {
  String uid = leerRFID();
  if (uid.length() > 0) {
    sendRFID(uid);
  }

  unsigned long ahora = millis();
  if (ahora - tiempoAnterior >= INTERVALO_LECTURA) {
    tiempoAnterior = ahora;

    bool ir = leerSensorIR();
    float peso = leerPeso();

    sendSensorReading(peso, ir);
  }
}
