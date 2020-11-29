#include <Servo.h>
#define R 3
#define G 5
#define B 6

Servo indice;
Servo mayor;
Servo anular;
Servo menique;
Servo pulgar;

unsigned long Tiempoentrada = 0;
int sensorValue = 0;
int p1_0s_0_5s = 0;
int p1_0_5s_1s  = 0;
int p1_1s_2s = 0;
int p1_2s_3s = 0;

int p2r2_0s_1s = 0;
int p2r2_1s_2s = 0;
int p2r2_2s_3s = 0;

int p2r3_0s_1s = 0;
int p2r3_1s_2s = 0;
int p2r3_2s_3s = 0;

int Sindice  = 180;;
int Smayor   = 180;;
int Sanular  = 180;;
int Smenique = 180;
int Spulgar  = 70;;

int Mindice  = 0;
int Mmayor   = 0;
int Manular  = 0;
int Mmenique = 0;
int Mpulgar  = 0;



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);

  indice.attach(5);  
  mayor.attach(4);
  anular.attach(3);
  menique.attach(2);
  pulgar.attach(6);
  
  indice.write(180);
  mayor.write(180);
  anular.write(180);
  menique.write(180);

}

// the loop routine runs over and over again forever:
void loop() {
  /*--------------------------------------------------------LOOP------------------------------------------------------*/


  sensorValue = digitalRead(8);
  
  if (sensorValue  == 1){ 
    Tiempoentrada=millis();
    
    while (sensorValue  == 1){
      sensorValue = digitalRead(8);
      Serial.println(sensorValue);
      
      if ((millis() - Tiempoentrada) < 500 ){
        p1_0s_0_5s = 1;
        p1_0_5s_1s = 0;
        p1_1s_2s   = 0;
        p1_2s_3s   = 0;
      }
      
      if ((millis() - Tiempoentrada) > 500 and (millis() - Tiempoentrada) < 1000){
        analogWrite(R,255);
        analogWrite(G,0);
        analogWrite(B,0);
        p1_0s_0_5s = 0;
        p1_0_5s_1s = 1;
        p1_1s_2s   = 0;
        p1_2s_3s   = 0;
      }
      
      if ((millis() - Tiempoentrada) >1000 and (millis() - Tiempoentrada) < 2000){
        analogWrite(R,0);
        analogWrite(G,255);
        analogWrite(B,0);
        p1_0s_0_5s = 0;
        p1_0_5s_1s = 0;
        p1_1s_2s   = 1;
        p1_2s_3s   = 0;
      }
      
      if ((millis() - Tiempoentrada) > 2000){
        analogWrite(R,0);
        analogWrite(G,0);
        analogWrite(B,255);
        p1_0s_0_5s = 0;
        p1_0_5s_1s = 0;
        p1_1s_2s   = 0;
        p1_2s_3s   = 1;
      }
    }
    if(p1_0_5s_1s == 1){
      abrir();
    }
    if (p1_0s_0_5s == 1){
       cerrar();
    }
}




  while(p1_1s_2s == 1){
   sensorValue = digitalRead(8);
  
   if (sensorValue == 1){ 
    Tiempoentrada=millis();
    
    while (sensorValue == 1){
      sensorValue = digitalRead(8);
      Serial.println(sensorValue);
      
      if ((millis() - Tiempoentrada) < 1000){
        analogWrite(R,255);
        analogWrite(G,255);
        analogWrite(B,255);
        p2r2_0s_1s = 1;
        p2r2_1s_2s = 0;
        p2r2_2s_3s = 0;
      }
      
      if ((millis() - Tiempoentrada) >1000 and (millis() - Tiempoentrada) < 2000){
        analogWrite(R,255);
        analogWrite(G,255);
        analogWrite(B,0);
        p2r2_0s_1s = 0;
        p2r2_1s_2s = 1;
        p2r2_2s_3s = 0 ;
      }
      
      if ((millis() - Tiempoentrada) > 2000){
        analogWrite(R,255);
        analogWrite(G,0);
        analogWrite(B,255);
        p2r2_0s_1s = 0;
        p2r2_1s_2s = 0;
        p2r2_2s_3s = 1;
      }
    }
    if(p2r2_0s_1s == 1){
      cilindrico();
      p2r2_0s_1s = 0;
    }
    if(p2r2_1s_2s == 1){
      gancho();
      p2r2_1s_2s = 0;
    }
    if(p2r2_2s_3s == 1) {
      punta();
      p2r2_2s_3s = 0; 
      }
    p1_1s_2s = 0;
}  
  }




  while(p1_2s_3s == 1){
  sensorValue = digitalRead(8);
  
  if (sensorValue == 1){ 
    Tiempoentrada=millis();
    
    while (sensorValue ==1){
      sensorValue = digitalRead(8);
      Serial.println(sensorValue);
      
      if ((millis() - Tiempoentrada) < 1000){
        analogWrite(R,255);
        analogWrite(G,255);
        analogWrite(B,255);
        p2r3_0s_1s = 1;
        p2r3_1s_2s = 0;
        p2r3_2s_3s = 0;
      }
      
      if ((millis() - Tiempoentrada) > 1000 and (millis() - Tiempoentrada) < 2000){
        analogWrite(R,255);
        analogWrite(G,255);
        analogWrite(B,0);
        p2r3_0s_1s = 0;
        p2r3_1s_2s = 1;
        p2r3_2s_3s = 0 ;
      }
      
      if ((millis() - Tiempoentrada) > 2000){
        analogWrite(R,255);
        analogWrite(G,0);
        analogWrite(B,255);
        p2r3_0s_1s = 0;
        p2r3_1s_2s = 0;
        p2r3_2s_3s = 1;
      }
    }
    if(p2r3_0s_1s == 1){
      cerrarpulgar();
      p2r3_0s_1s = 0;
    }
    if(p2r3_1s_2s == 1){
      senalar();
      p2r3_1s_2s = 0;
    }
    if(p2r3_2s_3s == 1) {
      tresdedos();
      p2r3_2s_3s = 0;
      }
    p1_2s_3s = 0;
}  
  }



  analogWrite(R,0);
  analogWrite(G,0);
  analogWrite(B,0);
}


