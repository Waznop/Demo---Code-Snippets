#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// Hints: M1, K2
// O(n) where n is the map size
int count_odd_values(const map<int, int>& m) {
  int count = 0;
  // M1
  for (const auto& [key, value] : m) {
    // K2
    if (value % 2 == 1) {
      count++;
    }
  }
  return count;
}

// Hints: A1, K1, A1, A1, K4
// O(1)
int biggest_first_dimension(const int a[3][3][3]) {
  int best_idx = -1;
  int best_total = -1;
  // A1
  for (int i = 0; i < 3; i++) {
    // K1
    int total = 0;
    // A1
    for (int j = 0; j < 3; j++) {
      // A1
      for (int k = 0; k < 3; k++) {
        total += a[i][j][k];
      }
    }
    // K4
    if (i == 0 || total > best_total) {
      best_total = total;
      best_idx = i;
    }
  }
  return best_idx;
}

// Hint: V4, V1, K3
// O(n) where n is the smaller vector's size
int smallest_difference(const vector<int>& v1, const vector<int>& v2) {
  // V4
  if (v1.size() != v2.size()) {
    return -1;
  }
  int answer = 0;
  // V1
  for (int i = 0; i < v1.size(); i++) {
    int diff = abs(v1[i] - v2[i]);
    // K3
    if (i == 0 || diff < answer) {
      answer = diff;
    }
  }
  return answer;
}

// Hint: V7, M1, S1, K2
// O(nm) where n is the map size and m is the average set size in the map
vector<string> lottery_winners(const map<string, set<int>>& lottery,
                               const set<int>& winning_numbers) {
  // V7
  vector<string> winners = {};
  // M1
  for (const auto& [name, numbers] : lottery) {
    // S1
    for (int number : numbers) {
      // K2
      if (winning_numbers.count(number) > 0) {
        winners.push_back(name);
        break;
      }
    }
  }
  return winners;
}

// Hint: V7, V1, K2, V5 / V6
// O(n) where n is the vector size
void remove_dupes(vector<int>& v) {
  set<int> s = {};
  // V7
  vector<int> new_v = {};
  // V1
  for (int el : v) {
    // K2
    if (s.count(el) <= 0) {
      s.insert(el);
      new_v.push_back(el);
    }
  }
  // V5 / V6
  v = new_v;
}

int main() {
  cout << count_odd_values({{3, 2}, {4, 5}, {1, 1}, {-2, -2}}) << endl;
  // should print 2
  int a[3][3][3] = {
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      {{0, 10, 0}, {10, 0, 10}, {0, 10, 0}},
      {{2, -2, 2}, {3, -2, 3}, {8, -2, 8}},
  };
  cout << biggest_first_dimension(a) << endl;
  // should print 0
  cout << smallest_difference({5, 2, 10}, {10, -2, 8}) << endl;
  // should print 2
  vector<string> winners = lottery_winners(
      {{"Alice", {1, 4, 7}}, {"Bob", {2, 4}}, {"Carl", {6}}}, {6, 7});
  for (const string& name : winners) {
    cout << name << endl;
  }
  // should print Alice, Carl in new lines
  vector<int> v = {1, 4, 7, 7, 6, 4, 2};
  remove_dupes(v);
  for (int el : v) {
    cout << el << " ";
  }
  cout << endl;
  // should print 1, 4, 7, 6, 2
}