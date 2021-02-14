class Solution {
public:
    
    int grid_size = 0;
    queue<pair<int, int>> Q;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        grid_size = grid[0].size();
        
        int result = -1;
        if(grid[0][0] == 0) {
            Q.push(make_pair(0, 0));
            grid[0][0] = 1;
            result = BFS(grid);
        }
        
        return result;
    }
    
    int BFS(vector<vector<int>>& grid) {
        
        while(!Q.empty()) {
            
            pair<int, int> cur = Q.front();
            
            Q.pop();
            int row = cur.first;
            int col = cur.second;
            int level = grid[row][col];
            
            //n-1, n-1에 다다르면 리턴
            if(row == grid_size-1 && col == grid_size-1) {
                return grid[row][col];
            }
            
            //상
            if(isAvailable(row-1, col, grid)) {
                Q.push(make_pair(row-1, col));
                grid[row-1][col] = level+1;
                //cout << "1" << endl;
            }

            //우상
            if(isAvailable(row-1, col+1, grid)) {
                Q.push(make_pair(row-1, col+1));
                grid[row-1][col+1] = level+1;  
                //cout << "2" << endl;
            }
            
            //우
            if(isAvailable(row, col+1, grid)) {
                Q.push(make_pair(row, col+1));
                grid[row][col+1] = level+1;
                //cout << "3" << endl;
            }

            //우하
            if(isAvailable(row+1, col+1, grid)) {
                Q.push(make_pair(row+1, col+1));
                grid[row+1][col+1] = level+1;  
                //cout << "4" << endl;
            }

            //하
            if(isAvailable(row+1, col, grid)) {
                Q.push(make_pair(row+1, col));
                grid[row+1][col] = level+1;    
                //cout << "5" << endl;
            }

            //좌하
            if(isAvailable(row+1, col-1, grid)) {
                Q.push(make_pair(row+1, col-1));
                grid[row+1][col-1] = level+1;
                //cout << "6" << endl;
            }

            //좌
            if(isAvailable(row, col-1, grid)) {
                Q.push(make_pair(row, col-1));
                grid[row][col-1] = level+1;  
                //cout << "8" << endl;
            }

            //좌상
            if(isAvailable(row-1, col-1, grid)) {
                Q.push(make_pair(row-1, col-1));
                grid[row-1][col-1] = level+1;   
                //cout << "9" << endl;
            }            
        }
        
        //BFS 전체 탐색했는데 n-1, n-1에 다다르지 못하는 경우 -1 리턴
        return -1;
    }
    
    //범위를 넘어서지 않는지, 갈 수 있는 길인지 체크(동익 코드 참고, 앞으로도 이렇게하면 좋을 듯)
    bool isAvailable(int x, int y, vector<vector<int>>& grid) {
        
        bool flag = true;
        
        if (x < 0 || y < 0 || x > grid_size - 1 || y > grid_size - 1) {
            flag = false;
        }
		else {
		    if (grid[x][y] != 0)
			    flag = false;            
        }

		return flag;
    }
};