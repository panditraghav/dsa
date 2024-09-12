#ifndef INPUT
#define INPUT
#include <iostream>
#include <vector>

std::vector<int> getVectorInput(int num = 0) {
  std::vector<int> arr;
  if (num == 0) {
    std::cout << "Enter number of elements in array: ";
    std::cin >> num;
  }
  std::cout << "\nEnter " << num << " elements :\n";

  for (int i = 0; i < num; i++) {
    int temp;
    std::cin >> temp;
    arr.push_back(temp);
  }
  return arr;
}
#endif
