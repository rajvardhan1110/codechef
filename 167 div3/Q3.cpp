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

    vector<int> arr(n);
    inputV(arr,n);

    int a=arr[0];

    sort(arr.begin(),arr.end());

    int index=-1;

    for(int i=0; i<n; i++){
        if(arr[i]==a){
            index=i;
            break;
        }
    }

    if(index==0){
        int diff=arr[1]-arr[0]-1;
        int diff1=arr[0]-1;

        if(diff%2==0){
            cout<<1+(diff/2)+diff1<<endl;
        }else{
            cout<<2+(diff/2)+diff1<<endl;
        }
    }else if(index==n-1){
        int diff1=1000000-arr[index];
        int diff2=arr[index]-arr[index-1]-1;
        int diff3;

        if(diff2%2==0){
            diff3=(diff2/2);
        }else{
            diff3=1+(diff2/2);
        }

        cout<<diff1+diff3+1<<endl;
    }else{
        int dif1=arr[index+1]-arr[index]-1;
        int dif2=arr[index]-arr[index-1]-1;

        int dif3;
        int dif4;

        if(dif1%2==0){
            dif3=(dif1/2);
        }else{
            dif3=1+(dif1/2);
        }

        if(dif2%2==0){
            dif4=(dif2/2);
        }else{
            dif4=1+(dif2/2);
        }

        cout<<dif3+dif4+1<<endl;


    }
}