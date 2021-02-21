class Solution {
public:
    int brokenCalc(int X, int Y) {
        
/*이걸 솔루션에서는 재귀적으로 풀었네...*/

        int count = 0;

        //기본적으로 Y를 X로 만들어간다고 생각하고 품. 나누어질 수 있을 때, 없을때로 구분해서 생각할 수 있으니까
        while(Y != X) {

            if(Y%2 == 0) {
                if(Y > X) {
                    Y /= 2;
                    count++;
                }
                else if(Y < X) {
                    Y += 1;
                    count++;
                }
            }
            else {
                Y += 1;
                count++;
            }
        }
        
        return count;
    }
};