#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair

using ll = long long;
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        ll tw = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tw += a[i];
        }

        if (n <= 2) {
            cout << -1 << '\n'; 
            continue;
        }

        double avg = static_cast<double>(tw) / n;
        double haf = avg / 2.0;

        int uhc = 0; 
        for (int i = 0; i < n; i++) {
            if (a[i] < haf) {
                uhc++;
            }
        }

        if (uhc > n / 2) {
            cout << 0 << '\n'; 
            continue;
        }

        int richest = *max_element(a.begin(), a.end());

        ll left = 0, right = 1e12, ans = -1; 

        while (left <= right) {
            ll mid = left + (right - left) / 2;

            double ntw = tw + mid;
            double newAvg = ntw / n;
            double newHaf = newAvg / 2.0;

            int nhc = 0; 
            for (int i = 0; i < n; i++) {
                if (a[i] < newHaf) {
                    nhc++;
                }
            }

            if (nhc > n / 2) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
