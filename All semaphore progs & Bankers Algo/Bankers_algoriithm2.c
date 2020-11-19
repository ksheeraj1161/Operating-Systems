#include<stdio.h>

void function(int n,int m){
	int flag;
	struct p{
		int max[m],alloc[m],need[m];
		}p[n];
	int avail[m], request[m];
	
	for(int i=0;i<m;i++){
		printf("\nEnter Available instances of Resource %d: ",i+1);
		scanf("%d",&avail[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		printf("\nEnter Details of process %d:",i);
	for(int j=0;j<m;j++){	
		printf("\nEnter max resource (%d) required;",j+1);
	scanf("%d",&p[i].max[j]);
	}
	
	for(int j=0;j<m;j++){
		printf("\n\tEnter allocated resourse (%d):",j+1);
		scanf("%d",&p[i].alloc[j]);
	}
	
	printf("\n\tDoes this process nedd additional resource?\(Enter 1 for Yes 0 for No)");
	scanf("%d",&flag);
	
	if(flag==0){
		for(int j=0;j<m;j++){
			p[i].need[j]=p[i].max[j].p[i].alloc[j];
		}
		}
		else{
			printf("\nEnter Request Details:");
		for(int j=0;j<m;j++){
			printf("\n\tEnter request of resource %d",j+1);
			scanf("%d",&request[j]);
			avail[j]-=request[j];
		}
		
		for(int j=0;j<m;j++){
			p[i].alloc[j]+=request[j];
			p[i].need[j]=p[i].max[j]-p[i].alloc[j];
		}
		}
	    }
	    
	    int finish[n];
	    for(int i=0;i<n;i++){
	    	finish[i]=0;
		}
		
		int safeseq[n];
		
		int i=0,I=0;
		while(i<n){
			if(finish[i]==0){
				int c=0;
			for(int j=0;j<m;j++){
				if(p[i].need[j]<=avail[j]){
			    c+=1
				}
			}
			
			if(c==m){
				for(int j=0;j<m;j++){
					avail[j]+=p[i].alloc[j];
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
		
		printf("\nSafe Sequence is:\n");
		for(int i=0;i<n;i++){
			printf(" -->process %d" ,safeseq[i]);
		}
		printf("\n");
}


int main(){
	int n,m;
	printf("Enter number of processes:\n");
	scanf("%d",&n);
	printf("Enter number of resources:\n");
	scanf("%d",&m);
	
	function(n,m);
	
	return 0;
}
