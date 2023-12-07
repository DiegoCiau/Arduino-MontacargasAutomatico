// Definición de pines
int VelocidadMotorTraccion = 6;
int VelocidadMotor2 = 5;
int VelocidadMotorElevador = 9;
//motor direccion
int MotorDirA = 4;
int MotorDirB = 7;
// motor traccion
int MotorTraccion1 = 17;
int MotorTraccion2 = 16;
// motor 3
int MotorElevadorA = 18;//
int MotorElevadorB = 19;//
// seguidor de linea 
const int infraseguidor1 = 14;
const int infraseguidor2 = 15;
// ubicacion
const int infraPinClasDer = 2;
const int infraPin4 = 3;
// caja
int infraPinCaja = 8;
//int infraPinCajaArriba = 10;
//0 fondo claro, 1 fondo negro
int valorinfraseguidor1 = 0;
int valorinfraseguidor2 = 0;
int valorinfraclasDer = 0; // derecho
int valorinfraclasIzq = 0; // izquierdo
int valorInfraCaja = 1; // caja
int CajaArriba = 0; // caja

int cajachica =0;
int cajamediana =0;
int cajagrande =0;

// Pins para el sensor ultrasónico HC-SR04
int trigPin = 12;
int echoPin = 13;

// Variables para medir distancias
float distancia;
String tamano;  // Variable para almacenar el tamaño

