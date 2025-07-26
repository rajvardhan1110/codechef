bool ok(vi &pre) {
    for(ll i : pre) {
        if(i%3 == 0) {
            return false;
        }
    }
    return true;
}
void solve() {
    ll n;
    cin >> n;
    vi v(n);
    inputv(v,n);
    vi a = v;
    vi pre(n,0);
    pre[0] = v[0];
    for(ll i = 1; i<n; i++) {
        pre[i] = pre[i-1]+v[i];
    }
    if(ok(pre)) {
        cout("YES"); 
        return;   
    }


    vi suf(n);
    suf[n-1] = v[n-1];
    for(ll i = n-2; i>=0; i--) {
        suf[i] = suf[i+1]+v[i];
    }

    debug(suf);
    ll x = -1;
    for(ll i = n-1; i>=0; i--) {
        if(pre[i]%3 == 0) {
            x = i;
            break;;
        }
    }

    if(ok(suf)) {
        cout("YES"); 
        return;   
    }

    for(ll i = x+1; i<n; i++) {
        bool f = true;
        for(ll j = i-1; j>=0; j--) {
            if((suf[j]-suf[i])%3 == 0) {
                f = false;
                break;
            }
        }

        if(f) {
            cout("YES");
            return;
        }
    }

    
    cout("NO");
}