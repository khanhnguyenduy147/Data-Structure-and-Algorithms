/*
There are n
 bags numbered from 1
 to n
, the i
-th bag contains ai
 golden coins and bi
 silver coins.

The value of a gold coin is 1
. The value of a silver coin is either 0
 or 1
, determined for each silver coin independently (0
 with probability 12
, 1
 with probability 12
).

You have to answer q
 independent queries. Each query is the following:

l
 r
 — calculate the probability that the total value of coins in bags from l
 to r
 is strictly greater than the total value in all other bags.
Input
The first line contains two integers n
 and q
 (1≤n,q≤3⋅105
) — the number of bags and the number of queries, respectively.

The second line contains n
 integers a1,a2,…,an
 (0≤ai≤106
) — the number of gold coins in the i
-th bag.

The third line contains n
 integers b1,b2,…,bn
 (0≤bi≤106
) — the number of silver coins in the i
-th bag.

Next q
 lines contain queries. The j
-th of the next q
 lines contains two integers lj
 and rj
 (1≤lj≤rj≤n
) — the description of the j
-th query.

Additional constraints on the input:

the sum of the array a
 doesn't exceed 106
;
the sum of the array b
 doesn't exceed 106
.
Output
For each query, print one integer — the probability that the total value of coins in bags from l
 to r
 is strictly greater than the total value in all other bags, taken modulo 998244353
.

Formally, the probability can be expressed as an irreducible fraction xy
. You have to print the value of x⋅y−1mod998244353
, where y−1
 is an integer such that y⋅y−1mod998244353=1
.

Examples
inputCopy
2 2
1 0
0 2
2 2
1 1
outputCopy
748683265 748683265
inputCopy
4 3
2 3 4 5
1 0 7 3
3 3
2 3
1 4
outputCopy
997756929 273932289 1
Note
In both queries from the first example, the answer is 1/4.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<long long> p(n), qv(n);
    for (int i = 0; i < n; ++i) {
        p[i] = (1LL * a[i] * b[i]) % MOD;
        qv[i] = (1LL * b[i] * b[i]) % MOD;
    }

    for (int i = 1; i < n; ++i) {
        p[i] = (p[i] + p[i - 1]) % MOD;
        qv[i] = (qv[i] + qv[i - 1]) % MOD;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        long long sum_p = (p[r] - (l > 0 ? p[l - 1] : 0) + MOD) % MOD;
        long long sum_q = (qv[r] - (l > 0 ? qv[l - 1] : 0) + MOD) % MOD;

        long long ans = (sum_p * sum_q) % MOD;
        long long inv_sum_q = 1;
        for (int i = 0; i < MOD - 2; ++i) {
            inv_sum_q = (inv_sum_q * sum_q) % MOD;
        }
        ans = (ans * inv_sum_q) % MOD;

        cout << ans << " ";
    }

    return 0;
}
