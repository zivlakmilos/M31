/*
 * Autor:           Zivlak Milos
 * Datum izrade:    9.11.2015.
 *
 * Tekst zadatka:
 *  Napisati program koji za uneti broj od 1 do 30
 *  ispisuje koji je to dan u mesecu, ako je 1 ponedeljak.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int day;

    printf("Uneti datum (dan u mesecu) [1-30]: ");
    scanf("%d", &day);

    switch(day % 7)
    {
        case 0:
            printf("Nedelja\n");
            break;
        case 1:
            printf("Ponedeljak\n");
            break;
        case 2:
            printf("Utorak\n");
            break;
        case 3:
            printf("Sreda\n");
            break;
        case 4:
            printf("Cetvrtak\n");
            break;
        case 5:
            printf("Petak\n");
            break;
        case 6:
            printf("Subota\n");
            break;
    }

    return 0;
}
