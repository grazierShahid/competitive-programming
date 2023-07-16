#include <bits/stdc++.h>
using namespace std;

#define ll long long

int cnt;
vector<int> buildLPS(string pat){
    vector<int> lps(pat.size());
    for(int ind=0, i=1; i<pat.size();){
        if(pat[ind] == pat[i])
            lps[i++] = ++ind;
        else if(ind != 0)
            ind = lps[ind-1];
        else lps[i++] = ind;
    }

    return lps;
}

void KMP(string text, string pat){
    vector<int> lps = buildLPS(pat); // failure table

    for(int i=0, j=0; i<text.size(); ){
        if(text[i] == pat[j]) i++, j++;
        else if(j!=0) j = lps[j-1];
        else i++;

        if(j==pat.size()){
            //cout << "matched at " << i-j << endl;
            j = lps[j-1];
            //break; // after first match
            cnt++;
        }
    }
}


int main(){
    string text, pat;
    cin>>text>>pat;

    cnt=0;
    KMP(text, pat);
    cout << cnt << endl;
    
    return 0;
}
