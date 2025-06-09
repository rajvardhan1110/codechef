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

    int a,b,c;

    cin>>a>>b>>c;

//     if((a%2==0 && b%2==0 && c%2!=0 ) || ((a%2!=0 && b%2!=0 && c%2!=0 )) ||(a%2!=0 && b%2==0 && c%2==0 ) || (a%2==0 && b%2!=0 && c%2==0 )){
//         cout<<-1<<endl;
//         return;
//     }

//     int count=0;

//    if(a==b){
//         while(a-b!=c){
//             a++;
//             b--;

//             count++;
//         }
//    }else{
//         int diff=abs(a-b);
//         int maxi=max(a,b);
//         int mini=min(a,b);

//         if(diff==c){
//             cout<<0<<endl;
//         }else if(diff < c){
//             while(maxi-mini!=c){
//                 mini--;
//                 maxi++;
//                 count++;
//             }
//         }else{
//             while(maxi-mini!=c){
//                 mini++;
//                 maxi--;
//                 count++;
//             }
//         }
//    }

//    cout<<count<<endl;

    if(((a+b)%2==0 && c%2==0) || ((a+b)%2!=0 && c%2!=0)){
        int v=(abs(a-b)-c)/2;

        cout<<abs(v)<<endl;
    }else{
        cout<<-1<<endl;
    }
}