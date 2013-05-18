#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <myfunctions.h>

char Text[1000];
int Stop=0;
void __gcov_flush(void);

void Wait()
{
    while(Stop)
        sleep(2);
}

int Sum(int a, int b)
{
	return a+b;
}

int Sub(int a, int b)
{
	return a-b;
}


void Write(char *p, const char *string)
{
	mycopy(p, string, 1000);
}


void Reset()
{
}

void Flush()
{
	__gcov_flush();
}
