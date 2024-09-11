#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//encoder pinleri
#define CLK 5
#define DT 6
#define SW 7

//led pini
#define led 3

// değişkenler
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;
int counter = 0;
String currentDir ="";

int menu;
int isik_yogunluk = 0;// light intencity
int i_y = 0;

int dakika,saniye,toplam_zaman;
int say1,say2,say3,say4;
int i,sure;

//secme işareti
byte customChar0[] = {
  B00000,
  B00000,
  B00100,
  B00110,
  B11111,
  B00110,
  B00100,
  B00000
};
// gei dönme işareti 
byte customChar1[] = {
  B00001,
  B00001,
  B00001,
  B00101,
  B01101,
  B11111,
  B01100,
  B00100
};
// saat işareti
byte customChar3[] = {
  B00000,
  B00000,
  B01110,
  B10101,
  B10111,
  B10001,
  B01110,
  B00000
};

void setup() {
  Serial.begin(9600);
  //lcd 
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  lcd.createChar(0, customChar0);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar3);
  //enkoder
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
  lastStateCLK = digitalRead(CLK);
  // led 
  pinMode(led,OUTPUT);
  menu_1_isik_yogunluk_print();
}

void loop() {
  // buton okuma
    int btnState = digitalRead(SW);
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      menu++;
    }
    lastButtonPress = millis();
  }
  
/**************************************** işik yogounlu end ***********/
  if(menu == 1){ // birinci menu işik yogunlu ayarlama
 //encoder okuma
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    if (digitalRead(DT) != currentStateCLK) {
      //counter --;
      i_y = i_y+5;
      //currentDir ="CCW";
    } else {
      i_y = i_y-5;
      //counter ++;
      //currentDir ="CW";
    }

    if(i_y<0){
      i_y =0;
     }
    else if(i_y>255){
      i_y = 255;
    }
    isik_yogunluk = map(i_y,0,255,0,100);
    menu_1_isik_yogunluk_print();
  }
  lastStateCLK = currentStateCLK;
  delay(1);
  }
  /**************************************** işik yogounlu end ***********/
  
  //--------------- dakika ayarlama
    if(menu == 2){
//encoder okuma
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    if (digitalRead(DT) != currentStateCLK) {
      //counter ++;
      dakika ++;
      //currentDir ="CCW";
    } else {
      dakika --;
      //counter --;
      //currentDir ="CW";
    }

    if(dakika<0){
      dakika =0;
     }
    else if(dakika>60){
      dakika = 60;
    }
    menu_2_dakika_print();
  }
  lastStateCLK = currentStateCLK;
  delay(1);
  }
//----------------saniye ayarlama
 if(menu == 3){
//encoder okuma
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    if (digitalRead(DT) != currentStateCLK) {
      //counter ++;
      saniye ++;
      //currentDir ="CCW";
    } else {
      saniye --;
      //counter --;
      //currentDir ="CW";
    }

    if(saniye<0){
      saniye = 0;
     }
    else if(saniye>60){
      saniye = 60;
    }
    menu_3_saniye_print();
  }
  lastStateCLK = currentStateCLK;
  delay(1);
  }
  /********************* ok menu *******************/
  //-----------------ok gecişi
  if(menu == 4){
    menu_4_go_to_ok();
  }
  //----------------- ok başlatma
  if(menu == 5){
    menu_5_enter_in_ok();
  }
  
}//------------------loop end

void menu_1_isik_yogunluk_print(){ //işik yogunlu lcd print function
  lcd.setCursor(0, 0);
  lcd.write(0);
  lcd.print(" I:%");
  lcd.print(isik_yogunluk);
  lcd.print("      ");
  
  lcd.setCursor(0, 1);
  lcd.print("  ");
  lcd.print(dakika);lcd.print(":");lcd.print(saniye);
  lcd.print("  ");

  lcd.setCursor(11, 1);
  lcd.print("  ");
  lcd.print("OK");
}

/***********************************************/
void menu_2_dakika_print(){//dakika lcd print function
  lcd.setCursor(0, 0);
  lcd.print("  I:%");
  lcd.print(isik_yogunluk);
  lcd.print("  ");
  
  lcd.setCursor(0, 1);
  lcd.write(0);
  lcd.print(" ");
  lcd.print(dakika);lcd.print(":");lcd.print(saniye);
  lcd.print("  ");

  lcd.setCursor(11, 1);
  lcd.print("  ");
  lcd.print("OK");
}
/************************************************************/
void menu_3_saniye_print(){ //---------------saniye ayarlama
  lcd.setCursor(0, 0);
  lcd.print("  I:%");
  lcd.print(isik_yogunluk);
  lcd.print("  ");
  
  lcd.setCursor(0, 1);
  lcd.write(0);
  lcd.print(" ");
  lcd.print(dakika);lcd.print(":");lcd.print(saniye);
  lcd.print("  ");

  lcd.setCursor(11, 1);
  lcd.print("  ");
  lcd.print("OK");
}
/***************************** ok geçişi **************/
void menu_4_go_to_ok(){
  lcd.setCursor(0, 0);
  lcd.print("  I:%");
  lcd.print(isik_yogunluk);
  lcd.print("  ");
  
  lcd.setCursor(0, 1);
  lcd.print("  ");
  lcd.print(dakika);lcd.print(":");lcd.print(saniye);
  lcd.print("  ");

  lcd.setCursor(11, 1);
  lcd.write(0);
  lcd.print(" ");
  lcd.print("OK");
}
/*******************************************ok başlama**************/
void menu_5_enter_in_ok(){
  int saat = 0;
  analogWrite(led,isik_yogunluk);
  //toplam_zaman = ((saat*3600 + dakika*60 + saniye)*1000);
  //toplam_zaman = (saat*3600 + dakika*60 + saniye);

  toplam_zaman = (saat*3600 + dakika*60 + saniye);
  if(toplam_zaman>0){
    for(i = 1 ; i<=toplam_zaman; i++){
    if(saniye>0){
      saniye--;
    }
    else{
      if(dakika>0 && saat>0){
        dakika--;
        saniye = 59;
      }
      else if(dakika==0 && saat>0){
          saat--;
          dakika = 60;
        }

      else if(dakika>0 && saat==0){
          dakika--;
          saniye = 59;
        }
       else if(dakika==0 && saat==0){
              if(saniye>0){
                saniye--;
                }
        }
      }
    Serial.print("toplam_zaman : ");Serial.print(toplam_zaman);Serial.print(" | i-->");Serial.print(i);Serial.print(" ");
    Serial.print(saat);Serial.print(":");Serial.print(dakika);Serial.print(":");Serial.println(saniye);

  lcd.setCursor(0, 0);
  lcd.print("  I:%");
  lcd.print(isik_yogunluk);
  lcd.print("  ");
  
  lcd.setCursor(0, 1);
  lcd.write(2);
  lcd.print(" ");
  lcd.print(dakika);lcd.print(":");lcd.print(saniye);
  lcd.print("                ");
    delay(1);// change delay to 1000(1 seconde to get real value)
    }
  }
  
  menu = 0;
  isik_yogunluk = 0;
  saat =0;
  dakika =0;
  saniye = 0;
  toplam_zaman=0;
  menu_1_isik_yogunluk_print();
  analogWrite(led,isik_yogunluk);
}
