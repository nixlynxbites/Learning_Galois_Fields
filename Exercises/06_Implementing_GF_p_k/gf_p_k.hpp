#pragma once
#include <stdint.h>
#include <cstddef>
#include <vector>

//NOTE: This is for Exercise 06

//NOTE: "Endianness" Definition (Vector Representation):
//Index 0 => x^0
//Index 1 => x^1
//Index 2 => x^2
//Or, In General Terms
//Index n => x^2


typedef uint32_t fieldsize_t;
typedef std::vector<fieldsize_t> vectorNotation_t;
typedef fieldsize_t decimalNotation_t;

//Added to return invalid states
template <class T>
struct GF_P_K_Result
{
    bool isSuccess;
    T result;
    GF_P_K_Result(bool success, T res) : isSuccess(success), result(res){};
};

class CGF_P_K
{
private:
    //HACK: To Quickly/User Configurably test out different P, K, Q Values
    static fieldsize_t mP;
    static fieldsize_t mK;
    static fieldsize_t mQ;
public:
    static void setP(fieldsize_t P) {mP = P;};
    static void setK(fieldsize_t K) {mK = K;};
    static void setQ(fieldsize_t Q) {mQ = Q;};

private:

    //TODO: a way to optimise is might be to hold both representations in memory. I'd need to take care of keeping them synchronised though
    //For now, we don't care about optimisation though
    vectorNotation_t mInternalRepresentation;

    decimalNotation_t ConvertVectorToDecimal(vectorNotation_t vec) const;
    //Note: the second parameter is needed, as we usually use it with K, but we also use this function to convert Q, which uses a power of K+1
    vectorNotation_t ConvertDecimalToVector(decimalNotation_t dec, uint32_t numberOfElements = mK) const;

    fieldsize_t addCoefficient(fieldsize_t a, fieldsize_t b) const;
    fieldsize_t negateCoefficient(fieldsize_t a) const;
    fieldsize_t multiplyCoefficient(fieldsize_t a, fieldsize_t b) const;

    //NOTE: the return value here will have a size of 2K-1 instead of K
    vectorNotation_t multiplyPolynomial(const vectorNotation_t vec1, const vectorNotation_t vec2) const;
    //NOTE: this function takes a vector of size 2K-1 as vec1 and the vector representation of our Q and return a vector of size K
    vectorNotation_t moduloPolynomial(vectorNotation_t vec1, const vectorNotation_t Q) const;

    GF_P_K_Result<CGF_P_K> invertPolynomial() const;

public:
    
    CGF_P_K(decimalNotation_t dec);
    CGF_P_K(vectorNotation_t vec);

    CGF_P_K operator+(const CGF_P_K& other) const;
    CGF_P_K operator-(const CGF_P_K& other) const;
    CGF_P_K operator*(const CGF_P_K& other) const;
    GF_P_K_Result<CGF_P_K> operator/(const CGF_P_K& other) const;
    
    bool operator==(const CGF_P_K& other) const;

    decimalNotation_t getDecimal() const;
    vectorNotation_t getVector() const;

    fieldsize_t size() const;
};