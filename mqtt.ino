unsigned long lastReconnect = 0;


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("[MQTT] Message arrived: ");
  
  int n;
  for (n = 0; n < length; n++) {
    Serial.print((char)payload[n]);
  }
  Serial.println();
  char* msgString = (char*)payload;
  msgString[n] = '\0';
  
  int i = 0;
  boolean startRobotCmd = false;
  int robotCmd;
  
  char* pch = strtok(msgString,":");
  while (pch != NULL) {
    if(i==0) {
      if(strcmp(pch, "robot") == 0)
        startRobotCmd = true;
      else
        Serial.println("[MQTT] Did not get robot command");
    }
    
    //check command
    if(startRobotCmd and i==1) {
      //Serial.print("[MQTT] Start checking command on validity: ");
      //Serial.println(pch);
      if(doAction(pch)) {
        Serial.print("[MQTT] Got valid command: ");
        Serial.println(pch);
      }
      else {
        Serial.println("[MQTT] Got invalid command");
      }
    }

    i++;
    pch = strtok(NULL, ":");
  }
}

//void mqttPublish(const char* format, ...) {
//  char msg[100];
//  snprintf(msg, 100, format, var1);
//  mqtt.publish(outTopic, msg);
//}


void reconnect() {
  unsigned long now = millis();
  
  // Loop until we're reconnected
  if(!mqtt.connected() and now-lastReconnect > 5000 or lastReconnect == 0) {
    lastReconnect = now;
    
    Serial.print("[MQTT] Attempting connection...");
    // Attempt to connect
    if (mqtt.connect("ESP8266Client")) {
//    if (mqtt.connect("ESP8266Client", mqtt_user, mqtt_pass)) { // use instead previous line when MQTT broker uses credentials
      Serial.println("connected");
      publishStatus();
      mqtt.subscribe(inTopic);
    }
    else {
      Serial.print(" failed, rc=");
      Serial.print(mqtt.state());
      Serial.println(" try again in 5 seconds");
    }
  }
}

