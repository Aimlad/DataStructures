//Smallest window in a string containing all the characters of another string
//Basic Concept is:
/*
1: Create map<char,vector<int>> to store indexes of all letters in str1 (mp)
2: Create another map<char,int> to store frequency of letters in str2(freq)
3: Copy all the indexes(of str1) of the letters present in str2 in a vector (res)
4: Sort the std::vector
5: Search for the window in which all the elements are present,keep increasing j
6: Once found, check if window can be decreased by increasing i, if Yes, i++
7: Keep updating min_window value if found
8: Output Result
*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int tc;cin>>tc;
	while(tc--){
	    string str1;
	    string str2;
	    cin>>str1>>str2;

	    unordered_map<char,vector<int>> mp;
	    unordered_map<char,int> freq;

	    for(int i=0;i<str1.size();i++){
	        mp[str1[i]].push_back(i);
	    }

	    vector<int> res;

	    for(int i=0;i<str2.size();i++){
	       freq[str2[i]]++;
	       if(mp.find(str2[i]) !=mp.end()){
	           for(int j=0;j<mp[str2[i]].size();j++){
	               res.push_back(mp[str2[i]][j]);
	           }
	           mp.erase(str2[i]);
	       }
	    }

	    sort(res.begin(),res.end());
	    int str2_unique_element_count=freq.size();

	    map<char,int> temp_freq; //Used to store current frequency of letters

	    int i=0,j=0,count=0;
	    int res_index_i=-1, res_index_j=-1,min_window=INT_MAX;

	    while(j<res.size()){
	        temp_freq[str1[res[j]]]++; //Frequency of that letter increased

          //Checking if all elements of str2 are found or not
          if(temp_freq[str1[res[j]]]==freq[str1[res[j]]]
	            && count<str2_unique_element_count)
	            count++;

          //If all found, then check if window can be shrunk
	        if(count==str2_unique_element_count){
	            if(temp_freq[str1[res[i]]]>freq[str1[res[i]]]){
	                while(temp_freq[str1[res[i]]]>freq[str1[res[i]]]){
	                    temp_freq[str1[res[i]]]--;
	                    i++;
	                }
	            }

              //Updating the result
	            if(res[j]-res[i] < min_window){
	                min_window=res[j]-res[i];
	                res_index_i=res[i];
	                res_index_j=res[j];
	            }
	            //cout<<res_index_i<<"-->"<<res_index_j<<endl;
	        }//cout<<j<<" ";
	        j++;
	    }
	    if(res_index_i==-1 && res_index_j==-1 && min_window==INT_MAX){
	        cout<<-1;
	    }
	    else{
    	    while(res_index_i<=res_index_j){
    	        cout<<str1[res_index_i];
    	        res_index_i++;
    	    }
	    }

	    cout<<endl;
	}
	return 0;
}
