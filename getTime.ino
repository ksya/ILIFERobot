/*#include <time.h>*/


void setupTime() {
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
//  setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 0);  // option to set timezone
  Serial.println("\nWaiting for time");
  int count = 0;
  while(time(nullptr) <= 100000 && (count++ <20)) {
    Serial.print(".");
    delay(100);
  }
}

time_t getCurrentTime() {
  time_t now = time(nullptr);
  Serial.println(ctime(&now));
  return now;
}
