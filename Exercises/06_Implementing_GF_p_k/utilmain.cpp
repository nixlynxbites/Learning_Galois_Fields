#include "gf_p_k.hpp"
#include <string.h>
#include <stdio.h>
#include <string>

const char* helpText = 
"-h\tshows help\n"
"--help\tshows help\n"
"-r [P] [n]\tshows the polynomial and vector representation of the number in GF(P)\n"
;//"-f [P] [K]\tfind irreducable polynomials in GF(P^K)";

struct argStruct
{
    bool showHelp;
    bool showRepresentation;
    bool findIrreducablePolynomials;
    fieldsize_t P;
    fieldsize_t N;
    fieldsize_t K;
};

argStruct ParseArgs(int argc, char* argv[]);
void DisplayData(fieldsize_t P, fieldsize_t K, fieldsize_t N, vectorNotation_t vec);

int main(int argc, char* argv[])
{
    printf("GFUtil V0.0.1\nGFUtil -h for help\n\n");
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
        printf("\tVector:\t\t[");
        //Invert loop, because internal representation is easier to calculate with, but external expects the first element to be the highest x^n
        for(uint32_t i = 1; i <= vec.size(); i++)
        {
            printf("%u", vec[vec.size()-i]);
            if(i != vec.size())
            {
                printf(", ");
            }
        }
        printf("]\n");
        printf("\tPolynomial:\t");
        for(uint32_t i = 1; i <= vec.size(); i++)
        {
            printf("%ux^%u", vec[vec.size()-i], vec.size()-i);
            if(i != vec.size())
            {
                printf(" + ");
            }
        }
        printf("\n");
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
    argRes.P = 0;
    argRes.N = 0;
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
        else if (strcmp(argv[i], "-f") == 0)
        {
            argRes.findIrreducablePolynomials = true;
            argRes.P = std::stoi(argv[++i]);
            argRes.K = std::stoi(argv[++i]);
        }
    }
    return argRes;
}
