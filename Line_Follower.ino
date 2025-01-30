int IN1 = 9;
int IN2 = 10;
// int motor_enable_left = 5;

int IN3 = 11;
int IN4 = 12;
//int motor_right_enable = 6;

int left = 8;
int right = 5 ;
int center_left = 7;
int center_right = 6;

void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  //pinMode(motor_left_speed,OUTPUT);

  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //pinMode(motor_right_speed,OUTPUT);

  pinMode(left, INPUT);
  pinMode(center_left, INPUT);
  pinMode(center_right,INPUT);
  pinMode(right, INPUT);

  Serial.begin(9600);
}

void loop(){
  int leftV = digitalRead(left);
  int center_leftV = digitalRead(center_left);
  int center_rightV = digitalRead(center_rightV);
  int rightV = digitalRead(right);

  while(leftV == 0 && rightV == 0 && center_leftV == 0 && center_rightV == 0) {
    carStop();
    delay(300);
    break;
  }
  
  while(leftV == 1 && rightV == 1 && center_leftV == 1 && center_rightV == 1) {
    carStop();
    delay(300);
    break;
  }

  while(leftV == 0 && center_leftV == 0 && rightV == 1 && center_rightV == 1) {
    carturnleft();
    delay(100);
    break;
  }

  while(rightV == 0 && center_rightV == 0 && leftV == 1 && center_leftV == 1) {
    carturnright();
    delay(100);
    break;
  }

  while(leftV == 0 && center_leftV == 1 && rightV == 1 && center_rightV == 1) {
    carturnleft();
    delay(300);
    break;
  }

  while(rightV == 0 && center_rightV == 1 && leftV == 1 && center_leftV == 1) {
    carturnight();
    delay(300);
    break;
  }
  
  while(rightV == 1 && center_rightV == 0 && center_leftV == 0 && center_rightV == 1) {
    carforward();
    delay(300);
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

