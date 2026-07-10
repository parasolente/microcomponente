// ================= RFID RC522 =================
#include <SPI.h>
#include <MFRC522.h>

MFRC522 rfid(RFID_SS_PIN, RFID_RST_PIN);

void initRFID() {
  SPI.begin();
  rfid.PCD_Init();
}

String leerRFID() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return "";
  }

  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      uid += "0";
    }
    uid += String(rfid.uid.uidByte[i], HEX);
    if (i < rfid.uid.size - 1) {
      uid += ":";
    }
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  return uid;
}
