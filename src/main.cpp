#include <Arduino.h>
// #include <IRremote.h>
#include "include.h"

extern IRsendRaw irsend;

unsigned char flag = 1;
const unsigned char LED = 13;
const unsigned char Btn = WIO_KEY_A;
const unsigned char IR = 3;

uint16_t buf[] = {4400, 4400,
                  550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 550,
                  550, 550, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 1660,
                  550, 550, 550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660,
                  550, 1660, 550, 550, 550, 1660, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550,
                  550, 1660, 550, 1660, 550, 550, 550, 1660, 550, 550, 550, 550, 550, 550, 550, 550,
                  550, 550, 550, 550, 550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 1660, 550, 1660,
                  550, 5220,
                  4400, 4400,
                  550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 550,
                  550, 550, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 1660,
                  550, 550, 550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660,
                  550, 1660, 550, 550, 550, 1660, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550,
                  550, 1660, 550, 1660, 550, 550, 550, 1660, 550, 550, 550, 550, 550, 550, 550, 550,
                  550, 550, 550, 550, 550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 1660, 550, 1660,
                  550, 8000};

void sendMeidi_OPEN(unsigned char A, unsigned char B, unsigned char C);

void getcode(unsigned char A, unsigned char B, unsigned char C);

void sendMeidi_CLOSE();
// IRsend irsend;
unsigned char state = LOW;
void setup()
{
  // put your setup code here, to run once:
  //   pinMode(jieshou, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Btn, INPUT);

  Serial.begin(9600);
  pinMode(IR, OUTPUT);
}

void loop()
{
  // sendMeidi_CLOSE();
  if (digitalRead(Btn) == LOW && state == LOW)
  {
    //消抖
    delay(15);
    if (digitalRead(Btn) == LOW)
    {
      state = HIGH;
      if (flag & 1)
      {
        // sendMeidi_CLOSE();
        sendMeidi_OPEN(0xB2, 0x5F, 0xB0);
        digitalWrite(LED, LOW);
        flag++;
        // Serial.println(flag);
      }
      else
      {
        sendMeidi_CLOSE();
        digitalWrite(LED, LOW);
        flag++;
        // Serial.println(flag);
      }
    }
  }
  if (digitalRead(Btn) == LOW && state == HIGH)
  {
    //消抖
    delay(15);
    if (digitalRead(Btn) == LOW)
    {
      state = LOW;
    }
  }
}

void sendMeidi_OPEN(unsigned char A, unsigned char B, unsigned char C)
{
  getcode(A, B, C);
  irsend.send(buf, 200, 38);
  Serial.print(sizeof(buf));
}
void getcode(unsigned char A, unsigned char B, unsigned char C)
{
  unsigned char mask = 0x80;
  unsigned int cnt = 2;
  buf[0] = 4400;
  buf[1] = 4400;
  //发A
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & A)
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & (~A))
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  //发B
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & B)
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & (~B))
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  //发C
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & C)
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & (~C))
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }

  buf[cnt++] = 550;
  buf[cnt++] = 5220;
  buf[cnt++] = 4400;
  buf[cnt++] = 4400;

  //发A
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & A)
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & (~A))
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  //发B
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & B)
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & (~B))
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  //发C
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & C)
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  for (mask = 0x80; mask != 0; mask >>= 1)
  {
    buf[cnt++] = 550;
    if (mask & (~C))
      buf[cnt++] = 1660;
    else
      buf[cnt++] = 550;
  }
  buf[cnt++] = 550;
  buf[cnt++] = 8800;

  // Serial.println(cnt);
}
void sendMeidi_CLOSE()
{
  uint16_t buf_close[] = {4400, 4400,
                          550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 550,
                          550, 550, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 1660,
                          550, 550, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 550, 550, 1660, 550, 1660,
                          550, 1660, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1660, 550, 550, 550, 550,
                          550, 1660, 550, 1660, 550, 1660, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550,
                          550, 550, 550, 550, 550, 550, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660,
                          550, 5220,
                          4400, 4400,
                          550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 550,
                          550, 550, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 1660,
                          550, 550, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 550, 550, 1660, 550, 1660,
                          550, 1660, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1660, 550, 550, 550, 550,
                          550, 1660, 550, 1660, 550, 1660, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550,
                          550, 550, 550, 550, 550, 550, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660,
                          550, 5220,
                          4400, 4400,
                          550, 1660, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 550,
                          550, 550, 550, 1660, 550, 550, 550, 550, 550, 1660, 550, 1660, 550, 550, 550, 1660,
                          550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550,
                          550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660,
                          550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550,
                          550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660, 550, 1660,
                          550, 8000};
  irsend.send(buf_close, 200, 38);
}