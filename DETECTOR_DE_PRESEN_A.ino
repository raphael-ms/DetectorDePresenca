#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
const int pinoBotao = 7; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON
const int pinoLed = 2; //LED VERDE
const int pinoLedVermelho = 3; //LED VERMELHO
const int buzzer = 9;
const int distancia = 115;
boolean validador = true; // true ALARME ATIVADO - false ALARME DESLIGADO

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup()
{
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  digitalWrite(pinoLedVermelho, LOW);
  digitalWrite(pinoLed, HIGH);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop()
{
  if(digitalRead(pinoBotao) == LOW){
    validador = false;
    delay(300);
    
    tone(buzzer,1500);   
    delay(100);
    noTone(buzzer);
    delay(50);
    tone(buzzer,1500);   
    delay(100);
    noTone(buzzer);
    delay(50);
    
  }

  if(digitalRead(pinoBotao) == LOW && validador == false){
    validador = true;
    delay(300);
    tone(buzzer,1500);   
    delay(100);
    noTone(buzzer);
    delay(50);
  }

  
      if(validador == true){
          Serial.print(validador);
          digitalWrite(pinoLedVermelho, LOW);
          digitalWrite(pinoLed, HIGH);
          float cmMsec;
          long microsec = ultrasonic.timing();        
          cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
          Serial.print("Distancia em cm: ");
          Serial.println(cmMsec);
          delay(250);
  
              if(cmMsec < distancia ){
                  for(int i = 0; i<45; i++){
                    delay(100);
                    tone(buzzer,1500);   
                    delay(400);
                    noTone(buzzer);
                    delay(400);
                    }
                }
        }else{
          digitalWrite(pinoLedVermelho, HIGH);
          digitalWrite(pinoLed, LOW);  
          
        }
          
    
  
}
