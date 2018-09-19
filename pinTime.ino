void initPinTimer(pinTime &pin, int pin_number, size_t readings) {
  if(readings > 512)
    readings = 512;
  pin.bufferSize = readings;
  pin.pin = pin_number;

  // init valueBuffer to value 0
  for(size_t i; i<readings; i++) {
    pin.valueBuffer[i] = 0;
  }
}


/*
 * pin is pin number
 * timout is when the pin is either high or low for sure
 * readings is the number of readings to average
 */
void calcPinTime(pinTime &pin, unsigned int timeout) {
  unsigned long now = millis();
  pin.changed = false;
  pin.statusChanged = false;

  int value = digitalRead(pin.pin); //calculateAverageValue(pin);
  
  if(value != pin.lastValue or pin.lastValue == -1) {
    pin.changed = true;
    if(value == LOW) {
      pin.lastValue = LOW;
      pin.high = now - pin.lastPinLow;
    }
    else {
      pin.lastValue = HIGH;
      pin.low = now - pin.lastPinHigh;
    }
  }
  
  if(value == LOW) {
    pin.lastPinLow = now;
  }
  else {
    pin.lastPinHigh = now;
  }
  
  unsigned long highTime = now - pin.lastPinLow;
  unsigned long lowTime = now - pin.lastPinHigh;
  
  //determine pin state (on, off or blinking)
  if(highTime > timeout) {
    if(pin.isHigh != true)
      pin.statusChanged = true;
    pin.isHigh = true;
    pin.isLow = false;
    pin.isBlinking = false;
    pin.ratio = 1;
  }
  else if(lowTime > timeout) {
    if(pin.isLow != true)
      pin.statusChanged = true;
    pin.isLow = true;
    pin.isHigh = false;
    pin.isBlinking = false;
    pin.ratio = 0;
  }
  else { //is blinking
    if(pin.isBlinking != true)
      pin.statusChanged = true;
    pin.isHigh = false;
    pin.isLow = false;
    pin.isBlinking = true;
    pin.ratio = (float)pin.high/(float)(pin.low+pin.high);
  }
}


int calculateAverageValue(pinTime &pin) {
  //first add reading to buffer
  pin.valueBuffer[pin.valn] = digitalRead(pin.pin);
  pin.valn++;

  if(pin.valn == pin.bufferSize)
    pin.valn = 0;
  
  unsigned int sum = 0;
  for(size_t i = 0; i < pin.bufferSize; i++) {
    sum += pin.valueBuffer[i];
  }

  return sum > (int)pin.bufferSize*0.9; //70 percent is positive, count as positive;
}
