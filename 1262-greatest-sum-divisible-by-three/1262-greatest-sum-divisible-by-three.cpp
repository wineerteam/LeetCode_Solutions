class Solution {
public:
    int maxSumDivThree(vector<int>& arr) {
        vector<int>r1,r2;
        int sum=0;
        
        for(int num:arr){
            sum +=num;
            if(num % 3==1){
                r1.push_back(num);
            }
            else if(num % 3==2)
            r2.push_back(num);

        }
        sort(r1.begin(),r1.end());
        sort(r2.begin(),r2.end());
        int rem=sum % 3;
    
        
        if(rem==0)
        return sum;
           
        int remove=INT_MAX;

        if(rem==1){
            if(!r1.empty())
            remove=min(remove,r1[0]);

            if(r2.size()>=2)
            remove=min(remove,r2[0]+r2[1]);
        }
        else{
            if(!r2.empty())
            remove=min(remove,r2[0]);
            if(r1.size()>=2)
            remove=min(remove,r1[0]+r1[1]);
        }
    

        return sum-remove;
    }
};