#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>

class RNG {
private:
  unsigned int x, y, z, w;

  unsigned int xorshift() {
    unsigned int t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = w ^ (w >> 19) ^ t ^ (t >> 8);
  }

public:
  RNG(unsigned int s) {
    x = y = z = w = s;
    for (int i = 0; i < 1000; ++i) xorshift();
  }

  unsigned int next() {
    unsigned int d = xorshift() % 32;
    return xorshift() % (1u << d);
  }

  unsigned int prime() {
    for (unsigned int r = next(); ; ++r) {
      if (r <= 1) continue;
      if (r >= (1u << 31)) r = next();
      bool prime = true;
      for (unsigned int i = 2; i <= r / i; ++i) {
        if (r % i == 0) prime = false;
      }
      if (prime) return r;
    }
  }
};

int main(int argc, char* argv[]) {
  RNG rng(atoi(argv[1]));
  unsigned int p = rng.prime();
  unsigned int x;
  while (true) {
    x = rng.next();
    if (1 <= x && x < p) break;
  }
  unsigned int a = rng.next();
  unsigned int b = rng.next();
  if (a > b) std::swap(a, b);
  std::cout << x << " " << p << " " << a << " " << b << std::endl;
}
