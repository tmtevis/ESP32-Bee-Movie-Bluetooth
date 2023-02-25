#include <WiFi.h>
#include <BluetoothSerial.h>
#include <FS.h>
#include <SPIFFS.h>
#define FORMAT_SPIFFS_IF_FAILED true

BluetoothSerial SerialBT;

void sendBees() {
    Serial.println("sendFileContents() called");
    File file = SPIFFS.open("/Bee_Movie_Script.txt");
    Serial.println(file.readString());
    if (!file) {
        Serial.println("Failed to open file");
        return;
    }

    while (file.available()) {
        SerialBT.write(file.read());
        delay(50); // add delay for stability
    }

    file.close();
}

void readFile(fs::FS &fs, const char * path){
   Serial.printf("Reading file: %s\r\n", path);

   File file = fs.open(path);
   if(!file || file.isDirectory()){
       Serial.println("− failed to open file for reading");
       return;
   }

   Serial.println("− read from file:");
   while(file.available()){
      Serial.write(file.read());
   }
}

void setup() {
  // Initialize SPIFFS file system
    delay(5000);
    if(SPIFFS.begin(true)){
        Serial.println("SPIFFS Started...");
    }
    if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){
        Serial.println("An error occurred while mounting SPIFFS");
        return;
    }
    if(SPIFFS.exists("/Bee_Movie_Script.txt")){
        Serial.println("Bee Movie Script UPLOADED");
    }

  // Initialize serial communication
    Serial.begin(115200);

  // Initialize Bluetooth
    SerialBT.begin("Bee Movie Stream");
    Serial.println("Bee Movie Stream started...");
    Serial.println("Waiting for serial connection...");
    readFile(SPIFFS, "/Bee_Movie_Script.txt");
}

void loop() {
    if (SerialBT.available()) {
        String message = SerialBT.readStringUntil('\n');
        message.trim();

        if (message == "start") {
            SerialBT.println("Starting...");
            sendBees();
        }
        else if (message == "pause") {
            return;
      // pause transmission
        }
        else if (message == "restart") {
      // start from the beginning of the text file
            sendBees();
        }
        else if (message == "stop") {
      // end transmission
            SerialBT.disconnect();
            return;
        }
        else if (message == "test"){
            readFile(SPIFFS, "/Bee_Movie_Script.txt");
        }
  }
}


