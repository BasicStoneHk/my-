#include<SoftwareSerial.h>
SoftwareSerial Bt(10,11);
void setup() {
 Bt.begin(9600);
 Serial.begin(9600);
}
 

void loop()
{
  String m=Bt.readString();
  int a=analogRead(A0);
  Serial.println(a);
  delay(500);
 
 
   if(a>999)            //조도값 999초과시 소리가 나도록 설계
    {
     Bt.write("일어나");  //일어나라는 값을 블루투스를 통해 보낸다.
     tone(4,659,500);    //도가 0.6초 후 반복하도록 설정
     delay(600);
    }
    
    if(m.indexOf("off")==0) //알람끄기 버튼을 누른다면 off를 보내고 알람을 끄게됨 하지만 블루투스가 1초딜레이여서 1번 더 시행되고 꺼짐
    {

      noTone(4);            //피에조스피커 끄기 
      while(1)              //반복문 실행 
      {
            Serial.println(a);
            delay(500);
            String m=Bt.readString(); //다시 한번 m.indexOf()값을 초기화 시키기위해서 전 내용들을 다시 반복 시켜보았다. 
              
            if(m.indexOf("on")==0)    //알람켜기 on값이 들어오면 반복문 탈출 설계
            {
            
                 break; 
                               
            }
            
      }
    }
  
         
  
}
