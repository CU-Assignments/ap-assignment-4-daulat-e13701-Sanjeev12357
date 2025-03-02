class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            int n=nums.size();
            priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
            unordered_map<int,int> freqMap;
    
            for(auto num:nums){
                freqMap[num]++;
            }
    
            for(auto num:freqMap){
                pq.push({num.second,num.first});
    
                if(pq.size()>k){
                    pq.pop();
                }
            }
    
            vector<int> result;
            while(!pq.empty()){
                result.push_back(pq.top().second);
                pq.pop();
            }
            return result;
    
        }
    };