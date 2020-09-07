#include <iostream>

int main() {
  int N;
  int i, j;

  std::cin >> N;
  for (i = 1; i < N; i++)
  {
    for (j = 1; j <= N - i; j++)
      std::cout << " ";
    std::cout << "*";
    for (j = 1; j < 2 * i - 2 ; j++)
      std::cout << " ";
    if(i != 1)
      std::cout << "*";
    std::cout << "\n";
  }
  for (i = 0; i < 2 * N - 1; i++)
    std::cout << "*";
  std::cout << "\n";
  return 0;
}
