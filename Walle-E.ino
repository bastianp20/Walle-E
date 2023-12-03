#include <Servo.h>
#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11
Servo motor; 
int dhtpin = 7; 
DHT temphum (dhtpin, Type); 
int servopin = 12; 
int servopos1 = 40;
int servopos2 = 140;
float humedad; 
float gradosC; 
int led = 3;
bool continuar = true; 
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); 
  Serial.begin(9600);
  temphum.begin();
  motor.attach(servopin);

}
void loop() {
  // put your main code here, to run repeatedly:
  int suelo = analogRead(A0);
  humedad = temphum.readHumidity();
  gradosC = temphum.readTemperature();
  
  Serial.print("humedad del aire ");
  Serial.println(humedad);
  delay(1000); 
  Serial.print("temperatura del aire ");
  Serial.println(gradosC);
  delay(1000);
  Serial.print("suelo ");
  Serial.println(suelo);
  
  // entre 40 y 50 es aire fresco 
  if (humedad >= 40.0 && humedad <= 50.0){
    delay(2000);
    motor.write(servopos1);
    delay(5000);
    motor.write(servopos2);
    delay(5000);
    Serial.println("la temperatura del suelo es: ");
    Serial.println(suelo);
  } 
  // entre 51 y 80 es humedo 
  else if (humedad >= 51.0 && humedad <= 80.0){
    digitalWrite(led, 1);
    delay(200);
    digitalWrite(led, 0);
    delay(200);
    digitalWrite(led, 1);
    delay(200);
    digitalWrite(led, 0);
    delay(200);
    digitalWrite(led, 1);
    delay(200);
    digitalWrite(led, 0);
    delay(200);
    motor.write(servopos1);
    delay(5000);
    motor.write(servopos2);
    delay(5000);
    Serial.println("la temperatura del suelo es: ");
    Serial.println(suelo);
  } 
  else if (suelo <= 600 && suelo >= 0){
    Serial.print(" está humedo ");
    digitalWrite(led, 1);
    delay(1000);
    digitalWrite(led, 0);
    delay(1000);
    digitalWrite(led, 1);
    delay(1000);
    digitalWrite(led, 0);
    Serial.println("la temperatura del suelo es: ");
    Serial.println(suelo);
  }
  
  if (suelo <= 1023 && suelo >= 600){
    digitalWrite(led, 1);
    delay(1000);
    digitalWrite(led, 0);
    delay(1000);
    digitalWrite(led, 1);
    delay(1000);
    digitalWrite(led, 0);
    delay(1000);
    digitalWrite(led, 1);
    delay(1000);
    digitalWrite(led, 0);
    delay(1000);
    digitalWrite(led, 1);
    delay(1000);
    digitalWrite(led, 0);
    delay(1000);
    digitalWrite(led, 1);
    Serial.print("la temperatura del suelo es: ");
    Serial.println(suelo);
    Serial.println(" no está humedo ");
  }
}
