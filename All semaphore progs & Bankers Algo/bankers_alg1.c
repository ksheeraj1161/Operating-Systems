#include<stdio.h>

void Need(int n,int m,int allo[n][m],int max[n][m],int need[n][m]){
		for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		need[i][j]=max[i][j]-allo[i][j];
		}
		}
}

void display(int safeseq[],int n){
	printf("\nSafe Sequence is:\n");
	for(int i=0;i<n;i++){
	printf(" --> process %d" ,safeseq[i]);
	}
	printf("\n");
}
void Safeseq(int n,int m,int need[n][m],int alloc[n][m],int avail[m],int finish[n],int safeseq[n]){
			int i=0,I=0;
			while(i<n){
			if(finish[i]==0){
			int c=0;
			for(int j=0;j<m;j++){
			if(need[i][j]<=avail[j]){
			c+=;
			}
			}
			if(c==m){
			for(int j=0;j<m;j++){
			avail[j]+=alloc[i][j];
			}
			finish[i]=1;
			safeseq[I]=i;
			I++;
			}
			i++;
			if(i>=n){
				i-=n;
			}	
			}
			else{
				i++;
				continue;	
			}
			}
}



int main(){
	int n,m;
	printf("\nEnter number of processes: ");
	scanf("%d",&n);
	printf("\nEnter number of resources available: ");
	scanf("%d",&m);
	
	int avail[m];
	for(int i=0;i<m;i++){
		printf("\nEnter Available instances of Resource %d: ",i+1);
		scanf("%d",&avail[i]);	
	}
	int max[n][m];
	for(int i=0;i<n;i++){
		printf("\nEnter max resource demand of process %d: ",i);
	for(int j=0;j<m;j++){
		printf("\n\tEnter demand of resource %d: ",j+1);
		scanf("%d",&max[i][j]);
	}	
	}


	int alloc[n][m];
	for(int i=0;i<n;i++){
		printf{"\nEnter current resource allocated for process %d: ",i};
	for(int j=0;j<m;j++0){
		printf("\n\tEnter allocated resource %d: ",j+1);
		scanf("%d",&alloc[i][j]);
	}
	}
	
	int need[n][m];
	Need(n,m,alloc,max,need);
	
	int finish[n];
	for(int i=0;i<n;i++){
		finish[i]=0;
	}
	
	int safeseq[n];
	safeseq(n,m,need,alloc,avail,finish,safeseq);
	display(safeseq,n);
	return 0;
}

