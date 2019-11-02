bool state=0;
char message [3] = {'H','I','!'};

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  while(!Serial){ 
  }
  Serial.println(message);
  Serial.println("Mkr1000 recieving");
}

void loop() {
  if (Serial.available()){
    recieveSerial();
    checkMessage();
  }
  digitalWrite(LED_BUILTIN,state);
}

void recieveSerial(){
  message[0]=message[1];
  message[1]=message[2];
  message[2]=Serial.read();
}

void checkMessage(){
  if(message[0]=='O' && message[1]=='F' && message[2]=='F'){
    Serial.println("LED OFF");
    state=0;
  }else if(message[1]=='O' && message[2]=='N'){
    Serial.println("LED ON");
    state=1;
  }
}
