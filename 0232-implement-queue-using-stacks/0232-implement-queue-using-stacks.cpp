class MyQueue {
public:
stack<int>inst;
stack<int>outst;
    MyQueue() {
        
    }
  void push(int x) {
        inst.push(x);}
        
    
  int pop() {
       if(outst.empty()){
        while(!inst.empty()){
            outst.push(inst.top());
            inst.pop();
        }
       }

       int ans=outst.top();
       outst.pop();
       return ans;
    }
    
    int peek() {
        if(outst.empty()){
        while(!inst.empty()){
            outst.push(inst.top());
            inst.pop();
        }
       }
       return outst.top();
    }
    
    bool empty() {
        return inst.empty()&&outst.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */