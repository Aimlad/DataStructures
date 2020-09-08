//Running Median

void addNumber(int a,priority_queue<int> &leftQ,
    priority_queue<int,vector<int>, greater<int> > &rightQ){

        if(leftQ.empty() || leftQ.top()>a)
            leftQ.push(a);
        else
            rightQ.push(a);

        //Balacing the two heaps

        if(leftQ.size()>rightQ.size()+1){
            rightQ.push(leftQ.top());
            leftQ.pop();
        }

        else if(rightQ.size()>leftQ.size()+1){
            leftQ.push(rightQ.top());
            rightQ.pop();
        }
    }

void median(priority_queue<int> leftQ,
    priority_queue<int,vector<int>, greater<int> > rightQ){

        if(leftQ.size()==rightQ.size() && leftQ.size()==0)
            cout<<0<<endl;
        else if(leftQ.size()==rightQ.size())
            cout<<(leftQ.top()+rightQ.top())/2<<endl;
        else
            if(leftQ.size()>rightQ.size())
                cout<<leftQ.top()<<endl;
            else
                cout<<rightQ.top()<<endl;

    }

int main()
 {
	//code
	int n;cin>>n;
	priority_queue<int> leftQ; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int> > rightQ;
	while(n--){
	    int a;cin>>a;
	    addNumber(a,leftQ,rightQ);
	    median(leftQ,rightQ);
	}
	return 0;
}
