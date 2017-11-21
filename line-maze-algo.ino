#define lefttwosensor 2
#define leftonesensor 3
#define centersensor 4
#define rightonesensor 5
#define righttwosensor 6
#define stopsensor 7
#define leftmotor1 8
#define leftmotor2 9
#define rightmotor1 10
#define rightmotor2 11
#define led 13
void setup()
{
  pinMode(lefttwosensor, INPUT);
  pinMode(leftonesensor, INPUT);
  pinMode(centersensor, INPUT);
  pinMode(righttwosensor, INPUT);
  pinMode(rightonesensor, INPUT);
  pinMode(stopsensor, INPUT);
  pinMode(leftmotor1, OUTPUT);
  pinMode(leftmotor2, OUTPUT);
  pinMode(rightmotor1, OUTPUT);
  pinMode(rightmotor2, OUTPUT);
  pinMode(led, OUTPUT);
}
int a, b, c, d, e, f, g, h;
char path[] = {};
int pathlength = 0;
int readlength;
int i, k;
int z = 0;
void readsensor()
{
  a = digitalRead(lefttwosensor);
  b = digitalRead(leftonesensor);
  c = digitalRead(centersensor);
  d = digitalRead(rightonesensor);
  e = digitalRead(righttwosensor);
  f = digitalRead(stopsensor);
}

void straight()
{
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor1, LOW);
}

void turnleft()
{
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
}
void turnright()
{
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, LOW);


}
void uturn()
{
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
}
void stop1()
{
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, LOW);
  exitled();
}
void loop()
{
  if (f == 0)
  {
    straight();
    readsensor();
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
    {
      straight();
      delay(100);
      readsensor();//delay T shape
    }
    else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0)
    {
      turnright();
      delay(500);      //delay + chapee
      path[pathlength] = 'R';
      pathlength++;
    }
    else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
    {
      turnright();
      delay(500);
      path[pathlength] = 'R';
      pathlength++;
      //path
    }
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 1)               //check f
    {
      stop1();
      delay(3000);

    }
  }
  else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0)
  {
    straight();
    delay(100);
    if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0)
    {
      turnright();
      delay(493);
    }
    else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
    {
      turnright();
      delay(493);
      path[pathlength] = 'R';
      pathlength++;
    }
  }
  else if (a == 0 && b == 0 && c == 0 && d == 1 && e == 1 && f == 0)
  {
    straight();
    delay(500);
    if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0)
    {
      turnleft();
      delay(493);
    }
    else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
    {
      straight();
      path[pathlength] = 'S';
      pathlength++;
    }
  }
  else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
  {
    straight();
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
    {
      uturn();
      delay(1000);
      path[pathlength] = 'U';
      pathlength++;
    }
  }
  readsensor();
  if (a == 0 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0)
  {
    for (;;)
    {
      turnleft();
      delay(10);
      if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
        break;
    }
    straight();
  }
  else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 1 && f == 0)
  {
    for (;;)
    {
      turnright();
      delay(10);
      if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
        break;
    }
    straight();
  }
  else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0)
  {
    for (;;)
    {
      turnleft();
      delay(10);
      if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
        break;
    }
    straight();
  }
  else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0)
  {
    for (;;)
    {
      turnright();
      delay(10);
      if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
        break;
    }
    straight();
  }
  else if (f == 1)
  {
    shortpath();
    straight();
    readsensor();
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
    {
      readsensor();
      straight();
      delay(100);
      if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 1)
      {
          stop1();
      }
      else
        test();
        delay(500);
      readlength++;
    }
    else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0)
    {
      readsensor();
      straight();
      delay(100);
      if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0)
      {
        turnright();
        delay(500);
      }
      else
        test();
        delay(500);
      readlength++;
    }
    else if (a == 0 && b == 0 && c == 0 && d == 1 && e == 1 && f == 0)
    {
      readsensor();
      straight();
      delay(100);
      if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0)
      {
        turnleft();
        delay(500);
      }
      else
        test();
        delay(500);
      readlength++;
    }

  }

  if (a == 0 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0)
  {
    for (;;)
    {
      turnleft();
      delay(10);
      if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
        break;
    }
    straight();
  }
  else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 1 && f == 0)
  {
    for (;;)
    {
      turnright();
      delay(10);
      if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
        break;
    }
    straight();
  }
  else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0)
  {
    for (;;)
    {
      turnleft();
      delay(10);
      if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
        break;
    }
    straight();
  }
  else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0)
  {
    for (;;)
    {
      turnright();
      delay(10);
      if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0)
        break;
    }
    straight();
  }
}
void shortpath()
{
  for (i = 0; i < pathlength; i++)
  {
    if (path[i] == 'U')
    {
      if (path[i - 1] == 'R' && path[i + 1] == 'L')
      {
        path[i - 1] = 'U';
        for (k = i + 2; k < pathlength; k++)
        {
          path[k - 2] = path[k];
        }
        path[pathlength - 1] = ' ';
        path[pathlength - 2] = ' ';
      }
    }
    if (path[i] == 'U')
    {
      if (path[i - 1] == 'R' && path[i + 1] == 'S')
      {
        path[i - 1] = 'L';
        for (k = i + 2; k < pathlength; k++)
        {
          path[k - 2] = path[k];
        }
        path[pathlength - 1] = ' ';
        path[pathlength - 2] = ' ';
      }
    }
    if (path[i] == 'U')
    {
      if (path[i - 1] == 'S' && path[i + 1] == 'R')
      {
        path[i - 1] = 'L';
        for (k = i + 2; k < pathlength; k++)
        {
          path[k - 2] = path[k];
        }
        path[pathlength - 1] = ' ';
        path[pathlength - 2] = ' ';
      }
    }
    if (path[i] == 'U')
    {
      if (path[i - 1] == 'L' && path[i + 1] == 'R')
      {
        path[i - 1] = 'U';
        for (k = i + 2; k < pathlength; k++)
        {
          path[k - 2] = path[k];
        }
        path[pathlength - 1] = ' ';
        path[pathlength - 2] = ' ';
      }
    }
    if (path[i] == 'U')
    {
      if (path[i - 1] == 'S' && path[i + 1] == 'S')
      {
        path[i - 1] = 'L';
        for (k = i + 2; k < pathlength; k++)
        {
          path[k - 2] = path[k];
        }
        path[pathlength - 1] = ' ';
        path[pathlength - 2] = ' ';
      }
    }
    if (path[i] == 'U')
    {
      if (path[i - 1] == 'R' && path[i + 1] == 'R')
      {
        path[i - 1] = 'S';
        for (k = i + 2; k < pathlength; k++)
        {
          path[k - 2] = path[k];
        }
        path[pathlength - 1] = ' ';
        path[pathlength - 2] = ' ';
      }
    }
  }
}
void test()
{
  shortpath();
  if (path[readlength] == 'r')
  {
    turnright();
  }
  else if (path[readlength] == 'l')
    turnleft();
  else if (path[readlength] == 'u')
    uturn();
  else if (path[readlength] == 's')
    straight();
}
void exitled()
{
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
}

