#include <IRremote.h>

int voltage[12];
unsigned int i = 0;

IRrecv irrecv(12);
decode_results results;
unsigned long key_value = 0;

//--------------------settingup-------------------------------------

void setup(){
  Serial.begin(9600);
  SetUpPins();
  irrecv.enableIRIn();
  irrecv.blink13(true);
}



void loop(){ 
  TranslateIR();
}

//--------------------functions---------------------------------

void SetUpPins() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

}
//-------------------TranslateIR-----------------------------------------------------
void TranslateIR() {
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
      	  case 0xFD00FF://power
          break;
          case 0xFD807F://vol+
          break;
          case 0xFD40BF://func/stop
          break;
          case 0xFD20DF://|<<
          break;
          case 0xFDA05F://>||
          break ;  
          case 0xFD609F://>>|
          break ;               
          case 0xFD10EF://down arrow
          break ;  
          case 0xFD906F://vol-
          break ;  
          case 0xFD50AF://up arrow
          break ;  
          case 0xFD30CF://0
          break ;
          case 0xFD08F7://1
          methodOne();
          break ;
          case 0xFD8877://2
          methodTwo();
          break ;
          case 0xFD48B7://3
          methodThree();
          break ;
          case 0xFD28D7://4
          methodFour();
          break ;
          case 0xFDA857://5
          methodFive();
          break ;
          case 0xFD6897://6
          break ;
          case 0xFD18E7://7
          break ;
          case 0xFD9867://8
          break ;
          case 0xFD58A7://9
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}

void methodOne()
{
  //1ST PATTERN
  int i;
  
   for(i=1; i<=10; i++)
  {
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);
  delay(100);
  }

  for(i=10; i>=1; i--)
  {
  digitalWrite(i,HIGH);
  delay(100);
  digitalWrite(i,LOW);
  delay(100);
  }
  delay(1000);

}

void methodTwo()
{
  	//2ND PATTERN
      for(i=1; i<=10 ; i++)
    {
    digitalWrite(i,HIGH);
    delay(100);
    }

    for(i=10; i>=1 ; i--)
    {
    digitalWrite(i,LOW);
    delay(100);
    }


    for(i=10; i>=1 ; i--)
    {
    digitalWrite(i,HIGH);
    delay(100);
    }

    for(i=10; i>=1 ; i--)
    {
    digitalWrite(i,LOW);
    delay(100);
    }
    delay(1000);

}

void methodThree()
{
  	//3RD PATTERN			
  
    for(i=1; i<=9 ; i++)
    {
    digitalWrite(i,HIGH);
    delay(100);
    }
    for(i=1; i<=9 ; i++)
    {
    digitalWrite(i,LOW);
    delay(100);
    }

    for(i=9; i>=1 ; i--)
    {
    digitalWrite(i,HIGH);
    delay(100);
    }
    for(i=1; i<=9 ; i++)
    {
    digitalWrite(i,LOW);
    delay(100);
    }
    delay(1000);
    }

void methodFour()
{	
     //4TH PATTERN
  
    for(i=1; i<=6 ; i++)
    {
    digitalWrite(i,HIGH);
    digitalWrite(10-i,HIGH);
    delay(100);
    }
    for(i=1; i<=6 ; i++)
    {
    digitalWrite(i,LOW);
    digitalWrite(10-i,LOW);
    delay(100);
    }
    delay(100);
    for(i=1; i<=6 ; i++)
    {
    digitalWrite(i,HIGH);
    digitalWrite(10-i,HIGH);
    delay(100);
    }
    for(i=5; i>=1 ; i--)
    {
    digitalWrite(i,LOW);
    digitalWrite(10-i,LOW);
    delay(100);
    }
    delay(1000);
}

void methodFive()
{
	//5TH PATTERN

    for(i=1 ; i<=3 ; i++)
    {
    digitalWrite(i,HIGH);
    digitalWrite(i+3,HIGH);
    digitalWrite(i+6,HIGH);
    delay(500/i);
    }
    delay(500);

    for(i=1 ; i<=3 ; i++)
    {
    digitalWrite(i,LOW);
    digitalWrite(i+3,LOW);
    digitalWrite(i+6,LOW);
    delay(500/i);
    }

    delay(1000);

}