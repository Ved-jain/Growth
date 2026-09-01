class Solution {
public:

    struct node {
        int i;
        int j ;
        int egy ;
        int mask;
        int dist;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>>liter(m , vector<int>(n , -1));
        int id = 0 ;
        int x =0 , y =0 ;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j <n ; j++){

                if(classroom[i][j]=='L'){
                    liter[i][j]=(1<<id);
                    id++;
                }

                if(classroom[i][j]=='S'){
                    x = i ;
                    y = j;
                }
            }
        }

        int totalmask = (1<<id) -1 ;
        queue<node>q;

        vector<vector<vector<int>>>best(m , vector<vector<int>>(n , vector<int>(1<<id , -1)));

        q.push({x , y , energy ,0 ,0});
        best[x][y][0] = energy;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!q.empty()){
            node curr = q.front();
            q.pop();

            if(curr.mask == totalmask){
                return curr.dist;
            }

            if(curr.egy==0) continue;

            for(int k = 0 ; k<4 ; k++){
                int nr = curr.i + dx[k];
                int nc = curr.j + dy[k];





                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;

                
                if(classroom[nr][nc]=='X') continue;

                int newenergy = curr.egy - 1;

                if(classroom[nr][nc]=='R')
                {
                    newenergy = energy ;

                }


                int newmask=curr.mask;

                if(classroom[nr][nc]=='L'){
                    newmask=newmask|liter[nr][nc];
                }
                

                if(best[nr][nc][newmask] >= newenergy ) continue;
                best[nr][nc][newmask] = newenergy;
                q.push({
                    nr ,
                    nc , 
                    newenergy,
                    newmask,
                    curr.dist+1
                });


            }
        }
        return -1;
    }
};