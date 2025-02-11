class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        map<pair<int,int>,list<pair<int,int>>>graph;

        vector<vector<int>>indegree(m,vector<int>(n,0));

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                for(int x = 0; x < 4; x++){
                    int newX = i + dx[x];
                    int newY = j + dy[x];
                    if(newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] > matrix[i][j]){
                        indegree[newX][newY]++;
                        graph[{i,j}].push_back({newX,newY});
                    }
                }
            }
        }

        queue<pair<pair<int,int>,int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(indegree[i][j] == 0) q.push({{i,j},1});
            }
        }
        int result = -1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
            auto p = q.front();
            q.pop();

            int x = p.first.first;
            int y = p.first.second;

            int steps = p.second;
            if(steps > result) result = steps;

            for(auto it : graph[{x,y}]){
                int newX = it.first;
                int newY = it.second;

                indegree[newX][newY]--;
                if(indegree[newX][newY] == 0) q.push({{newX,newY},steps + 1});
            }
        }
        }
        return result;
    }
};