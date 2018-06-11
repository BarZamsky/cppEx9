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

   template <typename T1,typename T2,typename T3>
   TestCase check_function(T1 (f) ,T2 num, T3 result)
   {
        if (f(num)==result){ pass++;}
        else
        {
            fail++;
            stream<<_testName<<": Failure in test #"<< fail <<": Function should return "<<result<<" but returned "<<f(num)<<"\n";
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
        stream<<"------\n";
    }
   
};


