#include<iostream>
#include<stack>

using namespace std;

class MinStack {
public:
    stack<int> main_stack,min_stack;
    MinStack() {
    }
    
    void push(int val) {
        main_stack.push(val);
        if(!min_stack.empty())
            min_stack.push(min(val,min_stack.top()));
        else
            min_stack.push(val);
    }
    
    void pop() {
        if(!main_stack.empty()){
            main_stack.pop();
            min_stack.pop();
        }
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

}