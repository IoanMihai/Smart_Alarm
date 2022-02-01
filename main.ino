#include<SoftwareSerial.h>
#define IR_PIN 3
#define BUZZ_PIN 2
#define RED_LED 6
#define GREEN_LED 5
#define WHITE_LED 9

bool is_activated = false;
int flag = 0;
String inputString = "";
char junk;

void setup() {
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT); 
  //digitalWrite(WHITE_LED, HIGH);
  Serial.begin(9600);
}
void loop() {

  char val;
  while(Serial.available() > 0){
    val = Serial.read();
    Serial.println(val);
  }

  if (val == '1'){
    is_activated = true;
  }else if (val == '2'){
    is_activated = false;
  }

  if (is_activated) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    if (digitalRead(IR_PIN) == LOW) {
      digitalWrite(BUZZ_PIN, HIGH);
      bool stop_alarm = false;
      while(stop_alarm == false){
        val = Serial.read();
        Serial.println(val);
        if (val == '3')
          stop_alarm = true;
      }
      digitalWrite(BUZZ_PIN, LOW);
    }
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

}
