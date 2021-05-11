#define trigpin 13
#define ecopin 12
#define motorleft_c 11
#define motorleft_a 10
#define motorright_c 9
#define motorright_a 8
#define ir_left 7
#define ir_right 6
#define vibrater 5
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trigpin,OUTPUT);
  pinMode(ecopin,INPUT);
  pinMode(motorleft_c,OUTPUT);
  pinMode(motorleft_a,OUTPUT);
  pinMode(motorright_c,OUTPUT);
  pinMode(motorright_a,OUTPUT);
  pinMode(ir_left,INPUT);
  pinMode(ir_right,INPUT);
  pinMode(vibrater,INPUT);
}

void loop() {
  

}
