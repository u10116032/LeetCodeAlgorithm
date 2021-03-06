class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> mystack;

    MinStack() {
    }

    void push(int x) {
        mystack.push_back(x);

    }

    void pop() {
        mystack.erase(mystack.end()-1);
    }

    int top() {
        return mystack[mystack.size()-1];
    }

    int getMin() {
        int min=std::numeric_limits<int>::max();
        for(int i=0; i<mystack.size();++i){
            if(mystack[i]<min) min=mystack[i];
        }
        return min;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
