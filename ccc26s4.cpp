#include <bits/stdc++.h>
using namespace std;

const int MM = 1000005;

struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    void clear() {
        fill(tree.begin(), tree.end(), 0);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int N;
    long long K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    Fenwick ball(MM + 5);
    Fenwick bmod(MM + 5);

    auto check = [&](int C) {
        long long cost = 0;
        ball.clear();
        bmod.clear();

        for (int i = N - 1;i >= 0; --i) {
            int val = A[i];
            if (val == 0) {
                bmod.add(1, 1);
                ball.add(1, 1);
            } else {
                long long cntLess = ball.query(val);
                if (cntLess > C) {
                    int req = cntLess - C;
                    int total = req;

                    int smodless = bmod.query(val);
                    if (smodless < req) return false;

                    while (req > 0) {
                        int k = smodless;

                        int idx = 0;
                        int currSum = 0;
                        for (int step = 19; step >= 0; --step) {
                            int nxtIdx = idx + (1 << step);
                            if (nxtIdx <= MM + 5 && currSum + bmod.tree[nxtIdx] < k) {
                                idx = nxtIdx;
                                currSum+= bmod.tree[nxtIdx];
                            }
                        }
                        int v_plus_1 = idx + 1;
                        int v = v_plus_1 - 1;

                        int c = bmod.query(v_plus_1) - bmod.query(v_plus_1 - 1);
                        int take = min(req, c);

                        cost += 1LL * take * (val - v);
                        if (cost > K) return false;
                        req -= take;

                        bmod.add(v_plus_1, -take);
                        ball.add(v_plus_1, -take);
                        smodless -= take;
                    }
                    bmod.add(val + 1,total);
                    ball.add(val + 1, total);
                }
                ball.add(val + 1, 1);
            }
        }
        return cost <= K;
    };

    int low = 0, high = N;
    int ans = N;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans<< "\n";
    return 0;
}