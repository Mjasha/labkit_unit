# labkit_unit
Repository to store documents and unit tests for Labkit


Step No
Action 
Expected results

00
Install pyserial, numpy and matplotlib
* pip3 install --user pyserial
* pip3 install --user numpy
* pip3 install --user matplotlib

Install PlatformIO 
* pip install platformio

Install Cygwin
Runtime environment
https://cygwin.com/install.html

Install Visual Studio Code
https://code.visualstudio.com/

Install USB-UART driver from https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers
The required libraries, languages, terminals and programs are installed.
01
Open the github repository https://github.com/jlublin/swt21_fw
Link loaded
02
Clone the github repository https://github.com/jlublin/swt21_fw
The repository was cloned to a test PC
03
Open the github repository 
https://github.com/Mjasha/labkit_unit
Link loaded
04
Clone the github repository 
https://github.com/Mjasha/labkit_unit
The repository was cloned to a test PC
05
Open folder “swt21_fw” cloned repository from step No 02 on test PC 
File opened
06
Replace file Platformio.ini from folder “labkit_unit” (step No 04) in folder “swt21_fw” (Step No 05)
The file is being replaced
07
Replace folder test from folder “labkit_unit” (step No 04) in folder “swt21_fw” (Step No 05)
The folder is being replaced
08
Open Cygwin Terminal
Terminal opened
09
In Terminal, go to the source code folder “swt21_fw”
Folder found and opened
10
Enter command 
* pio test
The program will build, load, test and give the result (PASSED or NOT PASSED).

The result of three tests should be displayed:
test_parse_message, 
test_parse_message_remote
test_transmit




