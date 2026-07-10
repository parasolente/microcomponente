// ================= IR SENSOR =================

void initIR() {
  pinMode(PIN_IR, INPUT);
}

bool leerSensorIR() {
  int lectura = digitalRead(PIN_IR);

  if (IR_ACTIVO_EN_LOW) {
    return lectura == LOW;
  } else {
    return lectura == HIGH;
  }
}
