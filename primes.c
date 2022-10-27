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
 int64_t ti[1]; double *tr = (double *) ti;

 i[0] = getint();
 i[1] = 2;
 L6:
 ti[0] = i[0] > 0;
 if (!ti[0]) goto L7;
 i[2] = 0;
 i[3] = 2;
 i[4] = i[3] * i[3];
 L3:
 ti[0] = i[4] <= i[1];
 if (!ti[0]) goto L4;
 i[5] = 2;
 i[6] = i[3] * i[5];
 L1:
 ti[0] = i[6] <= i[1];
 if (!ti[0]) goto L2;
 ti[0] = i[6] == i[1];
 if (!ti[0]) goto L0;
 i[2] = 1;
 L0:;
 i[5] = i[5] + 1;
 i[6] = i[3] * i[5];
 goto L1;
 L2:;
 i[3] = i[3] + 1;
 i[4] = i[3] * i[3];
 goto L3;
 L4:;
 ti[0] = i[2] == 0;
 if (!ti[0]) goto L5;
 putint(i[1]);
 i[0] = i[0] - 1;
 L5:;
 i[1] = i[1] + 1;
 goto L6;
 L7:;
}
