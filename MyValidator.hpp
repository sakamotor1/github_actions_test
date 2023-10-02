#ifndef MY_VALIDATOR_H_
#define MY_VALIDATOR_H_

#include <stdexcept>

/**
* @file MyVallidator.cpp
* @brief 各種バリデーション機能を提供する
*/

/**
 * データベースアクセス用クラス
*/
class MyDataBase {
public:
    /**
     * データベースから最低年齢を取得する。DBエラー時はruntime_errorをスローする。
     * 
     * @return 最低年齢
     * @throws std::runtime_error
    */
    virtual unsigned int getMinAge() = 0;

    /**
     * デストラクタ
    */
    virtual ~MyDataBase() {}
};

/**
 * データベースアクセス用クラスimpl
*/
class MyDataBaseImpl : public MyDataBase {
public:
    /**
     * コンストラクタ
    */
    MyDataBaseImpl() : MyDataBase() {}

    /**
     * データベースから最低年齢を取得する。DBエラー時はruntime_errorをスローする。
     * 
     * @return 最低年齢
     * @throws std::runtime_error
    */
    virtual unsigned int getMinAge() override {return 20;}
    
    /**
     * デストラクタ
    */
    virtual ~MyDataBaseImpl() {}
};

/**
 * 各種バリデーション機能を提供するクラス
*/
class MyValidator {
    friend class MyValidatorTest;
private:
    /** データベースにアクセスするためのオブジェクト */
    MyDataBase *db;

    /**
     * 加算処理を行う
     * 
     * @param[in] val1 加算する数値
     * @param[in] val2 加算する数値
     * @return val1とval2の合計値
    */
    int privateAdd(int val1, int val2) const;
public:

    /**
     * コンストラクタ
     * 
     * @param[in] db 内部でデータベースアクセスに利用されるデータベースオブジェクト
    */
    MyValidator(MyDataBase *db) : db(db) {}

    /**
     * 入力値が月の数になっているかを判定する。
     * 
     * @param[in] inputValue 判定する入力値
     * @return bool inputValueが1〜12ならtrue、それ以外ならfalse。
    */
    bool isMonth(unsigned int inputMonth) const ;

    /**
     * 入力値が最低年齢以上かを判定する。
     * 
     * @param[in] inputValue 判定する入力値
     * @return bool inputValueが最低年齢以上ならtrue、それ以外ならfalse。
    */
    bool isOver(unsigned int targetAge) const ;
};

#endif