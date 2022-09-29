//costant variables
const int  Up_buttonPin   = 2;    // the pin that the pushbutton is attached to
const int  Down_buttonPin = 3;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses

int up_buttonState = 0;         // current state of the up button
int up_lastButtonState = 0;     // previous state of the up button

int down_buttonState = 0;         // current state of the up button
int down_lastButtonState = 0;     // previous state of the up button

bool bPress = false; // for registering button press

//LED variables
int ledOK = 7;
int ledWarning = 8; 
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int led5 = 13;

void setup()
{
   Serial.begin(9600);

   //Assign pin OUTPUTS
   pinMode(ledOK, OUTPUT);
   pinMode(ledWarning, OUTPUT);
   pinMode(led1, OUTPUT); 
   pinMode(led2, OUTPUT); 
   pinMode(led3, OUTPUT); 
   pinMode(led4, OUTPUT); 
   pinMode(led5, OUTPUT);

   //Assign pin INPUTS
   pinMode( Up_buttonPin , INPUT_PULLUP);
   pinMode( Down_buttonPin , INPUT_PULLUP);
}


void loop()
{
   //Call functions for button clicks
   checkUp();
   checkDown();

   if( bPress)
   {
    //Reset bpress
    bPress = false;

    //Ouput correct level & Warning light
    if(buttonPushCounter < 0)
    {
      digitalWrite(ledOK,LOW);
      digitalWrite(ledWarning,HIGH);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
    }
    if(buttonPushCounter == 0 )
    {  
      digitalWrite(ledOK,LOW);
      digitalWrite(ledWarning,HIGH);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
    }
    if(buttonPushCounter == 1 )
    {  
      digitalWrite(ledOK,LOW);
      digitalWrite(ledWarning,LOW);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
    }  
    if(buttonPushCounter == 2 )
    {  
      digitalWrite(ledOK,LOW);
      digitalWrite(ledWarning,LOW);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
    }  
    if(buttonPushCounter == 3 )
    {
      digitalWrite(ledOK,LOW);
      digitalWrite(ledWarning,LOW);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,LOW);
    }  
    if(buttonPushCounter == 4 )
    {
      digitalWrite(ledOK,HIGH);
      digitalWrite(ledWarning,LOW);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
    }
  }
}


//Checks for Up button clicks
void checkUp()
{
  //define current state
  up_buttonState = digitalRead(Up_buttonPin);

  // compare the buttonState to its previous state
  if (up_buttonState != up_lastButtonState) 
  {
    // if the state has changed, increment the counter
    if (up_buttonState == LOW)
    {
      //change bool value for main loop
      bPress = true;
        
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
    }

    // Delay a little bit to avoid bouncing
    delay(50);

  }

  // save the current state as the last state, for next time through the loop
  up_lastButtonState = up_buttonState;

}

//Check for Down button clicks
void checkDown()
{
  //define current state
  down_buttonState = digitalRead(Down_buttonPin);

  // compare the buttonState to its previous state
  if (down_buttonState != down_lastButtonState)
  {
    // if the state has changed, increment the counter
    if (down_buttonState == LOW) 
    {
      //change bool value for main loop
      bPress = true;

      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter--;
    }

    // Delay a little bit to avoid bouncing

    delay(50);

  }

  // save the current state as the last state, for next time through the loo
  down_lastButtonState = down_buttonState;

}
