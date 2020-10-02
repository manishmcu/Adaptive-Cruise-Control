
 /* Ultrasonic Sensor HC-SR04 and Arduino */

 // defines pins numbers
 const int trigPin = 9;
 const int echoPin = 10;

 //defines variables
 long duration;
 float d1; float d2;
 float objspeed;
 float myspeed;  //unit km/h and  max speed = 255
 float a;

 void setup() {
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 pinMode(A0,INPUT);
 Serial.begin(9600); // Starts the serial communication
 }

 void loop() {

 a=analogRead(A0);
  
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 d1= duration*0.34/2;
 delay(1000); //delay 1000ms for checking aparent motion 
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 d2= duration*0.34/2; //mm

 myspeed= (a*80)/1023; //5v=1023 & If my vaicle max speed is 80 km/hr
 Serial.print("myspeed: ");
 Serial.println(myspeed);
 myspeed= myspeed/3.6;    //mm/ms

Serial.print(d2);
Serial.println(" mm");
if (d2-d1>150){
objspeed = myspeed+((d2-d1)/1000);
Serial.print("Speeding Up");
 }
if (d2-d1<-150){
objspeed = myspeed-((d1-d2)/1000);
Serial.print("Slowing Down");
 } 
if (-150<=d2-d1<=150){
objspeed = myspeed;
Serial.print("Same Speed");
 }
 
//Serial.print("Speed Triggered: ");
//Serial.println(objspeed);
}
