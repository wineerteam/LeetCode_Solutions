class Solution {
public:
    char findKthBit(int n, int k) {

         if( n==1)return '0';
        // find the len

        int len=(1<<n)-1;

        if(k<(len+1)/2)
        return findKthBit(n-1,k);

       else if(k==(len+1)/2)
        return '1';
        
        else{
           char check=findKthBit(n-1,len-(k-1));
            if(check=='0')return '1';
            else
            return '0';
        }
        
    }
};