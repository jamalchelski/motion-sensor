///////////////////////Code Created by///////////////////////
//////////////////////Moch Nur Jamalludin//////////////////////

int Pir = 6;           // output of Pir sensor
int led_red = 4;       // led pin
int led_yellow = 2;    //led pin
const int buzzer = 3;  // buzzer pin
int val = 0;           // value default
int mag = 12;          // magnetic sensor port
const int wait = 5000; // delay waktu untuk buzzer setelah pintu terbuka
bool timer = false;    // default sensor magnetic

void setup()
{
  pinMode(Pir, INPUT);         // setting Pir output as arduino input
  pinMode(led_red, OUTPUT);    //setting led as output
  pinMode(led_yellow, OUTPUT); //setting led as output
  pinMode(buzzer, OUTPUT);     //setting buzzer as output
  pinMode(mag, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600); //serial communication between arduino and pc
}
void loop()
{
  baca();
  magnetic();
}

void baca()
{
  if (digitalRead(Pir) == HIGH) // reading the data from the Pir sensor
  {
    digitalWrite(led_yellow, HIGH);
    digitalWrite(led_red, LOW); // setting led to high
    tone(buzzer, 2000);
    delay(500);
    noTone(buzzer);
    delay(200);

    Serial.println("motion detected");
  }
  else
  {
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, HIGH); // setting led to low
    noTone(buzzer);
    Serial.println("scanning");
  }
}

void magnetic()
{
  val = digitalRead(mag);

  if ((val == 0) & (timer == false))
  {
    noTone(buzzer);
  }
  else if ((val == 0) & (timer == true))
  {
    noTone(buzzer);
    timer = false;
  }
  else if ((val == 1) & (timer == false))
  {
    tone(buzzer, 2000);
    delay(wait);
    noTone(buzzer);
    delay(200);
    timer = true;
  }
  else if ((val == 1) & (timer == true))
  {
    noTone(buzzer);
  }
  delay(100);
}
