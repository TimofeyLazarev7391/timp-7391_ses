/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main() {
int n, x, count, i;
(void) scanf("%d", &n);
count = 0;
for (i = 1; i <= n; i++) {
(void) scanf("%d", &x);
if (x <= 0) {
count++;
}
}
printf("%d", count);
return 0;
}