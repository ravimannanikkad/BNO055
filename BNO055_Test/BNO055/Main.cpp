/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
//Beginning of Auto generated function prototypes by Atmel Studio
void setup(void );
void loop(void );

//End of Auto generated function prototypes by Atmel Studio

int ledPin = 9; // LED connected to digital pin 9

struct com {
	
	int x_axis;
	int y_axis;
	int z_axis;
	
	};
	
com com_reg;
	
void pwmOut(struct com *data);
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  pinMode(ledPin, OUTPUT); // sets the pin as output
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}

void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  
  
  
  com_reg.x_axis= (int) event.orientation.x;
  com_reg.y_axis= (int) event.orientation.y;
  com_reg.z_axis= (int) event.orientation.z;
  
  /* Display the floating point data */
  Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tX': ");
  Serial.print(com_reg.x_axis);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tY': ");
  Serial.print(com_reg.y_axis);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.print("\tZ': ");
  Serial.print( com_reg.z_axis);
  Serial.println("");
  pwmOut(&com_reg);
  
  delay(100);
}

void pwmOut(struct com *data){
	
	 analogWrite(ledPin, data->x_axis);
}