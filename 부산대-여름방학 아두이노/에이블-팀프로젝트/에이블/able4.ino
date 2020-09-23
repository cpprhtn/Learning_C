//큰방

#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "able-2f0cb.firebaseio.com"
#define FIREBASE_AUTH "R07QFZGFl7wLk2pcntScmWtqsIiixp7cOKbIlR1I"
#define WIFI_SSID "iptime-1"
#define WIFI_PASSWORD "mecha7859"

int R5=0;
int G5=0;
int Blue5=0;
String a = "0";
int fire;
int sound;
void setup() {
  Serial.begin(115200); // 시리얼 통신 초기화
  //LED 센서
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
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
  delay(1000);
  analogWrite(13,LOW);
  }
  //소리감지시-노랑
  sound=Firebase.getString("bigroomsound").toInt();
  if(sound==0)
  {
    analogWrite(13,HIGH);
    analogWrite(12,HIGH);
    analogWrite(14,LOW);
    delay(1000);
    analogWrite(13,LOW);
    analogWrite(12,LOW);
    Firebase.setFloat("bigroomsound",1);

  }
}
