class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int i=arr.size()-1;

        while(i>=0){
            if( arr[i]<9){
                arr[i]++;
                return arr;
            }
            // digit 9 h. agar us se chota hota to loop se hi return ho jata
            arr[i]=0;
            i--;
        }
        arr.insert(begin(arr),1);
        return arr;
        
    }
};