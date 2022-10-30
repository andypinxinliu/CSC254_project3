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
 int64_t ti[2]; double *tr = (double *) ti;

 i[0] = getint();
 i[1] = 2;
 L12:
 ti[0] = i[0] > 0;
 if (!ti[0]) goto L13;
 i[2] = 0;
 i[3] = 2;
 i[4] = i[3] * i[3];
 L9:
 tr[0] = to_real(i[1]);
 ti[0] = to_int(tr[0]);
 tr[1] = to_real(0);
 ti[1] = to_int(tr[1]);
 ti[0] = ti[0] + ti[1];
 ti[0] = i[4] <= ti[0];
 if (!ti[0]) goto L10;
 i[5] = 2;
 i[6] = i[3] * i[5];
 L7:
 ti[0] = i[6] <= i[1];
 if (!ti[0]) goto L8;
 ti[0] = i[6] == i[1];
 if (!ti[0]) goto L6;
 i[2] = 1;
 L4:
 ti[0] = i[2] < 10;
 if (!ti[0]) goto L5;
 i[2] = i[2] + 1;
 ti[0] = i[2] == 3;
 if (!ti[0]) goto L0;
 i[2] = i[2] - 1;
 L0:;
 L2:
 ti[0] = i[2] < 6;
 if (!ti[0]) goto L3;
 i[2] = i[2] + 1;
 ti[0] = i[2] == 5;
 if (!ti[0]) goto L1;
 i[2] = i[2] - 1;
 L1:;
 i[2] = i[2] + 1;
 goto L2;
 L3:;
 goto L4;
 L5:;
 i[2] = 1;
 L6:;
 i[5] = i[5] + 1;
 i[6] = i[3] * i[5];
 goto L7;
 L8:;
 i[3] = i[3] + 1;
 i[4] = i[3] * i[3];
 goto L9;
 L10:;
 ti[0] = i[2] == 0;
 if (!ti[0]) goto L11;
 putint(i[1]);
 i[0] = i[0] - 1;
 L11:;
 i[1] = i[1] + 1;
 goto L12;
 L13:;
}
