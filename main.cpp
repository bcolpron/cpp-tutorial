#include <iostream>


//
//         ** Passing strings - the proper way **
//
//  What is best way (A, B or C) to pass string to the functions below?
//

extern "C" { void legacy(const char* s); }

/* A */ void foo(const std::string& s)  { legacy(s.c_str()); }
/* B */ void foo(const char* s)         { legacy(s        ); }
/* C */ void foo(std::string s)         { legacy(s.c_str()); }

extern std::string global_str;

/* A */ void bar(const std::string& s)  { global_str = s;            }
/* B */ void bar(const char* s)         { global_str = s;            }
/* C */ void bar(std::string s)         { global_str = std::move(s); }          


int main(int, const char*[])
{
    foo("this is a string literal");
    bar(function_returning_a_std_string());
    return 0;
}



