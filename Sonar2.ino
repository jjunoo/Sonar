#include <NewPing.h>
 
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 400

// NewPing setup dos pins and distancia maxima
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
 
void setup() {
   Serial.begin(9600);
}
 
void loop() {
   delay(50);
   unsigned int distance = sonar.ping_cm();

   //Ignora quando há retorno inválido = 0
   if (distance != 0){
     Serial.print(distance);
     Serial.println("cm");
   }  
}
