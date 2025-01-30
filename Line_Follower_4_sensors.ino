int IN1 = 9;
int IN2 = 10;
// int motor_enable_left = 5;

int IN3 = 11;
int IN4 = 12;
//int motor_right_enable = 6;

int left = 8;
int right = 5 ;
int center_right = 6;
int center_left = 7;

void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  //pinMode(motor_left_speed,OUTPUT);

  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //pinMode(motor_right_speed,OUTPUT);

  pinMode(left, INPUT);
  pinMode(center_left,INPUT);
  pinMode(center_right,INPUT);
  pinMode(right, INPUT);

  Serial.begin(9600);
}

void loop(){
  int leftV = digitalRead(left);
  int center_leftV = digitalRead(center_left);
  int center_rightV = digitalRead(center_right);
  int rightV = digitalRead(right);

  while(center_leftV == 1 && center_rightV == 1 && leftV == 0 && rightV == 0) {
    carforward();
    delay(200);
    break;
  }

  while(leftV == 1 && center_leftV == 0 && center_rightV == 0 && rightV == 0) {
    carturnleft();
    delay(200);
    break;
  }

  while(rightV == 1 && center_leftV == 0 && center_rightV == 0 && leftV == 0) {
    carturnright();
    delay(200);
    break;
  }

  while(leftV == 1 && center_leftV == 1 && rightV == 0 && center_right == 0) {
    carturnleft();
    delay(200);
    break;
  }

  while(rightV == 1 && center_rightV == 1 && leftV == 0 && center_leftV == 0) {
    carturnright();
    delay(200);
    break;
  }

  while(rightV == 1 && center_rightV == 1 && center_leftV == 1 && leftV == 0) {
    carturnright();
    delay(200);
    break;

  }

  while(leftV == 1 && center_leftV == 1 && center_rightV == 1 && rightV == 0) {
    carturnleft();
    delay(200);
    break;
  }

  while(leftV == 0 && center_leftV == 0 && center_rightV == 0 && rightV == 0) {
    carturnright(); //For U Turn case
    delay(2000);
    break;
  }

  while(leftV == 1 && center_leftV == 1 && center_rightV == 1 && rightV == 1) {
    carforward();
    delay(200);
    break;
  }

  while(leftV == 0 && center_leftV == 1 && center_rightV == 0 && rightV == 0) {
    carturnright();
    delay(70);
    break;
  }

  while(leftV == 0 && center_rightV == 1 && center_leftV == 0 && rightV == 0) {
    carturnleft();
    delay(70);
    break;
  }

}

void carforward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnleft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
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

