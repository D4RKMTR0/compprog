#include <iostream>
using namespace std;

long double CtoF(long long c) {
  return (c * (9.0L / 5.0L)) + 32;
}

long double CtoK(long long c) {
  return c + 273.15L;
}

long double FtoC(long long f) {
  return (f - 32) * 5.0L / 9.0L;
}

long double FtoK(long long f) {
  return FtoC(f) + 273.15L;
}

long double KtoC(long long k) {
  return k - 273.15L;
}

long double KtoF(long long k) {
  return (KtoC(k) * (9.0L / 5.0L)) + 32;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long l, r;
  char a;
  int n;
  cin >> l >> r >> a >> n;

  while (n--) {
    long long x;
    char b;
    cin >> x >> b;

    long double output;

    if (a == b) {
      output = x;
    } else {
      switch(a) {
        case 'C':
          if (b == 'F') {
            output = FtoC(x);
          } else {
            output = KtoC(x);
          }
          break;

        case 'F':
          if (b == 'C') {
            output = CtoF(x);
          } else {
            output = KtoF(x);
          }
          break;

        case 'K':
          if (b == 'C') {
            output = CtoK(x);
          } else {
            output = FtoK(x);
          }
          break;
      }
    }

    bool inLimit = (l <= output) && (output <= r);
    cout << "Heat " << (inLimit ? "Normal" : "Abnormal") << '\n';
  }

  return 0;
}
