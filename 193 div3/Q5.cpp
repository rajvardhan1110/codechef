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
        return deg[x] > deg[y];
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
        fill(parentA.begin(), parentA.end(), -1);
        fill(visited.begin(), visited.end(), false);

        queue<int> q;
        q.push(start);
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
            int x = end;

            
            while (x != -1) {
                int label = lbarr[x];
                if (label <= 2000) seen[label] = true;
                x = parentA[x];
            }

            int mex = 0;
            while (seen[mex]) mex++;

            cnt += mex;
        }
    }

    cout << cnt << endl;
}