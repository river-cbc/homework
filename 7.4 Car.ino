void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char income;
  if(Serial.available()>0)
  {
    income=Serial.read();
    switch(income)
    {
      case 'f':
        forward();
        break;
      case 'b':
        backward();
        break;
      case 'l':
        {
          left();
          for(int i=0;;i++)
        {
          digitalWrite(13,HIGH);
          delay(300);
          digitalWrite(13,LOW);
          delay(300);
              if(Serial.available()>0)
                  break;
        }
        } 
        break;
      case 'r':
        {
          right();
          for(int i=0;;i++)
        {
          digitalWrite(12,HIGH);
          delay(300);
          digitalWrite(12,LOW);
          delay(300);
                if(Serial.available()>0)
                  break;
            }
        } 
        break;
      case 's':
        stop();
        break;
      default:
        break;
    }
  } 
}

void backward()
{
  digitalWrite(9,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(6,LOW);
}

void forward()
{
  digitalWrite(10,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(5,LOW);
}

void right()
{
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(12,HIGH);
}

void left()
{
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  
}

void stop()
{
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
}
