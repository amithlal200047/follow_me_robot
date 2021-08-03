 #define Enable1 5  // Enable Pin for motor 1
#define Enable2 3  // Enable Pin for motor 2
#define trigpin 13
#define ecopin 12
#define motorleft_c 11
#define motorleft_a 10
#define motorright_c 9
#define motorright_a 8
#define ir_left 7
#define ir_right 6
#define mini1 4
#define mini2 2
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(Enable1, OUTPUT);
  pinMode(Enable2, OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(ecopin,INPUT);
  pinMode(motorleft_c,OUTPUT);
  pinMode(motorleft_a,OUTPUT);
  pinMode(motorright_c,OUTPUT);
  pinMode(motorright_a,OUTPUT);
  pinMode(ir_left,INPUT);
  pinMode(ir_right,INPUT);
  pinMode(mini1,INPUT);
  pinMode(mini2,INPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Helo..");
}

void loop() {
  
  analogWrite(Enable1, 90);
  analogWrite(Enable2, 90);
  if(digitalRead(mini2)==HIGH){
    lcd.setCursor(0,0);
    lcd.print("LOCKED      ");
    Serial.println("Recived locked");
    }
  else if(digitalRead(mini1)==LOW){
    
    lcd.setCursor(0,0);
    lcd.print("FOLLOW MODE ");
    Serial.println("Recived follow mode");
    }
  else if(digitalRead(mini1)==HIGH){
    
    lcd.setCursor(0,0);
    lcd.print("CONTROL MODE");
    Serial.println("Recived control mode");
    
    }
    
  if(digitalRead(mini1)==LOW && digitalRead(mini2)==LOW){
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  long tim=pulseIn(ecopin,HIGH)/2;
  long distance=tim*0.034;
  //Serial.println(distance);
  if(distance<20){
    if(digitalRead(ir_left)==HIGH && digitalRead(ir_right)==LOW){
        digitalWrite(motorleft_c,HIGH);
        digitalWrite(motorright_a,HIGH);
        digitalWrite(motorleft_a,LOW);
        digitalWrite(motorright_c,LOW);
        //Serial.println("Left");
      }
    else if(digitalRead(ir_right)==HIGH && digitalRead(ir_left)==LOW){
        digitalWrite(motorleft_a,HIGH);
        digitalWrite(motorright_c,HIGH);
        digitalWrite(motorleft_c,LOW);
        digitalWrite(motorright_a,LOW);
        //Serial.println("Right");
      }
    else{
        digitalWrite(motorleft_a,HIGH);
        digitalWrite(motorright_a,HIGH);
        digitalWrite(motorleft_c,LOW);
        digitalWrite(motorright_c,LOW);
        //Serial.println("Forward");
      }
      
      
  }
  else if(digitalRead(ir_left)==HIGH && digitalRead(ir_right)==LOW){
        digitalWrite(motorleft_c,HIGH);
        digitalWrite(motorright_a,HIGH);
        digitalWrite(motorleft_a,LOW);
        digitalWrite(motorright_c,LOW);
        //Serial.println("Left");
      }
  else if(digitalRead(ir_right)==HIGH && digitalRead(ir_left)==LOW){
        digitalWrite(motorleft_a,HIGH);
        digitalWrite(motorright_c,HIGH);
        digitalWrite(motorleft_c,LOW);
        digitalWrite(motorright_a,LOW);
        //Serial.println("Right");
      }
  
  else{
    digitalWrite(motorleft_c,LOW);
    digitalWrite(motorleft_a,LOW);
    digitalWrite(motorright_c,LOW);
    digitalWrite(motorright_a,LOW);
    //Serial.println("Stopped");
    }
  }
}
