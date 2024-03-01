/* 
 * Imos imitar o funcionamento simplificado dunha xanela dun coche.
 *Cando prememos unha vez, o pulsador activa un motor que move o 
 *vidro cara arriba; ao premer unha segunda vez,
 *o pulsador activa outro motor que move o vidro cara abaixo.  
 *  
 * 
 *
 * 
 * 
 * 
 *
 * Autor: Fran Fernández
 * Data: Febreiro de 2024
 * Actualización:
*/

//Declaración dos pins de E/S
#define PULS 8
#define MOTOR1 10
#define MOTOR2 9

bool estado = 0;
int contador = 0;
int partes = 7000/10; 

void setup(){
 pinMode(PULS, INPUT);
 pinMode(MOTOR1, OUTPUT);
 pinMode(MOTOR2, OUTPUT);
 Serial.begin(9600);
 int estado;
}

void loop() {
 if(digitalRead(PULS)) {
   estado = !estado;
   contador = partes; 
 while(digitalRead(PULS)) {
     delay(10);
   }
}
 
  if (contador > 0) {
    if (estado == 0) {
    digitalWrite(MOTOR1, HIGH);
    digitalWrite(MOTOR2, LOW);
    contador--;
    
  }
  else {
   digitalWrite(MOTOR1, LOW);
   digitalWrite(MOTOR2, HIGH);
   contador--;
 }
}
else { 
  digitalWrite(MOTOR1, LOW);
  digitalWrite(MOTOR2, LOW);
 }
  delay(10); 
}
