//Paranthesis Balancing

int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    stack <char> s;
	    string str;
	    cin>>str;
	    if(str.size()==0)
	        return 0;
	    int len=str.size();
	    s.push(str[0]);
	    int i=1;
	    while(i<len){
	        if(!s.empty()){
    	        if(s.top()=='('&& str[i]==')'){
    	            s.pop();
    	        }
    	        else if(s.top()=='{'&& str[i]=='}'){
    	            s.pop();
    	        }
    	        else if(s.top()=='['&& str[i]==']'){
    	            s.pop();
    	        }
    	        else{
	            s.push(str[i]);
    	        }
	        }
	        else{
	            s.push(str[i]);
	        }
	        i++;

	    }
	    if(s.empty() && i==len){
	        cout<<"balanced"<<endl;
	    }
	    else
	        cout<<"not balanced"<<endl;
	}
	return 0;
}
