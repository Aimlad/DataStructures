//Remove Duplicates

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,hash[256];
    string str;
    cin>>t;
    cin.ignore();
    /*
    Could you tell me why I have to use cin.ignore() while using getline()?
            because after you have taken no. of test cases as input,
            getline would take the newline character at the end of
            the input as input. cin.ignore() is used to ignore the
            new line character
    */
    while(t--)
    {
        memset(hash,0,sizeof(hash));
       getline(cin,str);
       //cin >> ws;
        for(i=0;i<str.size();i++)
        {
            if(hash[str[i]]==0)
            {
                cout<<str[i];
                hash[str[i]]++;
            }
        }
        cout<<"\n";
    }
    return 0;

}
