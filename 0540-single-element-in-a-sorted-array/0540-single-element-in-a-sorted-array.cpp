class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
         if( n==1)return arr[0];
        
        while(l<=r){
            int m=l+(r-l)/2;
          
            if( m==0 && arr[m] !=arr[m+1]) return arr[m];
            if( m==n-1 && arr[m] !=arr[m-1])return arr[m];
            if( arr[m-1] !=arr[m] && arr[m] !=arr[m+1])return arr[m];             
              
            
            else{
                // even in both side so jid match udher hi ans
                if(m % 2==0){
                 if( arr[m-1]==arr[m])
                    r=m-1;
                 else
                  l=m+1;
                }
                else{
                    // odd in both side of mid
                    if( arr[m-1]==arr[m])
                        l=m+1;
                    
                    else
                        r=m-1;
                    
                }
            }

        }
        
        return -1;
    }
};