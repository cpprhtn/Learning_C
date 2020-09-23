//부엌, 거실
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "able-2f0cb.firebaseio.com"
#define FIREBASE_AUTH "R07QFZGFl7wLk2pcntScmWtqsIiixp7cOKbIlR1I"
#define WIFI_SSID "iptime-1"   
#define WIFI_PASSWORD "mecha7859"

int R1=0;
int G1=0;
int Blue1=0;
int R2=0;
int G2=0;
int Blue2=0;
int fire;
int sound;
void setup() {
  Serial.begin(115200); // 시리얼 통신 초기화
  //LED 부엌
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  //LED 거실
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(1,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
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
  //소리감지시-초록
  sound=Firebase.getString("kitchensound").toInt();
  if(sound==0)
  {
    analogWrite(13,LOW);
    analogWrite(12,HIGH);
    analogWrite(14,LOW);
    delay(1000);
    analogWrite(12,LOW);
    Firebase.setFloat ("kitckensound",1);

  }
  //소리감지시-보라
  sound=Firebase.getString("livingsound").toInt();
  if(sound==0)
  {
    analogWrite(13,HIGH);
    analogWrite(12,LOW);
    analogWrite(14,HIGH);
    delay(1000);
    analogWrite(13,LOW);
    analogWrite(14,LOW);
    Firebase.setFloat("livingsound",1);
  }

}
