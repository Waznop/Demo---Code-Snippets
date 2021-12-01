#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// K1. Keeping track
// - declare a variable and update it in the loop,
//   then return it as the function output
// - similar to V7 / S7 / M7 in a sense

int sum_to_n(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int factorial(int n) {
  int product = 1;
  for (int i = 1; i <= n; i++) {
    product *= i;
  }
  return product;
}

int average(const int scores[], int n) {
  int total = 0;
  // refer to A1
  for (int i = 0; i < n; i++) {
    total += scores[i];
  }
  int avg = total / n;
  return avg;
}

string join(const vector<char>& letters) {
  string out = "";
  // refer to V1
  for (char ch : letters) {
    out += ch;
  }
  return out;
}

// K2. Keeping track with condition
// - declare a variable and update it in the loop whenever
//   some criteria are met, then return it as function output
// - involves an if statement inside the loop

int sum_of_evens(const set<int>& s) {
  int total = 0;
  // refer to S1
  for (int el : s) {
    if (el % 2 == 0) {
      total += el;
    }
  }
  return total;
}

string join_by_even_keys(const map<int, string> m) {
  string out = "";
  // refer to M1
  for (const auto& [key, value] : m) {
    if (key % 2 == 0) {
      out += value;
    }
  }
  return out;
}

// K3. Keeping track + comparing elements in a container
// - declare a variable and compare it to each element of the container,
//   update it if needed then return it as function output
// - make sure to differentiate the placeholder (initial) value:
//   Option 1: use an impossible value as placeholder,
//             then replace it as soon as we get a valid value
//   Option 2: validate that there's at least 1 valid value,
//             then use that as the placeholder
//   Option 3: create a bool indicating whether the placeholder is valid,
//             then update the placeholder if it's invalid

// Option 1
int minimum_abs_value(const vector<int> v) {
  int min = -1;  // invalid placeholder
  // refer to V1
  for (int i = 0; i < v.size(); i++) {
    if (i == 0 || abs(v[i]) < min) {
      // replace invalid placeholder or update value
      min = abs(v[i]);
    }
  }
  if (min == -1) {
    // if min is still -1 here it means v is empty
    cout << "invalid" << endl;
  }
  return min;
}

// Option 2
int maximum(int a[], int n) {
  // refer to A4
  if (n <= 0) {
    cout << "invalid" << endl;
    return -1;
  }
  int max = a[0];  // valid placeholder
  // refer to A1
  for (int i = 1; i < n; i++) {
    if (a[i] > max) {
      // update value, no need to replace placeholder explicitly
      max = a[i];
    }
  }
  return max;
}

// Option 3
int closest_to_n(const set<int>& s, int n) {
  int closest = -1;  // invalid placeholder
  bool valid = false;
  // refer to S1
  for (int el : s) {
    if (!valid) {
      // replace placeholder
      closest = el;
      valid = true;
    } else if (abs(el - n) < abs(closest - n)) {
      // update value
      closest = el;
    }
  }
  if (!valid) {
    cout << "invalid" << endl;
  }
  return closest;
}

// K4. Keeping track + comparing elements in a container (with id)
// - same as above but need another variable to keep track of
//   the index / key associated with the value
// - any time you update the value, you need to update the index / key too

// Option 1
const int MAX_S = 20;
const int MAX_HW = 20;
int best_student(const int grades[MAX_S][MAX_HW], int num_s, int num_hw) {
  // refer to A4
  if (num_s < 0 || num_s >= MAX_S || num_hw < 0 || num_hw >= MAX_HW) {
    cout << "invalid" << endl;
    return -1;
  }
  int best_idx = -1;    // invalid placeholder id
  int best_grade = -1;  // invalid placeholder value
  // refer to A1
  for (int i = 0; i < num_s; i++) {
    int grade = average(grades[i], num_hw);
    // replace placeholder or update id + value
    if (i == 0 || grade > best_grade) {
      best_idx = i;
      best_grade = grade;
    }
  }
  return best_idx;
}

// Option 2
string poorest(const map<string, int>& bank) {
  // refer to M4
  if (bank.empty()) {
    cout << "invalid" << endl;
    return "";
  }
  auto poorest_it = bank.begin();  // valid placeholder id + value
  // refer to M1
  // note: starts iterating at the 2nd element
  // - bank.begin() + n doesn't work for set and map iterators
  // - next(bank.begin(), n) is a working alternative
  for (auto it = next(bank.begin(), 1); it != bank.end(); it++) {
    // update id + value, no need to replace placeholder explicitly
    if (it->second < poorest_it->second) {
      poorest_it = it;
    }
  }
  return poorest_it->first;
}

// Option 3
char initial_of_longest_word(const map<char, string>& initials_to_words) {
  char answer = ' ';             // invalid placerholder id
  int longest_word_length = -1;  // invalid placeholder value
  bool valid = false;
  // refer to M1
  for (const auto& [initial, word] : initials_to_words) {
    if (!valid) {
      // replace placeholder
      answer = initial;
      longest_word_length = word.length();
      valid = true;
    } else if (word.length() > longest_word_length) {
      // update id + value
      answer = initial;
      longest_word_length = word.length();
    }
  }
  if (!valid) {
    cout << "invalid" << endl;
  }
  return answer;
}

int main() {
  cout << sum_to_n(5) << endl;
  // should print 15
  cout << factorial(5) << endl;
  // should print 120
  int scores[5] = {60, 70, 80, 90, 100};
  cout << average(scores, 5) << endl;
  // should print 80
  cout << join({'h', 'e', 'y'}) << endl;
  // should print hey

  cout << sum_of_evens({1, -4, 12, -3, 0}) << endl;
  // should print 8
  cout << join_by_even_keys({{1, "hi "}, {4, "hello "}, {6, "world"}}) << endl;
  // should print hello world

  cout << minimum_abs_value({-6, 9, -16, 3, -2, 99}) << endl;
  // should print 2
  cout << maximum(scores, 5) << endl;
  // should print 100
  cout << closest_to_n({4, 9, 2, 10}, 5) << endl;
  // should print 4

  int grades[MAX_S][MAX_HW] = {{1, 2, 3}, {10, 20, 30}};
  cout << best_student(grades, 2, 3) << endl;
  // should print 1
  map<string, int> m = {{"Alice", 2}, {"Bob", 5}};
  cout << poorest(m) << endl;
  // should print Alice
  map<char, string> m2 = {{'A', "Apple"}, {'C', "Chocolate"}, {'O', "Orange"}};
  cout << initial_of_longest_word(m2) << endl;
  // should print C
}