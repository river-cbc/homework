#include <Morse.h>
#include <Morse.h>
Morse morse(13);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char MORSE[][4] = {
  {'.', '-', '*', '*'}, //A
  {'-', '.', '.', '.'}, //B
  {'-', '.', '-', '.'}, //C
  {'-', '.', '.', '*'}, //D
  {'.', '*', '*', '*'}, //E
  {'.', '.', '-', '.'}, //F
  {'-', '-', '.', '*'}, //G
  {'.', '.', '.', '.'}, //H
  {'.', '.', '*', '*'}, //I
  {'.', '-', '-', '-'}, //J
  {'-', '.', '-', '*'}, //K
  {'.', '-', '.', '.'}, //L
  {'-', '-', '*', '*'}, //M
  {'-', '.', '*', '*'}, //N
  {'-', '-', '-', '*'}, //O
  {'.', '-', '-', '.'}, //P
  {'-', '-', '.', '-'}, //Q
  {'.', '-', '.', '*'}, //R
  {'.', '.', '.', '*'}, //S
  {'-', '*', '*', '*'}, //T
  {'.', '.', '-', '*'}, //U
  {'.', '.', '.', '-'}, //V
  {'.', '-', '-', '*'}, //W
  {'-', '.', '.', '-'}, //X
  {'-', '.', '-', '-'}, //Y
  {'-', '-', '.', '.'}, //Z
  {'-', '-', '-', '*'},//回车
  {'*', '-', '*', '-'} //空格
};
  String ls = "";
  String morse_s = "";
  int i, t , temp = 0;
  int n = 0;
  while(Serial.available()>0)
  {
    temp = 1;
    ls += char(Serial.read());
    delay(2); 
    n++;
  }

  if(temp)
  {
    for(i=0;i<n;i++)
    {
      for(t=0;t<4;t++)
      {
        if((ls[i]>=97)&&(ls[i] <= 122))
        {
          morse_s += char(MORSE[int(ls[i] - 97)][t]);
        }
        if(ls[i]==13)
        {
          morse_s += char(MORSE[27][t]);
        }
        if(ls[i]==32)
        {
          morse_s += char(MORSE[28][t]);
        }
      }
      morse_s += ' ';
    }
    Serial.println(morse_s);
    for(i = 0; morse_s[i]!='\0' ; i++)
    {
      if(morse_s[i] == '.')
        morse.dot();
      else if(morse_s[i] == '-')
        morse.dash();
      else if(morse_s[i] == ' ')
        morse.w_space();
      if (morse_s[i] != ' ' && ls[i] != '*')
        morse.c_space();
    }
    delay(2);
  }
}
