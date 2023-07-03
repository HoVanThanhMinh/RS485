#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int Enable_pin = D2;
const int led_pin = D8;

const int frequency = 5000;
const int led_channel = 0;
const int resolution = 8;

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup()
{
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  pinMode(Enable_pin, OUTPUT);
  digitalWrite(Enable_pin, LOW);        //  (LOW to receive value from Master)
  Wire.begin(D1, D4);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(100);
  display.clearDisplay();
  display.display();
  display.setTextColor(WHITE);

}

void loop()

{
  while (Serial.available())
  {
    display.clearDisplay();
    int PWM_master = Serial.parseInt();           
    int duty_cycle = map(PWM_master, 0, 1023, 0, 255); 
    Serial.println(duty_cycle);

    analogWrite(led_pin, duty_cycle);


    display.setCursor(0, 0);
    display.setTextSize(2);
    display.print("MASTER PWM");

    display.setCursor(50, 30);
    display.setTextSize(4);
    display.print(duty_cycle);

    display.display();
    delay(100);

  }
}
