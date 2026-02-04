#include <bits/stdc++.h>
using namespace std;

void findCutoff(int K, vector<int> scores) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int x : scores) {
        if (minHeap.size() < K) {
            minHeap.push(x);
            cout << -1 << endl;
        } else {
            if (x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
            cout << minHeap.top() << endl;
        }
    }
}

int main() {
    int K = 3;
    vector<int> scores = {10, 20, 5, 15, 25, 8};
    findCutoff(K, scores);
    return 0;
}
