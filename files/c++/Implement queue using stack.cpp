class MyQueue {
public:
    stack<int> top;
    stack<int> front;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
         
        while(!front.empty()){
            top.push(front.top());
            front.pop();
        }
        top.push(x);
    }
    
    int pop() {
        
        while(!top.empty()){
            front.push(top.top());
            top.pop();
        }
        int val = front.top();
        front.pop();
        return val;
    }
    
    int peek() {
        while(!top.empty()){
            front.push(top.top());
            top.pop();
        }
        return front.top();
    }
    
    bool empty() {
        return front.empty() && top.empty();
    }
};