int dat = 4;
int clk = 5;

void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(dat, INPUT);
  pinMode(clk, INPUT);
}

void loop() 
{
  Serial.print(digitalRead(clk));
  Serial.print(",");
  Serial.println(digitalRead(dat));
}
