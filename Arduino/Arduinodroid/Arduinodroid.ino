#include <SoftwareSerial.h>

// Motor One pins
int enA = 10; 
int in1 = 9;
int in2 = 8;

// Motor Two pins
int enB = 5;
int in3 = 7;
int in4 = 6;

SoftwareSerial BT(1, 0); //RX 0 and TX 1

//List of bluetooth commands
#define move_forward 'f'
#define move_backward 'b'
#define move_left 'l'
#define move_right 'r'
#define stop_motor 's'

char command; 

void setup() {
  //Start listening bluetooth on serial port 9600
  BT.begin(9600);

  //Set all motors to stop
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if(BT.available()) { //If the bluetooth connexion is available
    command = (BT.read()); //Read the bluetooth command
    if(command == move_forward) { 
      BT.println("Move Forward"); //Send this on device for debug
      moveForward();
    }
    if(command == move_backward) {
      BT.println("Move Backward"); //Send this on device for debug
      moveBackward();
    }
    if(command == move_left) {
      BT.println("Move Left"); //Send this on device for debug
      moveLeft();
    }
    if(command == move_right) {
      BT.println("Move Right"); //Send this on device for debug
      moveRight();
    }
    if(command == stop_motor) {
      BT.println("Stop Motors");
      stopMotor();
    }       
  }
}

/**
 * Function for move start the motors forward
 */
void moveForward() {
  //Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //Set speed of motor A to 200 (Possible range 0~255)
  analogWrite(enA, 200);
  
  //Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //Set speed of motor B to 200 (Possible range 0~255)
  analogWrite(enB, 200);
}

/**
 * Function for move the motors backward
 */
void moveBackward() {
  //Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //Set speed of motor A to 200 (Possible range 0~255)
  analogWrite(enA, 200);
  
  //Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  //Set speed of motor B to 200 (Possible range 0~255)
  analogWrite(enB, 200);
}

/**
 * Function for move the motors to go on the left
 */
void moveRight() {
  //Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //Set speed of motor A to 200 (Possible range 0~255)
  analogWrite(enA, 200);
  
  //Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //Set speed of motor B to 200 (Possible range 0~255)
  analogWrite(enB, 200);
}

/**
 * Function for move the motors to go on the right
 */
void moveLeft() {
  //Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //Set speed of motor A to 200 (Possible range 0~255)
  analogWrite(enA, 200);
  
  //Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  //Set speed of motor B to 200 (Possible range 0~255)
  analogWrite(enB, 200);
}

/**
 * Function for stop the motors
 */
void stopMotor() {
  // Turn of the motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
