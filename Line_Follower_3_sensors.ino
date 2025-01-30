int IN1 = 9;
int IN2 = 10;
// int motor_enable_left = 5;

int IN3 = 11;
int IN4 = 12;
//int motor_right_enable = 6;

int left = 7;
int right = 5 ;
int center = 6;

void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  //pinMode(motor_left_speed,OUTPUT);

  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //pinMode(motor_right_speed,OUTPUT);

  pinMode(left, INPUT);
  pinMode(center,INPUT);
  pinMode(right, INPUT);

  Serial.begin(9600);
}

void loop(){
  int leftV = digitalRead(left);
  int centerV = digitalRead(center);
  int rightV = digitalRead(right);

  while(leftV == 0 && centerV == 1 && rightV == 0) {
    carforward();
    delay(200);
    break;
  }
  while(leftV == 1 && centerV == 0 && rightV == 0) {
    carturnleft();
    delay(200);
    break;
  }

  while(rightV == 1 && centerV == 0 && leftV == 0){
    carturnright();
    delay(200);
    break;
  }

  while(rightV == 1 && centerV == 1 && leftV == 0) {
    carturnright();
    delay(100);
    break;
  }

  while(leftV == 1 && centerV == 1 && rightV == 0) {
    carturnleft();
    delay(100);
    break;
  }

  while(leftV == 0 && centerV == 0 && rightV == 0) {
    carStop();
    delay(200);
    break;
  }

  while(leftV == 1 && centerV == 1 && rightV == 1) {
    carforward();
    delay(200);
    break;
  }
}

void carforward() {
  //analogWrite(ENA, Speed);
  //analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnleft() {
  //analogWrite(ENA, Speed);
  //analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  //analogWrite(ENA, Speed);
  //analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

