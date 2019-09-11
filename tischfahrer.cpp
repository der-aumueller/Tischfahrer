int Abstand;
int ir_sensor=A0;//Sensor an Analog 0
int richtungA           =12;  //Richtung Motor A an Pin 12
int pwmA                =3;   //Geschwindigkeit Motor A an Pin 3
int bremseA             =9;   //Bremse Motor A an Pin 9
int richtungB           =13;  //Richtung Motor B an Pin 13
int pwmB                =11;  //Geschwindigkeit Motor B an Pin 11
int bremseB             =8;   //Bremse Motor B an Pin 8
int geschwindigkeit   =180;   //Maximalgeschwindigkeit Motor A festlegen
void setup() {
  Serial.begin(9600);
  pinMode(richtungA, OUTPUT);   //Richtung A als Output deklarieren
  pinMode(richtungB, OUTPUT);   //Richtung B als Output deklarieren
  pinMode(bremseA, OUTPUT);     //Bremse A als Output deklarieren
  pinMode(bremseB, OUTPUT);     //Bremse B als Output deklarieren
  analogWrite(pwmA, geschwindigkeit);   //
  analogWrite(pwmB, geschwindigkeit);
  
  digitalWrite(bremseA, HIGH);  //Motor A aus
  digitalWrite(bremseB, HIGH);  //Motor B aus
  delay(1000);

}

void loop() {
  Abstand=analogRead(ir_sensor);
  
  delay(10);

if (Abstand<150) {//Wenn Abstandswert kleiner als 150
  digitalWrite(bremseA, HIGH);//Motor A aus
  digitalWrite(bremseB, HIGH);//Motor B aus
  delay(500);//500ms warten
  digitalWrite(bremseA, LOW);//Bremse A lösen
  digitalWrite(bremseB, LOW);//Bremse B lösen
  digitalWrite(richtungA, HIGH);//Motor A vorwärts(d.H. Fahrzeug rückwärts)
  digitalWrite(richtungB, HIGH);//Motor B vorwärts
  delay(1000);//eine Sekunde warten
  digitalWrite(bremseA, HIGH);//Motor A aus
  digitalWrite(bremseB, HIGH);//Motor B aus
  delay(1000);//eine Sekunde warten
  digitalWrite(bremseA, LOW);//Bremse A lösen
  digitalWrite(bremseB, LOW);//Bremse B lösen
  digitalWrite(richtungA, LOW);//Motor A rückwärts
  digitalWrite(richtungB, HIGH);//Motor B vorwärts (Fahrzeug dreht)
  delay(1000);//eine Sekunde warten
  
  }
else//ansonsten 
  digitalWrite(bremseA, LOW);//Bremse A lösen
  digitalWrite(bremseB, LOW);//Bremse B lösen
  digitalWrite(richtungA, LOW);//Motor A rückwärts
  digitalWrite(richtungB, LOW);//Motor B rückwärts (Fahrzeug fährt vorwärts)

}
