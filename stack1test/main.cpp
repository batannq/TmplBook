//
//  main.cpp
//  stack1test
//
//  Created by 中野 俊亮 on 11/08/27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <boost/test/included/unit_test_framework.hpp>
#include "stack1.hpp"
#include "mystruct.hpp"

using boost::unit_test_framework;
using boost::unit_test_framework::test_suite;

test_suite* init_unit_test_suite(int argc, char** argv);
void testStack1Pop(void);
void testStack1Top(void);
void testStack1Push(void);
void testStack1Empty(void);
void testStack1Destructor(void);

//pop()のテスト
void testStack1Pop(void){
    //check for Stack<std::string>
    Stack<std::string> s = Stack<std::string>();
    BOOST_CHECK_THROW(s.pop() , std::out_of_range);
    s.push("test");
    BOOST_CHECK_NO_THROW(s.pop());
    BOOST_CHECK_THROW(s.pop() , std::out_of_range);
    
    //check for Stack<mystruct>
    Stack<mystruct> smystruct = Stack<mystruct>();
    mystruct ms = {1 , 1.0};
    BOOST_CHECK_THROW(smystruct.pop() , std::out_of_range);
    smystruct.push(ms);
    BOOST_CHECK_NO_THROW(smystruct.pop());
    BOOST_CHECK_THROW(smystruct.pop() , std::out_of_range);
    
    //check for Stack<std::string*>
    Stack<std::string*> sstrp = Stack<std::string*>();
    std::string* str1 = new std::string("test");
    BOOST_CHECK_THROW(sstrp.pop() , std::out_of_range);
    sstrp.push(str1);
    BOOST_CHECK_NO_THROW(sstrp.pop());
    BOOST_CHECK_THROW(sstrp.pop() , std::out_of_range);
    
    return;
}

//top()のテスト
void testStack1Top(void)
{
    //check for Stack<std::string>
    Stack<std::string> s = Stack<std::string>();
    s.push("test1");
    BOOST_CHECK_EQUAL(s.top() , "test1");
    s.push("test2");
    BOOST_CHECK_EQUAL(s.top() , "test2");
    
    //check for Stack<mystruct>
    Stack<mystruct> smystruct = Stack<mystruct>();
    mystruct ms = {1 , 1.0};
    smystruct.push(ms);
    BOOST_CHECK_EQUAL(smystruct.top().a , 1);
    BOOST_CHECK_EQUAL(smystruct.top().b , 1.0);
    ms.a = -1;
    ms.b = -1.0;
    BOOST_CHECK_EQUAL(smystruct.top().a , 1);
    BOOST_CHECK_EQUAL(smystruct.top().b , 1.0);
    smystruct.push(ms);
    BOOST_CHECK_EQUAL(smystruct.top().a , -1);
    BOOST_CHECK_EQUAL(smystruct.top().b , -1.0);
    
    //check for Stack<std::string*>
    Stack<std::string*> sstrp = Stack<std::string*>();
    std::string* str1 = new std::string("test");
    sstrp.push(str1);
    BOOST_CHECK_EQUAL(*(sstrp.top()) , "test");
    
    return;
}

//push()のテスト
void testStack1Push(void)
{
    //check for Stack<std::string>
    Stack<std::string> s = Stack<std::string>();
    BOOST_CHECK_NO_THROW(s.push("test"));
    
    //check for Stack<mystruct>
    Stack<mystruct> smystruct = Stack<mystruct>();
    mystruct ms = {1 , 1.0};
    BOOST_CHECK_NO_THROW(smystruct.push(ms));
    
    //check for Stack<std::string*>
    Stack<std::string*> sstrp = Stack<std::string*>();
    std::string* str1 = new std::string("test");
    BOOST_CHECK_NO_THROW(sstrp.push(str1));
    
    return;
}

//empty()のテスト
void testStack1Empty(void)
{
    //check for Stack<std::string>
    Stack<std::string> s = Stack<std::string>();
    BOOST_CHECK_EQUAL(s.empty() , true);
    s.push("test");
    BOOST_CHECK_EQUAL(s.empty() , false);
    
    //check for Stack<mystruct>
    Stack<mystruct> smystruct = Stack<mystruct>();
    BOOST_CHECK_EQUAL(smystruct.empty() , true);
    mystruct ms = {1 , 1.0};
    smystruct.push(ms);
    BOOST_CHECK_EQUAL(smystruct.empty() , false);
    
    //check for Stack<std::string*>
    Stack<std::string*> sstrp = Stack<std::string*>();
    BOOST_CHECK_EQUAL(sstrp.empty() , true);
    std::string* str1 = new std::string("test");
    sstrp.push(str1);
    BOOST_CHECK_EQUAL(smystruct.empty() , false);
    
    return;
}

//デストラクタのテスト
void testStack1Destructor(void)
{
    //check for Stack<std::string*>
    Stack<std::string*>* s = new Stack<std::string*>();
    std::string* str1 = new std::string("test1");
    std::string* str2 = new std::string("test2");
    //std::string str3 = "test3";
    s->push(str1);
    s->push(str2);
    //s->push(&str3);
    BOOST_CHECK(*str1 == "test1");
    BOOST_CHECK(*str2 == "test2");
    delete s;
    //s1とs2が解放されたかどうかを検査していない...
    //解放出来ない変数をpushしたあとの動作を検査していない...
    return;
}

//テストメイン
test_suite* init_unit_test_suite(int argc, char** argv)
{
    test_suite* test = BOOST_TEST_SUITE("Stack1Test");
    
    test->add(BOOST_TEST_CASE(&testStack1Push)); 
    test->add(BOOST_TEST_CASE(&testStack1Pop));
    test->add(BOOST_TEST_CASE(&testStack1Top));
    test->add(BOOST_TEST_CASE(&testStack1Empty));
    test->add(BOOST_TEST_CASE(&testStack1Destructor));

    return test;
}
