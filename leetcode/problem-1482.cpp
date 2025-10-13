class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        if(m>n/k) return -1;
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            
            int help=0,count=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                count++;
            }else{
                
                help+=count/k;
                count=0;
            }
        }
        help+=count/k;
        if(help<m){
mini=mid+1;
        }else{
            maxi=mid-1;
            
            ans=mid;
        }
        
        }return ans;
    }
};
