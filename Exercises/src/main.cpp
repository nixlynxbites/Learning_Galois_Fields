#include "gf_p.hpp"
#include <stdio.h>


void PrintTableAddition(uint8_t P);
void PrintTableSubtraction(uint8_t P);
void PrintTableMultiplication(uint8_t P);
void PrintTableDivision(uint8_t P);

int main()
{
    printf("Current P: %u\n\n\n", 5);
    PrintTableAddition(5);
    printf("\n");
    printf("\n");
    PrintTableSubtraction(5);
    printf("\n");
    printf("\n");
    PrintTableMultiplication(5);
    printf("\n");
    printf("\n");
    PrintTableDivision(5);
    printf("\n");
    printf("\n");

    printf("Current P: %u\n\n\n", 7);
    PrintTableAddition(7);
    printf("\n");
    printf("\n");
    PrintTableSubtraction(7);
    printf("\n");
    printf("\n");
    PrintTableMultiplication(7);
    printf("\n");
    printf("\n");
    PrintTableDivision(7);
    printf("\n");
    printf("\n");

    for (uint8_t i = 0; i < 10; i++)
    {
        printf("Current P: %u\n\n\n", i);
        PrintTableAddition(i);
        printf("\n");
        printf("\n");
        PrintTableSubtraction(i);
        printf("\n");
        printf("\n");
        PrintTableMultiplication(i);
        printf("\n");
        printf("\n");
        PrintTableDivision(i);
        printf("\n");
        printf("\n");
    }

    return 0;
}


void PrintTableAddition(uint8_t P)
{
    CGF_P::setP(P);
    //Print Table Symbol
    printf("+\t");
    //Print Table Header
    for(uint8_t i = 0; i<P; i++)
    {
        printf("%u\t", i);
    }
    printf("\n");
    for(uint8_t i = 0; i<P; i++)
    {
        //Print Row Header
        printf("%u\t", i);
        for(uint8_t j = 0; j<P; j++)
        {
            //Print Row Content
            printf("%u\t", (CGF_P(i)+CGF_P(j)).mValue);
        }
        printf("\n");
    }
}

void PrintTableSubtraction(uint8_t P)
{
    CGF_P::setP(P);
    //Print Table Symbol
    printf("-\t");
    //Print Table Header
    for(uint8_t i = 0; i<P; i++)
    {
        printf("%u\t", i);
    }
    printf("\n");
    for(uint8_t i = 0; i<P; i++)
    {
        //Print Row Header
        printf("%u\t", i);
        for(uint8_t j = 0; j<P; j++)
        {
            //Print Row Content
            printf("%u\t", (CGF_P(i)-CGF_P(j)).mValue);
        }
        printf("\n");
    }
}

void PrintTableMultiplication(uint8_t P)
{
    CGF_P::setP(P);
    //Print Table Symbol
    printf("*\t");
    //Print Table Header
    for(uint8_t i = 0; i<P; i++)
    {
        printf("%u\t", i);
    }
    printf("\n");
    for(uint8_t i = 0; i<P; i++)
    {
        //Print Row Header
        printf("%u\t", i);
        for(uint8_t j = 0; j<P; j++)
        {
            //Print Row Content
            printf("%u\t", (CGF_P(i)*CGF_P(j)).mValue);
        }
        printf("\n");
    }
}

void PrintTableDivision(uint8_t P)
{
    CGF_P::setP(P);
    //Print Table Symbol
    printf("/\t");
    //Print Table Header
    for(uint8_t i = 0; i<P; i++)
    {
        printf("%u\t", i);
    }
    printf("\n");
    for(uint8_t i = 0; i<P; i++)
    {
        //Print Row Header
        printf("%u\t", i);
        for(uint8_t j = 0; j<P; j++)
        {
            //Print Row Content
            const GF_P_Result<CGF_P>  res = CGF_P(i)/CGF_P(j);
            if(res.isSuccess)
            {
                printf("%u\t", res.result.mValue);
            }
            else
            {
                printf("%c\t", '-');
            }
        }
        printf("\n");
    }
}