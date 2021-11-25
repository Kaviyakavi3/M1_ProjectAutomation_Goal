#include<stdio.h>
#define Password_Length 7 // Give enough room for six chars + NULL char

    char Data[Password_Length]; // 6 is the number of chars it can hold + the null
	char Master[Password_Length] = "123456";
	int data_count = 0;
	int master_count = 0;
    bool Pass_is_good;
	char key;
	int motorPin = 10;
    int ROWS = 4;
    int COLS = 3;
    int keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

int rowPins[ROWS] = { 5,4,3,2}; //connect to the row pinouts of the keypad
int colPins[COLS] = { 8,7,6}; //connect to the column pinouts of the keypad

void cdata() {
	while(data_count!=0)
	{
        Data[data_count--]=0;
    }
    return;
=void SendMessage(){
	mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
	delay(1000); // Delay of 1000 milli seconds or 1 second
	mySerial.println("AT+CMGS=\"+919080208409\"\r"); // Replace x with mobile number
	delay(1000);
	mySerial.println("I am SMS from GSM Module");// The SMS text you want to send
	delay(100);
	mySerial.println((char)26);// ASCII code of CTRL+Z
	delay(1000);
}

	Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS,
COLS );//initialize an instance of class NewKeypad

void setup(){
	Serial.begin(9600);
	Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)
	delay(100);

    pinMode(motorPin,OUTPUT);
}
void loop() {
	char key = keypad.getKey();
	digitalWrite(motorPin, HIGH);
    if (key) // makes sure a key is actually pressed, equal to (customKey !=NO_KEY)
    {
		Data[data_count]=key;
		Serial.println(Data[data_count]);// print char at said cursor
		data_count++;
    }
if(data_count== Password_Lenght-1) // if the array index is equal to the
number of expected chars, compare data to master
{
Serial.print("Password is ");
if(!strcmp(Data, Master)) // equal to (strcmp(Data, Master) == 0)
{ Serial.println("Good");
digitalWrite(motorPin, HIGH);}
else
{ Serial.println("Bad");
SendMessage();}
delay(1000);// added 1 second delay to make sure the password is completely
shown on screen before it gets cleared.
cdata();
}}
}
}
