#include <iostream>

int main() {
  char str[101];
  int i = 0;
  std::cin >> str;
  for (;str[i] != 0 && i <= 100;i++)
  {
    std::cout << str[i];
    if (i != 0 && (i + 1) % 10 == 0)
      std::cout << "\n";
  }
  return 0;
}
