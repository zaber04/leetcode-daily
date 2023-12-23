/*
Follow the below steps to implement the push(s, x) operation: 
Enqueue x to q1 (assuming the size of q1 is unlimited).

Follow the below steps to implement the pop(s) operation: 
One by one dequeue everything except the last element from q1 and enqueue to q2.
Dequeue the last item of q1, the dequeued item is the result, store it.
Swap the names of q1 and q2
Return the item stored in step 2.
*/
class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        // bring everything else ()but the new input) from back to front
        for (int i = 0, len = q.size(); i < len - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */