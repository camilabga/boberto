int motorA[] = {3, 5, 7, 9};
int motorB[] = {4, 6, 8, 10};
char command;
bool stop_flag = 0;
int side = 1;
long int cont = 0;
unsigned long int cont2 = 0;
int goal = 0;

void interrupt() {
  cont += side;
  if (cont == goal)
    stop_flag = 1;
}
void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(20), interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(21), interrupt, CHANGE);
  for (int i = 0; i < 4; i++) {
    pinMode(motorA[i], OUTPUT);
    pinMode(motorB[i], OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
  }
  
  if (stop_flag) {
    stop_flag = 0;
    for (int i = 0; i < 4; i++) {
      digitalWrite(motorA[i], LOW);
      digitalWrite(motorB[i], LOW);
    }
    Serial.println(cont2);
  }
  cont2++;
  
  if (command == 'w') {
    Serial.println("----------------------forward-----------------------------");
    cont2 = 0;
    side = 1;
    for (int i = 0; i < 4; i++) {
      digitalWrite(motorA[i], HIGH);
      digitalWrite(motorB[i], LOW);
    }
    goal += 1500;
    command = ' ';
  }
  else if (command == 's') {
    Serial.println("----------------------backward-----------------------------");
    cont2 = 0;
    side = -1;
    for (int i = 0; i < 4; i++) {
      digitalWrite(motorA[i], LOW);
      digitalWrite(motorB[i], HIGH);
    }
    goal -= 1500;
    command = ' ';
  }
  else if (command == 'd') {
    digitalWrite(motorA[0], HIGH);
    digitalWrite(motorB[0], LOW);
    digitalWrite(motorA[1], LOW);
    digitalWrite(motorB[1], HIGH);
    digitalWrite(motorA[2], LOW);
    digitalWrite(motorB[2], HIGH);
    digitalWrite(motorA[3], HIGH);
    digitalWrite(motorB[3], LOW);
    delay(5000);
    command = ' ';
  }
}

