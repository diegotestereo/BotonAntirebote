const int boton=A0;
const int tiempoAntirebote=20;
const int led=13;
int cuenta=0;
int estadoBoton;
int estadoBotonAnterior;

boolean antirebote(int pin){
  int contador=0;
  boolean estado;
  boolean estadoAnterior;
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
 pinMode(boton,INPUT);
}

void loop() {
  estadoBoton=digitalRead(boton);

  if(estadoBoton!=estadoBotonAnterior){
    if(antirebote(boton)){
      cuenta++;
      
     Serial.println(cuenta);
     
    
      }
       
    }
    estadoBotonAnterior=estadoBoton;
}
