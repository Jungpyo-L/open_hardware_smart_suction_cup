#include "Wire.h"
#include "Adafruit_MPRLS_SSC.h"

#define PCAADDR 0x70

int led = LED_BUILTIN;

// Define states
#define IDLE 1 //this is 3 in the ROS
#define STREAMING 2 //this is 2 in the ROS
int state = IDLE; // initial state

#define RESET_PIN  -1  // set to any GPIO pin # to hard-reset on begin()
#define EOC_PIN    -1  // set to any GPIO pin to read end-of-conversion by pin
Adafruit_MPRLS mpr0 = Adafruit_MPRLS(RESET_PIN, EOC_PIN);
Adafruit_MPRLS mpr1 = Adafruit_MPRLS(RESET_PIN, EOC_PIN);
Adafruit_MPRLS mpr2 = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

void pcaselect(uint8_t i) {
  if (i > 3) return;
 
  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}


// standard Arduino setup()
void setup()
{
  Serial.begin(115200);
  Serial.println("\n Start setup");

  Wire.begin();
  Wire.setClock(400000);
  delay(10);
  Serial.println("\nPCAScanner ready!");

  pcaselect(0);
  if (! mpr0.begin()) {
    Serial.println("Failed to communicate with MPRLS sensor, check wiring?");
    while (1) {
      delay(10);
    }
  }
  Serial.println("Found MPRLS sensor 0");

  pcaselect(1);
  if (! mpr1.begin()) {
    Serial.println("Failed to communicate with MPRLS sensor, check wiring?");
    while (1) {
      delay(10);
    }
  }
  Serial.println("Found MPRLS sensor 1");

  
  pcaselect(2);
  if (! mpr2.begin()) {
    Serial.println("Failed to communicate with MPRLS sensor, check wiring?");
    while (1) {
      delay(10);
    }
  }
  Serial.println("Found MPRLS sensor 2");

  pinMode(led, OUTPUT);
}

void loop() 
{
  switch (state)
  {
    case IDLE:
    {
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(100);
      byte incoming = Serial.read();
      if (incoming == 's')
      {
        state = STREAMING;
        digitalWrite(led,HIGH);
      }
      break;
    }
    case STREAMING:
    {
      byte incoming = Serial.read();
      if (incoming == 'i')
      {
        state = IDLE;
      }
      for (int i = 0; i <= 3; i++) {
        pcaselect(i);
        if (i == 0) {
          mpr0.requestData();
        }else if (i == 1) {
          mpr1.requestData();
        }else if (i == 2) {
          mpr2.requestData();
        }
      }

      pcaselect(0);
      float pressure_Pa0 = mpr0.readPressure2()*100;
      pcaselect(1);
      float pressure_Pa1 = mpr1.readPressure2()*100;
      pcaselect(2);
      float pressure_Pa2 = mpr2.readPressure2()*100;
      Serial.print(pressure_Pa0);
      Serial.print(" ");
      Serial.print(pressure_Pa1);
      Serial.print(" ");
      Serial.print(pressure_Pa2);
      Serial.print(" ");
      Serial.println(pressure_Pa2);
      break;
    }
  }
 
}