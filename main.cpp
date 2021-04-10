#include <iostream>
#include "MyString.h"

int main()
{
    MyString first("Hello");
    MyString second(first);
    MyString third(MyString("Aloha"));
    MyString prob;
    prob = MyString("a");
}
