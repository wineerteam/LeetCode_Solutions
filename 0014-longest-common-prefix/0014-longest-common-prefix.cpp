class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n=strs.size();
        string ans;
      for(int i=0; i<strs[0].size(); i++){

        char ch=strs[0][i];
        for(int j=0; j<n; j++){
            char ch1=strs[j][i];

            if(i>=strs[j].size()|| ch != ch1)
            return ans;
        }
                ans.push_back(ch);
      }
        return ans;
    }
};
//   The time complexity is O(n*m) and space complexity is Order O(1)
// use tries then time complexity is redcuce and tc--- O(1) but space complexity is increase 
// becasue insert tries all words then seach it 
