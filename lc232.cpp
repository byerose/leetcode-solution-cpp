#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    stack<int> instack,outstack;
    MyQueue() {

    }
    void transfer(stack<int>& instack,stack<int>& outstack){
        int t;
        if(outstack.empty()){
            while(!instack.empty()){
                t = instack.top();
                instack.pop(); 
                outstack.push(t);
            }
        }
    }

    void push(int x) {
        instack.push(x);
    }
    
    int pop() {
        transfer(instack,outstack);
        int t = outstack.top();
        outstack.pop();
        return t;
    }
    
    int peek() {
        transfer(instack,outstack);
        return outstack.top();
    }
    
    bool empty() {
        return instack.empty() && outstack.empty();
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

int main(){

}