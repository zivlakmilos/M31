#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int src, dst;

    scanf("%d %d", &src, &dst);
    if(src == dst)
        return 0;
    if(src > 13)
    {
        src = 7;
        printf("G");
    }
    if(src > 11)
    {
        src = 6;
        printf("G");
    }
    if(src > 9)
    {
        src = 5;
        printf("G");
    }
    if(src > 7)
    {
        src = 4;
        printf("G");
    }
    if(src == 1)
    {
        if(dst % 2 == 0 || dst == 5 || (src > 7 && src < 11))
        {
            printf("L");
            src = 2;
        } else
        {
            printf("D");
            src = 3;
        }
    }
    while(src != dst)
    {
        if(src == 2)
        {
            if(dst == 4 || (dst > 7 && dst < 9))
            {
                printf("L");
                src = dst;
            } else if(dst == 5 || (dst > 7 && dst < 9))
            {
                printf("D");
                src = dst;
            }
            else
            {
                printf("G");
                if(dst == 1)
                    return 0;
                else
                {
                    src = 3;
                    printf("D");
                }
            }
        } else if(src == 3)
        {
            if(dst == 6 || (dst > 11 && dst < 14))
            {
                printf("L");
                src = dst;
            } else if(dst == 7 || dst > 13)
            {
                printf("D");
                src = dst;
            } else
            {
                printf("G");
                if(dst == 1)
                    return 0;
                else
                {
                    src = 2;
                    printf("L");
                }
            }
        }
    }

    printf("\n");
    return 0;
}
