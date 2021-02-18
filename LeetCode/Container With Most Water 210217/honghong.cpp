class Solution {
public:
    int maxArea(vector<int>& height) {
    
        int max = 0;
        int start = 0;
        int end = height.size() - 1;
        
        while(end - start > 0) {
            
            int smaller;
            int length = end - start;
            
            if(height[end] > height[start]) {
                smaller = height[start];
                start++;
            }
            else {
                smaller = height[end];
                end--;
            }
            
            int width = length * smaller;
            max = max > width ? max : width;
        }
        
        return max;
    }
};