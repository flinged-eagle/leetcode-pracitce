//最小栈

/*
    设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

    push(x) —— 将元素 x 推入栈中。
    pop() —— 删除栈顶的元素。
    top() —— 获取栈顶元素。
    getMin() —— 检索栈中的最小元素。

    分析：
        以O(1)的时间复杂度查找最小元素
        可使用辅助空间，保存最小元素_min，每次push x，push的数为min(_min, x),更新 _min;
        注意pop时，_min可能会发生变化；

        可使用辅助栈 min，当push元素<=min.top(), min.push(x); 否则不入栈；
                        出栈时，当min.top() == s.top() 出栈；
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        _s1.push(x);
        if(_min.empty() || _min.top() >= x)
        {
            _min.push(x);
        }
    }
    
    void pop() {
        if(_s1.top() == _min.top())
        {
            _min.pop();
        }
        _s1.pop();
    }
    
    int top() {
        return _s1.top();
    }
    
    int getMin() {
        return _min.top();
    }
    stack<int> _s1,_min;
};