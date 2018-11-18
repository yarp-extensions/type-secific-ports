//
// Created by jonb on 11/18/18.
//

#include <gtest/gtest.h>
#include <memory>

#define private public
#define protected public
#include "../TypeTemplate.h"
using namespace ::testing;
using namespace std;

class TypeTemplateTest : public Test {
public:
    shared_ptr<TypeTemplate> TT;
    void SetUp(){
        TT = shared_ptr<TypeTemplate>(new TypeTemplate());
    }
    void TearDown(){
        TT.reset();
    }
};


TEST_F(TypeTemplateTest, created) {
    ASSERT_TRUE(TT);
}

