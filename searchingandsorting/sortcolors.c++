class Solution {
    public:
        void sortColors(vector<int>& nums) {
        //    int n= nums.size();
        //    int l=0;
        //    int i=0;
        //    int r=n-1;
        //    while(i<=r){
        //     if(nums[i]==0){
        //         swap(nums[i],nums[l]);
        //         i++;
        //         l++;
        //     }else if(nums[i]==1){
        //         i++;
        //     }else{
        //         swap(nums[i],nums[r]);
        //         r--;
        //     }
        //    }
    
        int zeros,ones,twos;
            zeros=ones=twos=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                {
                    zeros++;
                }
                else if(nums[i]==1)
                {
                    ones++;
                }
                else
                {
                    twos++;
                }
            }
            int i=0;
            while(zeros--)
            {
                nums[i]=0;
                i++;
            }
            while(ones--)
            {
                nums[i]=1;
                i++;
            }
            while(twos--)
            {
                nums[i]=2;
                i++;
            }
           
        }
    };