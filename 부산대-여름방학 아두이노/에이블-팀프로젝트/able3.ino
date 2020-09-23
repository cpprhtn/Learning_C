//작은방,화장실
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "able-2f0cb.firebaseio.com"
#define FIREBASE_AUTH "R07QFZGFl7wLk2pcntScmWtqsIiixp7cOKbIlR1I"
#define WIFI_SSID "iptime-1"
#define WIFI_PASSWORD "mecha7859"

int R3=0;
int G3=0;
int Blue3=0;
int R4=0;
int G4=0;
int Blue4=0;
int fire;
int sound;
void setup() {
  Serial.begin(115200); // 시리얼 통신 초기화
  //LED 3 화장실
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  //LED4 작은방
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(1,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  /*Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());*/
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  //불날시
  fire=Firebase.getString("Gas").toInt();
  if(fire==0)
  {
  analogWrite(13,HIGH);
  analogWrite(12,LOW);
  analogWrite(14,LOW);
  analogWrite(2,HIGH);
  analogWrite(5,LOW);
  analogWrite(1,LOW);
  delay(1000);
  analogWrite(13,LOW);
  analogWrite(2,LOW);
  }
  //소리감지시-갈색
  sound=Firebase.getString("smallroomsound").toInt();
  if(sound==0)
  {
    analogWrite(2,153);
    analogWrite(5,102);
    analogWrite(1,LOW);
    delay(1000);
    analogWrite(13,LOW);
    analogWrite(12,LOW);
    Firebase.setFloat("smallroomsound",1);
  }
  //소리감지시-파란색
  sound=Firebase.getString("bathsound").toInt();
  if(sound==0)
  {
    analogWrite(13,LOW);
    analogWrite(12,LOW);
    analogWrite(14,HIGH);
    delay(1000);
    analogWrite(14,LOW);
    Firebase.setFloat("bathsound",1);
  }
}
