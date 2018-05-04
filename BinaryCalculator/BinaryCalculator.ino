//Christian Rios Mancilla
/*
 * A simple binary calculator shows the result by 
 * the serial monitor and in leds it can be easily modified 
 * for the control of qualifications
 */
//Puerto A
int p13 =13;
int p12=12;
int p11=11;

//Puerto B
int p10=10;
int p9=9;
int p8=8;

//Puerto de salida
int p3=3;
int p2=2;
int p1=1;
int p0=0;

//Puertos para banderas
int p4=4;
int p5=5;

//Puertos para operaciones + - * /
int p7=7;
int p6=6;

void setup() {
  // put your setup code here, to run once:
//Puertos de entrada
  Serial.begin(9600);
pinMode(p13,INPUT);
pinMode(p12,INPUT);
pinMode(p11,INPUT);
pinMode(p10,INPUT);
pinMode(p9,INPUT);
pinMode(p8,INPUT);
pinMode(p7,INPUT);
pinMode(p6,INPUT);

//Puertos de salida
pinMode(p5,OUTPUT);
pinMode(p4,OUTPUT);
pinMode(p3,OUTPUT);
pinMode(p2,OUTPUT);
pinMode(p1,OUTPUT);
pinMode(p0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  
  //Serial.println("");
    //Serial.println("Iniciando Programa...");
  //Serial.println("Ingresa el primer Numero");
   delay(1000);
  //Leer datos d elos puertos
 

int num1= leerPuertoA();
  
//Serial.println("Ingresa el segundo Numero");
 delay(1000);
int num2 = leerPuertoB();
  
//leer la operacion seleccionada

 //Serial.println("Operacion a realizar");
delay(1000);
int operacion = leerOperacion();
  
int numDecimal=0;
//Reallizar operaciones
switch (operacion){
  case 1:
//Suma
numDecimal=num1+num2;
//Serial.println("Resultado de la suma:");
 //Serial.println(numDecimal); 
 
mostrarResultado(numDecimal);
  break;
  case 2:
//Resta
numDecimal=num1-num2;
//Serial.println("Resultado de la resta:");
// Serial.println(numDecimal); 
 
mostrarResultado(numDecimal);
  break;
  case 3:
//Multiplicacion
numDecimal=num1*num2;
 //Serial.print("");
//Serial.println("Resultado de la multiplicacion:");
 //Serial.println(numDecimal); 
mostrarResultado(numDecimal);
  break;
  case 4:
//Divicion
numDecimal=num1/num2;
//Serial.println("Resultado de la divicion:");
 //Serial.println(numDecimal); 
mostrarResultado(numDecimal);
  break;

 
}


}

int leerPuertoA(){
  int pins[]={p13,p12,p11};
  int valores[]={1,2,4};
  int num1=0;
for(int i=0;i<3;i ++){
  if(digitalRead(pins[i])==HIGH){
    num1=num1+valores[i];
  }
}
 //Serial.println("Numero 1:");
      //Serial.println(num1);  
      
return num1;
}

int leerPuertoB(){
 int pins[]={p10,p9,p8};
  int valores[]={1,2,4};
  int num2=0;
for(int i=0;i<3;i ++){
  if(digitalRead(pins[i])==HIGH){
    num2=num2+valores[i];
}
}
 //Serial.println("Numero 2:");
     // Serial.println(num2);  
    
return num2;
}

int leerOperacion(){
  if(digitalRead(p7)==LOW && digitalRead(p6) == LOW){
    //Suma
    // Serial.println("Operacion: Suma");
  return 1;
}else if(digitalRead(p7)==HIGH && digitalRead(p6)==LOW){
  //Resta
 // Serial.println("Operacion: Resta");
  return 2;
}else if (digitalRead(p7)==LOW && digitalRead(p6)==HIGH){
  //Multiplicacion
 // Serial.println("Operacion: Multiplicacion");
  return 3;
}else if(digitalRead(p7)==HIGH && digitalRead(p6)==HIGH){
  //Divicion
  //Serial.println("Operacion: Divicion");
 return 4;
}

}

void mostrarResultado(int numDecimal){

if(numDecimal>0 && numDecimal<16){
      int pins[]={p5,p4,p3,p2};
  int cont=0;
  //Serial.println("Resultado:");
  while(numDecimal!=0){
    if(numDecimal% 2 == 1){
      digitalWrite(pins[cont],HIGH);
     // Serial.print("1");
    }else{
        digitalWrite(pins[cont],LOW);
       // Serial.print("0");
    }
    cont++;
    numDecimal=numDecimal/2;
  }
}else{
  if(numDecimal<0){
     digitalWrite(p0,HIGH);
  }
  if(numDecimal>15){
    digitalWrite(p1,HIGH);
  }
  
}
   




delay(10000);

}


