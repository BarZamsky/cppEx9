#pragma once
#include <iostream>
#include <sstream>
using namespace std; 

//template <typename T>
class TestCase
{
    string _testName;
    ostream& stream;
    int pass,fail;

    public:
    TestCase(const string s, ostream& os): _testName(s), stream(os) { pass=0;fail=0;}
                                        
    template <typename T>
    TestCase check_equal(T a, T b)
    {
    if (a==b) pass++;
    else
    {        
        fail++;
        stream<<_testName<<": Failure in test #"<< fail <<": "<<a<<" should equal "<<b<<"!\n";
    }
    return *this; 
    }

     template <typename T>
    TestCase check_different(T a, T b)
    {
         if (a!=b) pass++;
    else
    {        
        fail++;
        stream<<_testName<<": Failure in test #"<< fail <<": "<<a<<" should not equal "<<b<<"!\n";
    }
    return *this; 

    }

    template <typename T>
    TestCase check_function(T (*f)(T),T num, T result)
    {
        T a=f(num);
        if (a==result){ pass++;}
        else
        {
            fail++;
            stream<<_testName<<": Failure in test #"<< fail <<": Function should return "<<result<<" but returned "<<a<<"\n";
        }
        return *this;
    }

    template <typename T1, typename T2>
    TestCase check_function(T2 (*fncptr)(T1),T1 num, T2 result)
    {
        T1 a=fncptr(num);
        if (a==result){ pass++;}
        else
        {
            fail++;
            stream<<_testName<<": Failure in test #"<< fail <<": Function should return "<<result<<" but returned "<<a<<"\n";
        }
        return *this;
    }

   template <typename T1,typename T2,typename T3>
   TestCase check_function(T1 (*f)(const T2),T3 num, T1 result)
   {
       T1 a=f(num);
        if (a==result){ pass++;}
        else
        {
            fail++;
            stream<<_testName<<": Failure in test #"<< fail <<": Function should return "<<result<<" but returned "<<a<<"\n";
        }
        return *this;
   }

    template <typename T>
    TestCase check_output(T a, string str )
    {   
        stringstream ss;
        ss << a;
        if(ss.str().compare(str)==0) pass++;
        else {
            fail++;
            stream<<_testName<<": Failure in test #"<< fail <<": string value should be "<< str << " but is " << ss.str() << "\n"; 
            }
            return *this;
    }

    void print()
    {
        stream<< _testName<<": "<< fail<<" failed, "<<pass<<" passed, "<<fail+pass<<" total\n";
    }
   
};


