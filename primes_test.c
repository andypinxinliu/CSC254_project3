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
 int64_t i[7]; double *r = (double *) i;
 int64_t ti[8]; double *tr = (double *) ti;

 i[0] = getint();
 i[1] = 2;
 L1:
 ti[0] = i[0] > 0;
 if (!ti[0]) goto L9;
 i[2] = 0;
 i[3] = 2;
 ti[1]=i[3]*i[3];
 i[4] = ti[1];
 L2:
 ti[2] = i[4] <= i[1];
 if (!ti[2]) goto L7;
 i[5] = 2;
 ti[3]=i[3]*i[5];
 i[6] = ti[3];
 L3:
 ti[4] = i[6] <= i[1];
 if (!ti[4]) goto L6;
 ti[5] = i[6] == i[1];
 if (!ti[5]) goto L5;
 i[2] = 1;
 L5:;
 ti[6]=i[5]+1;
 i[5] = ti[6];
 ti[7]=i[3]*i[5];
 i[6] = ti[7];
 goto L3;
 L6:;
 ti[4]=i[3]+1;
 i[3] = ti[4];
 ti[5]=i[3]*i[3];
 i[4] = ti[5];
 goto L2;
 L7:;
 ti[2] = i[2] == 0;
 if (!ti[2]) goto L8;
 putint(i[1]);
 ti[3]=i[0]-1;
 i[0] = ti[3];
 L8:;
 ti[3]=i[1]+1;
 i[1] = ti[3];
 goto L1;
 L9:;
}
