//Topological topoSort
// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    void dfs(int i,vector <bool> &visited,vector<bool> &instack,vector<int> pq[],bool &flag){
        visited[i]=true;
        instack[i]=true;
        for(auto it=pq[i].begin(); it!=pq[i].end();it++){
            if(instack[*it]){
                flag=false;
                return;
            }
            if(!visited[*it])
                dfs(*it,visited,instack,pq,flag);
        }
        instack[i]=false;
        return;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <bool> visited(numCourses);
        vector<bool> instack(numCourses);
        bool flag = true;
        for(int i=0;i< numCourses;i++){
            visited[i]=false;
            instack[i]=false;
        }
        vector< int > adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }


        for(int i=0;i<numCourses;i++){
            if(flag== false || (!visited[i] && instack[i]))
                return 0;
            if(!visited[i])
                dfs(i,visited,instack,adj,flag);
        }
        return 1;
    }
};
