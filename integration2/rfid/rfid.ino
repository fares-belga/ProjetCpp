#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

LiquidCrystal_I2C lcd(0x27, 16, 2);

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;

byte nuidPICC[4];
String cardUID = "";

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Bonjour");
  lcd.setCursor(0, 1);
  lcd.print("smart product");
  delay(2000);
  lcd.clear();
  SPI.begin();          // Init SPI bus
  rfid.PCD_Init();      // Init MFRC522

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {
 // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;



 for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
  printHex(rfid.uid.uidByte, rfid.uid.size);
    //Serial.println();
   rfid.PICC_HaltA();

  // Display the RFID information on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Card UID:");
  lcd.setCursor(0, 1);
  lcd.print(cardUID);
  Serial.println(cardUID);
  Serial.println();
cardUID="";
  // Prompt the user to enter a message on the Serial Monitor
 // Serial.println("Scan complete. Enter a message for the LCD:");

  // Wait for user input
  while (!Serial.available()) {
    delay(100);
  }

  // Read the message from the Serial Monitor
  String message = Serial.readString();

  // Display the message on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Action:");
  lcd.setCursor(0, 1);
  lcd.print(message);
  delay(2000);
}

void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    //Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    //Serial.print(buffer[i], DEC);
    cardUID+=buffer[i];
  }
}