const int buttonPin = 2;
const int buzzerPin = 8;

const int trigPin = 9;
const int echoPin = 10;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  Serial.println();
  Serial.println("======================================");
  Serial.println("        USELESS BUTTON 3000");
  Serial.println("======================================");
  Serial.println("SYSTEM STATUS: READY");
  Serial.println("Please press the button.");
  Serial.println();
}

float getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  float distance = duration * 0.0343 / 2;

  return distance;
}

void loop() {

  if (digitalRead(buttonPin) == LOW) {

    Serial.println();
    Serial.println("======================================");
    Serial.println("       BUTTON ACTIVATED");
    Serial.println("======================================");

    delay(500);

    Serial.println("> Initializing useless analysis...");
    tone(buzzerPin, 800);
    delay(200);
    noTone(buzzerPin);

    delay(500);

    Serial.println("> Detecting human...");
    
    float distance = getDistance();

    if (distance > 0) {

      Serial.print("> Human distance: ");
      Serial.print(distance);
      Serial.println(" cm");

    } else {

      Serial.println("> Distance measurement failed.");
      Serial.println("> This is completely acceptable.");

    }

    delay(700);

    Serial.println("> Performing advanced calculations...");

    tone(buzzerPin, 1000);
    delay(150);
    noTone(buzzerPin);

    delay(400);

    Serial.println("[████░░░░░░░░░░░░░░] 25%");
    delay(500);

    Serial.println("[████████░░░░░░░░░░] 50%");
    delay(500);

    tone(buzzerPin, 1200);
    delay(150);
    noTone(buzzerPin);

    Serial.println("[████████████░░░░░░] 75%");
    delay(500);

    Serial.println("[████████████████████] 100%");
    delay(500);

    Serial.println();
    Serial.println("======================================");
    Serial.println("          ANALYSIS COMPLETE");
    Serial.println("======================================");

    Serial.println("Human detected: YES");
    Serial.println("Intelligence detected: UNKNOWN");
    Serial.println("Useful information obtained: NONE");
    Serial.println();
    
    tone(buzzerPin, 600);
    delay(300);

    tone(buzzerPin, 900);
    delay(300);

    tone(buzzerPin, 1300);
    delay(500);

    noTone(buzzerPin);

    Serial.println("**************************************");
    Serial.println("             FINAL RESULT");
    Serial.println("**************************************");
    Serial.println();
    Serial.println("          USEFULNESS: 0%");
    Serial.println();
    Serial.println("       NOTHING HAPPENED.");
    Serial.println();
    Serial.println("**************************************");
    Serial.println("Thank you for wasting your time.");
    Serial.println("**************************************");

    delay(3000);

    Serial.println();
    Serial.println("SYSTEM READY.");
    Serial.println("Please press the button again.");

    delay(1000);
  }
}
