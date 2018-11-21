//
// Created by jonb on 11/18/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#define private public
#define protected public
#include "../BoolInput.h"
using namespace ::testing;
using namespace std;
#include <typeinfo>

const string testPinName = "fooBar";
class MockTypeTemplate : public BoolInput {
public:
    MockTypeTemplate() : BoolInput(testPinName) {}
    MOCK_METHOD1(registerPin, void(const string &name));
};

class TypeTemplateTest : public Test {
public:
    shared_ptr<BoolInput> TT;
    void SetUp(){
        TT = shared_ptr<BoolInput>(new BoolInput());
    }
    void TearDown(){
        TT.reset();
    }
};
TEST_F(TypeTemplateTest, created) {
    ASSERT_TRUE(TT);
}
TEST_F(TypeTemplateTest, registerPinName) {
    TT->registerPin("foo");
    ASSERT_EQ(TT->name, "/bool/foo");
}
TEST_F(TypeTemplateTest, constructWithPinName) {
//    auto thisTest = MockTypeTemplate();
    //    auto thisTest = unique_ptr<MockTypeTemplate>(new MockTypeTemplate((string)"bar"));

//    auto  thisTest = unique_ptr<BoolInput>(new BoolInput((string)"bar"));
//    ASSERT_EQ(thisTest->name, "bar");
}

