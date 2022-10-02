1st ANSWER:

#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> Front,Rear;
    int Q;
    cin >> Q;
    while(Q--)
    {
        int type, a;
        cin >> type;
        if(type == 1)
        {
            cin >> a;
            Rear.push(a);
        }    
        else 
        {
           if(Front.empty())
           { 
               while(!Rear.empty())
               {
                   Front.push(Rear.top());
                   Rear.pop();
               }   
            }    
           if(!Front.empty())
           {
               if(type == 2) Front.pop();
               if(type == 3) cout << Front.top() << endl;
           }  
        }   
    }    
    return 0;
}