// Configuración inicial
void setup() {
  Serial.begin(9600);
// Configuramos los sensores
 pinMode(infraseguidor1, INPUT);
 pinMode(infraseguidor2, INPUT);
 pinMode(infraPinClasDer, INPUT);
 pinMode(infraPin4, INPUT);
 pinMode(infraPinCaja, INPUT);
// pinMode(infraPinCajaArriba, INPUT);
 // Establecemos modo de los pines del control de motores
  pinMode(MotorDirA,OUTPUT);
  pinMode(MotorDirB,OUTPUT);
  pinMode(MotorTraccion1,OUTPUT);
  pinMode(MotorTraccion2,OUTPUT);
  pinMode(MotorElevadorA,OUTPUT);
  pinMode(MotorElevadorB,OUTPUT);
  pinMode(VelocidadMotorTraccion, OUTPUT);
  pinMode(VelocidadMotor2, OUTPUT);
  pinMode(VelocidadMotorElevador, OUTPUT);


  // Configuramos los TRES motores a velocidad 150/255
  analogWrite(VelocidadMotorTraccion, 210);//
  analogWrite(VelocidadMotor2, 180);
  analogWrite(VelocidadMotorElevador, 180);

  // Configuramos sentido de giro
  digitalWrite(MotorDirA, LOW);
  digitalWrite(MotorDirB, LOW);
  digitalWrite(MotorTraccion1, LOW);
  digitalWrite(MotorTraccion2, LOW);
  digitalWrite(MotorElevadorA, LOW);
  digitalWrite(MotorElevadorB, LOW);
  // Configuramos las interrupciones para los infrarrojos

  // Configuramos el sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Ejecución continua
void loop() {
  // Leemos el valor de los infrarrojos: 0 - fondo claro y 1 - línea negra
  valorInfraCaja= digitalRead(infraPinCaja);
//  valorInfraCajaarriba=digitalRead(infraPinCajaArriba);
  valorinfraseguidor1 = digitalRead(infraseguidor1);
  valorinfraseguidor2 = digitalRead(infraseguidor2);
  valorinfraclasDer = digitalRead(infraPinClasDer);
  valorinfraclasIzq = digitalRead(infraPin4);

  Serial.println(valorInfraCaja);
//  Serial.println(infraPinCajaArriba);
  Serial.println(valorinfraseguidor2);
  Serial.println(valorinfraseguidor1);
  Serial.println(valorinfraclasDer);
  Serial.println(valorinfraclasIzq);
  Serial.println(CajaArriba);
  
    //linea recta
  if (valorinfraseguidor1 == 0 && valorinfraseguidor2 == 0) {
    CaminoRecto();
  }
  if (valorinfraseguidor1 == 1 && valorinfraseguidor2 == 1) {
    Detener();
  }
  //para caja chica
  if (cajachica == 1 && valorinfraclasDer == 1 && valorinfraclasIzq == 1) {
        //cajamediana == false;
        //cajagrande == false;
        Serial.println("acomodandochica");
        digitalWrite(MotorDirA, HIGH);
        digitalWrite(MotorDirB, LOW);
        delay(1000);
        digitalWrite(MotorTraccion1, HIGH);
        digitalWrite(MotorTraccion2, LOW);
        delay(2000);
        //riel abajo
        digitalWrite(MotorElevadorA,LOW);
        digitalWrite(MotorElevadorB,HIGH);
        delay(50);
        //regreso de lugar
        digitalWrite(MotorDirA, HIGH);
        digitalWrite(MotorDirB, LOW);
        delay(1000);
        digitalWrite(MotorTraccion1, LOW);
        digitalWrite(MotorTraccion2, HIGH);
        delay(2000);
        cajachica = 0;
        CajaArriba=0;
        Serial.println("finchica");
        }
        //para caja mediana
    if (cajamediana == 1 && valorinfraclasDer == 1 && valorinfraclasIzq == 0) {
        //cajachica == false;
        //cajagrande == false;
        Serial.println("acomodandomediana");
        digitalWrite(MotorDirA, HIGH);
        digitalWrite(MotorDirB, LOW);
        delay(1000);
        digitalWrite(MotorTraccion1, HIGH);
        digitalWrite(MotorTraccion2, LOW);
        delay(2000);
        //riel abajo
        digitalWrite(MotorElevadorA,LOW);
        digitalWrite(MotorElevadorB,HIGH);
        delay(50);
        //regreso de lugar
        digitalWrite(MotorDirA, HIGH);
        digitalWrite(MotorDirB, LOW);
        delay(1000);
        digitalWrite(MotorTraccion1, LOW);
        digitalWrite(MotorTraccion2, HIGH);
        delay(2000);
        cajamediana = 0;
        CajaArriba=0;
        Serial.println("finmediana");
        }
        //para caja cajagrande
    if (cajagrande == 1 && valorinfraclasDer == 0 && valorinfraclasIzq == 1) {
        //cajachica == false;
        //cajamediana == false;
        Serial.println("acomodandogrande");
        digitalWrite(MotorDirA, HIGH);
        digitalWrite(MotorDirB, LOW);
        delay(1000);
        digitalWrite(MotorTraccion1, HIGH);
        digitalWrite(MotorTraccion2, LOW);
        delay(2000);
        //riel abajo
        digitalWrite(MotorElevadorA,LOW);
        digitalWrite(MotorElevadorB,HIGH);
        delay(50);
        //regreso de lugar
        digitalWrite(MotorDirA, HIGH);
        digitalWrite(MotorDirB, LOW);
        delay(1000);
        digitalWrite(MotorTraccion1, LOW);
        digitalWrite(MotorTraccion2, HIGH);
        delay(2000);
        cajagrande = 0;
        CajaArriba=0;
        }
  
  if (valorinfraseguidor1 == 0 && valorinfraseguidor2 == 1) {
    Serial.println("linea izquierda");

    // Modificamos sentido de giro de los motores
    digitalWrite(MotorDirA, HIGH);
    digitalWrite(MotorDirB, LOW);
    digitalWrite(MotorTraccion1, HIGH);
    digitalWrite(MotorTraccion2, LOW);
    delay(20);

  }
  if (valorinfraseguidor1 == 1 && valorinfraseguidor2 == 0 ) {
    Serial.println("linea derecha");
    // Modificamos sentido de giro de los motores
    digitalWrite(MotorDirA, LOW);
    digitalWrite(MotorDirB, HIGH);
    digitalWrite(MotorTraccion1, HIGH);
    digitalWrite(MotorTraccion2, LOW);
    delay(25);

  }
  if (valorInfraCaja == 0 && CajaArriba==0) {
    CajaArriba=1;
    Serial.println("caja ");
    // Modificamos sentido de giro de los motores
    digitalWrite(MotorDirA, LOW);
    digitalWrite(MotorDirB, LOW);
    delay(20);
    digitalWrite(MotorTraccion1, HIGH);
    digitalWrite(MotorTraccion2, LOW);
    delay(500);
    
    // Medimos la distancia con el sensor ultrasónico
    distancia = medirDistancia();

    // Determinamos el tamaño basado en los rangos de distancia
    if (distancia >= 9 && distancia <= 10) {
      // RIEL ARRIBA
      digitalWrite(MotorElevadorA, HIGH);
      digitalWrite(MotorElevadorB, LOW);
      delay(200);
      CajaArriba=1;
      tamano="chica";
      cajachica=1;
      cajamediana=0;
      cajagrande=0;
      // Imprimimos el tamaño en el monitor serial
      medicionCaja();
    } else if (distancia >= 6 && distancia <= 8) {
      digitalWrite(MotorElevadorA, HIGH);
      digitalWrite(MotorElevadorB, LOW);
      delay(200);
      CajaArriba=1;
      tamano="cajamediana";
      cajachica=0;
      cajamediana=1;
      cajagrande=0;
      // Imprimimos el tamaño en el monitor serial
      medicionCaja();
    } else if (distancia >= 3 && distancia <= 5) {
      digitalWrite(MotorElevadorA, HIGH);
      digitalWrite(MotorElevadorB, LOW);
      delay(200);
      CajaArriba=1;
      tamano="cajagrande";
      cajachica=0;
      cajamediana=0;
      cajagrande=1;
      // Imprimimos el tamaño en el monitor serial
      medicionCaja();
    }
    else{
      Serial.print("Distancia: ");
      Serial.print(distancia);
      Serial.print("Sin caja");
      CajaArriba=0;
      cajachica=0;
      cajamediana=0;
      cajagrande=0;
     }
   
  } 
}

// Función para medir la distancia con el sensor ultrasónico
float medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee la duración del pulso en el pin ECHO
  float duracion = pulseIn(echoPin, HIGH);

  // Calcula la distancia
  float distancia_cm = duracion * 0.034 / 2;

  return distancia_cm;
}

void CaminoRecto(){
    Serial.println("Linea recta");
    digitalWrite(MotorDirA, LOW);
    digitalWrite(MotorDirB, LOW);
    delay(20);
    digitalWrite(MotorTraccion1, HIGH);
    digitalWrite(MotorTraccion2, LOW);
    delay(100);
    digitalWrite(MotorDirA, LOW);
    digitalWrite(MotorDirB, LOW);
    delay(500);
}
void Detener(){
    //CajaArriba=1;
    Serial.println("Paro");
    digitalWrite(MotorDirA, LOW);
    digitalWrite(MotorDirB, LOW);
    delay(1000);
    digitalWrite(MotorTraccion1, LOW);
    digitalWrite(MotorTraccion2, LOW);
    delay(1000);

}
void medicionCaja(){
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.print(" cm - Tamaño: ");
    Serial.println(tamano);
  }
