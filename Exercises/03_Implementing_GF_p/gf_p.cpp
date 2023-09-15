#include "gf_p.hpp"
#include <stdexcept>

//NOTE: This is for Exercise 03

//HACK: To Quickly/User Configurably test out different P Values
std::size_t CGF_P::mP = 5;


CGF_P CGF_P::negate() const
{
    return CGF_P((mP - mValue) % mP);
}

GF_P_Result<CGF_P>  CGF_P::invert() const
{
    //throw out all 0s
    if(mValue == 0)
    {
        return GF_P_Result<CGF_P> (false, CGF_P(0));
    }
    //scan through all possibilities to find the inverse
    for(uint32_t i = 0; i < mP; i++)
    {
        if(CGF_P((mValue * i)%mP) == CGF_P(1))
        {
            return GF_P_Result<CGF_P> (true, CGF_P(i));
        }
    }
    //This gets returned when no valid pairing was found
    return GF_P_Result<CGF_P> (false, CGF_P(0));
}

CGF_P::CGF_P(uint8_t value)
{
    if(value < mP)
    {
        mValue = value;
    }
    else
    {
        //Even if I really dislike exceptions, this is the easiest way to get what I want
        //And since only the constructor throws, I can use this in my tests and to see if a part of my calculations is wrong
        throw std::overflow_error("too big");
    }
}

CGF_P CGF_P::operator+(const CGF_P& other) const
{
    return CGF_P((mValue + other.mValue) % mP);
}

CGF_P CGF_P::operator-(const CGF_P& other) const
{
    return CGF_P((mValue + other.negate().mValue) % mP);
}

CGF_P CGF_P::operator*(const CGF_P& other) const
{
    return CGF_P((mValue * other.mValue) % mP);
}

GF_P_Result<CGF_P>  CGF_P::operator/(const CGF_P& other) const
{
    GF_P_Result<CGF_P>  res = other.invert();
    if(res.isSuccess)
    {
        return GF_P_Result<CGF_P> (true,((mValue * res.result.mValue) %mP ));
    }
    else
    {
        return GF_P_Result<CGF_P> (false, res.result);
    }
}

bool CGF_P::operator==(const CGF_P& other) const
{
    if(mValue == other.mValue)
    {
        return true;
    }
    return false;
}

std::size_t CGF_P::size()
{
    return mP;
}