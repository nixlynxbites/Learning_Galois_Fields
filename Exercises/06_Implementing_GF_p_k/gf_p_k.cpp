#include "gf_p_k.hpp"
#include <stdexcept>
#include <cmath>

//NOTE: This is for Exercise 06

//HACK: To Quickly/User Configurably test out different P Values
fieldsize_t CGF_P_K::mP = 3;
fieldsize_t CGF_P_K::mK = 2; //GF(3^2); only polynomials below x^2
fieldsize_t CGF_P_K::mQ = 10; //x^2+1



decimalNotation_t CGF_P_K::ConvertVectorToDecimal(vectorNotation_t vec) const
{
    //NOTE: what we are doing here is basically this
    //f(x) = ((a)*x+b)*x+c
    //which is an equivalent representation to
    //f(x) = ax^2 + bx + c
    //The latter is what we expect to need to do here
    //While the former seems to have quite a few advantages in code (as in, it should complete in O(n) time, and doesn't need any pow(x))
    //Keep in Mind that our Vector stores it's information like this vec[0] = c; vec[1] = b; vec[2] = a;
    //With that said, here's the implementation:

    fieldsize_t dec = 0;

    for(vectorNotation_t::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
    {
        dec = (dec * mP) + *it;
    }
    return dec;
}

vectorNotation_t CGF_P_K::ConvertDecimalToVector(decimalNotation_t dec, uint32_t numberOfElements) const
{
    //NOTE: this should be self explainatory
    //So I'm gonna briefly explain
    //we take the modulo of our decimal value giving us our x^0 value
    //then we shift by x (mP) making our x^1 value our new x^0 value, which we'll then modulo again
    //that way, we'll fill our vector like this vec[0] = c; vec[1] = b; vec[2] = a;
    //where a; b; c stand for f(x) = ax^2 + bx + c

    vectorNotation_t vec = {};

    for(fieldsize_t i = 0; i < numberOfElements; i++)
    {
        vec.push_back(dec % mP);
        dec = dec / mP;
    }
    return vec;
}

fieldsize_t CGF_P_K::addCoefficient(fieldsize_t a, fieldsize_t b) const
{
    return (a+b) % mP;
}

fieldsize_t CGF_P_K::negateCoefficient(fieldsize_t a) const
{
    return (mP - a) % mP;
}

fieldsize_t CGF_P_K::multiplyCoefficient(fieldsize_t a, fieldsize_t b) const
{
    return (a * b) % mP;
}

vectorNotation_t CGF_P_K::multiplyPolynomial(const vectorNotation_t vec1, const vectorNotation_t vec2) const
{
    vectorNotation_t resultVector = {};
    resultVector.resize((2*mK)-1);

    for(fieldsize_t i = 0; i < (2*mK)-1; i++)
    {
        for(fieldsize_t j = 0; j < mK; j++)
        {
            if(i < j || i-j > mK)
            {
                //out of bounds values (implicitly zero)
                continue;
            }
            //vec1 is reversed here (with i as upper bounds)
            //this is because reversing with i as upper bounds causes all multiplication of the current i cycle to result in the same x^n
            //small example:
            //i=1
            //for j=0 it results in x^1 * x^0 (x^1 because i-j = 1; x^0 because j = 0)
            //for j=1 it results in x^0 * x^1 (x^0 because i-j = 0; x^0 because j = 1)
            //and since this example uses K=2, those are the only possible combinations that result in x^1
            resultVector[i] = addCoefficient(resultVector[i], multiplyCoefficient(vec1[i-j], vec2[j]));
        }
    }
    return resultVector;
}

vectorNotation_t CGF_P_K::moduloPolynomial(vectorNotation_t vec1, const vectorNotation_t Q) const
{
    //Iterate in reverse order since the highest index holds the highest x^n
    for(fieldsize_t i = ((2*mK)-1)-1; i >= mK; i--)
    {
        //The first shift should have a size of K-1; the last shift of 0
        fieldsize_t shift = i-mK;
        //if our x^n coefficient is 0; this will also return 0 and the cycle will have no effect
        fieldsize_t scale = negateCoefficient(vec1[i]);

        //this loop just applies our scaling factor to every element taking part in the division
        for(fieldsize_t j = shift; j <= i; j++)
        {
            fieldsize_t temp = multiplyCoefficient(scale, Q[j-shift]);
            vec1[j] = addCoefficient(vec1[j], temp);
        }
        //we'll just pop the elements of vec1 that we just zeroed through division, giving us a vector of size K at the end
        vec1.pop_back();
    }
    return vec1;
}

GF_P_K_Result<CGF_P_K> CGF_P_K::invertPolynomial() const
{
    //Brute force method
    if(*this == CGF_P_K(0))
    {
        //0 has no inverse
        return GF_P_K_Result(false, CGF_P_K(0));
    }
    //Scan through all possibilities until we find one that works
    for(fieldsize_t i = 1; i < size(); i++)
    {
        if((*this * CGF_P_K(i)) == CGF_P_K(1))
        {
            return GF_P_K_Result(true, CGF_P_K(i));
        }
    }
    //Nothing found
    return GF_P_K_Result(false, CGF_P_K(0));
}

CGF_P_K::CGF_P_K(decimalNotation_t dec)
{
    if(dec < size())
    {
        mInternalRepresentation = ConvertDecimalToVector(dec);
    }
    else
    {
        //Even if I really dislike exceptions, this is the easiest way to get what I want
        //And since only the constructor throws, I can use this in my tests and to see if a part of my calculations is wrong
        throw std::overflow_error("decimal representation too big");
    }
}

CGF_P_K::CGF_P_K(vectorNotation_t vec)
{
    //Check if Vector Representation has the correct size
    if(vec.size() != mK)
    {
        throw std::overflow_error("vector size too big (or too small)");
    }
    //Check if all elements of vector representation are within bounds of mP
    for(vectorNotation_t::iterator it = vec.begin(); it != vec.end(); it++)
    {
        if(*it >= mP)
        {
            throw std::overflow_error("vector item too big");
        }
    }
    mInternalRepresentation = vec;
}


CGF_P_K CGF_P_K::operator+(const CGF_P_K& other) const
{
    vectorNotation_t vec = {};
    for(fieldsize_t i = 0; i < mK; i++)
    {
        vec.push_back(addCoefficient(mInternalRepresentation[i], other.mInternalRepresentation[i]));
    }
    return vec;
}

CGF_P_K CGF_P_K::operator-(const CGF_P_K& other) const
{
    vectorNotation_t vec = {};
    for(fieldsize_t i = 0; i < mK; i++)
    {
        vec.push_back(addCoefficient(mInternalRepresentation[i], negateCoefficient(other.mInternalRepresentation[i])));
    }
    return vec;
}

CGF_P_K CGF_P_K::operator*(const CGF_P_K& other) const
{
    return CGF_P_K(moduloPolynomial(multiplyPolynomial(mInternalRepresentation, other.mInternalRepresentation), ConvertDecimalToVector(mQ, mK+1)));
}

GF_P_K_Result<CGF_P_K> CGF_P_K::operator/(const CGF_P_K& other) const
{
    GF_P_K_Result<CGF_P_K>  res = other.invertPolynomial();
    if(res.isSuccess)
    {
        return GF_P_K_Result<CGF_P_K> (true,(((*this) * res.result)));
    }
    else
    {
        return GF_P_K_Result<CGF_P_K> (false, res.result);
    }
}

bool CGF_P_K::operator==(const CGF_P_K& other) const
{
    for(fieldsize_t i = 0; i < mK; i++)
    {
        if(mInternalRepresentation[i] != other.mInternalRepresentation[i])
        {
            return false;
        }
    }
    return true;
}

decimalNotation_t CGF_P_K::getDecimal() const
{
    return ConvertVectorToDecimal(mInternalRepresentation);
}

vectorNotation_t CGF_P_K::getVector() const
{
    return mInternalRepresentation;
}

fieldsize_t CGF_P_K::size() const
{
    //TODO: ensure there's no overflows
    return std::pow(mP, mK);
}


vectorNotation_t CGF_P_K::getVectorRepresentationStatic(const fieldsize_t P, const fieldsize_t dec)
{
    fieldsize_t decBuf = dec;
    fieldsize_t bufferP = mP;
    CGF_P_K::setP(P);
    vectorNotation_t vec = {};

    fieldsize_t K = 0;
    //calculate our K
    for(;decBuf!=0; K++, decBuf=decBuf/P);

    vec = CGF_P_K(0).ConvertDecimalToVector(dec, K);

    CGF_P_K::setP(bufferP);
    return vec;
}