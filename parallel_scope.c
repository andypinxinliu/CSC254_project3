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
 int64_t ti[1]; double *tr = (double *) ti;

 i[0] = getint();
 i[1] = getint();
 L3:
 ti[0] = i[0] != i[1];
 if (!ti[0]) goto L4;
 ti[0] = i[0] > i[1];
 if (!ti[0]) goto L0;
 i[0] = i[0] - i[1];
 L0:;
 ti[0] = i[1] > i[0];
 if (!ti[0]) goto L1;
 i[1] = i[1] - i[0];
 L1:;
 ti[0] = i[0] == i[1];
 if (!ti[0]) goto L2;
 putint(i[0]);
 L2:;
 goto L3;
 L4:;
 L8:
 ti[0] = i[0] < i[1];
 if (!ti[0]) goto L9;
 ti[0] = i[0] > i[1];
 if (!ti[0]) goto L5;
 i[0] = i[0] - i[1];
 L5:;
 ti[0] = i[1] > i[0];
 if (!ti[0]) goto L6;
 i[1] = i[1] - i[0];
 L6:;
 ti[0] = i[0] == i[1];
 if (!ti[0]) goto L7;
 putint(i[0]);
 L7:;
 goto L8;
 L9:;
 ti[0] = i[0] > i[1];
 if (!ti[0]) goto L10;
 i[0] = i[0] - i[1];
 L10:;
}
