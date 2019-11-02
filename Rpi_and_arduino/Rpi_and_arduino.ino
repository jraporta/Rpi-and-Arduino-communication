bool state=0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  while(!Serial){ 
  }
  Serial.println("Mkr1000 receiving");
}

void loop() {
  digitalWrite(LED_BUILTIN,state);
  if (Serial.available()){
    if (state==0){
      if(Serial.find("ON")){
        state=1;
        Serial.print ("I recieved... ");
        Serial.println("ON");
      }
    }else if (state==1){
      if(Serial.find("OFF")){
        state=0;
        Serial.print ("I recieved... ");
        Serial.println("OFF");
      }
    }
  }
}
