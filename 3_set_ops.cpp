#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// S1. Iterate without modifying
// - use const reference
// - eg. print (return void)
// - eg. sum (return int)
void print(const set<string>& s) {
  // range-based is the simplest
  // - el has type string because s is a set of strings
  for (const string& el : s) {
    cout << el << endl;
  }

  // iterator-based also works
  // for (auto it = s.begin(); it != s.end(); it++) {
  //   cout << *it << endl;
  // }
}

// S2. Iterate with modifying
// - N/A
// - don't do it, remove then insert instead (refer to S5 / S6)

// S3. Search
// - refer to S2 if we want to modify what we find, otherwise S1
// - eg. check if a user is registered
bool is_registered(const set<string>& s, const string& user) {
  // count() is the simplest
  return s.count(user) > 0;

  // find() also works
  // return s.find(user) != s.end();
}

// S4. Input validation
// - generally not needed as we don't do indexing on sets
// - but just in case:
string get_first(const set<string>& s) {
  if (s.empty()) {
    return "";  // invalid
  }
  return *s.begin();
}

// S5. Insert in place
// - eg. sign up for a new user
void signup(set<string>& list, const string& user) { list.insert(user); }

// S6. Remove in place
// - eg. delete a user
void delete_user(set<string>& list, const string& user) { list.erase(user); }

// S7. Create new
// - declare and populate new variable to return as function output
// - eg. create a set of all odd integers from 1 to n
set<int> odd_til_n(int n) {
  set<int> odds;  // declare new variable to return at the end
  for (int i = 1; i <= n; i += 2) {
    odds.insert(i);
  }
  return odds;
}

int main() {
  set<string> s = {"Alice", "Alice", "Bob"};
  print(s);
  // should print Alice, Bob in new lines
  cout << "Bob is registered: " << is_registered(s, "Bob") << endl;
  cout << "First: " << get_first(s) << endl;
  // should print Alice
  // should print 1 (true)
  signup(s, "Alice");
  // s should remain unchanged since "Alice" is already in it
  delete_user(s, "Bob");
  // s should now be {"Alice"}

  set<int> s2 = odd_til_n(10);
  // s2 should be {1, 3, 5, 7, 9}
}