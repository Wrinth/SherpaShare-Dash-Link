#include <SoftwareSerial.h>
 
int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3
 
int led = 12;
int led2 = 11;

int soundPin = 9;
 
int buttonPin = 7;
int buttonState = 0;
int ledState = 0;
int led2State = 0;
 
char dataFromBt;
 
boolean lightBlink = false;
 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
 
void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
 
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(soundPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}
 
void loop()
{
 
  if (bluetooth.available()) // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
 
    //Serial.println((char)bluetooth.read());
    dataFromBt = (char)bluetooth.read();
    
    //Serial.println(dataFromBt);
    if (dataFromBt == '3') {
      Serial.println("led and led2 on");
      digitalWrite(led, HIGH);
      digitalWrite(led2, HIGH);
      bluetooth.print("3");
    }
    if (dataFromBt == '2') {
      Serial.println("led2 on");
      digitalWrite(led, LOW);
      digitalWrite(led2, HIGH);
      bluetooth.print("2");
    }
    if (dataFromBt == '1') {
      Serial.println("led on");
      digitalWrite(led, HIGH);
      digitalWrite(led2, LOW);
      bluetooth.print("1");
    }
    if (dataFromBt == '0') {
      Serial.println("led off");
      digitalWrite(led, LOW);
      bluetooth.print("0");
    }
    if (dataFromBt == 'b') {
      Serial.println("a");
      lightBlink = true;
    } else {
      lightBlink = false;
    }
 
  }
 
  if (Serial.available()) // If stuff was typed in the serial monitor
  {
    // Send any characters the Serial monitor prints to the bluetooth
    //String myStr = (String)Serial.read();
    //char myStr1[] = "hello this is testing!";
 
   // uint8_t payload[myStr.length() + 1];
    //    myStr.getBytes(payload, myStr.length()+1);
 
    int bytes=Serial.available();
    //Serial.readBytes(buffer, startPosition, bytes);
 
    bluetooth.print((char)Serial.read());
 
  }
 
  // and loop forever and ever!
  if (lightBlink) {
    digitalWrite(led, HIGH);
    digitalWrite(led2, LOW);
    bluetooth.print("1");
    Serial.println("1");
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    bluetooth.print("2");
    Serial.println("2");
    delay(500);
  }
 
  //------arduino push button code----------------
 
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    ledState = digitalRead(led);
    led2State = digitalRead(led2);
    delay(500); 
    if(ledState == LOW && led2State == LOW) {
      digitalWrite(led, HIGH);
      bluetooth.print("1");
      Serial.println("LED 1 on");
      beep(200);
    } else if(ledState == HIGH && led2State == LOW) {
      digitalWrite(led, LOW);
      digitalWrite(led2, HIGH);
      bluetooth.print("2");
      Serial.println("LED 2 on");
      beep(200);
    }else if(ledState == LOW && led2State == HIGH) {
      digitalWrite(led, HIGH);
      bluetooth.print("3");
      Serial.println("LED 1 & 2 on");
      beep(200);
    } else {
      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
      Serial.println("LED 1 & 2 off");
      bluetooth.print("0");
      beep(200);
    }
  } 
}

void beep(unsigned char delayms){
  analogWrite(9, 20);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
} 
