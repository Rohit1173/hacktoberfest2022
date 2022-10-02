#include<bits/stdc++.h>
using namespace std;

vector<int>primes_24={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

bool isPrime(int num){
    bool f=true;
    for(int i = 2; i <= ceil(sqrt(num)); i++) {
       if(num % i == 0) {
          f = false;
          break;
       }
    }
    return f;
}
int getNextPrime(int currentPrime){
    int nextPrime;
    int n=currentPrime+1;
    while(true){
        if(isPrime(n)){
            nextPrime=n;
            break;
        }else{
            n++;
        }
    }
    return nextPrime;
}

int main(){
    stack<int>plates;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        plates.push(x);
    }
    int i=1;
    int ith_prime;
    while(i<=q){
        stack<int>a,b;
        ith_prime=i<=25?primes_24[i]:getNextPrime(ith_prime);
        while(!plates.empty()){
            if(plates.top()%ith_prime==0)
                b.push(plates.top());
            else
                a.push(plates.top());
            plates.pop();
        }
        if(plates.empty())
            plates=a;
        while(!b.empty()){
            cout<<b.top()<<endl;
            b.pop();
        }
        i++;
    }
    while(!plates.empty()){
        cout<<plates.top()<<endl;
        plates.pop();
    }
    return 0;
}