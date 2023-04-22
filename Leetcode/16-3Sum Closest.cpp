class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int closest=nums[len-3]+nums[len-2]+nums[len-1];
        for(int i=2;i<len;i++){
            int dis=nums[i]+twoSumClosest(nums,target-nums[i],i-1)-target;
            if(abs(dis)<abs(closest-target))
                closest=dis+target;
        }
        return closest;
    }
    int twoSumClosest(vector<int>& nums, int target,int ep){
        if(ep==1)
            return nums[0]+nums[1];
        int lb=0;
        int ub=ep;
        int closest=nums[ep-1]+nums[ep];
        while(lb<ub){
            int dis=nums[lb]+nums[ub]-target;
            if (abs(dis)<abs(closest-target))
                    closest=dis+target;
            if (dis==0)
                return target; 
            if (dis>0){
                ub--;
            }
            else{
                lb++;
            }   
        }
        return closest;
    }
};