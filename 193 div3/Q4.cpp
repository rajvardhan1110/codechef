#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007; // 1e9 + 7

void inputV(vector<ll> &v, int size) {
    v.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(const vector<ll> &v) {
    for (ll val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll binExpRecur(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1) {
        return (a * ((res * res) % MOD)) % MOD;
    } else {
        return (res * res) % MOD;
    }
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    //Rajvardhan Patil

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);

        deg[a]++;
        deg[b]++;
    }

    vector<int> ndlist(n);
    for (int i = 0; i < n; i++) ndlist[i] = i;

    sort(ndlist.begin(), ndlist.end(), [&deg](int x, int y) {
        return deg[x] < deg[y];
    });

    vector<int> lbarr(n);
    for (int i = 0; i < n; i++) {
        lbarr[ndlist[i]] = i;
    }

    int cnt = 0;
    vector<int> parentA(n);
    vector<bool> visited(n);
    bool seen[2001];

    for (int start = 0; start < n; start++) {
        for (int i = 0; i < n; i++) {
            parentA[i] = -1;
            visited[i] = false;
        }

        queue<int> q;
        q.push(start);
        parentA[start] = start;
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parentA[v] = u;
                    q.push(v);
                }
            }
        }

        for (int end = start; end < n; end++) {
            memset(seen, 0, sizeof(seen));
            int mex = 0;
            int x = end;

            while (true) {
                int label = lbarr[x];
                if (label <= 2000) seen[label] = true;
                while (mex <= 2000 && seen[mex]) mex++;
                if (x == start) break;
                x = parentA[x];
            }

            cnt += mex;
        }
    }

    cout << cnt <<endl;
}
