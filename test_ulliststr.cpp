#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
{ULListStr list;
assert(list.empty());
assert(list.size()== 0);
list.pop_front();
list.pop_back();
list.push_back("one");
assert(!list.empty());
assert(list.size() == 1);
assert(list.front() =="one");
assert(list.back() == "one");
list.pop_back();
assert(list.empty());
assert(list.size() == 0);

}{
ULListStr list;
list.push_back("middle");
list.push_front("front");
list.push_back("back");
assert(list.size() == 3);
assert(list.get(0) == "front");
assert(list.get(1) == "middle");
assert(list.get(2) == "back");
list.set(1,"changed");
assert(list.get(1) == "changed");
bool excepotionCaught = 0;
try {
  list.get(100);
}
catch (const std::invalid_argument&){
  excepotionCaught = 1;
}
assert(excepotionCaught);
list.pop_front();
list.pop_back();
list.pop_back();
assert(list.empty());
assert(list.size() == 0);
}
std::cout<<"passed";
return 0;
}