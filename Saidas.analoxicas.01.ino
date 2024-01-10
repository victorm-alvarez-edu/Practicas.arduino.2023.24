/* Programa que ilumina con diferentes intensidades un LED.
 * 
 * O programa debe definir un número limitado de niveis
 * de luminosidade e empezando desde 0, subir de luminosidade.
 * Ao chegar ao máximo debe diminuir a luminosidade até 0
 * novamente.
 *
 * Criterios acerca do código:
 * (a) debe ser lexible, 
 * (b) o mantemento debe ser o máis fácil posible
*/

#define LED 11  // Saída analóxica

int tempo = 500; 
int nivel = 0; 
int incremento = 255/255; 

void setup() {
  // As entradas e saídas analóxica non se declaran no setup()
  nivel = 0; 
  Serial.begin(9600); 
}

void loop() {
  Serial.print("Nivel de luminosidade: ");
  Serial.println(nivel);  
  
  analogWrite(LED, nivel); 
  delay(tempo); 
  
  if(nivel + incremento < 0 || nivel + incremento > 255) {
    incremento = -incremento; 
  }
  nivel += incremento;  
}

/* --- PRIMEIRA TENTATIVA ---
#define LED 11  // Saída analóxica

int tempo = 200; 

// Declaración de niveis
int nivel00 = 0; 
int nivel01 = 51; 
int nivel02 = 102; 
int nivel03 = 153; 
int nivel04 = 204; 
int nivel05 = 255; 

void setup() {
  // As entradas e saídas analóxica non se declaran no setup()
}

void loop() {
  analogWrite(LED, nivel00); 
  delay(tempo); 
  analogWrite(LED, nivel01); 
  delay(tempo); 
  analogWrite(LED, nivel02); 
  delay(tempo); 
  analogWrite(LED, nivel03); 
  delay(tempo); 
  analogWrite(LED, nivel04); 
  delay(tempo); 
  analogWrite(LED, nivel05); 
  delay(tempo); 
  analogWrite(LED, nivel04); 
  delay(tempo); 
  analogWrite(LED, nivel03); 
  delay(tempo); 
  analogWrite(LED, nivel02); 
  delay(tempo); 
  analogWrite(LED, nivel01); 
  delay(tempo); 
  analogWrite(LED, nivel00); 
  delay(tempo);
}
 --- FIN PRIMEIRA TENTATIVA --- */
