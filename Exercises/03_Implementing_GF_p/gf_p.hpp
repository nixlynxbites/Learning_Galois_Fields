#pragma once
#include <stdint.h>
#include <cstddef>

//NOTE: This is for Exercise 03

class CGF_P;

//Added to return invalid states
template <class T>
struct GF_P_Result
{
    bool isSuccess;
    T result;
    GF_P_Result(bool success, T res) : isSuccess(success), result(res){};
};

class CGF_P
{
private:
    static std::size_t mP;
    //HACK: To Quickly/User Configurably test out different P Values
public:
    static void setP(std::size_t P) {mP = P;};

private:
    CGF_P negate() const;
    GF_P_Result<CGF_P> invert() const;

public:
    //Lazyness
    uint8_t mValue;


    CGF_P(uint8_t value);

    CGF_P operator+(const CGF_P& other) const;
    CGF_P operator-(const CGF_P& other) const;
    CGF_P operator*(const CGF_P& other) const;
    GF_P_Result<CGF_P> operator/(const CGF_P& other) const;

    bool operator==(const CGF_P& other) const;

    std::size_t size();
};