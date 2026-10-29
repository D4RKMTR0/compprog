#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin >> t;

  vector<float> tower1;
  vector<float> tower2;

  while (t--) {
    float n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    while (n--) {
      int x, y;
      cin >> x >> y;

      float t1Distance = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)); 
      float t2Distance = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
      if (t1Distance < t2Distance) {
        tower1.push_back(t1Distance);
      } else {
        tower2.push_back(t2Distance);
      }
    }

    float t1Total = tower1.empty() ? 0.f : pow(*max_element(tower1.begin(), tower1.end()), 2.0f);
    float t2Total = tower2.empty() ? 0.f : pow(*max_element(tower2.begin(), tower2.end()), 2.0f);

    cout << (t1Total + t2Total) << '\n';

    tower1.clear();
    tower2.clear();
  }

  return 0;
}
