#include "gf_p_k.hpp"
#include <string.h>
#include <stdio.h>
#include <string>
#include <cmath>

const char* helpText = 
"-h\tshows help\n"
"--help\tshows help\n"
"-r [P] [n]\tshows the polynomial and vector representation of the number in GF(P)\n"
"-d [P] [n1] [n2]\tdo a polynomial division of n1/n2 in GF(P)\n"
"-f [P] [K]\tfind irreducable polynomials in GF(P^K)[HEAVY]\n";

struct argStruct
{
    bool showHelp;
    bool showRepresentation;
    bool findIrreducablePolynomials;
    bool doPolynomialDivision;
    fieldsize_t P;
    fieldsize_t N;
    fieldsize_t N2;
    fieldsize_t K;
};

argStruct ParseArgs(int argc, char* argv[]);
void PrintDecimal(fieldsize_t dec);
void PrintVector(vectorNotation_t vec);
void PrintPolynomial(vectorNotation_t vec);

int main(int argc, char* argv[])
{
    printf("GFUtil V0.1.0\nGFUtil -h for help\n\n");
    argStruct args = ParseArgs(argc, argv);

    if(args.showHelp)
    {
        printf(helpText);
        return 0;
    }
    if(args.showRepresentation)
    {
        printf("Using GF(%u)[x]:\n", args.P);
        printf("\tDecimal:\t%u\n", args.N);
        vectorNotation_t vec = CGF_P_K(args.N, args.P, CGF_P_K::getKfromP(args.P, args.N)).getVector();
        printf("\tVector:\t\t");
        PrintVector(vec);
        printf("\n");
        printf("\tPolynomial:\t");
        PrintPolynomial(vec);
        printf("\n");
        return 0;
    }
    if(args.doPolynomialDivision)
    {
        printf("Using GF(%u)[x]:\n", args.P);
        CGF_P_K num1 = CGF_P_K(args.N, args.P, CGF_P_K::getKfromP(args.P, args.N));
        CGF_P_K num2 = CGF_P_K(args.N2, args.P, CGF_P_K::getKfromP(args.P, args.N2));
        GF_P_K_Full_Div_Result<vectorNotation_t> res = num1.fullDivision(num2);

        if (res.isSuccess != true)
        {
            printf("Invalid Values\n\n");
        }
        else
        {
            CGF_P_K div = CGF_P_K(res.divisionResult, args.P, res.divisionResult.size());
            CGF_P_K rem = CGF_P_K(res.divisionRemainder, args.P, res.divisionRemainder.size());
            printf("\tDecimal:\t%u / %u = %u R %u\n", num1.getDecimal(), num2.getDecimal(), div.getDecimal(), rem.getDecimal());
            printf("\tVector:\t\t");
            PrintVector(num1.getVector());
            printf(" / ");
            PrintVector(num2.getVector());
            printf("\n\t\t\t= ");
            PrintVector(div.getVector());
            printf(" R ");
            PrintVector(rem.getVector());
            printf("\n");

            printf("\tPolynomial:\t");
            PrintPolynomial(num1.getVector());
            printf(" / ");
            PrintPolynomial(num2.getVector());
            printf("\n\t\t\t= ");
            PrintPolynomial(div.getVector());
            printf(" R ");
            PrintPolynomial(rem.getVector());
            printf("\n");
        }
        return 0;
    }
    if(args.findIrreducablePolynomials)
    {
        printf("Irreducable Polynomials in GF(%u^%u):\n\n", args.P, args.K);
        bool reduced = false;
        //Loop through all Polynomials that have x^K as the highest order term
        const fieldsize_t PpowK = std::pow(args.P, args.K);
        const fieldsize_t PpowK1 = std::pow(args.P, args.K+1);
        for(fieldsize_t i = PpowK; i < PpowK1; i++)
        {
            CGF_P_K num1 = CGF_P_K(i, args.P, CGF_P_K::getKfromP(args.P, i));
            //Test for all of GF(P^K) elements, exiting if we've managed to reduce it, because it obviously isn't irreducable
            //Note: we need to start at P, as everything is reducable by a ax^0 term
            for(fieldsize_t j = args.P; j < PpowK; j++)
            {
                CGF_P_K num2 = CGF_P_K(j, args.P, CGF_P_K::getKfromP(args.P, j));
                GF_P_K_Full_Div_Result<vectorNotation_t> res = num1.fullDivision(num2);
                if(CGF_P_K(res.divisionRemainder, args.P, res.divisionRemainder.size()) == CGF_P_K(0, args.P, res.divisionRemainder.size()))
                {
                    reduced = true;
                    break;
                }
            }
            if(reduced == false)
            {
                printf("\tDecimal:\t%u\n", num1.getDecimal());
                printf("\tVector:\t\t");
                PrintVector(num1.getVector());
                printf("\n");
                printf("\tPolynomial:\t");
                PrintPolynomial(num1.getVector());
                printf("\n\n");
            }
            reduced = false;
        }

        return 0;
    }
}


argStruct ParseArgs(int argc, char* argv[])
{
    argStruct argRes = {};

    //Set to default Values
    argRes.showHelp = false;
    argRes.showRepresentation = false;
    argRes.findIrreducablePolynomials = false;
    argRes.doPolynomialDivision = false;
    argRes.P = 0;
    argRes.N = 0;
    argRes.N2 = 0;
    argRes.K = 0;

    for(uint32_t i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-h") == 0)
        {
            argRes.showHelp = true;
        }
        else if (strcmp(argv[i], "--help") == 0)
        {
            argRes.showHelp = true;
        }
        else if (strcmp(argv[i], "-r") == 0)
        {
            argRes.showRepresentation = true;
            argRes.P = std::stoi(argv[++i]);
            argRes.N = std::stoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-d") == 0)
        {
            argRes.doPolynomialDivision = true;
            argRes.P = std::stoi(argv[++i]);
            argRes.N = std::stoi(argv[++i]);
            argRes.N2 = std::stoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            argRes.findIrreducablePolynomials = true;
            argRes.P = std::stoi(argv[++i]);
            argRes.K = std::stoi(argv[++i]);
        }
    }
    return argRes;
}

void PrintDecimal(fieldsize_t dec)
{
    printf("%u", dec);
}

void PrintVector(vectorNotation_t vec)
{
    //TODO: strip leading zeroes, when put into it's own function
    //Invert loop, because internal representation is easier to calculate with, but external expects the first element to be the highest x^n
    printf("[");
    for(uint32_t i = 1; i <= vec.size(); i++)
    {
        printf("%u", vec[vec.size()-i]);
        if(i != vec.size())
        {
            printf(", ");
        }
    }
    printf("]");
}

void PrintPolynomial(vectorNotation_t vec)
{
    //TODO: strip leading zeroes, when put into it's own function
    for(uint32_t i = 1; i <= vec.size(); i++)
    {
        //Skip zeroes:
        if(vec[vec.size()-i] == 0)
        {
            continue;
        }
        if(i != 1)
        {
            printf("+ ");
        }
        printf("%ux^%u ", vec[vec.size()-i], vec.size()-i);
    }
}
