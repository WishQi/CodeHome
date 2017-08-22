//
//  main.cpp
//  GoSightseeing
//
//  Created by limaoqi on 21/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

ll S[2001];
ll F[2001];
ll D[2001];
ll dp[2001][2001];

int n;
ll ts, tf;

const ll inf = (1ll << 62);

ll next(ll t, ll s, ll f, ll d) {
    return (t <= s) ? (s + d) : ((t - s) % f + t + d);
}

void solve(int k) {
    scanf("%d %lld %lld", &n, &ts, &tf);
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%lld %lld %lld", &S[i], &F[i], &D[i]);
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n - 1; ++i) {
        for (int j = 0; j <= n - 1; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i - 1][j] != inf) {
                dp[i][j] = next(dp[i - 1][j], S[i], F[i], D[i]);
            }
            if (j) {
                dp[i][j] = min(dp[i][j], next(dp[i - 1][j - 1] + ts, S[i], F[i], D[i]));
            }
        }
    }
    printf("Case #%d: ", k);
    for (int i = n - 1; i >= 0; --i) {
        if (dp[n - 1][i] <= tf) {
            printf("%d\n", i);
            return;
        }
    }
    printf("IMPOSSIBLE\n");
}

int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve(i + 1);
    }
    return 0;
}
