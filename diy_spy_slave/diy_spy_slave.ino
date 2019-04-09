int but0 = 9;
int but1 = 10;
int but2 = 11;
int but3 = 12;

int add_r[4] = {LOW, LOW, LOW, LOW};
int add_m[4] = {LOW, LOW, LOW, LOW};
int state[4] = {LOW, LOW, LOW, LOW};
int frame[4] = {LOW, LOW, LOW, LOW};

int rec = 0;
int cnt = 0;

int dat = 4;
int clk = 5;

void setup() 
{
  // put your setup code here, to run once:
  for(int i=9; i<=12; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(dat, INPUT);
  pinMode(clk, INPUT);
}

void loop() 
{
  // write to LEDs if frame is currently complete
  for(int i=0; i<4; i++)
  {
    digitalWrite(9+i, !frame[i+4]);
  }
  // receive frame
  /*
   * 
   * to receive a frame, wait for clock to pull high. 
   * if clock is low for more than 20 ms, reset to a new frame
   * once the clock pulls high, wait for it to pull low 
   * when the clock pulls low, read the first bit, then wait for high
   * 
   * repeat until a full frame is received (8 bits)
   */
  // wait for clock to pull high 
  // if it is low for more than 20 ms reset to new frame
  while (digitalRead(clk)==LOW && cnt<20)
  {
    delay(1);
    cnt++;
  }
  // TODO verify address
  // start new frame
  if(cnt >= 20)
  {
    cnt = 0;
    rec = 0;
  }
  else
  {
    // wait for falling edge
    while(digitalRead(clk)==HIGH)
    {
      delay(1);
    }
    // receive bit
    frame[rec] = digitalRead(dat);
    rec++;
    cnt = 0;
  }
}
