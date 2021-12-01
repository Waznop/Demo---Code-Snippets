#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// M1. Iterate without modifying
// - use const reference
// - eg. print (return void)
// - eg. sum (return int)
void print(const map<string, int>& m) {
  // range-based with decomposition declaration is the simplest
  for (const auto& [key, value] : m) {
    cout << key << ": " << value << endl;
  }

  // normal range-based also works
  // for (const auto& el : m) {
  //   cout << el.first << ": " << el.second << endl;
  // }

  // iterator-based also works
  // for (auto it = m.begin(); it != m.end(); it++) {
  //   cout << it->first << ": " << it->second << endl;
  // }
}

// M2. Iterate with modifying (values only)
// - use non-const reference
// - eg. initialize all values to something
// - eg. add a fixed pay to everyone's balance in a bank
void pay_day(map<string, int>& bank, int pay) {
  // range-based with decomposition declaration is the simplest
  for (auto& [name, balance] : bank) {
    balance += pay;
  }

  // normal range-based also works
  // for (auto& el : bank) {
  //   el.second += pay;
  // }

  // iterator-based also works
  // for (auto it = bank.begin(); it != bank.end(); it++) {
  //   it->second += pay;
  // }
}

// M3. Search (by value)
// - refer to M2 if we want to modify what we find, otherwise M1
// - involves if statement inside of loop
// - eg. find a user with $100 at the bank
string has_100(const map<string, int>& bank) {
  for (const auto& [user, balance] : bank) {
    if (balance == 100) {
      return user;  // found one
    }
  }
  // didn't find any
  return "";  // invalid
}

// M4. Input validation (~ search by key)
// - prevent crashing due to out of bounds access
// - involves if statement BEFORE access (generally at the beginning)
// - check empty() if no keys involved
// - eg. find the account balance of a user
int balance(const map<string, int>& bank, const string& user) {
  // count() is the simplest
  if (bank.count(user) <= 0) {
    return -1;  // invalid
  }

  // find() also works
  // if (bank.find(user) == bank.end()) {
  //   return -1;
  // }

  return bank.at(user);
}

// M5. Insert in place
// - eg. sign up for a new user
void signup(map<string, int>& bank, const string& user) {
  bank.insert({user, 0});
}

// M6. Remove in place
// - eg. delete a user
void delete_user(map<string, int>& bank, const string& user) {
  bank.erase(user);
}

// M7. Create new
// - declare and populate new variable to return as function output
// - eg. create map from a list of words with their lengths as values
map<string, int> word_lengths(const vector<string>& words) {
  map<string, int> lengths;  // declare new variable to return at the end
  // refer to V1
  for (const string& word : words) {
    lengths.insert({word, word.length()});
  }
  return lengths;
}

int main() {
  map<string, int> m = {
      {"Alice", 100},
      {"Bob", 50},
  };
  pay_day(m, 20);
  print(m);
  // should print Alice: 120, Bob: 70 in new lines
  cout << "Someone with $100: " << has_100(m) << endl;
  // should print ""
  cout << "Bob's balance: " << balance(m, "Bob") << endl;
  // should print 70
  signup(m, "Carl");
  // m should now be {{"Alice", 120}, {"Bob", 70}, {"Carl", 0}}
  delete_user(m, "Bob");
  // m should now be {{"Alice", 120}, {"Carl", 0}}

  map<string, int> m2 = word_lengths({"table", "cat"});
  // m2 should be {{"cat", 3}, {"table", 5}}
}