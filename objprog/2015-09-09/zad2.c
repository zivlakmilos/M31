/*
 * napisati program za funkciju
 * f =
 * {
 *  (x + y) / z     x > 1
 *  (x - y) / z     x = 1
 *  (x / y) * z     x < 1
 *  }
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    float x, y, z;
    float f;

    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    printf("z = ");
    scanf("%f", &z);

    if(x > 1)
        f = (x + y) / z;
    else if(x == 1)
        f = (x - y) / z;
    else
        f = (x / y) * z;

    printf("\nf = %.2f\n", f);

    return 0;
}
