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
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    inputV(arr,n);

    map<int,int> mp;

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    int cheack=mp[k];
    bool flag=true;

    for(auto i:mp){
        if(k!=i.first){
            if(i.second > cheack){
                flag = false;
                break;
            }
        }
    }

    if(flag){
        cout<<'0'<<endl;
        return;
    }

    int first=-1;
    int last=-1;

    int i=0;
    int j=n-1;

    while(1){
        if(arr[i]==k){
            first=i;
            break;
        }

        i++;
    }

    while(1){
        if(arr[j]==k){
            last=j;
            break;
        }

        j--;
    }

    map<int,int> f;
    map<int,int> s;

    int maxi=INT_MIN;

    bool z=true;

    for(int i=0; i<n; i++){
        f[arr[i]]++;
        maxi=max(maxi,f[k]);

        if(maxi==f[k]){
            z=false;
            break;
        }
    }

    maxi=INT_MIN;

    for(int i=n-1; i>=0; i--){
        s[arr[i]]++;

        maxi=max(maxi,s[k]);

        if(maxi==s[k]){
            z=false;
            break;
        }
    }

   

    if(!flag){
        cout<<1<<endl;
    }else{
        cout<<2<<endl;
    }



}