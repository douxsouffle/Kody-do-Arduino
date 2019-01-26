int pomiar = 0;
int odleglosc = 0;
int sensorValue = 0;
float voltage;
int ppm = 0;

void setup(){
Serial.begin(9600);
        pinMode(A1, INPUT);
        pinMode(A0, INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.00 / 1023.0);
  pomiar = analogRead (A1);
  odleglosc = ((67870 / (pomiar - 3)) - 40);
  if (odleglosc > 1000){
      Serial.println("Odleglosc jest za duza!!!");
    }
    else{
      Serial.println("Odleglosc to:");
      Serial.print(odleglosc);
      Serial.println(" mm");
      Serial.println("Stezenie gazu wynosi");
      Serial.print (voltage);
      Serial.print ("  ");

    }
if (voltage <= 0.49) {
    ppm = 100;
   }
else if  (voltage > 0.49 && voltage <=1.18) {
    ppm = 1000;
   } 
else if  (voltage > 1.18 && voltage <=2.1) {
    ppm = 10000;
   }  
    delay (1000);
}

