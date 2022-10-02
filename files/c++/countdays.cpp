#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> O(n);
    for(int i=0;i<n;i++) cin >> O[i];

    vector<int> e(n);
    vector<int> s(n);

    for(int i=0;i<n;i++){
        s[i] = i-1;
        e[i] = i+1;
    }
    e[n-1] = -1;

    vector<bool> killed(n, false);
    queue<int> done;
    int days = 0;

    for(int i=0;i<n;i++){
        if(s[i]!=-1 && O[s[i]] < O[i]){
            done.push(i);
            killed[i] = true;
        }
    }
    while(!done.empty()){
        days++;
        int klen = done.size();
        for(int k=0;k<klen;k++){
            int cur = done.front();
            done.pop();

            if(s[cur]!=-1) {
                e[s[cur]] = e[cur];
            }
            if(e[cur]!=-1) {
                s[e[cur]] = s[cur];
            }
            if(s[cur]!=-1&&e[cur]!=-1){
                if(O[s[cur]] < O[e[cur]] && !killed[e[cur]]){
                    done.push(e[cur]);
                    killed[e[cur]] = true;
                }
            }
        }
    }

    cout << days << endl;

    return 0;
}