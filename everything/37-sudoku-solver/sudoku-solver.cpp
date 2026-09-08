class Solution {
public:

    bool check(int row,int col,char ch,vector<vector<char>>&board){

        for(int i=0;i<9;i++){
            if(board[row][i]==ch)
                return false;
        }

        for(int j=0;j<9;j++){
            if(board[j][col]==ch)
                return false;
        }

        int sr=(row/3)*3;
        int sc=(col/3)*3;

        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>&board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.'){

                    for(char ch='1';ch<='9';ch++){

                        if(check(i,j,ch,board)){

                            board[i][j]=ch;

                            if(solve(board))
                                return true;

                            board[i][j]='.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>&board){
        solve(board);
    }
};