#include<iostream>
#include<queue>

using namespace std;

class MyStack{
    public:
        queue<int> queue_main,queue_sub;
        MyStack(){

        }
        void push(int x){
            if(!queue_main.empty()) queue_main.swap(queue_sub);
            queue_main.push(x);
            while(!queue_sub.empty()){
                queue_main.push(queue_sub.front());
                queue_sub.pop();
            }
        }
        int pop(){
            int t = queue_main.front();
            queue_main.pop();
            return t;
        }
        int top(){
            return queue_main.front();
        }
        bool empty(){
            return queue_main.empty();
        }
};

int main(){
    MyStack* obj = new MyStack();
    cout<<obj->empty();
    obj->push(1);
    cout<<obj->top();
    obj->push(2);
    cout<<obj->top();
    obj->pop();
    cout<<obj->top();
    obj->push(3);
    cout<<obj->top();
    cout<<obj->empty();
}