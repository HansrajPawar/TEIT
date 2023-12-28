#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& Arr, int n) {
    sort(Arr.begin(), Arr.end());
    vector<int> containers(3, 0);

    for (int i = n - 1; i >= 0; i--) {
        int minContainer = min_element(containers.begin(), containers.end()) - containers.begin();
        containers[minContainer] += Arr[i];
    }

    int score = abs(containers[0] - containers[1]) + abs(containers[1] - containers[2]) + abs(containers[2] - containers[0]);
    return score;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solution(arr, n);

    return 0;
}
