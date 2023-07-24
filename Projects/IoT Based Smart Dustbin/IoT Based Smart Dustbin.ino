  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // the loop function runs over and over again forever
  void loop() {
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000); // wait for a second
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    delay(1000); // wait for a second
  }

  //int LED  = 13;
  #include <SoftwareSerial.h>

  #define BTTX 9
  #define BTRX 10
  SoftwareSerial SerialBT(BTTX, BTRX);

  void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    SerialBT.begin(9600);
    SerialBT.println("Bluetooth connection established");
  }

  void loop() {
    delay(300);
    if (SerialBT.available()) {
      String msg = SerialBT.readString();
      if (msg == "on\r\n") {
        digitalWrite(LED_BUILTIN, HIGH);
        SerialBT.println("LED is ON");
      } else
      if (msg == "off\r\n") {
        digitalWrite(LED_BUILTIN, LOW);
        SerialBT.println("LED is OFF");
      }
    }
  }

  98 d3: 31: fda812
  98 D3, 31, FDA812