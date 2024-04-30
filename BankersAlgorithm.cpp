#include<iostream>
using namespace std;
int main(){
    int n=5;
    int r=3;
    int avail[3] = {3, 3, 2};
	int maxm[n][r] = {{7, 5, 3},
					{3, 2, 2},
					{9, 0, 2},
					{2, 2, 2},
					{4, 3, 3}};
	int allot[n][r] = {{0, 1, 0},
					{2, 0, 0},
					{3, 0, 2},
					{2, 1, 1},
					{0, 0, 2}};
	
	int need[n][r];
	for(int i=0; i<n; i++){
	    for(int j=0;j<r;j++){
	        need[i][j]=maxm[i][j]-allot[i][j];
	    }
	}
	
	int f[n],ans[n];
	int ind=0;
	for(int k=0;k<n;k++){
	    f[k]=0;
	}
	for(int k=0;k<n;k++){
	    for(int i=0;i<n;i++){
	        if(f[i]==0){
	            int flag = 0;
	            for(int j=0;j<n;j++){
            	    if(need[i][j]>avail[j]){
            	        flag = 1;
            	        break;
            	    }
            	}
            	if(flag==0){
            	    ans[ind++]=i;
            	    for(int y=0;y<r;y++){
            	        avail[y]+=allot[i][y];
            	    }
            	    f[i]=1;
            	}
	        }
	    }
	}
	cout<<"The safe sequence is : "<<endl;
	
	for(int i=0;i<n;i++){
	    cout<<"P"<<ans[i]<<"->";
	}
}
