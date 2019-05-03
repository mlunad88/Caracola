//Código micro
int volumen;
int salida;
void setup() {
  Serial.begin(9600);
  int i;
  //Encender y apagar todos los LEDS para probar que funcionan
  for(i=5;i<=11;i++){
    pinMode(i,OUTPUT);
  }
  for (i=5;i<=11;i++){
    digitalWrite(i,HIGH);
    delay(100);
  };
  for (i=5;i<=11;i++){
    digitalWrite(i,LOW);
    delay(100);
  };
}



void loop() {
  int rango=0;
  int contador=0;
  int i;
  salida = analogRead(A0);
  volumen = salida*log(salida)/10;
  Serial.println(volumen);
  for (i=5;i<=11;i++){
    contador=contador+1;
    rango=(rango+(contador*volumen)/6);
    if (rango>=0 && rango<=contador*volumen/6){
      digitalWrite(i,HIGH);
    }
  }
  for (i=5;i<=11;i++){
    digitalWrite(i,LOW);
  };
  delay(10);
}
