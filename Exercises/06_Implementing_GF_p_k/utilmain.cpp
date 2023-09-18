#include "gf_p_k.hpp"
#include <string.h>
#include <stdio.h>
#include <string>

const char* helpText = 
"-h\tshows help\n"
"--help\tshows help\n"
"-r [P] [n]\tshows the polynomial and vector representation of the number in GF(P)\n";

struct argStruct
{
    bool showHelp;
    bool showRepresentation;
    fieldsize_t P;
    fieldsize_t N;
};

argStruct ParseArgs(int argc, char* argv[]);

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
        printf("\tNumber:\t\t%u\n", args.N);
        vectorNotation_t vec = CGF_P_K::getVectorRepresentationStatic(args.P, args.N);
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
    argRes.P = 0;
    argRes.N = 0;

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
    }
    return argRes;
}