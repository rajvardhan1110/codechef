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
    string a;
    string b;
    cin>>a;
    cin>>b;

    if(a.size() < b.size()){
        cout<<-1<<endl;
        return;
    }

    int cost=1;

    vector<bool> arr(a.size());

    int i=a.size()-1; 
    int j=b.size()-1;

    while(i>=0 && j>=0){
        if(a[i]==b[j]){
            arr[i]=true;
            i--;
            j--;
        }else{
            i--;
        }

        if(i<0 && j>=0){
            cout<<-1<<endl;
            return;
        }
    }

    int ans=0;

    for(int i=0; i<a.size(); i++){
        if(arr[i]==true){
            cost++;
        }else{
            ans +=cost;
        }
    }

    cout<<ans<<endl;
}