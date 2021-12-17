//count subisland============================================================================
class Solution {
public:
    vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
    bool isvalid(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int n,int m){
        grid1[i][j]=0;
        grid2[i][j]=0;
        bool ans=true;
        
        for(int t=0;t<4;t++){
            int r=i+dirs[t][0];
            int c=j+dirs[t][1];
            if(r<n && c<m && r>=0 && c>=0 && grid2[r][c]==1){
                if(grid1[r][c]!=1)ans=false;
                
                ans=isvalid(grid1,grid2,r,c,n,m)&&ans;
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1&&grid1[i][j]==1){
                    bool valid=isvalid(grid1,grid2,i,j,n,m);
                    
                    if(valid){
                        cout<<i<<" "<<j<<"\n";
                        count++;
                    }
                }
            }
        }
        return count;
         
    }
};

//no of island2============================================================================================



class Solution {
public:
    vector<int>par;
    int findpar(int v){
        if(par[v]==v){
            return v;
        }
        return par[v]=findpar(par[v]); 
    }
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
     vector<int>ans;
     int count=0;
     par.resize(n*m,-1);
     vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
     for(auto p:operators){
         
         int i=p.x;
         int j=p.y;
         int idx=i*m+j;
         int p1=par[idx];
         if(p1!=-1){
             ans.push_back(count);
             continue;
         }
         count++;
         par[idx]=idx;
         for(auto d:dirs){
             int r=i+d[0];
             int c=j+d[1];
             if(r<n&&r>=0&&c>=0&&c<m&&par[r*m+c]!=-1){
                 int p2=findpar(r*m+c);
                 p1=findpar(i*m+j);
                 if(p1!=p2){
                     par[p2]=p1;
                     count--;
                 }
             }
         }
         ans.push_back(count);
     }
     return ans;

    }
};

