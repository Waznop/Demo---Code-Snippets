#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

// V1. Iterate without modifying
// - use const reference
// - eg. print (return void)
// - eg. sum (return int)
void print(const vector<int>& v) {
  // range-based is the simplest
  // - el has type int because v is a vector of ints
  // - eg. if v was a vector of strings then el would be a string
  //       in which case we should use `const string& el`
  for (int el : v) {
    cout << el << endl;
  }

  // index-based if the index is needed
  // for (int i = 0; i < v.size(); i++) {
  //   cout << v[i] << endl;
  // }

  // iterator-based also works
  // for (auto it = v.begin(); it != v.end(); it++) {
  //   cout << *it << endl;
  // }
}

// V2. Iterate with modifying
// - use non-const reference
// - eg. initialize all to some value
// - eg. add 1 to all
void add_one(vector<int>& v) {
  // range-based is simplest
  for (int& el : v) {
    el += 1;
  }

  // index-based if the index is needed
  // for (int i = 0; i < v.size(); i++) {
  //   v[i]++;
  // }

  // iterator-based also works
  // for (auto it = v.begin(); it != v.end(); it++) {
  //   (*it)++;
  // }
}

// V3. Search
// - refer to V2 if we want to modify what we find, otherwise V1
// - involves if statement inside of loop
// - eg. check if every element is smaller than some cap
bool all_smaller_than(const vector<int>& v, int cap) {
  for (int el : v) {
    if (el >= cap) {
      return false;
    }
  }
  // this means we couldn't find any element that's >= cap
  return true;
}

// V4. Input validation
// - prevent crashing due to out of bounds access
// - involves if statement BEFORE access (generally at the beginning)
// - eg. get the first element
int get_first(const vector<int>& v) {
  if (v.empty()) {
    return -1;  // invalid
  }
  return v[0];
}

// V5. Insert in place
// - refer to V2 since insert requires modifying
// - don't insert while iterating
// - if we wanted to insert at multiple different places,
//   prefer just creating new (refer to V7) and overriding old value
// - eg. sign up for a new user
void signup(vector<string>& list, const string& user) {
  // eg. if we want to keep the list sorted
  auto it = list.begin();  // declare outside of loop to use it later
  for (; it != list.end(); it++) {
    // refer to V3
    if (*it >= user) {
      // we found where to insert, but don't do it inside the loop
      break;
    }
  }
  list.insert(it, user);

  // eg. if we just wanted to add to the end
  // list.push_back(user);
}

// V6. Remove in place
// - refer to V2 since remove requires modifying
// - don't remove while iterating
// - if we wanted to remove from multiple different places,
//   prefer just creating new (refer to V7) and overriding old value
// - eg. delete a user
void delete_user(vector<string>& list, const string& user) {
  // refer to V4
  if (list.empty()) {
    return;
  }
  auto it = list.begin();
  for (; it != list.end(); it++) {
    // refer to V3
    if (*it == user) {
      // we found where to erase, but don't do it inside the loop
      break;
    }
  }
  // only erase if it's a valid location
  if (it != list.end()) {
    list.erase(it);
  }

  // eg. if we just wanted to delete from the end
  // list.pop_back();
}

// V7. Create new
// - declare and populate new variable to return as function output
// - eg. merge 2 lists of users together
vector<string> merge(const vector<string>& v1, const vector<string>& v2) {
  vector<string> merged(v1);  // declare new variable to return at the end
  // refer to V1
  for (const string& user : v2) {
    // eg. if we want to keep the list sorted
    signup(merged, user);

    // eg. if we just wanted to add to the end
    // merged.push_back(user);
  }
  return merged;
}

int main() {
  vector<int> v = {3, 1, 2};
  add_one(v);
  print(v);
  // should print 4, 2, 3 in new lines
  cout << "First: " << get_first(v) << endl;
  // should print 4
  cout << "All smaller than 4: " << all_smaller_than(v, 4) << endl;
  // should print 0 (false)

  vector<string> users = {"Alice", "Carl"};
  signup(users, "Bob");
  // users should now be {"Alice", "Bob", "Carl"}
  delete_user(users, "Carl");
  // users should now be {"Alice", "Bob"}
  users = merge(users, {"Annie", "Carla"});
  // users should now be {"Alice", "Annie", "Bob", "Carla"}
}