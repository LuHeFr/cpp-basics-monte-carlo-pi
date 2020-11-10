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

  for (int i = 0; i < 10; ++i) {
    cout << random() << '\n';
  }
}