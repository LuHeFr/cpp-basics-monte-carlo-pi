#include <iostream>
#include <random>

using namespace std;

int main() {
  random_device rd{};  // Zufallszahl aus der Temperatur
  mt19937 rng{rd()};   //"pseudo Zufallszahlen" ahnhand einer echten Zufallszahl
  uniform_real_distribution<float> dist{
      0, 1};  // Verteilungsfunktion zischen 0 und 1
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

  auto monte_carlo_pi = 4 * float(c) / float(n);
  cout << "pi = " << monte_carlo_pi << '\n';
}