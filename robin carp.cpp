#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll hashh(string s, int n, ll b, ll mod){
    ll h=0, p=1;
    for(int i=n-1; i>=0; i--){
        h = h+(s[i]*p)%mod;
        h%=mod;
        p = (p*b)%mod;
    }
    return h;
}

int match(string &t, string &pat){
    int n = t.size(), m = pat.size();
    
    if(n<m) return -1;
    if(n==0 || m==0) return -1;

    ll b=347, p=1, mod=1e9+7;
    for(ll i=1; i<m; i++) p = (p*b)%mod;

    ll hashT = hashh(t, m, b, mod);
    ll hashP = hashh(pat, m, b, mod);

    if(hashP == hashT) return 0;

    for(int i=m; i<n; i++){
        hashT = (hashT - (p *t[i-m])%mod)%mod;
        hashT = (hashT + mod)%mod;
        hashT = (hashT * b) % mod;
        hashT = (hashT + t[i]) % mod;

        if(hashT == hashP) return i-m+1;
    }
    return -1;

}

int main(){
    string t, p; cin>>t>>p;
    cout<<match(t, p)<<endl;
    return 0;
}
