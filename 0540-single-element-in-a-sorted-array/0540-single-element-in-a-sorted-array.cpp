class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {

       for(int i = 0; i < arr.size(); i += 2) {

            if(i == arr.size() - 1 || arr[i] != arr[i + 1]) {
                return arr[i];
            }
        }
        return -1;
    }
};