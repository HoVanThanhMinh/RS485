int Enable_pin = 4;  
int Analog_pin = A0;
int ADC_Value =0 ;

void setup()
{
  Serial.begin(115200);            
  pinMode(Enable_pin, OUTPUT);
  pinMode(Analog_pin,INPUT); 
  delay(10); 
  digitalWrite(Enable_pin, HIGH);  
}
void loop()
{
    int ADC_Value = analogRead(Analog_pin);
    Serial.println(ADC_Value);          //Serial Write ADC_Value to RS-485 Bus
    delay(100);
}
