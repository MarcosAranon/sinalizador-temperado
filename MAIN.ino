//Importando a biblioteca da DHT
#include "DHTesp.h"
//Definindo a porta que irá receber os dados da temperatura;
const int DHT_PIN = 15;

DHTesp dhtSensor; //Declarando o objeto;

//Estabelecendo as portas digitais das cores do led
const int pinR = 21;
const int pinG = 19;
const int pinB = 18;

//Função para atuar como valor nulo nas operações ternárias
void nada(){}

void setup() {
  //definindo a porta sereal
  Serial.begin(115200);
  //configurando o sensor DHT22 com sua porta
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  //Definindo que as portas das cores do led são de sáida
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);

  //Estabelescendo que o led não reproduxirá nenhuma cor incialmente.
  digitalWrite(pinR, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinB, LOW);
}

//função principal
void loop() {
  //Tempo de 1 segundo para a verificação da temperatura e toda a rotina estabelecida.
  delay(1000);
  //Comando para obter os dados do DHT e armazena-los em variaveis;
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  //Pinta no serial a temperatura obtida para realizção de testes;
  Serial.println("Temperatura: " + String(data.temperature) + "°C");

  //Comandos lógicos para estabelecer a cor de acordo com o intervalo de temperatura
  // Azul para temperatura abaixo de 0°C, amarelo para temperatura entre 0 40°C e vermelho
  // para temperaturas acima de 40°C
  if (data.temperature < 0){
    digitalRead(pinR) == HIGH ? digitalWrite(pinR, LOW) : nada();
    digitalRead(pinG) == HIGH ? digitalWrite(pinG, LOW) : nada();
    digitalRead(pinB) == LOW ? digitalWrite(pinB, HIGH) : nada();
  } else { 
    if (data.temperature <= 40){
      digitalRead(pinR) == LOW ? digitalWrite(pinR, HIGH) : nada();
      digitalRead(pinG) == LOW ? digitalWrite(pinG, HIGH) : nada();
      digitalRead(pinB) == HIGH ? digitalWrite(pinB, LOW) : nada();
    } else {
      digitalRead(pinR) == LOW ? digitalWrite(pinR, HIGH) : nada();
      digitalRead(pinG) == HIGH ? digitalWrite(pinG, LOW) : nada();
      digitalRead(pinB) == HIGH ? digitalWrite(pinB, LOW) : nada();
    }
  }
}
