/*
    This is a boiler plate for the algo Disjoint set union
*/

typedef long long ll;

vector<ll> rankVal(100005);
vector<ll> parVec(100005);

ll getPar(ll node){
    if( node == parVec[node] ){
        return node;
    }

    return parVec[node] = getPar(parVec[node]);
}

void combine(ll x, ll y){
    x = getPar(x);
    y = getPar(y);

    if( x != y ){
        if(rankVal[x] >= rankVal[y]){
            parVec[y] = x;
            rankVal[x]+=rankVal[y];
        }else{
            parVec[x] = y;
            rankVal[y]+=rankVal[x];
        }
    }
}


void startDSU(ll n){
    for(int i = 0 ; i < n+1; i++){
        parVec[i] = i;
        rankVal[i] = 1;
    }
}
