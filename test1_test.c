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
 int64_t ti[18]; double *tr = (double *) ti;

 i[0] = getint();
 i[1] = 2;
 L1:
 ti[0] = i[0] > 0;
 if (!ti[0]) goto L18;
 i[2] = 0;
 i[3] = 2;
 ti[1]=i[3]*i[3];
 i[4] = ti[1];
 L2:
 tr[2] = to_real(i[1]);
 ti[3] = to_int(tr[2]);
 tr[4] = to_real(0);
 ti[5] = to_int(tr[4]);
 ti[6]=ti[3]+ti[5];
 ti[7] = i[4] <= ti[6];
 if (!ti[7]) goto L15;
 i[5] = 2;
 ti[8]=i[3]*i[5];
 i[6] = ti[8];
 L3:
 ti[9] = i[6] <= i[1];
 if (!ti[9]) goto L14;
 ti[10] = i[6] == i[1];
 if (!ti[10]) goto L13;
 i[2] = 1;
 L5:
 ti[11] = i[2] < 10;
 if (!ti[11]) goto L12;
 ti[12]=i[2]+1;
 i[2] = ti[12];
 ti[13] = i[2] == 3;
 if (!ti[13]) goto L7;
 ti[14]=i[2]-1;
 i[2] = ti[14];
 L7:;
 L8:
 ti[14] = i[2] < 6;
 if (!ti[14]) goto L11;
 ti[15]=i[2]+1;
 i[2] = ti[15];
 ti[16] = i[2] == 5;
 if (!ti[16]) goto L10;
 ti[17]=i[2]-1;
 i[2] = ti[17];
 L10:;
 ti[15]=i[2]+1;
 i[2] = ti[15];
 goto L8;
 L11:;
 goto L5;
 L12:;
 i[2] = 1;
 L13:;
 ti[11]=i[5]+1;
 i[5] = ti[11];
 ti[12]=i[3]*i[5];
 i[6] = ti[12];
 goto L3;
 L14:;
 ti[9]=i[3]+1;
 i[3] = ti[9];
 ti[10]=i[3]*i[3];
 i[4] = ti[10];
 goto L2;
 L15:;
 ti[7] = i[2] == 0;
 if (!ti[7]) goto L17;
 putint(i[1]);
 ti[8]=i[0]-1;
 i[0] = ti[8];
 L17:;
 ti[8]=i[1]+1;
 i[1] = ti[8];
 goto L1;
 L18:;
}
