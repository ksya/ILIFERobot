void processCmdRequest() {
  if(!server.hasArg("c")) return returnFail("BAD ARGS");
  String cmd = server.arg("c");

  int robotCmd = findValidRobotCmd(cmd.c_str());

  if(robotCmd != -1) {
    IRbutton irbutton = buttonCmds[robotCmd];
    Serial.print("[HTTP] Got valid robot command: ");
    Serial.println(irbutton.name);
    
    server.send(200, "text/plain", "Robot "+String(irbutton.name));

    SendIRCode(irbutton);
  }
  else {
    returnFail("INVALID COMMAND");
  }
  
}

void returnFail(String msg) {
  server.send(200, "text/plain", msg);
}

void setupHTTP() {
  MDNS.begin(host);
  
  httpUpdater.setup(&server, update_path, update_username, update_password);
  server.begin();

  MDNS.addService("http", "tcp", 80);
  Serial.printf("[HTTP] HTTPUpdateServer ready! Open http://%s.local%s in your browser and login with username '%s' and password '%s'\n", host, update_path, update_username, update_password);
  Serial.println("");
  
  server.on("/", [](){
    server.send(200, "text/html", makeRobotCmdPage());
  });
  
  server.on("/cmd", HTTP_GET, processCmdRequest);
}








//
//void HTTPRobotAction(IRbutton irbutton){
//  //SendIRCode(irbutton);
//  
//  Serial.print("[HTTP] Got robot request: ");
//  Serial.println(irbutton.name);
//  
//  server.send(200, "text/plain", "Robot "+String(irbutton.name));
//
//  char command[20];
//  sprintf(command, "robot;%s", irbutton.name);
//  mqtt.publish(outTopic, command);
//}
//    
//void setupHTTPRobotCmd() {
//  for(int c = 0; c < sizeof(buttonCmds)/sizeof(buttonCmds[0]); c++) {
//    
//    char requesturl[20];
//    sprintf(requesturl, "/cmd=%s", buttonCmds[c].name);
//
//    //handle http request
//    server.on(requesturl, std::bind(&HTTPRobotAction, buttonCmds[c]));
//  }
//}

