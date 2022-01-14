#include <stdio.h>
#include "libreria.h"
#include <cs50.h>
#include <string.h>


#define menu get_int("\n1.PSET-1.\n2.PSET-2.\n3.Exit\nR/: ")
//int exit = 0;

int main(void)
{
    int exit = 0;
   
    while (exit == 0)
    {           
        system("clear");
        switch (menu)
        {
        case 1:
            pset1();
            break;
        case 2:
            pset2();
            break;
        case 3:
            exit = 1;
            break;
        default:
            printf("You did not enter a valid option\n\n");
        }        
    }
}