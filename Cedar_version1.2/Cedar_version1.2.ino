#include <IRremote.h>                  // 引用 IRRemote 函式库
#include <avr/pgmspace.h>
#include <avr/wdt.h>             // flash数据存储
#include <VoiceRecognition.h>    // 语音识别函数库
VoiceRecognition Voice;

// DATA BASE Infra
const PROGMEM unsigned int rawCodes_ac_16c[229]={3124,3004,3132,4408,564,1632,588,512,592,1632,584,472,632,512,592,1628,592,1628,592,508,592,488,616,512,592,508,592,512,592,508,592,512,616,1604,592,508,592,508,596,508,616,1608,588,512,592,508,592,512,616,484,620,484,616,488,612,488,616,488,592,512,612,488,616,484,616,1608,612,488,616,484,616,1604,616,484,620,484,620,484,616,484,620,480,620,488,616,484,616,488,616,1604,616,488,612,484,620,484,616,484,620,484,616,488,616,488,612,484,620,484,616,488,616,488,616,484,616,488,616,484,616,484,620,1604,616,484,616,484,620,484,616,488,616,488,612,488,616,484,616,488,616,488,616,484,616,488,616,484,616,488,616,436,664,456,648,484,616,488,616,488,612,492,612,484,616,488,616,484,616,488,616,484,616,484,620,488,616,484,616,488,616,484,616,488,616,488,612,484,620,484,616,488,616,484,616,488,616,484,616,464,640,488,588,512,592,512,612,484,596,508,592,508,596,1628,592,512,592,1628,592,512,588,516,588,1632,584,516,588,1632,588,1632,588
};  // 16c code
const PROGMEM unsigned int rawCodes_ac_26c[229]={3144,3028,3104,4408,580,1640,584,516,584,1636,584,520,556,548,584,1636,556,1664,584,516,584,1632,588,516,588,1636,584,516,588,520,580,512,592,1636,584,516,584,520,584,516,584,1636,584,516,588,468,636,496,604,516,588,540,560,544,560,516,584,516,588,480,620,512,592,476,624,1640,580,500,604,512,588,1636,584,520,584,516,588,516,584,516,588,516,584,516,584,520,584,520,584,1520,700,516,584,520,584,512,588,516,588,512,588,520,584,516,588,512,588,516,588,512,588,512,588,520,584,516,584,516,588,512,592,1632,588,472,628,520,584,516,588,516,584,516,584,520,584,516,588,516,584,544,560,512,588,520,584,516,560,516,612,496,604,492,612,520,584,480,620,516,608,496,584,520,604,472,628,496,608,496,608,496,608,492,608,492,612,520,580,468,636,496,608,448,652,492,612,492,608,496,608,520,584,488,612,496,608,492,612,492,608,488,616,492,608,516,588,440,664,488,612,492,608,492,556,1620,604,1664,556,1664,556,548,608,1612,556,568,532,1664,556,548,556
};  // 26c code
const PROGMEM unsigned int rawCodes_ac_op[229]={3096,3032,3124,4388,560,1664,556,572,532,1660,560,544,556,548,556,1660,556,1684,540,544,556,548,556,548,552,548,556,548,556,540,560,544,560,1660,560,548,552,552,552,548,556,1660,560,544,556,548,556,548,556,544,612,516,532,508,648,492,612,488,612,492,612,492,608,496,608,1608,556,548,612,492,608,1612,608,492,612,488,612,488,616,492,608,488,616,492,608,496,604,496,608,1608,616,488,612,492,608,496,608,520,584,492,608,496,604,500,604,496,604,492,612,488,616,492,612,488,612,496,604,496,608,492,612,1612,608,492,608,496,608,492,612,488,616,492,608,492,612,492,608,468,636,492,612,484,616,492,612,492,608,492,612,488,612,492,612,488,612,496,608,496,608,488,612,492,556,544,616,484,616,492,612,492,608,472,632,488,612,488,612,492,612,488,616,492,608,492,612,492,608,496,608,472,628,488,616,488,612,520,584,492,608,496,608,492,608,488,612,472,632,1612,612,492,608,1612,608,492,612,1612,608,424,676,496,604,1620,604,1612,608,1612,612,1600,564
};  // open code
const PROGMEM unsigned int rawCodes_ac_cl[229]={3096,3040,3124,4408,584,1612,612,484,616,1608,556,548,556,548,552,1660,560,1668,552,552,624,500,528,524,576,520,584,548,556,540,560,552,552,572,528,552,552,548,552,548,556,1664,556,548,552,552,624,476,552,548,556,548,552,552,552,524,648,472,560,572,604,472,556,548,556,1688,528,572,532,572,528,552,552,548,552,552,552,552,548,544,560,548,552,552,552,548,556,544,556,1664,556,544,560,548,552,548,624,480,624,476,556,544,556,548,628,472,556,552,548,544,560,572,608,468,556,548,628,476,552,504,600,1664,556,548,552,548,556,572,528,552,552,548,552,552,552,548,552,576,528,548,552,544,560,544,556,552,552,540,560,548,556,552,548,552,552,552,548,552,552,548,552,548,644,460,552,552,552,548,552,544,560,552,548,552,552,548,552,552,552,548,552,548,556,572,532,540,560,548,552,552,552,548,552,544,560,548,556,548,552,576,528,572,528,552,552,504,600,1664,552,552,552,1668,552,548,552,552,552,548,552,576,528,1668,552,1668,552,552,548,1672,548
};  // close code


