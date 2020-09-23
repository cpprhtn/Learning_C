//D1보드
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "able-2f0cb.firebaseio.com"
#define FIREBASE_AUTH "R07QFZGFl7wLk2pcntScmWtqsIiixp7cOKbIlR1I"
#define WIFI_SSID "iptime-1"
#define WIFI_PASSWORD "mecha7859"

int gasPin = 12 ;


void setup() {
  Serial.begin(115200); // 시리얼 통신 초기화
  //가스센서
  pinMode(12,INPUT);
  //사운드 센서 - 5개
  pinMode(13, INPUT);
  pinMode(14,INPUT);
  pinMode(2,INPUT);
  pinMode(5,INPUT);
  pinMode(15,INPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  int ad1 = digitalRead(15);
  int ad2 = digitalRead(14);
  int ad3 = digitalRead(5);
  int ad4 = digitalRead(2);
  int ad5 = digitalRead(13);
  Serial.println(gasPin);
  if(ad1==0){
    Firebase.setFloat("bathsound",ad1);
  }
  if(ad2==0)
  {
    Firebase.setFloat ("livingsound",ad2);
  }
  if(ad3==0)
  {
    Firebase.setFloat("bigroomsound",ad3);
  }
  if(ad4==0)
  {
    Firebase.setFloat("smallroomsound",ad4);
  }    
  if(ad5==0)
  {
    Firebase.setFloat ("kitckensound",ad5);
  }
  if(gasPin==0)
  {
   Firebase.setFloat("Gas",gasPin);
  }
}
