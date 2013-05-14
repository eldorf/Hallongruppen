#include <wiringPi.h>

#include <cstdio>
#include <cstdlib>

#define SHORT 0
#define LONG 1
#define LAST 2

#define SHORT_DELAY 105
#define LONG_DELAY 365

//int sequence[] = {SHORT, LONG, LONG, LAST};
//int sequence[] = {LONG, LONG, LONG, LONG, LONG, LONG, LONG, LONG, LONG, LONG, SHORT, SHORT, SHORT, LONG, SHORT, LONG, SHORT, LONG, SHORT, LONG, SHORT, SHORT, SHORT, LONG, SHORT, LAST};
int sequence[] = {LONG, LONG, LONG, LONG, LONG, LONG, LONG, LONG, LONG, LONG, SHORT, SHORT, SHORT, LONG, SHORT, LONG, SHORT, LONG, SHORT, LONG, SHORT, LONG, SHORT, SHORT, SHORT, LAST};


void playShort();
void playLong();

int main()
{
    if (wiringPiSetupGpio() == -1)
        exit(1);

    pinMode(23, OUTPUT);
    digitalWrite(23,0);

    
    digitalWrite(23,0);

    int i = 0;
    for (; i < 4 ; i++)
    {
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
				    ;
		    }
		    seqNumber++;
	    } while(action != LAST); 

      delayMicroseconds(1000);
  }
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
