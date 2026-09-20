class Solution {
    bool ans=false;
    int n,m;
    void solve(int i, int j,vector<vector<char>>& arr, string &str, string &temp){
        if( temp == str){
            ans=true;
            return ;
        }
        if(i<0 || i>=n || j<0 || j>=m || temp.length()>str.length()) return ;
          
          if( arr[i][j]=='#') return;
        // left 
        char ch=arr[i][j];
        temp.push_back(ch);
        
        if( temp.back()!=str[temp.length()-1]){
            temp.pop_back();

         return;
}


        // found ans
        if( temp== str){
            temp.pop_back();
            ans=true;
            return;
        }
        

        // marked visited 
        arr[i][j]='#';

        solve(i,j-1,arr,str,temp);
        // right
        
        solve(i,j+1,arr,str,temp);
       

        // up 
        solve(i-1,j,arr,str,temp);
        // down
        solve(i+1, j, arr, str, temp);     
        /// back track
        arr[i][j]=ch;
        temp.pop_back();

    }
public:
    bool exist(vector<vector<char>>& arr, string str) {

         n=arr.size();
         m=arr[0].size();
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
        string temp="";
                if( arr[i][j]==str[0])
            solve(i,j,arr,str,temp);
             if( ans) 
             return true;
            }
        }
        return false;
        
    }
};

// 