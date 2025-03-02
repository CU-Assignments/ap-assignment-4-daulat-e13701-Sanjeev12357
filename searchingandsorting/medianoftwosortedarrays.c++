class Solution {
    public:
        int upper_bound(vector<int> & nums, int number){
            int s=0;
            int e=nums.size()-1;
    
            int ans=nums.size();
            while(s<=e){
                int mid=s+(e-s)/2;
    
                if(nums[mid]>number){
                    ans=mid;
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }
            return ans;
        }
        int calc(vector<int> & nums1, vector<int> & nums2, int number){
            int ans=0;
            if(nums1.size()>0)
            ans+=upper_bound(nums1,number);
            if(nums2.size()>0)
            ans+=upper_bound(nums2,number);
    
            return ans;
        }
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // song : slow motion
            // timing : 2:35pm
            int low=INT_MAX;
            int low2=INT_MAX;
            int high=INT_MIN;
            int high2=INT_MIN;
            if(nums1.size()>0){
             low=*min_element(nums1.begin(),nums1.end());
                high = *max_element(nums1.begin(),nums1.end());
            }
            
            if(nums2.size()>0){
             low2=*min_element(nums2.begin(),nums2.end());
             
              high2 = *max_element(nums2.begin(),nums2.end());
            
            
            }
            low=min(low,low2);
            high=max(high,high2);
            low2=low;
            high2=high;
           
            int req=(nums1.size() + nums2.size())/2;
            while(low<=high){
    
                int mid=low+(high-low)/2;
                int smallerElements=calc(nums1,nums2,mid);
    
                if(smallerElements <= req){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            if((nums1.size() + nums2.size()) % 2 ==1 ){
                return low;
            }
            int first=low;
           
            while(low2<=high2){
    
                int mid=low2+(high2-low2)/2;
                int smallerElements=calc(nums1,nums2,mid);
    
                if(smallerElements < req){
                    low2=mid+1;
                }else{
                    high2=mid-1;
                }
            }
            int second=low2;
            return (first + second)/2.0;
            
        }
    };