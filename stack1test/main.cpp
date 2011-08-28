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


void testStack1Pop(void){
    Stack<std::string> s = Stack<std::string>();
    BOOST_CHECK_THROW(s.pop() , std::out_of_range);
    s.push("test");
    BOOST_CHECK_NO_THROW(s.pop());
    BOOST_CHECK_THROW(s.pop() , std::out_of_range);
    return;
}


void testStack1Top(void)
{
    //check for Stack<int>
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

    return;
}


void testStack1Push(void)
{
    Stack<std::string> s = Stack<std::string>();
    BOOST_CHECK_NO_THROW(s.push("test"));
}


void testStack1Empty(void)
{
    Stack<std::string> s = Stack<std::string>();
    BOOST_CHECK_EQUAL(s.empty() , true);
    s.push("test");
    BOOST_CHECK_EQUAL(s.empty() , false);
}


void testStack1Destructor(void)
{
    Stack<std::string*>* s = new Stack<std::string*>();
    std::string* s1 = new std::string("test1");
    std::string* s2 = new std::string("test2");
    s->push(s1);
    s->push(s2);
    delete s;
    BOOST_CHECK(*s1 == "test1");
}


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
