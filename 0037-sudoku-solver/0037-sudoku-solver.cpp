class Solution {
      bool isValid(vector<vector<char>>& arr, int i , int j, char d){
       // row 
       // col 
       for(int k=0; k<9;k++){
        if(arr[i][k]==d)return false;
        if(arr[k][j]==d)return false;
       }

       // box
       int start_i=i/3*3;
       int start_j=j/3*3;
       for(int k=0; k<3; k++){
        for(int l=0; l<3; l++){
            if(arr[start_i+k][start_j+l]==d)return false;
        }
       }
return true;
    } 
    bool solve(vector<vector<char>>&arr){
    for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(arr[i][j]=='.'){
                    for(char d='1'; d<='9'; d++){
                        if(isValid(arr,i,j,d)){
                            arr[i][j]=d;  // do
                          if( solve(arr)==true) return true;   // explore
                            arr[i][j]='.'; // undo
                        }
                    }
                    return false;
                }
            }
        }
        return true;  //cels filed
    }
public:
    void solveSudoku(vector<vector<char>>& arr) {
         solve(arr);
        
    } 
  
};

// time complexity is 9*9=81 so 2^81 but constant