/*
https://atcoder.jp/contests/abc330/tasks/abc330_c
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iterator>
#include <utility>

using namespace std;

using ll = long long;

constexpr ll mxN = 2e6;

std::vector<ll> items;

void init() {
    for (ll i = 0; i < mxN; ++i) {
        items.push_back(i * i);
    }
}

std::pair<ll, ll> find(ll x) {
    ll l = 0, r = mxN;
    while (r - l > 2) {
        ll mid = (l + r) / 2;
        if (items[mid] > x) {
            r = mid;
        } else if (items[mid] < x) {
            l = mid;
        } else {
            return std::make_pair(x, x);
        }
    }
    return std::make_pair(items[l], items[l + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    ll d = 0;
    cin >> d;

    ll result = 1e18;

    for (ll i = 0; i < mxN; ++i) {
        ll to_find = abs(d - items[i]);
        auto j = find(to_find);
        result = min(result, abs(j.first + items[i] - d));
        result = min(result, abs(j.second + items[i] - d));
    }

    cout << result << endl;

    return 0;
}
