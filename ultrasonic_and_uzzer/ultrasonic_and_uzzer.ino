/*
  Coded by : Electronics RnD Department @ ROBOTRONiX Engineering Tech Pvt. LTD.
  For more project ideas and details, contact us at ec.robotronix01@gmail.com
*/
//
//#include <WiFi.h>
//#include <ThingSpeak.h>

const int trigPin = 12; //Trigger Pin
const int echoPin = 13; //Echo Pin
const int buzzer = 32;  //Buzzer Positive terminal
//const char* ssid = "haris"; //Enter your Wi-Fi Name
//const char* pass = "12345678";  //Enter your Wi-Fi password
//unsigned long myChannelNumber = Put your thingspeak channel id here; //Enter your Thingspeak channel id
//const char * myWriteAPIKey = "Put your write API key here";
//WiFiClient client;

long duration;
int distance;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echoPin, INPUT);
  
//
//  Serial.print("Connecting to Wi-Fi : ");
//  Serial.println(ssid);
//  WiFi.begin(ssid, pass);
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    delay(500);
//    Serial.print(".");
//  }
//   Serial.println("");
//   Serial.println("WiFi connected\n");
//   delay(500);
//   ThingSpeak.begin(client);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm.");
  Serial.println("\n...Sending data to cloud...\n");
  Serial.println("------------------------------------------------------------------------------------------\n");
  delay(500);
//  ThingSpeak.setField(1, distance);
//  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
//  delay(5000); 
  if(distance > 25)
  {
    digitalWrite(buzzer, LOW);  
  }
  else
  {
    digitalWrite(buzzer, HIGH);
  }
  
}
