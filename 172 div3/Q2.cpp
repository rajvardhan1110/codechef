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

int maximum(vector<int>& nums){
    int maxi=0;
    int count=0;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<=nums[i+1]){
                count++;
            }else{
                count=0;
            }

            maxi=max(maxi,count);
        }

    return maxi;
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

    int maxim=0;
    vector<int> arr(n);
    inputV(arr,n);

    for(int i=0; i<n; i++){
        arr[i]=arr[i]*k;
        int a=maximum(arr);
        maxim=max(maxim,a);
        arr[i] = arr[i]/k;

    }

    cout<<maxim+1<<endl;

}