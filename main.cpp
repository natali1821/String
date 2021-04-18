#include <iostream>
#include "MyString.h"

int main()
{
    MyString first("Hello");
    MyString second(first);
    MyString third(MyString("Aloha"));
    MyString prob;
    prob = MyString("a");
    try{
        first.erase(7, 2);
    }
    catch(StringExceptions& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << first.rawString() ;
}
