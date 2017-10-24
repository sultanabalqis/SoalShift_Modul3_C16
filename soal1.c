#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

//pthread_t tid[6];
int senjata[6]={10,10,10,10,10,10};
void pembeli();
void penjual(){
	int pilihan=0;	
//	system ("clear");
	printf("SEBAGAI PENJUAL\n");
	printf("1. Lihat Stock Senjata\n");
	printf("2. Tambah Stock Senjata\n");
	printf("PILIH: "); scanf("%d ",&pilihan);
	
	if (pilihan==1){
//		system ("clear");
		int i;
		printf("STOK SENJATA\n\n");
		for(i=0;i<6;i++){
			//if(senjata[i]==0) continue;
			if(i==0) printf("MP4A1 %d\n",senjata[i]);
			else if(i==1) printf("PM2-V1 %d\n",senjata[i]);
			else if(i==2) printf("SPR-3 %d\n",senjata[i]);
			else if(i==3) printf("SS2-V5 %d\n",senjata[i]);
			else if(i==4) printf("SPG1-V3 %d\n",senjata[i]);
			else if(i==5) printf("MINE %d\n", senjata[i]);		
		}
		printf("\n\n");
		penjual();
	}

	else if (pilihan==2){
	//	system ("clear");
		char masuk[8];
		int input;
		scanf("%s %d", masuk,&input);
		if(masuk=="MP4A1") senjata[0]+=input;
		penjual();	
	}
		
	if(pilihan==3) pembeli();
}	

void pembeli(){
	printf("cie masuk pembeli\n");
}

int main(){

	int i=0,temp;
	int t;
	int err;

	printf ("===SISTEM INFORMASI KHAWARI STORE===\n\n");
	sleep(1);
	printf("PILIH MODE\n");
	printf("1. PENJUAL\n");
	printf("2. PEMBELI\n");
	printf("INPUT: ");
	scanf("%d",&temp);
	
//	while(1){
		if(temp==1) penjual();
		//else if(temp==2) pembeli;
//	}
	return 0;
}
