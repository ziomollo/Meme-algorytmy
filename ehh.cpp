#include <iostream>
#include "tree.hpp"
#include <iomanip>
using namespace std;

int main()
{
  //hanoi(30, 'L', 'S', 'P');

  Tree tree;

  tree.push(5);
  tree.push(6);
  tree.push(4);

  std::cout << std::boolalpha;
  std::cout << tree.find(6);
  return 0;
}
