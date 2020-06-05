#include<Keypad.h>
#include<LiquidCrystal.h>
#include<Wire.h>
#include <SD.h>
#include <SPI.h>
#include <Audio.h>


LiquidCrystal lcd(15,16,18,19,20,21);
char customKey;
const byte ROWS = 5;
const byte COLS = 5;
double first = 0;
double second = 0;
double total = 0;

 int count=0,c,decimal[20];
  long long res=0;
  long long yogi=0;
  int arr=0,deci=0;
  int r=0,x=0;
  int result[20];

//int sine=22;
//int cosine=24;
//int tangent=26;
//int logue=34;
//int arcsin=28;
//int arccos=30;
//int arctan=32;
//int root=36;
int resetpin=38;

int i=0;

char keys[ROWS][COLS] = {
  {'s','o','t','x','y'},
  {'1','2','3','+','z'},
  {'4','5','6','-','e'},
  {'7','8','9','*','l'},
  {'C','0','=','/','r'}
};
byte rowPins[ROWS] = {8,9,10,11,12}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3,4,5,6,7}; //connect to the column pinouts of the keypadvoid setup() {
  // put your setup code here, to run once:
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  digitalWrite(resetpin, HIGH);
  //pinMode(sine,INPUT);
  //pinMode(cosine,INPUT);
  //pinMode(tangent,INPUT);
  //pinMode(logue,INPUT);
  //pinMode(arcsin,INPUT);
  //pinMode(arccos,INPUT);
  //pinMode(arctan,INPUT);
  //pinMode(root,INPUT);
  pinMode(resetpin, OUTPUT); 
  
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TALKING CALCULATOR");
  delay(1000);
  lcd.clear();
  // setup SD-card
  Serial.print("Initializing SD card...");
  if (!SD.begin(13)) {
    Serial.println(" failed!");
    while(true);
  }
  Serial.println(" done.");
  // hi-speed SPI transfers

  // 44100kHz stereo => 88200 sample rate
  // 100 mSec of prebuffering.
  Audio.begin(44100, 100); 
} 
bool isDecimal1=false;
float decimals1=10.0;
bool isDecimal2=false;
float decimals2=10.0;

