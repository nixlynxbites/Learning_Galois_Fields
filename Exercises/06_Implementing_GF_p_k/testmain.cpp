#include "../utest/utest.h"
#include "gf_p_k.hpp"

//NOTE: All Tests Assume
//P = 3;
//K = 2; //GF(3^2); only polynomials below x^2
//Q = 10; //x^2+1
//NOTE: They also these values are the default values, and don't explicitly set them
//NOTE: This doesn't hold for Test 7 as that needs different values to effectively test the implementation

UTEST_MAIN();


//Basic Convertion
UTEST(1, 0)
{
    ASSERT_EQ(CGF_P_K(0), CGF_P_K(vectorNotation_t({0, 0})));
    ASSERT_EQ(CGF_P_K(1), CGF_P_K(vectorNotation_t({1, 0})));
    ASSERT_EQ(CGF_P_K(2), CGF_P_K(vectorNotation_t({2, 0})));
    ASSERT_EQ(CGF_P_K(3), CGF_P_K(vectorNotation_t({0, 1})));
    ASSERT_EQ(CGF_P_K(4), CGF_P_K(vectorNotation_t({1, 1})));
    ASSERT_EQ(CGF_P_K(5), CGF_P_K(vectorNotation_t({2, 1})));
    ASSERT_EQ(CGF_P_K(6), CGF_P_K(vectorNotation_t({0, 2})));
    ASSERT_EQ(CGF_P_K(7), CGF_P_K(vectorNotation_t({1, 2})));
    ASSERT_EQ(CGF_P_K(8), CGF_P_K(vectorNotation_t({2, 2})));
}

//Convertion Identity
UTEST(1, 1)
{
    ASSERT_EQ(CGF_P_K(0).getDecimal(), 0);
    ASSERT_EQ(CGF_P_K(1).getDecimal(), 1);
    ASSERT_EQ(CGF_P_K(2).getDecimal(), 2);
    ASSERT_EQ(CGF_P_K(3).getDecimal(), 3);
    ASSERT_EQ(CGF_P_K(4).getDecimal(), 4);
    ASSERT_EQ(CGF_P_K(5).getDecimal(), 5);
    ASSERT_EQ(CGF_P_K(6).getDecimal(), 6);
    ASSERT_EQ(CGF_P_K(7).getDecimal(), 7);
    ASSERT_EQ(CGF_P_K(8).getDecimal(), 8);
}


//Initialisation
UTEST(1, 2){
    //Decimal Representation too large
    try
    {
        CGF_P_K(9);
        ASSERT_TRUE_MSG(0, "(9)");
    }
    catch(...)
    {
        ASSERT_TRUE(1);
    }
    //Element of vector representation too large
    try
    {
        CGF_P_K(vectorNotation_t({3, 1}));
        ASSERT_TRUE_MSG(0, "{3, 1}");
    }
    catch(...)
    {
        ASSERT_TRUE(1);
    }
    //Element of vector representation too large
    try
    {
        CGF_P_K(vectorNotation_t({0, 3}));
        ASSERT_TRUE_MSG(0, "{0, 3}");
    }
    catch(...)
    {
        ASSERT_TRUE(1);
    }
    //Too many elements in vector representation
    try
    {
        CGF_P_K(vectorNotation_t({1, 1, 1}));
        ASSERT_TRUE_MSG(0, "{1, 1, 1}");
    }
    catch(...)
    {
        ASSERT_TRUE(1);
    }
}

//Addition
UTEST(1, 3){
    ASSERT_EQ(CGF_P_K(0)+CGF_P_K(1), CGF_P_K(1));
    ASSERT_EQ(CGF_P_K(1)+CGF_P_K(1), CGF_P_K(2));
    ASSERT_EQ(CGF_P_K(1)+CGF_P_K(2), CGF_P_K(0));
    ASSERT_EQ(CGF_P_K(2)+CGF_P_K(2), CGF_P_K(1));
    ASSERT_EQ(CGF_P_K(1)+CGF_P_K(3), CGF_P_K(4));
    ASSERT_EQ(CGF_P_K(2)+CGF_P_K(3), CGF_P_K(5));
    ASSERT_EQ(CGF_P_K(3)+CGF_P_K(3), CGF_P_K(6));
    ASSERT_EQ(CGF_P_K(2)+CGF_P_K(4), CGF_P_K(3));
    ASSERT_EQ(CGF_P_K(4)+CGF_P_K(4), CGF_P_K(8));
    ASSERT_EQ(CGF_P_K(2)+CGF_P_K(7), CGF_P_K(6));
    ASSERT_EQ(CGF_P_K(6)+CGF_P_K(7), CGF_P_K(4));
    ASSERT_EQ(CGF_P_K(8)+CGF_P_K(8), CGF_P_K(4));
}

//Subtraction
UTEST(1, 4){
    ASSERT_EQ(CGF_P_K(1)-CGF_P_K(0), CGF_P_K(1));
    ASSERT_EQ(CGF_P_K(0)-CGF_P_K(1), CGF_P_K(2));
    ASSERT_EQ(CGF_P_K(1)-CGF_P_K(1), CGF_P_K(0));
    ASSERT_EQ(CGF_P_K(1)-CGF_P_K(2), CGF_P_K(2));
    ASSERT_EQ(CGF_P_K(2)-CGF_P_K(2), CGF_P_K(0));
    ASSERT_EQ(CGF_P_K(1)-CGF_P_K(3), CGF_P_K(7));
    ASSERT_EQ(CGF_P_K(2)-CGF_P_K(3), CGF_P_K(8));
    ASSERT_EQ(CGF_P_K(3)-CGF_P_K(3), CGF_P_K(0));
    ASSERT_EQ(CGF_P_K(2)-CGF_P_K(4), CGF_P_K(7));
    ASSERT_EQ(CGF_P_K(4)-CGF_P_K(4), CGF_P_K(0));
    ASSERT_EQ(CGF_P_K(2)-CGF_P_K(7), CGF_P_K(4));
    ASSERT_EQ(CGF_P_K(6)-CGF_P_K(7), CGF_P_K(2));
    ASSERT_EQ(CGF_P_K(8)-CGF_P_K(8), CGF_P_K(0));
}

