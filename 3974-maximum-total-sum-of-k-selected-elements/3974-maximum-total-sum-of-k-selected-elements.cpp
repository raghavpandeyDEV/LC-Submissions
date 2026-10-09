class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
      sort(nums.rbegin(),nums.rend());
      
      int i=0;
      long long sum=0;

      while(k!=0){
      if(mul>0){
        sum+= 1LL * nums[i] * mul;
      }
      else{
        sum+=nums[i];
      }
      mul--;
      k--;
      i++;
      }

return sum;
    }
};