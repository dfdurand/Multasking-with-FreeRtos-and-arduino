#include <Arduino_FreeRTOS.h>

#define red 7
#define green 8
#define btn 2

// define two tasks for Blink & AnalogRead
void TaskBlink( void *pvParameters );
void TaskBlink2( void *pvParameters );

TaskHandle_t task1_handle = NULL;
TaskHandle_t task2_handle = NULL;
// TaskHandle_t task3_handle = NULL;

// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(btn, INPUT_PULLUP);
  // pinMode(red, OUTPUT);
  
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

  // Now set up two tasks to run independently.
  xTaskCreate(
    TaskBlink
    ,  "Blink red "   // A name of task
    ,  128  // This stack size 
    ,  NULL
    ,  2  // Priority
    ,  &task1_handle
    );

  xTaskCreate(
    TaskBlink2
    ,  "blink green"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  &task2_handle 
    );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{

  int sensorVal = digitalRead(btn);

  if (sensorVal == LOW) {


    vTaskSuspend(task1_handle);


  } else {


    vTaskResume(task1_handle);


  }

  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
 
  pinMode(red, OUTPUT);
  // Serial.println (xPortGetCoreID());

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}

void TaskBlink2(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  pinMode(green, OUTPUT);
  // Serial.println (xPortGetCoreID());
  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}

























// void TaskAnalogRead(void *pvParameters)  // This is a task.
// {
//   (void) pvParameters;
  
// /*
//   AnalogReadSerial
//   Reads an analog input on pin 0, prints the result to the serial monitor.
//   Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
//   Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

//   This example code is in the public domain.
// */

//   for (;;)
//   {
//     // read the input on analog pin 0:
//     int sensorValue = analogRead(A0);
//     // print out the value you read:
//     Serial.println(sensorValue);
//     vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
//   }
// }
