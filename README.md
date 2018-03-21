Written by Justin Wagg 10/5/2015.

Button class can be modified to fit an array of inputs, but as written here for a momentary button. The primary function of this code is to modify a counter variable from j_min to j_max. 

An example use is for selecting a position on a menu screen. Each button press could be used to cycle thru the menu from j_min position to j_max position. 

Initialize the class, set the pin number the button is wired on, and the values for j_min to j_max. As the number of button presses exceeds j_max, the counter will be set back to j_min to cylce thru again. 

Standard debounce delay of 50ms can be edited, and the class can be modified to do a number of different things, like executing a function on button press. Rather than incrementing a counter, you can call a function. 


Example:
```
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
```