int n;
int k;   

int count = 0;
int count_close = 0;
int time_p = 0;

const int buttonstate_op = 8; // open button
const int buttonstate_on = 6;

int val_op = 0;  // Check state
int val_on = 0;  // Check state
int old_val_on = 0; 
int state = 0; 

int val = 0;            //存储获取到的PIR数值
int PIR_sensor = A0;    //指定PIR模拟端口 A0

#include <dht11.h>        // load temp and moisture detector
dht11 DHT11;
#define DHT11PIN 7
void(* resetFunc) (void) = 0; //制造重启命令
 
IRsend irsend;                          // 定义 IRsend 物件来发射红外线讯号
 

void setup()
{
  pinMode(PIR_sensor, INPUT);   //设置PIR模拟端口为输入模式
  pinMode(buttonstate_op,INPUT);
  pinMode(buttonstate_on,OUTPUT);

  pinMode(3, OUTPUT);   
  digitalWrite(3, HIGH);   // 点亮LED测试（需通过手机摄像模式观察） 你可以开始插个led灯来观察led灯是否亮，如果亮就可以换成红外线发射灯了
  delay(3000);             // 等待3秒
  digitalWrite(3, LOW);    // 结束测试

  Serial.begin(9600);    // 温度传感

    Voice.init();//初始化VoiceRecognition模块   
    Voice.addCommand("kai ji",0);                     //添加指令，参数1:指令内容，参数2：指令标签（可重复）
    Voice.addCommand("kai kong tiao",0); 
                                                   //如“北京”和“首都”代表同样含义，则可共用标签。无返回
    Voice.addCommand("guan ji",1);                    //添加指令，参数（指令内容，指令标签（可重复））
    Voice.addCommand("guan kong tiao",1); 
    Voice.start();                                 //开始识别
}


 
void loop()
{
 
  while(1)
  {  
  
  
  
  
    val_op = digitalRead(buttonstate_op);
    if(val_op==LOW)
    {
     digitalWrite(buttonstate_on,HIGH); 
    
      switch(Voice.read())                //判断识别内容，在有识别结果的情况下Voice.Read()会返回该指令标签，否则返回-1
    {
      case 0://若是指令“kai”
      Serial.println("kaiji");
      unsigned int shuzu_op[229];
      for (k = 0; k<229; k++)
    {
      shuzu_op[k] = pgm_read_word_near(rawCodes_ac_op + k);
    }
      irsend.sendRaw(shuzu_op,229, 38);
      Serial.println("open code sended");
      break;
      case 1://若是指令“guan”
      Serial.println("guanji");
      unsigned int shuzu_cl[229];
      for (k = 0; k<229; k++)
    {
      shuzu_cl[k] = pgm_read_word_near(rawCodes_ac_cl + k);
    }
      irsend.sendRaw(shuzu_cl,229, 38);
      Serial.println("close code sended");
      break;   
    }
    wdt_reset();
  
    
    
    val = analogRead(PIR_sensor);                        //DHT11温控模块，获取温湿度
    Serial.println();
    int chk = DHT11.read(DHT11PIN);
    Serial.print("Read sensor: ");
    Serial.print("Humidity (%): ");
    Serial.println((float)DHT11.humidity, 2);
    Serial.print("Temperature (oC): ");
    Serial.println((float)DHT11.temperature, 2);
    delay(2000);          

  digitalWrite(buttonstate_on,LOW);

    
    if(val > 300)       // 人体红外传感数值  有人一般为600+ 没人则为0
    {
    Serial.print("count =");  // count值测试，决定温度区间
    Serial.print((int)count);
    count_close = 0;  // 红外感应关机条件，在有人的时候清零
    time_p = 0;       // 红外感应关机条件，计数器模块，可调节，在val值变化时清零
    
    if((float)DHT11.temperature >= 32.0 and count == 0)
     {
      unsigned int shuzu_16c[229];
    for (k = 0; k<229; k++)
  {
    shuzu_16c[k] = pgm_read_word_near(rawCodes_ac_16c + k);
  }
    irsend.sendRaw(shuzu_16c,229, 38);
    Serial.println("16c code sended");
    count = 5;         //count变为5，不再满足=0条件，使16度代码只发送一次
    //测试count值
    Serial.print("count ="); 
    Serial.print((int)count);
     }
     

    if((float)DHT11.temperature <= 26.0 and count == 0)
    { 
      unsigned int shuzu_26c[229];
    for (k = 0; k<229; k++)
  {
    shuzu_26c[k] = pgm_read_word_near(rawCodes_ac_26c + k);
  }
    irsend.sendRaw(shuzu_26c,229, 38);
    Serial.println("26c code sended");
    count = 3;
    Serial.print("count =");
    Serial.print((int)count);
   }

    if (((float)DHT11.temperature > 26.0) and ((float)DHT11.temperature < 32.0))
      {
      count = 0;
      Serial.print("count =");
      Serial.print((int)count);
      }
    }
    else
    {
      
      if(count_close == 0 and time_p > 75){
      unsigned int shuzu_cl[229];
    for (k = 0; k<229; k++)
  {
    shuzu_cl[k] = pgm_read_word_near(rawCodes_ac_cl + k);
  }
    irsend.sendRaw(shuzu_cl,229, 38);
    Serial.println("Close code sended");
      
      count_close = 5;
      }
      time_p = time_p + 1;
      delay(2000);
      Serial.print("time = ");
      Serial.print(time_p);
      }
    }
      else if(val_op==HIGH)  //------------------------------------------------------
      {
        digitalWrite(buttonstate_on,LOW); 
        //send warm coode
    
      switch(Voice.read())                //判断识别内容，在有识别结果的情况下Voice.Read()会返回该指令标签，否则返回-1
    {
      case 0://若是指令“kai”
      Serial.println("kaiji");
      unsigned int shuzu_op[229];
      for (k = 0; k<229; k++)
    {
      shuzu_op[k] = pgm_read_word_near(rawCodes_ac_op + k);
    }
      irsend.sendRaw(shuzu_op,229, 38);
      Serial.println("open code sended");
      break;
      case 1://若是指令“guan”
      Serial.println("guanji");
      unsigned int shuzu_cl[229];
      for (k = 0; k<229; k++)
    {
      shuzu_cl[k] = pgm_read_word_near(rawCodes_ac_cl + k);
    }
      irsend.sendRaw(shuzu_cl,229, 38);
      Serial.println("close code sended");
      break;   
    }
    wdt_reset();
  
    
    
    val = analogRead(PIR_sensor);                        //DHT11温控模块，获取温湿度
    Serial.println();
    int chk = DHT11.read(DHT11PIN);
    Serial.print("Read sensor: ");
    Serial.print("Humidity (%): ");
    Serial.println((float)DHT11.humidity, 2);
    Serial.print("Temperature (oC): ");
    Serial.println((float)DHT11.temperature, 2);
    delay(2000);          


    
    if(val > 300)       // 人体红外传感数值  有人一般为600+ 没人则为0
    {
    Serial.print("count =");  // count值测试，决定温度区间
    Serial.print((int)count);
    count_close = 0;  // 红外感应关机条件，在有人的时候清零
    time_p = 0;       // 红外感应关机条件，计数器模块，可调节，在val值变化时清零
    
    if((float)DHT11.temperature <= 15.0 and count == 0)
     {
      unsigned int shuzu_16c[229];
    for (k = 0; k<229; k++)
  {
    shuzu_16c[k] = pgm_read_word_near(rawCodes_ac_16c + k);
  }
    irsend.sendRaw(shuzu_16c,229, 38);
    Serial.println("16c code sended");
    count = 5;         //count变为5，不再满足=0条件，使16度代码只发送一次
    //测试count值
    Serial.print("count ="); 
    Serial.print((int)count);
     }
     

    if((float)DHT11.temperature >= 24.0 and count == 0)
    { 
      unsigned int shuzu_26c[229];
    for (k = 0; k<229; k++)
  {
    shuzu_26c[k] = pgm_read_word_near(rawCodes_ac_26c + k);
  }
    irsend.sendRaw(shuzu_26c,229, 38);
    Serial.println("26c code sended");
    count = 3;
    Serial.print("count =");
    Serial.print((int)count);
   }

    if (((float)DHT11.temperature > 15.0) and ((float)DHT11.temperature < 24.0))
      {
      count = 0;
      Serial.print("count =");
      Serial.print((int)count);
      }
    }
    else
    {
      
      if(count_close == 0 and time_p > 75){
      unsigned int shuzu_cl[229];
    for (k = 0; k<229; k++)
  {
    shuzu_cl[k] = pgm_read_word_near(rawCodes_ac_cl + k);
  }
    irsend.sendRaw(shuzu_cl,229, 38);
    Serial.println("Close code sended");
      
      count_close = 5;
      }
      time_p = time_p + 1;
      delay(2000);
      Serial.print("time = ");
      Serial.print(time_p);
      }
      }
  
  } 
}

