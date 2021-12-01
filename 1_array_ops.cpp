#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int SIZE = 10;

// A1. Iterate without modifying
// - use const
// - eg. print (return void)
// - eg. sum (return int)
void print(const int a[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    // a[i] has type int because a is an array of ints
    // eg. if a was an array of strings then a[i] would be a string
    cout << a[i] << endl;
  }
}

// A2. Iterate with modifying
// - don't use const
// - eg. initialize all to some value
// - eg. add 1 to all
void init(int a[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    // use a[i] on the left side of = to assign a value to it
    a[i] = i;
  }
}

// A3. Search
// - refer to A2 if we want to modify what we find, otherwise A1
// - involves if statement inside of loop
// - eg. find a specific element
bool find_number(const int a[SIZE], int n) {
  for (int i = 0; i < SIZE; i++) {
    if (a[i] == n) {
      return true;  // immediately return if found
    }
  }
  // this means we couldn't find n in any of the array elements
  return false;
}

// A4. Input validation
// - prevent crashing due to out of bounds access
// - involves if statement BEFORE access (generally at the beginning)
// - eg. only n valid values
int partial_sum(const int a[SIZE], int n) {
  if (n < 0 || n >= SIZE) {
    return -1;  // invalid
  }
  int total = 0;  // use variable to keep track of running total
  for (int i = 0; i < n; i++) {
    total += a[i];
  }
  return total;
}

// A5. Insert in place
// - refer to A2 since insert requires modifying
// - since we can't actually insert into an array,
//   we use an extra int variable to simulate a growing size
//   after modifying the "last" element
// - eg. pick up passenger if there's still space
bool pickup(string car[SIZE], int& num_passengers, const string& name) {
  // refer to A4
  if (num_passengers >= SIZE || num_passengers < 0) {
    // convey that we weren't able to pick up the new passenger
    return false;
  }
  car[num_passengers] = name;
  num_passengers++;
  return true;
}

// A6. Remove in place
// - refer to A2 since remove requires modifying
// - since we can't actually remove from an array,
//   we use an extra int variable to simulate a shrinking size
// - eg. take the top out of a stack of plates
int take_top(int plates[SIZE], int& num_plates) {
  // refer to A4
  if (num_plates < 1 || num_plates > SIZE) {
    return -1;  // invalid
  }
  num_plates--;
  return plates[num_plates];  // take the last plate id
}

// A7. Create new
// - N/A
// - generally not passed as function outputs
// - generally done via {} (list initializer)
//   or some init function after declaration (refer to A2)

int main() {
  int a[SIZE];
  init(a);
  print(a);
  // should print 0 to 9 in new lines
  cout << "Contains 3? " << find_number(a, 3) << endl;
  // should print 1 (true)
  cout << "Sum of first 5: " << partial_sum(a, 5) << endl;
  // should print 10 (0 + 1 + 2 + 3 + 4)

  string car[SIZE];
  int num_passengers = 0;
  cout << "Pick up new passenger: " << pickup(car, num_passengers, "Alice")
       << endl;
  // should print 1 (true)
  // num_passengers should now be 1
  // car should now be {"Alice"}

  int plates[SIZE] = {9, 1, 2};
  int num_plates = 3;
  cout << "Take out top plate: " << take_top(plates, num_plates) << endl;
  // should print 2 (the previously last element)
  // num_plates should now be 2
  // plates should now be {9, 1}
}