#include <stdio.h>
#include <stdlib.h>

int64_t getint() {
int64_t rtn;
switch (scanf("%lld", &rtn)) {
case EOF:
fprintf(stderr, "unexpected end of file\n");
exit(1);
case 0:
fprintf(stderr, "unexpected non-numeric input\n");
exit(1);
case 1: break;
}
return rtn;
}

void putint(int64_t x) {
printf("%lld\n", x);
}

double divide_int(int64_t n, int64_t d) {
if (d == 0) {
fprintf(stderr, "divide by zero\n");
exit(1);
}
return n/d;
}

double getreal() {
double rtn;
switch (scanf("%lf", &rtn)) {
case EOF:
fprintf(stderr, "unexpected end of file\n");
exit(1);
case 0:
fprintf(stderr, "unexpected non-numeric input\n");
exit(1);
case 1: break;
}
return rtn;
}

void putreal(double x) {
printf("%lg\n", x);
}

double divide_real(double n, double d) {
if (d == 0) {
fprintf(stderr, "divide by zero\n");
exit(1);
}
return n/d;
}

double to_real(int64_t n) {return (double) n;}
int64_t to_int(double x) {return (int64_t) x;}

int main() {
 int64_t i[2]; double *r = (double *) i;
 int64_t ti[4]; double *tr = (double *) ti;

 i[0] = getint();
 i[1] = getint();
 L1:
 ti[0] = i[0] != i[1];
 if (!ti[0]) goto L6;
 ti[1] = i[0] > i[1];
 if (!ti[1]) goto L3;
 i[0] = i[0]-i[1];
 L3:;
 ti[2] = i[1] > i[0];
 if (!ti[2]) goto L4;
 i[1] = i[1]-i[0];
 L4:;
 ti[3] = i[0] == i[1];
 if (!ti[3]) goto L5;
 putint(i[0]);
 L5:;
 goto L1;
 L6:;
}
