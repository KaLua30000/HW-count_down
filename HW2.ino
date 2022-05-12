byte pins[11]={13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
byte btn;int k=1;
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
   pinMode(1, INPUT_PULLUP);
  }
}
int count = 3600;
void loop()
{
  btn=digitalRead(1);
  if(btn==0){count=(3600-count);k=-k;delay(100);}
      for(byte led = 0; led <4 ;led++)
      {
        digitalWrite(pins[led+7], 1);
        switch(led)
        {
        case 0:
          for(byte j = 0; j < 7; j++)
          {
            digitalWrite(pins[j], show[(count%60)%10][j]);
          }delay(10);digitalWrite(pins[led+7], 0);count-=k;break;
        case 1:
          for(byte j = 0; j < 7; j++)
          {
            digitalWrite(pins[j], show[(count%60)/10][j]);
          }delay(10);digitalWrite(pins[led+7], 0);count-=k;break;
        case 2:
          for(byte j = 0; j < 7; j++)
          {
            digitalWrite(pins[j], show[(count/60)%10][j]);
          }delay(10);digitalWrite(pins[led+7], 0);count-=k;break;
        case 3:
          for(byte j = 0; j < 7; j++)
          {
            digitalWrite(pins[j], show[(count/60)/10][j]);
          }delay(10);digitalWrite(pins[led+7], 0);count-=k;break;
        }
      }
    
 }