void loop() {
  W:
  customKey = customKeypad.getKey();
  // put your main code here, to run repeatedly:
  if(customKey)
  {
  lcd.print(customKey);
  }
//*********************sine**********************

     //sine ends
//************ cos******************
   
//cosine ends
//****************tangent**************
 
//tangent ends
//*****************sin inv*********
  
  // sin inverse
  //*******************cos inv**********
  //cosine inverse    
//********************tan inv*************
  //tan inv ends
  //***************log*********************** 
  //****************root***********
  //root ends  
//****************************************  
switch(customKey)
{
  case '0' ... '9':// This keeps collecting the first value until a operator is pressed "+-*/"
    if (isDecimal1==false)
    {
      lcd.setCursor(0,0);
    first = first * 10 + (customKey - '0');
    lcd.print(first);
    }
    else
  {
    lcd.setCursor(0,0);
    first=first+(customKey - '0')/decimals1;
    decimals1=decimals1*10;
    lcd.print(first);
  }
      break;
    
    case '+':
    first = (total != 0 ? total : first);
    A:
    lcd.setCursor(0,1);
    lcd.print("+");
    second = SecondNumber(); // get the collected the second number
    total = first + second;
    lcd.setCursor(0,3);
    break;
    
    case '-':
    first = (total != 0 ? total : first);
    B:
    lcd.setCursor(0,1);
    lcd.print("-");
    second = SecondNumber();
    total = first - second;
    lcd.setCursor(0,3);
    break;

     case '*':
    first = (total != 0 ? total : first);
    C:
    lcd.setCursor(0,2);
    lcd.print("x");
    second = SecondNumber();
    total = first * second;
    
    lcd.setCursor(0,3);
    break;

    case '/':
    first = (total != 0 ? total : first);
    D:
    lcd.setCursor(0,1);
    lcd.print("/");
    second = SecondNumber();
    lcd.setCursor(0,2);

    second == 0 ? lcd.print("Invalid") : total = (float)first / (float)second;
    
    if(second!=0)
      {
        lcd.setCursor(0,3);
      lcd.print(total);
      }
      break;
      
    case '=':
    lcd.print(total);
    equal();
    break;
    
    case 'C':
   total = 0;
     first=0;
    second=0;
    res=0;
    deci=0;
   lcd.clear();
   digitalWrite(resetpin, LOW);
    break;

    case 's':
  
      if(first!=0)
         {
          for(i=0;i<2;i++)
          {
          total=sin(first); 
          }
          first=0;
         } 
    else 
      first=0;
      
    lcd.setCursor(0,2);
    lcd.print("sine");  
    lcd.setCursor(0,3);
    lcd.print(total,4);
    delay(100);
    break;
    
    case 'o':
      
      if(first!=0)
        {
         for(i=0;i<2;i++)
         {
       total=cos(first);
         }
         first=0;
        }
    else 
      first=0; 
   
   lcd.setCursor(0,2);
    lcd.print("cosine");  
    lcd.setCursor(0,3);
    lcd.print(total,4);
    delay(100);
    break;

    case 't':
      
      if(first!=0)
      {
        for(i=0;i<2;i++)
        {
       total=tan(first);
        }
        first=0;
      }
    else 
      first=0; 
    lcd.setCursor(0,2);
    lcd.print("tangent");  
    lcd.setCursor(0,3);
    lcd.print(total,4);
    delay(100);
   break;

   case 'x':
      
      if(first!=0)
      {
        for(i=0;i<2;i++)
        {
       total=asin(first);
        }
        first=0;
      }
    else 
      first=0; 
    lcd.setCursor(0,2);
    lcd.print("sine inv");  
    lcd.setCursor(0,3);
    lcd.print(total,4);
    delay(100);
    break;

    case 'y':
        
      if(first!=0)
      {
        for(i=0;i<2;i++)
        {
       total=acos(first);
        }
        first=0;
      }
    else 
      first=1.57; 
    lcd.setCursor(0,2);
    lcd.print("cosine inv");  
    lcd.setCursor(0,3);
    lcd.print(total,4);
    delay(100);
    break;

    case 'z':
        
      if(first!=0)
      {
        for(i=0;i<2;i++)
        {
       total=atan(first);
        }
        first=0;
      }
    else 
      first=0; 
    lcd.setCursor(0,3);
    lcd.print(total,4);
        break;

    case 'l':
         
      lcd.setCursor(0,2);
      lcd.print("log10");
      if(first!=0)
      { 
        for(i=0;i<2;i++)
        {
       total=log10(first);
        }
        first=0;
      }
    else 
      first=0; 
    lcd.setCursor(0,3);
    lcd.print(total,4);
    break;

    case 'r':
      lcd.setCursor(0,2);
      lcd.print("Square root");
      if(first!=0)
      { 
        for(i=0;i<2;i++)
        {
       total=sqrt(first);
        }
        first=0;
      }
    else 
      first=0; 
    lcd.setCursor(0,3);
    lcd.print(total,4);
    break;
    
   case 'e':
      lcd.setCursor(0,2);
      lcd.print("Exponential");
      if(first!=0)
      { 
        for(i=0;i<2;i++)
        {
       total=exp(first);
        }
        first=0;
      }
    else 
      first=0; 
    lcd.setCursor(0,3);
    lcd.print(total,4);
    break;
}

}
void equal()
{
  lcd.setCursor(15,3);
  lcd.print("AUDIO");
  res=total;
  while(arr<12 && res!=0)
  {
    result[arr]=res%10;
    res=res/10;
    arr++;

  }
 Serial.println(result[0]);
 Serial.println(result[1]);
 Serial.println(result[2]);
 Serial.println(result[3]);
 Serial.println(result[4]);
 Serial.println(result[5]);
 Serial.println(result[6]);
 delay(10);
  for(r=arr-1;r>=0;r--)      //r or i
  {
      c=result[r];
          if(c==0)
          {    
            audio0();
          } 
          if (c==1)
          {   
            audio1();
          }
          if (c==2)
          {
            audio2(); 
          }
          if (c==3)
          {
              audio3();
          }
         if (c==4)
          {
             audio4();
          }
          if (c==5)
          {
              audio5();                 
          }       
          if (c==6)
          {
            audio6();
          }
          if(c==7)
          {
             audio7();
          }
          if (c==8)
          {
            audio8();
          }
          if(c==9)
          {
            audio9();
          }
  }
  decimalpoint();
  
yogi=total*100;
while(deci<2)
{
  decimal[deci]=yogi%10;
  yogi= yogi/10;
  deci++;  
}
for(x=1;x>=0;x--)
{
          if(decimal[x]==0)
          {    
            audio0();
          } 
          if (decimal[x]==1)
          {   
            audio1();
          }
          if (decimal[x]==2)
          {
            audio2(); 
          }
          if (decimal[x]==3)
          {
              audio3();
          }
         if (decimal[x]==4)
          {
             audio4();
          }
          if (decimal[x]==5)
          {
              audio5();                 
          }       
          if (decimal[x]==6)
          {
            audio6();
          }
          if(decimal[x]==7)
          {
             audio7();
          }
          if (decimal[x]==8)
          {
            audio8();
          }
          if(decimal[x]==9)
          {
            audio9();
          }
}
Serial.println("decimal");
Serial.println(decimal[1]);
Serial.println(decimal[0]); 
}
void audio0()
{
     // open wave file from sdcard
                File myFile = SD.open("zero.wav");

                if (!myFile) {
                // if the file didn't open, print an error and stop
                Serial.println("error opening test.wav");
                while (true);
                              }

                const int S = 1024; // Number of samples to read in block
                short buffer[S];

                 Serial.print("Playing 0");
                // until the file is not finished
                while (myFile.available()) {
                // read from the file into buffer
                myFile.read(buffer, sizeof(buffer));

                // Prepare samples
                int volume = 1024;
                Audio.prepare(buffer, S, volume);
                // Feed samples to audio
                Audio.write(buffer, S);

                // Every 100 block print a '.'
                count++;
                if (count == 100) {
                Serial.print(".");
                
                count = 0;
                                  }
                        }
                myFile.close();
               
}
void audio1()
{
  File myFile = SD.open("one.wav");
      
               if (!myFile) {
                // if the file didn't open, print an error and stop
                Serial.println("error opening test.wav");
                while (true);
                }

                const int S = 1024; // Number of samples to read in block
                short buffer[S];

                Serial.print("Playing 1");
                // until the file is not finished
                while (myFile.available()) {
                // read from the file into buffer
                myFile.read(buffer, sizeof(buffer));

                // Prepare samples
                int volume = 1024;
                Audio.prepare(buffer, S, volume);
                // Feed samples to audio
                Audio.write(buffer, S);

                // Every 100 block print a '.'
                count++;
                if (count == 100) {
                Serial.print(".");
                count = 0;
                  }
                  }
                myFile.close();
               
}
void audio2()
{
   File myFile = SD.open("two.wav");
                if (!myFile) {
                // if the file didn't open, print an error and stop
                Serial.println("error opening test.wav");
                while (true);
                }

                const int S = 1024; // Number of samples to read in block
                short buffer[S];

                Serial.print("Playing 2");
                // until the file is not finished
                while (myFile.available()) {
                // read from the file into buffer
                myFile.read(buffer, sizeof(buffer));

                // Prepare samples
                int volume = 1024;
                Audio.prepare(buffer, S, volume);
                // Feed samples to audio
                Audio.write(buffer, S);

                // Every 100 block print a '.'
                count++;
                if (count == 100) {
                Serial.print(".");
                count = 0;
                  }
                  }
                myFile.close();
               
}
void audio3()
{
  File myFile = SD.open("three.wav");
      
              if (!myFile) {
              // if the file didn't open, print an error and stop
              Serial.println("error opening test.wav");
              while (true);
              }

              const int S = 1024; // Number of samples to read in block
              short buffer[S];

              Serial.print("Playing");
              // until the file is not finished
              while (myFile.available()) {
              // read from the file into buffer
              myFile.read(buffer, sizeof(buffer));

              // Prepare samples
              int volume = 1024;
              Audio.prepare(buffer, S, volume);
              // Feed samples to audio
              Audio.write(buffer, S);

              // Every 100 block print a '.'
              count++;
              if (count == 100) {
              Serial.print(".");
               count = 0;
              }
             }
            myFile.close();
}
void audio4()
{
  File myFile = SD.open("four.wav");
      
              if (!myFile) {
              // if the file didn't open, print an error and stop
              Serial.println("error opening test.wav");
              while (true);
              }

              const int S = 1024; // Number of samples to read in block
              short buffer[S];

              Serial.print("Playing");
              // until the file is not finished
              while (myFile.available()) {
              // read from the file into buffer
              myFile.read(buffer, sizeof(buffer));

              // Prepare samples
              int volume = 1024;
              Audio.prepare(buffer, S, volume);
              // Feed samples to audio
              Audio.write(buffer, S);

              // Every 100 block print a '.'
              count++;
              if (count == 100) {
              Serial.print(".");
               count = 0;
              }
             }
            myFile.close();
}
void audio5()
{
  File myFile = SD.open("five.wav");
      
              if (!myFile) {
              // if the file didn't open, print an error and stop
              Serial.println("error opening test.wav");
              while (true);
              }

              const int S = 1024; // Number of samples to read in block
              short buffer[S];

              Serial.print("Playing");
              // until the file is not finished
              while (myFile.available()) {
              // read from the file into buffer
              myFile.read(buffer, sizeof(buffer));

              // Prepare samples
              int volume = 1024;
              Audio.prepare(buffer, S, volume);
              // Feed samples to audio
              Audio.write(buffer, S);

              // Every 100 block print a '.'
              count++;
              if (count == 100) {
              Serial.print(".");
               count = 0;
              }
             }
            myFile.close();
}
void audio6()
{
  File myFile = SD.open("six.wav");
      
              if (!myFile) {
              // if the file didn't open, print an error and stop
              Serial.println("error opening test.wav");
              while (true);
              }

              const int S = 1024; // Number of samples to read in block
              short buffer[S];

              Serial.print("Playing");
              // until the file is not finished
              while (myFile.available()) {
              // read from the file into buffer
              myFile.read(buffer, sizeof(buffer));

              // Prepare samples
              int volume = 1024;
              Audio.prepare(buffer, S, volume);
              // Feed samples to audio
              Audio.write(buffer, S);

              // Every 100 block print a '.'
              count++;
              if (count == 100) {
              Serial.print(".");
               count = 0;
              }
             }
            myFile.close();
}
void audio7()
{
  File myFile = SD.open("seven.wav");
      
              if (!myFile) {
              // if the file didn't open, print an error and stop
              Serial.println("error opening test.wav");
              while (true);
              }

              const int S = 1024; // Number of samples to read in block
              short buffer[S];

              Serial.print("Playing");
              // until the file is not finished
              while (myFile.available()) {
              // read from the file into buffer
              myFile.read(buffer, sizeof(buffer));

              // Prepare samples
              int volume = 1024;
              Audio.prepare(buffer, S, volume);
              // Feed samples to audio
              Audio.write(buffer, S);

              // Every 100 block print a '.'
              count++;
              if (count == 100) {
              Serial.print(".");
               count = 0;
              }
             }
            myFile.close();
}
void audio8()
{
  File myFile = SD.open("eight.wav");
      
              if (!myFile) {
              // if the file didn't open, print an error and stop
              Serial.println("error opening test.wav");
              while (true);
              }

              const int S = 1024; // Number of samples to read in block
              short buffer[S];

              Serial.print("Playing");
              // until the file is not finished
              while (myFile.available()) {
              // read from the file into buffer
              myFile.read(buffer, sizeof(buffer));

              // Prepare samples
              int volume = 1024;
              Audio.prepare(buffer, S, volume);
              // Feed samples to audio
              Audio.write(buffer, S);

              // Every 100 block print a '.'
              count++;
              if (count == 100) {
              Serial.print(".");
               count = 0;
              }
             }
            myFile.close();
}
void audio9()
{
  File myFile = SD.open("nine.wav");
      
              if (!myFile) {
              // if the file didn't open, print an error and stop
              Serial.println("error opening test.wav");
              while (true);
              }

              const int S = 1024; // Number of samples to read in block
              short buffer[S];

              Serial.print("Playing");
              // until the file is not finished
              while (myFile.available()) {
              // read from the file into buffer
              myFile.read(buffer, sizeof(buffer));

              // Prepare samples
              int volume = 1024;
              Audio.prepare(buffer, S, volume);
              // Feed samples to audio
              Audio.write(buffer, S);

              // Every 100 block print a '.'
              count++;
              if (count == 100) {
              Serial.print(".");
               count = 0;
              }
             }
            myFile.close();
}
void decimalpoint()
{
  File myFile = SD.open("point.wav");
      
              if (!myFile) {
              // if the file didn't open, print an error and stop
              Serial.println("error opening test.wav");
              while (true);
              }

              const int S = 1024; // Number of samples to read in block
              short buffer[S];

              Serial.print("Playing");
              // until the file is not finished
              while (myFile.available()) {
              // read from the file into buffer
              myFile.read(buffer, sizeof(buffer));

              // Prepare samples
              int volume = 1024;
              Audio.prepare(buffer, S, volume);
              // Feed samples to audio
              Audio.write(buffer, S);

              // Every 100 block print a '.'
              count++;
              if (count == 100) {
              Serial.print(".");
               count = 0;
              }
             }
            myFile.close();
}


double SecondNumber()
{
  while( 1 )
  {
    customKey = customKeypad.getKey();  
 if(customKey >= '0' && customKey <= '9')
    {
 if (isDecimal2==false)
    {
    lcd.setCursor(0,2);
    second = second * 10 + (customKey - '0');
    lcd.print(second);
    }    
   }
   if(customKey == '=') break;  //return second;
  }
   
  return second;
}
