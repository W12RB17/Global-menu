#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include "libreria.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void readability();
void caesar();


void pset2()
{
    int keep_going = 0;
    while (keep_going == 0)
    {
        system("clear");
        int answer = get_int("\n1.Readability\n2.Caesar\n3.Substitution\n4.Back to main menu.\nR/: ");
        switch (answer)
        {
        case 1:
            readability();
            break;
        case 2:
            caesar();
            break;
        case 3:
            printf("\nMissing option\n\n");
            break;
        case 4:
            keep_going = 1;
        default:
            printf("\nYou did not enter a valid option...\n");
        }
    }
}

void caesar()
{
    int keep_going = 0;
    while (keep_going == 0)
    {
        system("clear");
        int get_key = get_int("Enter the key: ");

        int key = get_key % 26;
        
        string plaintext = get_string("Plaintext:  ");
        printf("ciphertext: ");
        
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int ciphertext = plaintext[i] + key;
            if (plaintext[i] <= 122 && plaintext[i] >= 97)
            {
                if (ciphertext > 122)
                {
                    printf("%c", (ciphertext % 122) + 96);
                }
                else
                {
                    printf("%c", ciphertext);    
                }
            }
            else if (plaintext[i] <= 90 && plaintext[i] >= 65)
            {
                if (ciphertext > 90)
                {
                    printf("%c", (ciphertext % 90) + 64);
                }
                else
                {
                    printf("%c", ciphertext);    
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        int question = get_int("\n[1] If you want to continue, [0] to go back to menu.\nR/: ");
        if (question == 0)
        {
            keep_going = 1;
        }          
    }
}


void readability()
{
    int keep_going = 0;
    while (keep_going == 0)
    {
        system("clear");
        float letters = 0;
        int i = 0; 
        float words = 0;
        float sentences = 0;

        string text = get_string("\nText: ");

        for (int i = 0; i < strlen(text); i++) 
        {
            if (isalpha(text[i]))  
            letters++;  
        }
        //printf("%f letters\n", letters); 
        for (i = 0; text[i] != '\0'; i++)
        {
            if((text[i] != ' ' && text[i+1]==' ')||(text[i+1] == '\0' && text[i] != ' '))
            {
                words++;
            }    
        }
        //printf("%f words\n", words );
        for (i = 0; text[i] != '\0'; i++)
        {
            if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
                sentences++;
            }
        }

        float L = (letters / words) * 100;
        float S = ((sentences * 100) / words);
        float grade = (0.0588 * L )-( 0.296 * S) - 15.8;
        //printf("%f sentences\n", sentences );
        //printf("L = %f, S = %f, grade = %.f", L, S, grade);
        if (grade > 16)
        {
            printf("\nGrade: 16+\n\n");
        }
        else
        {
            printf("\nGrade: %.f\n\n", round(grade));
        }
        int question = get_int("\n[1] If you want to continue, [0] to go back to menu.\nR/: ");
        if (question == 0)
        {
            keep_going = 1;
        }          
    }
}