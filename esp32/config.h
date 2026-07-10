#ifndef CONFIG_H
#define CONFIG_H

// ================= RFID RC522 =================
#define RFID_SS_PIN   5
#define RFID_RST_PIN  22

// ================= HX711 =================
#define HX711_DT   32
#define HX711_SCK  33

// ================= SENSOR IR =================
#define PIN_IR      27

// ================= TIEMPOS =================
const unsigned long INTERVALO_LECTURA = 500;

// ================= BALANZA =================
float factorCalibracion = -7050.0;

// Muchos sensores IR dan LOW cuando detectan objeto.
// Si tu sensor funciona al revés, cambia esto a false.
const bool IR_ACTIVO_EN_LOW = true;

#endif
