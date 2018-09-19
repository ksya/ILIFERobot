typedef struct IRbutton {
  const char* name;
  unsigned int signal[67];
} IRbutton;


typedef struct PinTime {
  int pin;
  unsigned long high = 0;
  unsigned long low = 0;
  unsigned long lastPinHigh = 0;
  unsigned long lastPinLow = 0;
  int lastValue = -1;
  boolean isHigh = false;
  boolean isLow = false;
  boolean isBlinking = false;
  float ratio = 0;
  boolean changed = false;
  boolean statusChanged = false;
  
  unsigned int valueBuffer[512]; //used to calculate average
  size_t bufferSize; //total buffer size, used to calculate average
  size_t valn = 0; //position in buffer, used to calculate average
} pinTime;

typedef struct Battery {
  float voltageBuffer[8] = {0,0,0};
  size_t bufferSize = 8; //total buffer size, used to calculate average
  size_t valn = 0; //position in buffer, used to calculate average
} battery;

enum Status {
  S_BOOTING,
  S_SLEEP,
  S_IDLE,
  S_BUSY,
  S_STUCK,
  S_CHARGING,
  S_GOING_HOME
};
