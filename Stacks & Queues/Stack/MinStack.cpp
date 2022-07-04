class MinStack
{
    vector<int> min_stack;
    vector<int> stack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        int current_min = val;
        if (min_stack.size() == 0 || val <= getMin())
            min_stack.push_back(val);
        stack.push_back(val);
    }

    void pop()
    {
        if (stack.back() == min_stack.back())
            min_stack.pop_back();

        stack.pop_back();
    }

    int top()
    {
        return stack[stack.size() - 1];
    }

    int getMin()
    {
        return min_stack[min_stack.size() - 1];
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