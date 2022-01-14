#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include "libreria.h"
#include <stdlib.h>

int get_cents(void);
int calculate_quarters(int get_cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
long get_credit_car_number();
void cash();
void credit();
void mario_less();
void mario_more();

void pset1()
{
    int back_to_main_menu = 1;
    while (back_to_main_menu == 1)
    {
        system("clear");
        int answer = get_int("\n1.Cash\n2.Credit\n3.mario_less\n4.mario_more\n5.Back to main menu.\nR/: ");
        switch (answer)
        {
        case 1:
            cash();
            break;
        case 2:
            credit();
            break;
        case 3:
            mario_less();
            break;
        case 4:
            mario_more();
            break;
        case 5:
            back_to_main_menu = 0;
            break;
        default:
            printf("\nYou did not enter a valid option...\n");
        }
    }
}

void mario_more()
{
    int keep_going = 0;
    while (keep_going == 0)
    {
        int n;
        do
        {

            n = get_int("\nHeight: ");

        } while (n < 1 || n > 8);

        int jump = 2;
        int width = (n * 2) + jump;
        int left_spaces = (width /2) - 2 ;
        int right_spaces = (width /2) + 1;

        for (int i = 0; i < n; i++, left_spaces--,right_spaces++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == width /2 || j == (width /2) - 1)
                {
                    printf(" ");
                }
                else if (j < left_spaces)
                {
                    printf(" ");
                }
                else if (j > right_spaces)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }
            printf("\n");
        }
        int question = get_int("\n[1] If you want to continue, [0] to go back to menu.\nR/: ");
        if (question == 0)
        {
            keep_going = 1;
        }          
    }
}

void mario_less()
{
    int keep_going = 0;
    while (keep_going == 0)
    {
        int n;
        do
        {

            n = get_int("\nHeight: ");

        } while (n < 1 || n > 8);


        int spaces = n - 1;
        for (int i = 0; i < n; i++, spaces--)
        {
            for (int j = 0; j < n; j++)
            {
                if (j < spaces)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                } 
                
            }
            printf("\n");
        }
        int question = get_int("\n[1] If you want to continue, [0] to go back to menu.\nR/: ");
        if (question == 0)
        {
            keep_going = 1;
        }          
    }
}

void credit()
{
    int keep_going = 0;
    while (keep_going == 0)
    {
        system("\nclear");   
        long number = get_credit_car_number();
        int suma = 0;
        int suma2 = 0; 
        int result = 0;
        int valid = 0;
        int contador = 0;

        while (contador < 16)
        {
            long digit = number / pow(10,contador);
            contador++;
            int last = contador + 1;
            if (digit < 100)
            {
                //printf("%li\n", digit);
                
                if ((digit == 34 || digit == 37) && last == 15)
                {
                    printf("AMEX\n");
                }
                else if ((digit >= 51 && digit <= 55) && last == 16)
                {
                    printf("MASTERCARD\n");
                }
                else if ((last == 13 || last == 16) && (digit >= 40 && digit <= 49))
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("OTHERS\n");
                }                  
                break;   
            }
        }
        //printf("%i\n", contador + 1);

        for (int i = 1; i < contador + 1; i+=2) 
        {   
            int digit = fmod(number / pow(10,i), 10) * 2;

            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
            suma = suma + digit;
            //printf("%i ", digit);
        }
        //printf("\n%i\n", suma);

        for (int j = 0; j < contador; j+=2)
        {
            int digit2 = fmod(number / pow(10,j), 10);

            //printf("%i ",digit2);
            suma2 = suma2 + digit2;
        }
        //printf("\n%i\n", suma2);

    
        result = suma + suma2;
        valid = result % 10;

        if (valid != 0)
        {
            system("\nclear");
            printf("Number: %li\nINVALID\n\n", number);
        }   
        //printf("%i", result);
        int question = get_int("\n[1] If you want to continue, [0] to go back to menu.\nR/: ");
        if (question == 0)
        {
            keep_going = 1;
        }        
    }
}

void cash(void)
{
    int keep_going = 0;
    while (keep_going == 0)
    { 
        system("clear");
        int cents = get_cents();
        int quarters = calculate_quarters(cents);
        int dimes = calculate_dimes(cents);
        int nickels = calculate_nickels(cents);
        int pennies = calculate_pennies(cents);
        printf("\nQuarters: %i\nDimes: %i\nNickels: %i\nPennies: %i \n\n", quarters, dimes, nickels, pennies);
        int question = get_int("\n[1] If you want to continue, [0] to go back to menu.\nR/: ");
        if (question == 0)
        {
            keep_going = 1;
        }
    }
}

long get_credit_car_number()
{
    long number;
    do
    {
        number = get_long("\nNumber: ");
    } while (number < 1);    
    return number;
}

int get_cents(void)
{   
    int cents_owed;

    do
    {
        cents_owed = get_int("\nHow many cents I owed you? ");
    } while (cents_owed < 0);

    return cents_owed;   
}

int calculate_quarters(int cents)
{
    int quarters = cents / 25;
    return quarters;
}


int calculate_dimes(int cents)
{
    int dimes = (cents % 25) / 10;
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = ((cents % 25) % 10) / 5;
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = (((cents % 25) % 10) % 5) / 1;
    return pennies;
}