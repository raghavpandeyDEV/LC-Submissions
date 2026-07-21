class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // -5 -> cant place , +5->can place
        int size=flowerbed.size();
        vector<int>canPlace(size,5);


        for(int i=0;i<size;i++){
            if(flowerbed[i]==1){
                canPlace[i]=-5;
               if(i+1<size)canPlace[i+1]=-5;
               if(i-1>=0)canPlace[i-1]=-5;
            }
        }
      int cnt=0;
      for(int i=0;i<size;i++){
        if(canPlace[i]==5){cnt++;
               canPlace[i]=-5;
               if(i+1<size)canPlace[i+1]=-5;
               if(i-1>=0)canPlace[i-1]=-5;
        }
      }

      return cnt>=n;
    }
};