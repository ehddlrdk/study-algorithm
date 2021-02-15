class Solution {
public:
    
    bool visited[101] = {0,};
    bool label[101] = {0,};
    queue<int> Q;
    
    bool result = true;
    
    bool isBipartite(vector<vector<int>>& graph) {

        //연결그래프 + 비연결그래프 둘 다 고려하기 위한 Loop문
        for(int i=0; i<graph.size(); i++) {
            if(!graph[i].empty() && visited[i] == false) {
                BFS(i, graph);
            }
        }

        return result;
    }
    
    void BFS(int start, vector<vector<int>>& graph) {
        
        Q.push(start);
        visited[start] = true;
        label[start] = true;
        
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            
            for(auto next : graph[cur]) {
                
                //방문하지 않은 노드
                if(visited[next] == false) {
                    Q.push(next);
                    visited[next] = true;
                    label[next] = !label[cur];
                }
                //방문한 노드라면 현재 Label과 비교 -> 같은 값이면 False 처리
                else if(visited[next] == true) {
                    if(label[cur] == label[next]) {
                        result = false;
                        break;
                    }
                }
            } 
        }
    }
};