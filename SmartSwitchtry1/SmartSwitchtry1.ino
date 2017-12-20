const int buttonPin = 2;    
const int ledPin =  13; //hghjfgs    
int ledState = LOW;
boolean buttonState = LOW; 

int pressed=0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  if(debounceButton(buttonState) == HIGH && buttonState == LOW)
  {
    digitalWrite(ledPin, ledState);   // turn the LED on (HIGH is the voltage level)
  ledState=~ledState;
    buttonState = HIGH;
  }
  else if(debounceButton(buttonState) == LOW && buttonState == HIGH)
  {
       buttonState = LOW;
  }
   
}

boolean debounceButton(boolean state)
{
  boolean stateNow = digitalRead(buttonPin);
  if(state!=stateNow)
  {
    delay(10);
    stateNow = digitalRead(buttonPin);
  }
  return stateNow;
  
}/*
int relay = 13;
int pushbutton=2;
int state=HIGH;
int realstate=HIGH;
void setup() {
  pinMode(pushbutton, INPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  if( digitalRead(pushbutton) == HIGH){
    toggel();
    delay(1000);
  }
}
void toggel() {
  digitalWrite(relay, state);
  realstate=state;
  state=!state;
}*/
