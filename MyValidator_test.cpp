#include <gtest/gtest.h>
#include <gmock/gmock.h> 
#include <stdexcept>
#include "MyValidator.hpp"
//
class MockMyDataBaseImpl : public MyDataBaseImpl {
 public:
    MOCK_METHOD(unsigned int, getMinAge, (), (override));
};

// フィクスチャークラス
class MyValidatorTest : public testing::Test {
  protected:
    MockMyDataBaseImpl db;
    MyValidator *validator;

    virtual void SetUp() {
        validator = new MyValidator(&db);
    }
    
    virtual void TearDown() {
        delete validator;
    }

    int privateAdd(int val1, int val2) {return validator->privateAdd(val1, val2);}
};

TEST_F(MyValidatorTest, 入力値0は月の数と判定されないこと) {
    EXPECT_FALSE(validator->isMonth(0));
}

TEST_F(MyValidatorTest, 入力値1は月の数と判定されること) {
    EXPECT_TRUE(validator->isMonth(1));
}

TEST_F(MyValidatorTest, 入力値12は月の数と判定されること) {
    EXPECT_TRUE(validator->isMonth(12));
}

TEST_F(MyValidatorTest, 入力値13は月の数と判定されないこと) {
    EXPECT_FALSE(validator->isMonth(13));
}

// dbからMinAgeを取得する処理をモック化し、20が返ってくるように定義
TEST_F(MyValidatorTest, 年齢19歳は最低年齢以上と判定されないこと) {
    EXPECT_CALL(db, getMinAge()).WillOnce(testing::Return(20));

    EXPECT_FALSE(validator->isOver(19));
}

TEST_F(MyValidatorTest, 年齢20歳は最低年齢以上と判定されること) {
    EXPECT_CALL(db, getMinAge()).WillOnce(testing::Return(20));

    EXPECT_TRUE(validator->isOver(20));
}

TEST_F(MyValidatorTest, DBアクセスで例外が発生した場合に最低年齢以上と判定されないこと) {
    EXPECT_CALL(db, getMinAge()).WillOnce(testing::Throw(std::runtime_error("DBアクセスエラー")));

    EXPECT_FALSE(validator->isOver(20));
}

TEST_F(MyValidatorTest, 1と2を加算した値は3) {
    EXPECT_EQ(privateAdd(1, 2), 3);
}