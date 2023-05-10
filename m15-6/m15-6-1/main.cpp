#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = a.size();
    int max_sum = a[0], max_start = 0, max_end = 0;
    int cur_sum = a[0], cur_start = 0;
    for (int i = 1; i < n; i++) {
        if (cur_sum < 0) {
            cur_sum = 0;
            cur_start = i;
        }
        cur_sum += a[i];
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
            max_start = cur_start;
            max_end = i;
        }
    }
    cout << max_start << " " << max_end << endl;
    return 0;
}
