#include "gf_p_k.hpp"
#include <stdio.h>
#include <cmath>

void PrintTableAddition(fieldsize_t P, fieldsize_t K, fieldsize_t Q);
void PrintTableSubtraction(fieldsize_t P, fieldsize_t K, fieldsize_t Q);
void PrintTableMultiplication(fieldsize_t P, fieldsize_t K, fieldsize_t Q);
void PrintTableDivision(fieldsize_t P, fieldsize_t K, fieldsize_t Q);

int main()
{
    printf("Current P: %u K: %u Q: %u\n\n\n", 3, 2, 10);
    PrintTableAddition(3, 2, 10);
    printf("\n");
    printf("\n");
    PrintTableSubtraction(3, 2, 10);
    printf("\n");
    printf("\n");
    PrintTableMultiplication(3, 2, 10);
    printf("\n");
    printf("\n");
    PrintTableDivision(3, 2, 10);
    printf("\n");
    printf("\n");

    //Added this part to check Exercise from Chapter 05
    printf("Current P: %u K: %u Q: %u\n\n\n", 2, 3, 11);
    PrintTableAddition(2, 3, 11);
    printf("\n");
    printf("\n");
    PrintTableSubtraction(2, 3, 11);
    printf("\n");
    printf("\n");
    PrintTableMultiplication(2, 3, 11);
    printf("\n");
    printf("\n");
    PrintTableDivision(2, 3, 11);
    printf("\n");
    printf("\n");

    return 0;
}


void PrintTableAddition(fieldsize_t P, fieldsize_t K, fieldsize_t Q)
{
    CGF_P_K::setGlobalP(P);
    CGF_P_K::setGlobalK(K);
    CGF_P_K::setGlobalQ(Q);
    //Print Table Symbol
    printf("+\t");
    //Print Table Header
    for(fieldsize_t i = 0; i<std::pow(P, K); i++)
    {
        printf("%u\t", i);
    }
    printf("\n");
    for(fieldsize_t i = 0; i<std::pow(P, K); i++)
    {
        //Print Row Header
        printf("%u\t", i);
        for(fieldsize_t j = 0; j<std::pow(P, K); j++)
        {
            //Print Row Content
            printf("%u\t", (CGF_P_K(i)+CGF_P_K(j)).getDecimal());
        }
        printf("\n");
    }
}

void PrintTableSubtraction(fieldsize_t P, fieldsize_t K, fieldsize_t Q)
{
    CGF_P_K::setGlobalP(P);
    CGF_P_K::setGlobalK(K);
    CGF_P_K::setGlobalQ(Q);
    //Print Table Symbol
    printf("-\t");
    //Print Table Header
    for(fieldsize_t i = 0; i<std::pow(P, K); i++)
    {
        printf("%u\t", i);
    }
    printf("\n");
    for(fieldsize_t i = 0; i<std::pow(P, K); i++)
    {
        //Print Row Header
        printf("%u\t", i);
        for(fieldsize_t j = 0; j<std::pow(P, K); j++)
        {
            //Print Row Content
            printf("%u\t", (CGF_P_K(i)-CGF_P_K(j)).getDecimal());
        }
        printf("\n");
    }
}

void PrintTableMultiplication(fieldsize_t P, fieldsize_t K, fieldsize_t Q)
{
    CGF_P_K::setGlobalP(P);
    CGF_P_K::setGlobalK(K);
    CGF_P_K::setGlobalQ(Q);
    //Print Table Symbol
    printf("*\t");
    //Print Table Header
    for(fieldsize_t i = 0; i<std::pow(P, K); i++)
    {
        printf("%u\t", i);
    }
    printf("\n");
    for(fieldsize_t i = 0; i<std::pow(P, K); i++)
    {
        //Print Row Header
        printf("%u\t", i);
        for(fieldsize_t j = 0; j<std::pow(P, K); j++)
        {
            //Print Row Content
            printf("%u\t", (CGF_P_K(i)*CGF_P_K(j)).getDecimal());
        }
        printf("\n");
    }
}

void PrintTableDivision(fieldsize_t P, fieldsize_t K, fieldsize_t Q)
{
    CGF_P_K::setGlobalP(P);
    CGF_P_K::setGlobalK(K);
    CGF_P_K::setGlobalQ(Q);
    //Print Table Symbol
    printf("/\t");
    //Print Table Header
    for(fieldsize_t i = 0; i<std::pow(P, K); i++)
    {
        printf("%u\t", i);
    }
    printf("\n");
    for(fieldsize_t i = 0; i<std::pow(P, K); i++)
    {
        //Print Row Header
        printf("%u\t", i);
        for(fieldsize_t j = 0; j<std::pow(P, K); j++)
        {
            //Print Row Content
            const GF_P_K_Result<CGF_P_K>  res = CGF_P_K(i)/CGF_P_K(j);
            if(res.isSuccess)
            {
                printf("%u\t", res.result.getDecimal());
            }
            else
            {
                printf("%c\t", '-');
            }
        }
        printf("\n");
    }
}