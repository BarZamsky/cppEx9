// #include "TestCase.hpp"

// //template<class T>
// //TestCase::TestCase(const string s, ostream& os): _testName(s), stream(os) { pass=0;fail=0;}

// template <class T>
// TestCase TestCase<T>::check_equal(T a, T b)
// {
//     if (a==b) pass++;
//     else
//     {        
//         fail++;
//         stream<<_testName<<": Failure in test #"<< fail <<":"<<a<<"should equal "<<b<<"!\n";
//     }
//     return *this; 
//     }