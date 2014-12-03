#define pir 2
#define buzzer 8
int calibrationTime = 60;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;

int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(pir, LOW);
  Serial.println("CALIBRANDO: ");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println("SENSOR ACTIVO");
  delay(1000);
}
 
void loop(){
  if(digitalRead(pir) == HIGH){
    tone(buzzer, 1000);
    if(lockLow){
      lockLow = false;
      Serial.println(++i);
      delay(50);
    }
    takeLowTime = true;
  }
  
  if(digitalRead(pir) == LOW){
    if(takeLowTime){
      lowIn = millis();
      takeLowTime = false;
    }
    if(!lockLow && (millis() - lowIn > pause)){
      lockLow = true;
      noTone(buzzer);
      delay(50);
    }
  }
}

  


