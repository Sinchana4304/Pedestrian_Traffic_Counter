// C++ code

#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x26, 16,2);
int red_led = 4;
int green_led = 2;
int yellow_led = 3;
int button = 5;
int count = 0;


void setup()
{
  Serial.begin(9600);
  Serial.println("Pedestrian Traffic Counter");
  Serial.println("No Pedastarin crossed the road yet!");
  Serial.println("Careful GREEN LIGHT - Vehicles are moving");
  
    
  lcd.init();
  lcd.backlight();
  
  pinMode(green_led,OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
  lcd.setCursor(0,0);
  lcd.print("Pedestrian");
  lcd.setCursor(0,1);
  lcd.print("Count: ");
  lcd.setCursor(7,1);
  lcd.print(count);         
}

void loop()
{
  digitalWrite(green_led, HIGH);
  //Serial.println("Status: Careful- Vehicles are moving");
  int button_status = digitalRead(button);
  if(button_status == LOW)
  {
    count++; 
    
    Serial.print("Pedestrian Detected! Current Count: ");
    Serial.println(count);
    
    lcd.setCursor(7,1);
    lcd.print("   "); 
    lcd.setCursor(7,1);
    lcd.print(count); 
    
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, HIGH);
    Serial.println("Status: YELLOW LIGHT - Traffic prepare to stop");
    delay(2000);
    
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led,HIGH); 
    Serial.println("Status: RED LIGHT - Pedestrians is Crossing");
    delay(5000);
    
    digitalWrite(red_led,LOW);
    digitalWrite(green_led, HIGH);
    Serial.println("Status: GREEN LIGHT - Pedestrians crossed the road");
    Serial.println("        Careful- Vehicles are moving");
  }
}
