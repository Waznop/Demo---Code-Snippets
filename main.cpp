#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// Return how many odd VALUES there are in the map
// Hints: M1, K2
int count_odd_values(const map<int, int>& m) { return -1; }

// Return the index of the first dimension (a[i]) with the largest sum
// Hints: A1, K1, A1, A1, K4
int biggest_first_dimension(const int a[3][3][3]) { return -1; }

// Return the smallest difference between indices in the two vectors (v1[i] and
// v2[i]). If they don't have the same length, return -1.
// Hint: V4, V1, K3
int smallest_difference(const vector<int>& v1, const vector<int>& v2) {
  return -1;
}

// Return the list of names from the lottery map who chose a number that's among
// the winning numbers.
// Hint: V7, M1, S1, K2
vector<string> lottery_winners(const map<string, set<int>>& lottery,
                               const set<int>& winning_numbers) {
  return {};
}

// Remove duplicates from the vector while keeping the same ordering.
// Hint: V7, V1, K2, V5 / V6
void remove_dupes(vector<int>& v) { return; }

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