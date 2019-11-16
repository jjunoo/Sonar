#include <NewPing.h>
 
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 300

// NewPing setup dos pins and distancia maxima
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
 
void setup() {
   Serial.begin(9600);
   pinMode(8,OUTPUT);//Pin Vermelho
   pinMode(9,OUTPUT);//Pin Verde
   pinMode(10,OUTPUT);//Pin Azul
}
 
void loop() {
   delay(125);
   unsigned int distAnterior = sonar.ping_cm();
   delay(125);
   unsigned int distAtual = sonar.ping_cm();
   long time = millis();
   Serial.println("Fora do laço while");
   Serial.println(distAtual);
   Serial.println(distAnterior);
   
  
   //Ignora quando há retorno inválido = 0
   if (distAtual != 0 && distAnterior != 0){
     int cont = 0;
     while ((distAtual+2) > distAnterior){
       //Excêntrica - Peso descendo
       cont++;//cada passada pelo cont = 250ms (sem contar a primeira passada fora do laço = 250ms)
       delay(125);
       unsigned int distAnterior = sonar.ping_cm();
       delay(125);
       unsigned int distAtual = sonar.ping_cm();
       //Serial.println("Excêntrica"); 
       if (distAtual < (distAnterior-2)){
          if (cont > 7){
            //Liga a luz azul
            Serial.print("Tempo de finalização Excêntrica:  ");
            Serial.println(cont);
            Serial.println(distAtual);
            Serial.println(distAnterior); 
            digitalWrite(8,0);//Desliga Vermelho
            digitalWrite(9,0);//Desliga Verde
            digitalWrite(10,1);//Liga Azul
            break;
          }
          else if (cont < 5){
            //Liga a luz vermelha
            Serial.print("Tempo de finalização Excêntrica:  ");
            Serial.println(cont);
            Serial.println(distAtual);
            Serial.println(distAnterior);          
            digitalWrite(9,0);//Desliga Verde
            digitalWrite(10,0);//Desliga Azul
            digitalWrite(8,1);//Liga Vermelho
            break;
          }
          else{
            //Liga a luz verde
            Serial.print("Tempo de finalização Excêntrica:  ");
            Serial.println(cont);
            Serial.println(distAtual);
            Serial.println(distAnterior);
            digitalWrite(8,0);//Desliga Vermelho           
            digitalWrite(10,0);//Desliga Azul
            digitalWrite(9,1);//Liga Verde
            break; 
          }    
       }
     }
     while (distAtual < (distAnterior+2)){
      //Concêntrica - Peso subindo 
        cont++;//cada passada pelo cont = 250ms (sem contar a primeira passada fora do laço = 250ms)
        delay(125);
        unsigned int distAnterior = sonar.ping_cm();
        delay(125);
        unsigned int distAtual = sonar.ping_cm();
       // Serial.println("Concentrica");
        if (distAtual > (distAnterior+2)){
           if (cont > 7){
            //Liga a luz azul
            Serial.print("Tempo de finalização Concentrica:  ");
            Serial.println(cont);
            Serial.println(distAtual);
            Serial.println(distAnterior); 
            digitalWrite(8,0);//Desliga Vermelho
            digitalWrite(9,0);//Desliga Verde
            digitalWrite(10,1);//Liga Azul
            break;
          }
          else if (cont < 5){
            //Liga a luz vermelha
            Serial.print("Tempo de finalização Concentrica:  ");
            Serial.println(cont);
            Serial.println(distAtual);
            Serial.println(distAnterior);          
            digitalWrite(9,0);//Desliga Verde
            digitalWrite(10,0);//Desliga Azul
            digitalWrite(8,1);//Liga Vermelho
            break;
          }
          else{
            //Liga a luz verde
            Serial.print("Tempo de finalização Concentrica:  ");
            Serial.println(cont);
            Serial.println(distAtual);
            Serial.println(distAnterior);
            digitalWrite(8,0);//Desliga Vermelho           
            digitalWrite(10,0);//Desliga Azul
            digitalWrite(9,1);//Liga Verde
            break; 
          }    
       }
     }
   }  
}
