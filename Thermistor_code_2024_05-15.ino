int Therm1Pin = 0;
int Therm2Pin = 1;
int Therm3Pin = 2;
int Therm4Pin = 3;

int V1, V2, V3, V4;
float R = 10000;
float logR1, R1, T1, T1c, logR2, R2, T2, T2c, logR3, R3, T3, T3c, logR4, R4, T4, T4c;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
}

void loop() {

  V1 = analogRead(Therm1Pin);
  //Serial.print("V1 ");
  //Serial.print(V1);
  R1 = R * (1023.0 / (float)V1 - 1.0); //therm1 res
  logR1 = log(R1);
  T1 = (1.0 / (c1 + c2*logR1 + c3*logR1*logR1*logR1));
  T1c = T1 - 273.15;

  V2 = analogRead(Therm2Pin);
  //Serial.print("V2 ");
  //Serial.print(V2);
  R2 = R * (1023.0 / (float)V2 - 1.0); //therm2 res
  logR2 = log(R2);
  T2 = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T2c = T2 - 273.15;

  V3 = analogRead(Therm3Pin);
  //Serial.print("V3 ");
  //Serial.print(V3);
  R3 = R * (1023.0 / (float)V3 - 1.0); //therm3 res
  logR3 = log(R3);
  T3 = (1.0 / (c1 + c2*logR3 + c3*logR3*logR3*logR3));
  T3c = T3 - 273.15;

  V4 = analogRead(Therm4Pin);
  //Serial.print("V4 ");
  //Serial.print(V4);
  R4 = R * (1023.0 / (float)V4 - 1.0); //therm4 res
  logR4 = log(R4);
  T4 = (1.0 / (c1 + c2*logR4 + c3*logR4*logR4*logR4));
  T4c = T4 - 273.15;
  

  Serial.print("T1: "); 
  Serial.print(T1c);
  Serial.println(" C");   

  Serial.print("T2: "); 
  Serial.print(T2c);
  Serial.println(" C");  

  Serial.print("T3: "); 
  Serial.print(T3c);
  Serial.println(" C");  

  Serial.print("T4: "); 
  Serial.print(T4c);
  Serial.println(" C");  




  delay(5000);
}

