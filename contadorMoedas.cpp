#include <LiquidCrystal.h>
// definições das portas LCD
LiquidCrystal lcd(4,5,6,7,8,9,10);
// definições das variaveis que iram guardar a quantidade de moedas
int contUm = 0;
int contDois = 0;
int contTres = 0;

// variaveis que irão guardar o sinal do sensor infravermelho 
int leituraDez;
int leituraCinquenta;
int leituraCem;
void setup ( ) {
  //inicia o painel lcd e seta as posições onde serão mostrados os prints dos valores usados
  		lcd.begin(16, 2);
  		lcd.setCursor(0,0); 
  		lcd.print("-0,10:");
  		lcd.setCursor(8,0);
  		lcd.print("-0,50:");
  		lcd.setCursor(0,1);
  		lcd.print("-1,00:");
  		
  // portas de entrada que receberam os sinais dos tres sensores
  		pinMode(13,INPUT);
  		pinMode(12,INPUT);
  		pinMode(11,INPUT);
  // portas de saida ligadas a led's para mostrar que as moedas foram contadas
  		pinMode(1,OUTPUT);
  		pinMode(2,OUTPUT);
  		pinMode(3,OUTPUT);
}
        
void loop ( ) {
  	//leitores de sinal 
  	leituraDez = digitalRead(13);
   	leituraCinquenta = digitalRead(12);
  	leituraCem = digitalRead(11);
 // caso o sinal seja alto, entrara e fará a contagem da moeda
  if (leituraDez == HIGH){	
  	digitalWrite(1,HIGH);
        contUm ++;
    for( int i = 0; i<= contUm; i++){ // esse loop serve para garantir que apenas uma moeda tenha caido, pois existe uma propagação da transmissão do sinal (aparentemente XD)
      
      delay(1000);
      lcd.setCursor(6,0); // posição onde a  quantidade sera exibida
      lcd.print(contUm);
      digitalWrite(1,LOW);
    }
    delay(10);
   
   
  }if(leituraCinquenta == HIGH){
   	digitalWrite(2,HIGH); 
   	contDois ++;
    for(int i = 0; i<= contDois; i++){
      delay(1000);
      lcd.setCursor(14,0);
      lcd.print(contDois);
      digitalWrite(2,LOW);
    }
	delay(10);
      
    
  }if(leituraCem == HIGH){
    digitalWrite(3,HIGH);
    contTres ++;
    for(int i = 0; i<= contTres; i++){
      delay(1000);
      lcd.setCursor(6,2);
      lcd.print(contTres);
      digitalWrite(3,LOW);
    }
    
   
    delay(10);
    
  }
}
  
