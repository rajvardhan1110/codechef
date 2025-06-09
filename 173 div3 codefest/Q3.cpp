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
    //Add your code here

    int n,m;
    cin>>n>>m;

    vector<int> arr(n);
    vector<int> b(m);

    inputV(arr,n);
    inputV(b,m);
    int minPosition = 0;
   

    for (int i = 1; i < m; ++i) {
        if (b[i] < b[minPosition]) {
            minPosition = i;  
            
        }
    }

    int mini=b[minPosition];

    int mini = 1e10;
   
   int min_index;
    vector<int> newb;

    for(int i=0; i<n; i++){
    if(b[i] < mini){
        min_index  = i ;
        mini  = min(b[i],mini);
      }
   }


   for(int i=0;i<m;i++){
      newb.push_back(b[(i+min_index)%m]);
   }

    if(m==1){
        for(int i=0; i<n; i++){
            cout<<min(arr[i],mini)<<" ";
        }

        cout<<endl;
        return;
    }

    for(int i=0; i<=n-m; i++){
        
    }






    // vector<int> ans=arr;
    // int index=-1;

    // for(int i=0; i<=n-m; i++){
    //     bool flag=false;

        // for(int j=0; j<m; j++){
        //     if(ans[i+j]<b[(j+minPosition)%m]){
        //         break;
        //     }else if(ans[i+j]>b[(j+minPosition)%m]){
        //         flag=true;
        //         index=i;
        //         break;
        //     }
        // }

        // if(ans[i]>mini){
        //     index=i;
        //     break;
        // }


        // if(flag){
        //     // for(int j=0; j<m; j++){
        //     //     ans[i+j]=b[(j+minPosition)%m];
        //     // }

        //     break;

           
        // }
    // }

    // if(index!=-1){

    
    // for(int i=index; i<=n-m; i++){
    //     ans[i]=mini;
    // }

    
    // }

    // int count=0;

    // for(int i=n-m; i<n; i++){
    //     ans[i]=b[(count+minPosition)%m];
    //     count++;
    // }

   


    // for(int i=0; i<n; i++){
    //     cout<<ans[i]<<" ";
    // }

    // cout<<endl;


    // int n, m;
    // cin >> n >> m;
    // vector<int> A(n), B(m);
    // inputV(A, n);
    // inputV(B, m);

   
    // vector<int> bestB = B;
    // for (int i = 1; i < m; i++) {
    //     rotate(B.begin(), B.begin() + 1, B.end());
    //     bestB = min(bestB, B);  
    // }

    // for (int i = 0; i <= n - m; i++) {
    //     if (vector<int>(A.begin() + i, A.begin() + i + m) > bestB) {
    //         copy(bestB.begin(), bestB.end(), A.begin() + i);
    //     }
    // }
    

    // for(int i=0; i<n; i++){
    //     cout<<A[i]<<" ";
    // }

    // cout<<endl;



 }