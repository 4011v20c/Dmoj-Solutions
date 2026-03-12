// orz bruce
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Line {
    long long A, B, C;
};

inline long long eval(long long H, long long W, long long N, long long M, long long K, long long hm, long long wm) {
    if (H < 2 || W < 2 || H > N || W > M) return -1;
    long long P = (H + W) * 2 - 4;
    if (P > K) return -1;

    long long X = H - hm;
    long long Y = W - wm;
    long long lost = 0;

    if (X > 0 && Y > 0) {
        long long E = K - P;
        if (E >= X || E >= Y) {
            lost = (X < Y) ? X : Y;
        } else {
            long long m = (X > Y) ? X - 1 : Y - 1;
            lost = X * Y - E * m;
        }
    }
    return (H - 2)* (W - 2) - lost;
}

void solve() {
    long long N, M, K, R, C;
    cin >> N >> M >> K >> R >> C;

    long long hm = max(R, N - R + 1);
    long long wm = max(C, M - C + 1);

    vector<Line> lines = {
        {1, 0, 2}, {1, 0, N}, {1, 0, hm}, {1, 0, hm + 1},
        {0, 1, 2}, {0, 1, M}, {0, 1, wm}, {0, 1, wm + 1},
        {1, -1, hm - wm}, {1, -1, 0},
        {2, 2, K + 4}, {2, 2, K + 3},
        {3, 2, K + 4 + hm}, {2, 3, K + 4 + wm},
        {2, 0, 3 * hm}, {4, 2, K + 4 + 2 * hm + wm},
        {0, 2, 3 * wm}, {2, 4, K + 4 + hm + 2 * wm},
        {3, -2, 0}, {2, -3, 0},
        {1, 0, 3}, {0, 1, 3}
    };

    long long ans = 0;
    ans = max(ans, eval(2, 2, N, M, K, hm, wm));

    for(size_t i = 0; i < lines.size(); ++i) {
        for(size_t j = i + 1; j < lines.size(); ++j) {
            long long A1 = lines[i].A, B1 = lines[i].B, C1 = lines[i].C;
            long long A2 = lines[j].A, B2 = lines[j].B, C2 = lines[j].C;
            long long det = A1 * B2 - A2 * B1;
            if (det != 0) {
                double h = (double)(C1 * B2 - C2 * B1) / det;
                double w = (double)(A1 * C2 - A2 * C1) / det;
                long long H0 = round(h);
                long long W0 = round(w);

                for (long long dh = -2; dh <= 2; ++dh) {
                    for (long long dw = -2; dw <= 2; ++dw) {
                        ans = max(ans, eval(H0 + dh, W0 + dw, N, M, K, hm, wm));
                    }
                }
            }
        }
    }

    vector<long long> Hcands = {2LL, hm, N};
    vector<long long> Wcands = {2LL, wm, M};
    for(long long h_c : Hcands) {
        for(long long w_c : Wcands) {
            for(long long dh = -2; dh <= 2; ++dh) {
                for(long long dw = -2; dw <= 2; ++dw) {
                    ans = max(ans, eval(h_c + dh, w_c + dw, N, M, K, hm, wm));
                }
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {solve();}
    return 0;
}

