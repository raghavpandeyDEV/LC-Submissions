class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            int changes=0;
            for(int j=i;j<n;j++){
                if(blocks[j]=='W')changes++;
                if((j-i+1)==k){
                    mini=min(mini,changes);
                    break;
                }
            }
        }
        return mini;
    }
};