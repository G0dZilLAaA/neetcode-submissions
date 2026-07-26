class Solution {
public:
    bool dfs(vector<vector<int>>&graph , int i , unordered_map<int,bool>& hash,vector<int>& visit){
        if(hash.find(i)!=hash.end()) return false;
        hash[i]=true;
        visit[i]=2;
        for(int j=0;j<graph[i].size();j++){
            if(!dfs(graph,graph[i][j],hash,visit)) return false;
        }
        hash.erase(i);
        return true;
    }

    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> graph(num);
        for(int i=0;i<pre.size();i++){
            graph[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> visit(num,0);
        for(int i=0;i<num;i++){
            unordered_map<int , bool> hash;
            if(visit[i]==0)
            if(!dfs(graph,i,hash,visit)) return false;
        }
        return true;
    }
};
