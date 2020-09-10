

void push(int x,stack<int> &s){
  if(s.empty()){
    s.push(x);
    minEle=x;
  }

  if(x < minEle){
    minEle= x;
    s.push(2*x-minEle);
  }
  else
    s.push(x);

}


void pop(stack<int> s){
  if(s.empty())
    return;

  int t= s.top();
  s.pop();

  if(t<minEle){
    cout<<minEle;
    minEle = 2*minEle - t;
    return;
  }

  cout<<t<<endl;
  return;




}
