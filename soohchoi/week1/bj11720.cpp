#include <iostream>

int main() {
  int N, i = 0;
  int sum = 0;
  std::string str;
  
  std::cin >> N;
  std::cin >> str;
  for (;str[i] != 0 && i <= 100;i++)
  {
    sum += str[i] - '0';
  }
  std::cout << sum << "\n";
  return 0;
}
