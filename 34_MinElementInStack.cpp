// 34. Minimum element in stack in constant space (neglecting recursion stack)

#include <iostream>
#include <stack>
using namespace std;

int minElement(stack <int> &st){
    if (st.empty())
        return INT_MAX;
    int top = st.top();
    st.pop();
    return min(minElement(st),top);
}

int main(){
    stack<int> st;
    st.push(12);
    st.push(10);
    st.push(9);
    st.push(9);
    st.push(2);
    st.push(5);

    cout<<"Min Element: "<<minElement(st);
}