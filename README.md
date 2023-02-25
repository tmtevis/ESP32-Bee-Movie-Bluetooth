# ESP32-Bee-Movie-Bluetooth
 Uses ESP32 BTSerial to send entire script of Bee Movie to connected peer reading from SPIFFS storage.

Prerequisites:

    - Visual Studio Code
        - Arduino Extension
        - PlatformIO Extension


    - ESP32 board -- In my prototype, I used a PICO D4 Kit which can be bought for around $8 without headers: https://www.amazon.com/Espressif-ESP32-PICO-KIT-Development-Board/dp/B09D3V2VSN/


    - Movie script sourced from: https://stockq.org/moviescript/  where you can find thousands of scripts to alter this with - or do something else with the project.  It's your choice, really.




Loading SPIFFS (Serial Peripheral Interface Flash File System) with your Bee Movie script:
        
        - After the Arduino extension is installed, check the bottom right of VS Code to configure the settings for programming your board
                
                - Choose the COM port it is connected to via USB
                
                - Choose the type of board -- in my case, I am using a ESP32 PICO-D4 with approx. 4MB SPIFFS memory
                
                - Choose the Arduino program to flash if it isn't already defaulted to "BEE-MOVIE-ESP32.ino"
                
                - Choose the programmer if it isn't already defaulted to "Esptool"
        
        
        - Click on the PlatformIO button on the toolbar found on the left side of VS Code after you've installed the extension
        
        
        - Click "Open Project" and navigate to where you saved this repository to
                
                - This might take a few minutes while dependencies are installed
        
        
        - Under the Project Tasks left sidebar menu of PlatformIO, navigate to the Platform folder
        
        
        - Click "Build Filesystem Image" to capture the files placed in the "data" folder of the PlatformIO project
        
        
        - Next, click "Upload Filesystem Image" to upload the contents of the "data" folder to the ESP32




Loading the program onto the ESP32:

        - After initializing SPIFFS and loading the script (or other files) onto your ESP32 module
        
        
        - In the Explorer (Ctrl + Shift + E), open 'BEE-MOVIE-ESP32.ino'
        
        
        - Press (Ctrl + Alt + R) to begin Verifying the Arduino sketch prior to uploading
                
                - The check-mark button in the top right can also be used
        
        
        - Press (Ctrl + Alt + U) to Upload the Arduino sketch to your ESP32 device
                
                - The down-arrow button in the top right can also be used
        
        
        - Check the Serial Monitor tab on the COM port you are programming using a baud rate of 115200 right after uploading to check that the print statements shown on network startup appear




Interacting with the device:
        
        - Now that it is flashed with the BEE-MOVIE-ESP32.ino sketch which relies on the SPIFFS storage of the Bee Movie script, connect with the device using any Bluetooth serial-supporting device
                
                - I use my Galaxy S22 with an app called "Serial Bluetooth Terminal"
                
                - A PC/laptop would work too if you used PuTTY and selected "serial" and the COM port which your ESP32 is connected
                        
                        - To check which COM port is being used, go to Settings->Bluetooth->More Bluetooth Settings->COM Ports tab and look for "Bee Movie Stream"
        
        
        - With your Bluetooth enabled device, scan for a network called "Bee Movie Stream" and connect.
        
        
        - Once paired and connected via Bluetooth serial, send the message "start" to begin streaming the entire script of the Bee Movie until completion. Go ahead, unpair and pair again -- it's still playing.





![image](https://user-images.githubusercontent.com/57959739/221375454-e5a51483-754a-42cc-bc20-41e8e0ef5f8a.png)



