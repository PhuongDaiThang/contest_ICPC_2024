#include <bits/stdc++.h>
using namespace std;

vector<int> calculateMaxMin(const vector<int>& A) {
    int N = A.size();
    vector<int> result(N, 0);

    vector<int> left(N, -1), right(N, N);
    stack<int> s;

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }

    for (int i = N - 1; i >= 0; --i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top();
        }
        s.push(i);
    }

    for (int i = 0; i < N; ++i) {
        int length = right[i] - left[i] - 1;
        result[length - 1] = max(result[length - 1], A[i]);
    }

    for (int i = N - 2; i >= 0; --i) {
        result[i] = max(result[i], result[i + 1]);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> result = calculateMaxMin(A);

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}


