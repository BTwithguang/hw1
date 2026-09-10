/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include "split.h"

int main(int argc, char* argv[])
{
{Node* a=new Node(3,nullptr);
Node* o=nullptr;
Node* e=nullptr;
split(a,o,e);
std::cout << "a is nullptr: " << (a == nullptr) << '\n';
if(o!=nullptr){std::cout << "o value: " << (o->value) << '\n';}
std::cout << "e is nullptr: " << (e == nullptr) << '\n';
delete o;

}

{Node* a=nullptr;
Node* o=nullptr;
Node* e=nullptr;
split(a,o,e);
std::cout << "a is nullptr: " << (a == nullptr) << '\n';
std::cout << "o is nullptr: " << (o == nullptr) << '\n';
std::cout << "e is nullptr: " << (e == nullptr) << '\n';
delete o;


}

{Node* a=new Node(2,nullptr);
Node* o=nullptr;
Node* e=nullptr;
split(a,o,e);
std::cout << "a is nullptr: " << (a == nullptr) << '\n';
if(e!=nullptr){std::cout << "e value: " << (e->value) << '\n';}
std::cout << "o is nullptr: " << (o == nullptr) << '\n';
delete e;


}
{Node* a=new Node(2,nullptr);
  a->next=new Node(3,nullptr);
   
Node* o=nullptr;
Node* e=nullptr;
split(a,o,e);
std::cout << "a is nullptr: " << (a == nullptr) << '\n';
if(e!=nullptr){std::cout << "e value: " << (e->value) << '\n';}
if(o!=nullptr){std::cout << "o value: " << (o->value) << '\n';}
delete o;
delete e;


}
}