#include <bits/stdc++.h>
using namespace std;
#define int long long

void inputV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(vector<int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i];
    }
}

void createsieve(vector<bool> &prime, int n) {
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool PowOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void solve();

int32_t main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    // Add your code here
    int n;
    cin>>n;

    vector<int> st(2);

    string s1;
    string s2;

    cin>>s1;
    cin>>s2;

    for(int i=0; i<n; i++){
        if(s1[i]=='1' && s2[i]=='1'){
            st[0]++;
        }else if((s1[i]=='1' && s2[i]!='1') || (s1[i]!='1' && s2[i]=='1')){
            st[1]++;
        }
    }

    if(st[0]%2 != 0){
        cout<<"YES"<<endl;
    }else{
        if(st[1]>0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}