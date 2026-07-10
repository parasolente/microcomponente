// ================= JSON SERIAL OUTPUT =================

void sendSensorReading(float peso, bool ir) {
  Serial.print("{\"t\":\"s\",\"w\":");
  Serial.print(peso, 2);
  Serial.print(",\"i\":");
  Serial.print(ir ? "true" : "false");
  Serial.println("}");
}

void sendRFID(String uid) {
  Serial.print("{\"t\":\"r\",\"u\":\"");
  Serial.print(uid);
  Serial.println("\"}");
}

void sendStatus(const char* msg) {
  Serial.print("{\"t\":\"st\",\"m\":\"");
  Serial.print(msg);
  Serial.println("\"}");
}

void sendCalibration(float factor) {
  Serial.print("{\"t\":\"c\",\"f\":");
  Serial.print(factor, 2);
  Serial.println("}");
}
