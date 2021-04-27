#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) {
        write(e, " ");
    }
    write("\n");
}

double solve(int i, int j, vector<double> arr, vector<vector<double>> &dp) {
    if (dp[i][j] > -1) {
        return dp[i][j];
    }
    if (j == 0) return 1;
    if (i == 0) return 0;
    dp[i][j] = (solve(i - 1, j - 1, arr, dp) * arr[i]) + (solve(i - 1, j, arr, dp) * (1 - arr[i]));
    return dp[i][j];
}

void solve(int tc) {
    int n;
    read(n);
    vector<double> arr(n);
    readContainer(arr);
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] * (1 - arr[i - 1]);
            } else {
                dp[i][j] = (dp[i - 1][j] * (1 - arr[i - 1])) + (dp[i - 1][j - 1] * arr[i - 1]);
            }
        }
    }
    double ans = 0;
    for (int j = (n + 1) / 2; j <= n; ++j) ans += dp[n][j];
    write(fixed, setprecision(16), ans, "\n");
}

signed main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}