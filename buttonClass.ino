
class Button
{
    //class variables
    //initialized at start
    int buttonPin;

    //state variables
    int buttonState;
    int lastButtonState;

  public: int j; //current button state
    int j_max;  //max button counter
    int j_min;  //min button counter

    long lastDebounceTime; 
    long debounceDelay;

    //constructor - creates a button and initializes member variables and states
  public:
    Button(int pin, int min_, int max_)
    {
      buttonPin = pin;
      pinMode(buttonPin, INPUT);

      j = min_;
      j_min = min_;
      j_max = max_;

      lastDebounceTime = 0;
      debounceDelay = 50;
    }

    void Update() {
      // read the state of the switch into a local variable:
      int reading = digitalRead(buttonPin);

      if (reading != lastButtonState) {
        // reset the debouncing timer
        lastDebounceTime = millis();
      }

      if ((millis() - lastDebounceTime) > debounceDelay) {


        // if the button state has changed:
        if (reading != buttonState) {
          buttonState = reading;

          // only toggle the LED if the new button state is HIGH
          if (buttonState == HIGH) {
            //            ledState = !ledState;

            if (j < j_max) {
              j++;
            }
            else {
              j = j_min;
            }

          }
        }
      }

      lastButtonState = reading;
    }

};

//initialize buttons, set the pin the button is on, and the range of counting variables
//button name(pin , min_counter, max_counter);
Button button1(38, 0, 2);
Button button2(31, 0, 7);

int lastButton1;
int lastButton2;

void setup() {

}

void loop() {
//call button class - will auto update and initialize all variables.
  button1.Update();
  button2.Update();

//take the button value into variables
    lastButton1 = button1.j;
    lastButton2 = button2.j;
 


}

