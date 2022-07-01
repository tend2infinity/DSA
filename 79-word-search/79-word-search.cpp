class Solution {
public:
    bool recur(int i, int j, vector<vector<char>>& board, string & word, int wordIndex, int n, int m){
        //base
        if(wordIndex<0)
            return true;
        
        if(i<n && i>=0 && j<m && j>=0 && wordIndex>=0){
            if(board[i][j] == word[wordIndex]){
                char ch = board[i][j];
                board[i][j]='*';
                wordIndex--;
                bool res = recur(i-1,j,board,word,wordIndex,n,m)|| recur(i,j-1,board,word,wordIndex,n,m) 
                    || recur(i,j+1,board,word,wordIndex,n,m) ||  recur(i+1,j,board,word,wordIndex,n,m) ;
                board[i][j] = ch;
                if(res==true) return true;
                else return false;
            }
            return false;
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool ans=false;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                ans = ans || recur(i,j,board,word,word.size()-1,n,m);
            }            
        }

        return ans;
    }
};