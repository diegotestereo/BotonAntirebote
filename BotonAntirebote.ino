const int boton=A0;
const int led=13;

const int tiempoAntirebote=20;
int cuenta=0;
boolean estadoBoton=false;
boolean estadoBotonAnterior=false;
 boolean state=false;

 
boolean antirebote(int pin){
  int contador=0;
  boolean estado=false;
  boolean estadoAnterior=false;
  
  do{
    estado=digitalRead(pin);
    if(estado != estadoAnterior){
     
      contador=0;
      estadoAnterior=estado;      
      }
     else{
      contador++;
      
      }
      delay(1);
     }while(contador < tiempoAntirebote);

    return estado;
  }


void setup() {
 Serial.begin(115200);
 pinMode(boton,INPUT);pinMode(13,OUTPUT);
}

void loop() {
  estadoBoton=digitalRead(boton);

  if(estadoBoton!=estadoBotonAnterior){

    state = antirebote(boton);
    if(state){
      cuenta++;
      
     Serial.println(cuenta);
     digitalWrite(13,true);
    
      }else{
      cuenta++;
      
     Serial.println(cuenta);
     digitalWrite(13,false);
    
      }
       
    }
  
  estadoBotonAnterior=estadoBoton;
}
