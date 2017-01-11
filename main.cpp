#include <iostream>

extern std::string global_str;
std::string function_returning_a_std_string();

void foo(const std::string& s)  { printf(s.c_str()); }
void foo(const char* s)         { printf(s);         }
void foo(std::string s)         { printf(s.c_str()); }

void bar(const std::string& s)  { global_str = s;            }
void bar(const char* s)         { global_str = s;            }
void bar(std::string s)         { global_str = std::move(s); }


int main(int, const char*[])
{
    foo("this is a string literal");
    bar(function_returning_a_std_string());
    return 0;
}