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
    vector<int> arr(n);

    inputV(arr,n);

    map<int,pair<int,int>> mp;

    for(int i=0; i<n; i++){
        if(mp.find(arr[i])==mp.end()){
            mp[arr[i]]={i,i};
        }else{
            mp[arr[i]].second=i;
        }
    }

    vector<pair<int,int>> st;

    for(auto &[value,pair]:mp){
        if(pair.first != pair.second){
            st.push_back({pair.first,pair.second});
        }
    }

    // if(st.empty()){
    //     cout<<"0"<<endl;
    //     return;
    // }


    if(st.empty()){
        cout<<"0"<<endl;
        return;
    }

    sort(st.begin(),st.end());
    vector<pair<int,int>> merge;

    int cs=st[0].first;
    int ce=st[0].second;

    for(int i=1; i<st.size(); i++){
        int s=st[i].first;
        int e=st[i].second;

        if(s<=ce){
            ce=max(ce,e);
        }else{
            merge.push_back({cs,ce});
            cs=s;
            ce=e;

        }
    }

    merge.push_back({cs,ce});

    int ans=0;

    for(auto &[start,end]:merge){
        set<int> dub(arr.begin()+start,arr.begin()+end+1);
        ans += dub.size();
    }

    cout<<ans<<endl;


}


if(c1%2 != 0){
    cout<<"YES"<<endl;
}else{
    if(c>0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}