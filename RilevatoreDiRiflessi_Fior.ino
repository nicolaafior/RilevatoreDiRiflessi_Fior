int TempoBuzzer;
int TempoLed;



int CreazioneTempoAccensioneLed = random (1000,4000); 
int CreazioneTempoAccensioneBuzzer = random (1000,4000); 
int StatoBottoneStart = 13;
int StatoBottoneLed = 2;
int StatoBottoneBuzzer = 5;                   
int buzzer = 7;
int VERDE = 9;
int BLU = 0;
int ROSSO = 11;
int ledblu = 3;


void setup(){
  TempoLed=0;
  TempoBuzzer=0;
  //Imposto gli input
  
  pinMode(StatoBottoneStart,INPUT);
  pinMode(StatoBottoneLed,INPUT);
  pinMode(StatoBottoneBuzzer,INPUT);

  //Imposto gli output 
  
  pinMode(VERDE, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(ROSSO, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ledblu,OUTPUT);

  
  Serial.begin(9600);
}

void loop(){
  
  if (digitalRead(StatoBottoneStart) == HIGH) 
  {
    Serial.println ("Il gioco è iniziato" );
    
    digitalWrite(VERDE,LOW);
    digitalWrite(ROSSO,LOW);
    digitalWrite(BLU,LOW);

    delay (CreazioneTempoAccensioneLed); //delay random
    digitalWrite(ledblu,HIGH); // accendo il led 
    
    while(digitalRead(ledblu) == HIGH) 
    {
   
      if (digitalRead(StatoBottoneLed) == HIGH)
      {
        
        digitalWrite(ledblu,LOW); 
        Serial.println ("Il tempo del led è: " );
        Serial.println (TempoLed); // restituisco in output il tempo
        
      }
    else // se invece non è premuto 
    {
      
      while(digitalRead(StatoBottoneLed) == LOW) 
      {
        TempoLed++; 
        delay(1);
      }
      
    }
    delay(100);
    }
  delay (CreazioneTempoAccensioneBuzzer); //delay random
    
    digitalWrite(buzzer, HIGH);// attivo il buzzer
 
    
    while(digitalRead(buzzer) == HIGH)
    {
      if (digitalRead(StatoBottoneBuzzer) == HIGH)
      {
        
        digitalWrite(buzzer,LOW);
        Serial.println ("Il tempo del buzzer è: " );
        Serial.println (TempoBuzzer);// restituisco in output il tempo
        
      }
    
    else// se invece non è premuto 
    {
     
      while(digitalRead(StatoBottoneBuzzer) == LOW)
      {
        
        TempoBuzzer++; // incremento il tempo fino alla premuta del pulsante
        delay(1);
        }
        }
        }
        
        if (TempoBuzzer < 700 && TempoLed < 700)
        {
          
          digitalWrite(VERDE,HIGH);
          Serial.println ("BRAVO !! BUON TEMPO !! " );
        }
        
        else{
          Serial.println ("Riprovaci, puoi fare di meglio !! " );
          digitalWrite(ROSSO,HIGH);\
        }
  }  
 }





 




