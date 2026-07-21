class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();

        int num1=INT_MAX;
        int num2=INT_MAX;

        for(int i=0;i<n;i++){
            int num3=nums[i];

            if(num3<=num1)num1=num3;
            else if (num3<=num2)num2=num3;
            else return true;
        }
        
        return false;
    }

    //Q) [ 1  , 4 , 0 , 6 ] -> num1= 0 , num2=4 , num3=6 (0,4,6) but actual is (1,4,6)

 /*   The key insight

num1 and num2 are not necessarily the actual triplet.

They only store values, not the exact indices of the final answer.

When we reached 4, we already had

1 ----> 4

which is a perfectly valid increasing pair.

Later, when 0 arrives, we simply say

"If I ever want to start a new increasing sequence, 0 is an even better first element."

We are not destroying the fact that (1,4) already existed.

So after reading 0, internally we have two possibilities:

Existing pair:
1 -> 4

Potential new start:
0

Then 6 arrives.

Since 6 > 4, we know there already existed some first element before 4.

That first element is 1, not necessarily the current num1.

Hence the actual triplet is

1 -> 4 -> 6
*/

};