class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize==1)return false;

        map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }

        sort(hand.begin(),hand.end());

        while(!mpp.empty()){
            int curr=mpp.begin()->first;

            for(int i=0;i<groupSize;i++){
                if(mpp.find(curr+i)!=mpp.end()){
                    mpp[curr+i]--;
                    if(mpp[curr+i]==0){
                        mpp.erase(curr+i);
                    }
                }
                else return false;
            }
        }
return true;
    }
};