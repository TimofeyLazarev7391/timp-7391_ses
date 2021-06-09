/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main(void) {
int n, x, i, sum;
sum = 0;
(void) scanf("%d", &n);
for (i = 1; i <= n; i++) {
(void) scanf("%d", &x);
sum += x - i;
}
printf("%d", sum);
return 0;
}