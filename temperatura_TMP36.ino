// C++ code
//Programa para monitorear el nivel de temperatura mediante un sensor tmp36
//
#include <Servo.h>

#define led_salida 12
#define temp_in A0
#define piezo 7


Servo myservo;  //creamos un objeto servo 
int sensTemp;   // entero 20 - 358 segun el sensor
float valorTemp;  // °C

void setup()
{
  myservo.attach(6);  // asignamos el pin 6 al servo.

  pinMode(led_salida, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(temp_in, INPUT);
  
  Serial.begin(9600);
}

void loop(){

  sensTemp = analogRead(temp_in);
  valorTemp = map(sensTemp, 20, 358, -40, 125);
  Serial.println(valorTemp);
  Serial.println("*C");
  
  if((valorTemp >= 50) && (valorTemp <= 60)){
  	Serial.println("!Temperatura Demasiado Alta!");
    digitalWrite(LED_BUILTIN,HIGH);
    

  }else if(valorTemp > 60){
    myservo.write(90);

    digitalWrite(led_salida,HIGH);
	digitalWrite(piezo, HIGH);

    Serial.println("!Alerta, Personal en Peligro!");

  } else {
    myservo.write(0);

	digitalWrite(led_salida, LOW);
    digitalWrite(piezo,LOW);
    digitalWrite(LED_BUILTIN,LOW);

    Serial.println("Temperatura Normal");
    
  }
  

}
