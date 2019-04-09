int but0 = 9;
int but1 = 10;
int but2 = 11;
int but3 = 12;

int state[4] = {LOW, LOW, LOW, LOW};

int dat = 4;
int clk = 5;

void setup() 
{
  // put your setup code here, to run once:
  for(int i=9; i<=12; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(dat, OUTPUT);
  pinMode(clk, OUTPUT);
  digitalWrite(dat, LOW);
  digitalWrite(clk, LOW);
}

void loop() 
{
  // read buttons
  for(int i=0; i<4; i++)
  {
    state[i] = digitalRead(9+i);
  }
  // send frame
  /*
   * to begin a frame, pull the clock high
   * then write the first bit, wait 10 ms, then pull the clock low
   * after 10 ms, pull the clock high, repeat
   * 
   * each frame consists of a four bit address, then four bits of data
   * 
   * between each frame, a pause of 30 ms is required
   */
  // send address (using 0b0000 for testing)
  for(int i=0; i<4; i++)
  {
    digitalWrite(clk, HIGH);
    digitalWrite(dat, LOW);
    delay(10);
    digitalWrite(clk, LOW);
    delay(10);
  }

  // send message
  for(int i=0; i<4; i++)
  {
    digitalWrite(clk, HIGH);
    digitalWrite(dat, state[i]);
    delay(10);
    digitalWrite(clk, LOW);
    delay(10);
  }
  delay(20);
}
