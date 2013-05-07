#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SHORT 0
#define LONG 1
#define LAST 2

#define SHORT_DELAY 100
#define LONG_DELAY 200

int sequence[] = {SHORT, LONG, LONG, LAST};

void playShort();
void playLong();

int main()
{
    if (wiringPiSetupGpio() == -1)
        exit(1);

    pinMode(23, OUTPUT);
    digitalWrite(23,0);

    int seqNumber = 0;
    int action;
    do {
        action = sequence[seqNumber];
        switch (action)
        {
            case SHORT:
                playShort();
                break;
            case LONG:
                playLong();
                break;
            default:
        }
        seqNumber++;
  } while(action != LAST) 

  return 0 ;
}

void playShort()
{
    digitalWrite(23,1);
    delayMicroseconds(SHORT_DELAY);
    digitalWrite(23,0);
    delayMicroseconds(LONG_DELAY);
}

void playLong()
{
    digitalWrite(23,1);
    delayMicroseconds(LONG_DELAY);
    digitalWrite(23,0);
    delayMicroseconds(SHORT_DELAY);
}
