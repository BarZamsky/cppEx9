#pragma once
#include <iostream>
#include <sstream>
using namespace std; 

//template <typename T>
class TestCase
{
    string _testName;
    ostream& stream;
    int pass,fail,total;

    public:
    TestCase(const string s, ostream& os): _testName(s), stream(os) { pass=0;fail=0;total=0;}
                                        
    template <typename T>
    TestCase check_equal(T a, T b)
    {
    total++;
    if (a==b) pass++;
    else
    {        
        fail++;
        stream<<_testName<<": Failure in test #"<< total <<": "<<a<<" should equal "<<b<<"!\n";
    }
    return *this; 
    }

     template <typename T>
    TestCase check_different(T a, T b)
    {
    total++;
    if (a!=b) pass++;
    else
    {        
        fail++;
        stream<<_testName<<": Failure in test #"<< total <<": "<<a<<" should not equal "<<b<<"!\n";
    }
    return *this; 
    }

   template <typename T1,typename T2,typename T3>
   TestCase check_function(T1 (f) ,T2 num, T3 result)
   {
       total++;
        if (f(num)==result){ pass++;}
        else
        {
            fail++;
            stream<<_testName<<": Failure in test #"<< total <<": Function should return "<<result<<" but returned "<<f(num)<<"\n";
        }
        return *this;
   }

    template <typename T>
    TestCase check_output(T a, string str )
    {   
        total++;
        stringstream ss;
        ss << a;
        if(ss.str().compare(str)==0) pass++;
        else {
            fail++;
            stream<<_testName<<": Failure in test #"<< total <<": string value should be "<< str << " but is " << ss.str() << "\n"; 
            }
            return *this;
    }

    void print()
    {
        stream<< _testName<<": "<< fail<<" failed, "<<pass<<" passed, "<<total<<" total\n";
        stream<<"------\n";
    }
   
};