//Multiplication
UTEST(1, 5){
    ASSERT_EQ(CGF_P_K(0)*CGF_P_K(1), CGF_P_K(0));
    ASSERT_EQ(CGF_P_K(0)*CGF_P_K(2), CGF_P_K(0));
    ASSERT_EQ(CGF_P_K(1)*CGF_P_K(1), CGF_P_K(1));
    ASSERT_EQ(CGF_P_K(1)*CGF_P_K(2), CGF_P_K(2));
    ASSERT_EQ(CGF_P_K(2)*CGF_P_K(2), CGF_P_K(1));
    ASSERT_EQ(CGF_P_K(2)*CGF_P_K(3), CGF_P_K(6));
    ASSERT_EQ(CGF_P_K(3)*CGF_P_K(3), CGF_P_K(2));
    ASSERT_EQ(CGF_P_K(2)*CGF_P_K(4), CGF_P_K(8));
    ASSERT_EQ(CGF_P_K(3)*CGF_P_K(4), CGF_P_K(5));
    ASSERT_EQ(CGF_P_K(4)*CGF_P_K(4), CGF_P_K(6));
    ASSERT_EQ(CGF_P_K(2)*CGF_P_K(7), CGF_P_K(5));
    ASSERT_EQ(CGF_P_K(6)*CGF_P_K(7), CGF_P_K(8));
    ASSERT_EQ(CGF_P_K(8)*CGF_P_K(8), CGF_P_K(6));
}

//Division
UTEST(1, 6){
    GF_P_K_Result res(false, CGF_P_K(0));
    
    res = CGF_P_K(0)/CGF_P_K(1);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(0));
    res = CGF_P_K(0)/CGF_P_K(2);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(0));
    res = CGF_P_K(1)/CGF_P_K(0);
    ASSERT_FALSE(res.isSuccess);
    res = CGF_P_K(2)/CGF_P_K(0);
    ASSERT_FALSE(res.isSuccess);
    res = CGF_P_K(1)/CGF_P_K(1);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(1));
    res = CGF_P_K(1)/CGF_P_K(2);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(2));
    res = CGF_P_K(2)/CGF_P_K(2);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(1));
    res = CGF_P_K(2)/CGF_P_K(3);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(3));
    res = CGF_P_K(3)/CGF_P_K(3);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(1));
    res = CGF_P_K(1)/CGF_P_K(4);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(5));
    res = CGF_P_K(2)/CGF_P_K(4);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(7));
    res = CGF_P_K(3)/CGF_P_K(4);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(8));
    res = CGF_P_K(4)/CGF_P_K(4);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(1));
    res = CGF_P_K(1)/CGF_P_K(7);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(8));
    res = CGF_P_K(2)/CGF_P_K(7);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(4));
    res = CGF_P_K(6)/CGF_P_K(7);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(5));
    res = CGF_P_K(1)/CGF_P_K(8);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(7));
}

//Division part two
UTEST(1, 7){
    CGF_P_K::setGlobalP(2);
    CGF_P_K::setGlobalK(3);
    CGF_P_K::setGlobalQ(11);
    GF_P_K_Result res(false, CGF_P_K(0));
    
    res = CGF_P_K(4)/CGF_P_K(4);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(1));

    res = CGF_P_K(7)/CGF_P_K(7);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P_K(1));
}

//Test for Util
UTEST(1, 8)
{
    ASSERT_EQ(CGF_P_K(3, 2, 2).getVector(), CGF_P_K(vectorNotation_t({1, 1}), 2, 2).getVector());
    ASSERT_EQ(CGF_P_K::getKfromP(2, 3), 2);
    ASSERT_EQ(CGF_P_K::getKfromP(2, 2), 2);
    ASSERT_EQ(CGF_P_K::getKfromP(2, 1), 1);
    ASSERT_EQ(CGF_P_K::getKfromP(5, 126), 4);

    ASSERT_NE(CGF_P_K(3, 2, 2), CGF_P_K(3, 3, 2));

    GF_P_K_Full_Div_Result<vectorNotation_t> res = {false, {0}, {0}};

    res = CGF_P_K(vectorNotation_t({1, 0, 1, 0, 1}), 2, 5).fullDivision(CGF_P_K(vectorNotation_t({0, 1, 1}), 2, 3));

    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.divisionResult.size(), 3);
    ASSERT_EQ(res.divisionRemainder.size(), 2);
    ASSERT_EQ(CGF_P_K(res.divisionResult, 2, res.divisionResult.size()), CGF_P_K(vectorNotation_t({0, 1, 1}), 2, 3));
    ASSERT_EQ(CGF_P_K(res.divisionRemainder, 2, res.divisionRemainder.size()), CGF_P_K(vectorNotation_t({1, 0}), 2, 2));

    //No asserts for this code, it was causing segfaults, tests are easier to debug
    CGF_P_K num1 = CGF_P_K(7, 3, CGF_P_K::getKfromP(3, 7));
    CGF_P_K num2 = CGF_P_K(2, 3, CGF_P_K::getKfromP(3, 2));
    res = num1.fullDivision(num2);
}