/*------------------------------------FUNCIONES-------------------------------------*/
void mover(){
  pulgar.write (Spulgar);
  indice.write (Sindice);
  mayor.write  (Smayor);
  anular.write (Sanular);
  menique.write(Smenique);
}

void cerrar(){
  Serial.println("cerrar");
  if (Mpulgar  == 1){Spulgar  += 7;}
  if (Mindice  == 1){if(Sindice > 20){Sindice  -= 10;}}
  if (Mmayor   == 1){Smayor   -= 10;}
  if (Manular  == 1){Sanular  -= 10;}
  if (Mmenique == 1){Smenique -= 10;}

  mover();
}

void abrir(){
  Serial.println("abrir");
  Spulgar  = 40;  
  Sindice  = 180;
  Smayor   = 180;
  Sanular  = 180;
  Smenique = 180;

  Mpulgar  = 0;
  Mindice  = 0;
  Mmayor   = 0;
  Manular  = 0;
  Mmenique = 0; 


  mover();
}
//---------------------- P1/1s<t<2s
void cilindrico(){
  Serial.println("cilindrico"); 
  
  Spulgar  = 80;
  Sindice  = 80;
  Smayor   = 80;
  Sanular  = 80;
  Smenique = 100;

  Mpulgar  = 1; 
  Mindice  = 1;
  Mmayor   = 1;
  Manular  = 1;
  Mmenique = 1;


  mover();
}

void gancho(){
  Serial.println("gancho"); 
  Sindice  = 80;
  Smayor   = 80;
  Sanular  = 80;
  Smenique = 100;
  
  Mpulgar  = 0;  
  Mindice  = 1;
  Mmayor   = 1;
  Manular  = 1;
  Mmenique = 1;
  
  mover();

}

void punta(){
  Serial.println("punta");
  
  Spulgar  = 80;
  Sindice  = 50;
  Smayor   = 180;
  Sanular  = 180;
  Smenique = 180;

  Mpulgar  = 1; 
  Mindice  = 1;
  Mmayor   = 0;
  Manular  = 0;
  Mmenique = 0;
 

  mover();
}


//---------------------- P1/2s<t<3s
void cerrarpulgar(){
  Spulgar  = 80;
  Sindice  = 180;
  Smayor   = 180;
  Sanular  = 180;
  Smenique = 180;

  Mpulgar  = 1;  
  Mindice  = 0;
  Mmayor   = 0;
  Manular  = 0;
  Mmenique = 0;

  
  mover();
}

void senalar(){
  Serial.println("senalar"); 
  Spulgar  = 115;
  Sindice  = 180;
  Smayor   = 0;
  Sanular  = 0;
  Smenique = 0;

  Mpulgar  = 0; 
  Mindice  = 0;
  Mmayor   = 0;
  Manular  = 0;
  Mmenique = 0;
 
  
  mover();
}

void tresdedos(){
  Serial.println("tresdedos");   
  Spulgar  = 80;
  Sindice  = 50;
  Smayor   = 50;
  Sanular  = 0;
  Smenique = 0;

  Mpulgar  = 1;  
  Mindice  = 1;
  Mmayor   = 1;
  Manular  = 0;
  Mmenique = 0;


  mover();
}
