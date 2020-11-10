#include <iostream>
#include <random>

using namespace std;

int main() {
  mt19937 rng{random_device{}()};
  uniform_real_distribution<float> dist{0, 1};  // Zufallszahl
  auto random = [&]() {
    return dist(rng);
  };  // Lamdaexpression - hier definierte Funktion

  int n = 100000000;  // Anzahl der Zahlen
  int c = 0;          // Zählvariable für innerhlab des Kreises

  for (int i = 0; i < n; ++i) {
    // cout << random() << '\n';
    const auto x = random();
    const auto y = random();
    const auto r2 = x * x + y * y;
    if (r2 < 1) ++c;
  }

  const auto monte_carlo_pi = 4.0f * c / n;
  cout << "pi = " << monte_carlo_pi << '\n';
}