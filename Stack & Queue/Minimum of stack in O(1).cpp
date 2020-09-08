//Minimum of stack in o(1)

/*returns min element from stack*/
stack<int> minstack;
int _stack :: getMin()
{
   //Your code here
    if(s.empty())
        return -1;
    return minstack.top();
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
    if(s.empty())
        return -1;
    int n;
    n=s.top();
    s.pop();minstack.pop();
    return n;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()){
       s.push(x);
       minstack.push(x);
   }
   else{
       s.push(x);
       if(x<minstack.top()){
           minstack.push(x);
       }
       else{
           minstack.push(minstack.top());
       }
   }
}
