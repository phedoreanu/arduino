void setup() {
  Serial.begin(115200);
  Serial.println("Arduino online.");
}

int one_way = 0;
int second_way = 0;

void loop() {
  // put your main code here, to run repeatedly:
  one_way = analogRead(0);
  delay(1);
  Serial.print("1st= ");
  Serial.println(one_way);
  second_way = analogRead(2);
  delay(1);
  Serial.print("2nd= ");
  Serial.println(second_way);
  
  delay(1000);
}
