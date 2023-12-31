#include "../utest/utest.h"
#include "gf_p.hpp"



UTEST_MAIN();

//NOTE: All Tests Assume P=5
//NOTE: They also assume P=5 is the default

//Initialisation
UTEST(1, 1){
    try
    {
        CGF_P(5);
        ASSERT_TRUE(0);
    }
    catch(...)
    {
        ASSERT_TRUE(1);
    }
}

//Addition
UTEST(1, 2){
    ASSERT_EQ(CGF_P(0)+CGF_P(1), CGF_P(1));
    ASSERT_EQ(CGF_P(1)+CGF_P(1), CGF_P(2));
    ASSERT_EQ(CGF_P(1)+CGF_P(2), CGF_P(3));
    ASSERT_EQ(CGF_P(2)+CGF_P(2), CGF_P(4));
    ASSERT_EQ(CGF_P(1)+CGF_P(3), CGF_P(4));
    ASSERT_EQ(CGF_P(2)+CGF_P(3), CGF_P(0));
    ASSERT_EQ(CGF_P(3)+CGF_P(3), CGF_P(1));
    ASSERT_EQ(CGF_P(2)+CGF_P(4), CGF_P(1));
    ASSERT_EQ(CGF_P(4)+CGF_P(4), CGF_P(3));
}

//Subtraction
UTEST(1, 3){
    ASSERT_EQ(CGF_P(1)-CGF_P(0), CGF_P(1));
    ASSERT_EQ(CGF_P(0)-CGF_P(1), CGF_P(4));
    ASSERT_EQ(CGF_P(1)-CGF_P(1), CGF_P(0));
    ASSERT_EQ(CGF_P(1)-CGF_P(2), CGF_P(4));
    ASSERT_EQ(CGF_P(2)-CGF_P(2), CGF_P(0));
    ASSERT_EQ(CGF_P(1)-CGF_P(3), CGF_P(3));
    ASSERT_EQ(CGF_P(2)-CGF_P(3), CGF_P(4));
    ASSERT_EQ(CGF_P(3)-CGF_P(3), CGF_P(0));
    ASSERT_EQ(CGF_P(2)-CGF_P(4), CGF_P(3));
    ASSERT_EQ(CGF_P(4)-CGF_P(4), CGF_P(0));
}

//Multiplication
UTEST(1, 4){
    ASSERT_EQ(CGF_P(0)*CGF_P(1), CGF_P(0));
    ASSERT_EQ(CGF_P(0)*CGF_P(2), CGF_P(0));
    ASSERT_EQ(CGF_P(1)*CGF_P(1), CGF_P(1));
    ASSERT_EQ(CGF_P(1)*CGF_P(2), CGF_P(2));
    ASSERT_EQ(CGF_P(2)*CGF_P(2), CGF_P(4));
    ASSERT_EQ(CGF_P(2)*CGF_P(3), CGF_P(1));
    ASSERT_EQ(CGF_P(3)*CGF_P(3), CGF_P(4));
    ASSERT_EQ(CGF_P(2)*CGF_P(4), CGF_P(3));
    ASSERT_EQ(CGF_P(3)*CGF_P(4), CGF_P(2));
    ASSERT_EQ(CGF_P(4)*CGF_P(4), CGF_P(1));
}

//Division
UTEST(1, 5){
    GF_P_Result res(false, CGF_P(0));
    
    res = CGF_P(0)/CGF_P(1);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(0));
    res = CGF_P(0)/CGF_P(2);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(0));
    res = CGF_P(1)/CGF_P(0);
    ASSERT_FALSE(res.isSuccess);
    res = CGF_P(2)/CGF_P(0);
    ASSERT_FALSE(res.isSuccess);
    res = CGF_P(1)/CGF_P(1);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(1));
    res = CGF_P(1)/CGF_P(2);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(3));
    res = CGF_P(2)/CGF_P(2);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(1));
    res = CGF_P(2)/CGF_P(3);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(4));
    res = CGF_P(3)/CGF_P(3);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(1));
    res = CGF_P(2)/CGF_P(4);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(3));
    res = CGF_P(3)/CGF_P(4);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(2));
    res = CGF_P(4)/CGF_P(4);
    ASSERT_TRUE(res.isSuccess);
    ASSERT_EQ(res.result, CGF_P(1));
}


