/*#include <time.h>*/


void setupTime() {
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("\nWaiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
}

time_t getCurrentTime() {
  time_t now = time(nullptr);
  Serial.println(ctime(&now));
  return now;
}

