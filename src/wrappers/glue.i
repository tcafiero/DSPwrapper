%module EmptyProject

%{
extern char Text[1000];
extern int Stop;
extern void Wait();
extern void Reset();
extern int Sum(int a, int b);
extern int Sub(int a, int b);
extern void Write(char *p, const char*string);
%}

char Text[1000];
int Stop;
void Wait();
void Reset();
int Sum(int a, int b);
int Sub(int a, int b);
void Write(char *p, const char*string);


