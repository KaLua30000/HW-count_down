byte pins[11]={13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
const byte show[10][7]={
  {0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 1, 1, 0},
  {1, 0, 0, 1, 1, 0, 0},
  {0, 1, 0, 0, 1, 0, 0},
  {1, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0},
};
void setup()
{
  for (byte i = 0; i < 11; ++i) {
   pinMode(pins[i], OUTPUT); 
  }
}
void loop()
{
    for(int i = 9999; i > 0; i--)
    {
      for(byte led = 0; led <4 ;led++)
      {
        digitalWrite(pins[led+7], 1);
        switch(led)
        {
        case 0:
          for(byte j = 0; j < 7; j++)
          {
            digitalWrite(pins[j], show[i%10][j]);
          }delay(100);digitalWrite(pins[led+7], 0);break;
        case 1:
          for(byte j = 0; j < 7; j++)
          {
            digitalWrite(pins[j], show[(i%100)/10][j]);
          }delay(100);digitalWrite(pins[led+7], 0);break;
        case 2:
          for(byte j = 0; j < 7; j++)
          {
            digitalWrite(pins[j], show[(i%1000)/100][j]);
          }delay(100);digitalWrite(pins[led+7], 0);break;
        case 3:
          for(byte j = 0; j < 7; j++)
          {
            digitalWrite(pins[j], show[i/1000][j]);
          }delay(100);digitalWrite(pins[led+7], 0);break;
        }
      }
    }
 }