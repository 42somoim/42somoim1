#include <iostream>

int main() {
  int N;
  int i, j;

  std::cin >> N;
  for (i = 1; i < N; i++)
  {
    for(j = 1; j < i; j++)
      std::cout << " ";
    for(j = 0; j <= 2 * (N - i); j++)
      std::cout << "*";
    std::cout << "\n";
  }
  for (; i > 0; i--)
  {
    for(j = 1; j < i; j++)
      std::cout << " ";
    for(j = 0; j <= 2 * (N - i); j++)
      std::cout << "*";
    std::cout << "\n";
  }
  return 0;
}
