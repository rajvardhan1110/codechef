#include <bits/stdc++.h>
using namespace std;

void inputV (vector <int> &v, int size) {
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
}

void printV(vector<int> &v, int size){
    for(int i=0; i<size; i++){
        cout<<v[i];
    }
}

void createsieve(vector<bool> &prime, int n){
    // Declare prime vector in solve function with size n+1 and all values are true
    prime[0] = prime[1] = false;
    for(int i=2; i<n; i++){
        if(prime[i]){
            for(int j=2*i; j<n; j+=i){
                prime[j] = false;
            }
        }
    }
}

void solve();

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    // Implementation here
    int n;
    cin>>n;

    string s;
    cin>>s;

    int count1=0;
    int count2=0;

    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            count1++;
        }else{
            count2++;
        }
    }

    if(count1==n || count2==n){
        cout<<2<<endl;
    }else{
        cout<<1<<endl;
    }
}