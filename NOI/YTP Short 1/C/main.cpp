#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string n;
  cin >> n;

  string output;

  unordered_map<char, string> formulas = {
    {'0', "(6-6)"},
    {'1', "(7-6)"},
    {'2', "((((6-(7-6))-(7-6))-(7-6))-(7-6))"},
    {'3', "(((6-(7-6))-(7-6))-(7-6))"},
    {'4', "((6-(7-6))-(7-6))"},
    {'5', "(6-(7-6))"},
    {'6', "(6)"},
    {'7', "(7)"},
    {'8', "(((((7-6)+(7-6))-(7-6))-(7-6))-(7-6))"},
    {'9', "((((7-6)+(7-6))-(7-6))-(7-6))"}
  };

  for (int i = 0; i < n.size(); i++) {
    char currentDigit = n[i];
    output += formulas[currentDigit];

    if (i != n.size() - 1) {
      output += "+";
    }
  }

  cout << output << '\n';

  return 0;
}
