#include <iostream>
#include <vector>

using namespace std;

int processArray(vector<int> &array) {
  int consecutive_count = 0;
  int new_length = 0;

  for (int i = 0; i < array.size(); i++) {
    if (array[i] >= 100) {
      consecutive_count++;
    } else {
      if (consecutive_count > 0) {
        array[new_length++] = consecutive_count;
      }
      consecutive_count = 0;
      array[new_length++] = array[i];
    }
  }

  if (consecutive_count > 0) {
    array[new_length++] = consecutive_count;
  }

  // Return the new length of the array.
  return new_length;
}

int main() {
  vector<int> array;
  int val;
  while (cin >> val) {
    if (val < 0) break;
    array.push_back(val);
  }
  int new_len = processArray(array);
  for (int i = 0; i < new_len; i++) {
    cout << array[i] << endl;
  }
  return 0;
}
