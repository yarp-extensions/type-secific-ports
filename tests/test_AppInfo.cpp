//
// Created by jonb on 11/20/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#define private public
#define protected public
#include "../AppInfo.h"
using namespace ::testing;
using namespace std;

class TestSingleton
        : Singleton
{
public:
    void DestroySingleton()
    {
        // Here is where the paradox originates...
        // We are invoking the destructor directly.
        // Which in turn will invoke ~Singleton().
        this->~TestSingleton();
    }
    // We don't even need a default constructor
    // or destructor because the compiler gives us one.

};

class AppInfoTest : public Test {
    TestSingleton *pTest = 0;
    void SetUp() {
        pTest = (TestSingleton*)operator new(sizeof(TestSingleton));
    }
    void TearDown() {
        pTest->DestroySingleton();
        operator delete(pTest);
        pTest = 0;
    }
};

TEST_F(AppInfoTest, create) {
    Singleton* firstObj = Singleton::Instance();
    Singleton* secondObj = Singleton::Instance();
    ASSERT_EQ(firstObj, secondObj);
}
