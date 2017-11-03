#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


pthread_t tid1,tid2,tid3;


int skor1, skor2, status;
char sym[2][16];

void* game(void* arg){

    char player1[100];
    char player2[100];

    printf ("\n~ WELCOME ~\n\n");

    printf ("Nama player 1: ");
    scanf ("%s", player1);

    printf ("Nama player 2: ");
    scanf("%s", player2);

    int lubang, ranjau;
    int i, t;

	while(1){

	    printf ("....................\n");
	    printf ("Skor Awal\n%s: %d \n%s: %d", player1, skor1, player2, skor2);
	    printf ("\n....................\n");

	    printf("\n%s bisa memasang 1 sampai 4 ranjau\n", player1);
	    printf("1--2--3--4--5--6--7--8--9--10--11--12--13--14--15--16\n");

	    for (i=0; i<16; i++)
	    	printf("%c", sym[0][i]); 
	    	printf("\nBerapa lubang yang mau diisi ranjau?\n");
	    	scanf("%d", &lubang);
	    	printf("\nLubang mana saja?\n");

	    while(lubang--){
		scanf("%d",&ranjau);
	    }
	  
	    for (i=0; i<16; i++) 
	    	printf ("%c", sym[0][i]);
	    	printf ("\n%s, tebak 4 lubang yang dipilih %s\n", player2, player1);

	    for (i=0; i<4; i++){
	    	scanf ("%d", &t);

	    	if (sym[0][t]=='o')
		    skor2++;

	    	else 
		    skor1++;
	    }

	    status = 1;

	    while (status != 0){

	    	printf ("\n....................\n");
	    	printf ("Skor sementara:\n%s = %d \n%s = %d", player1, skor1, player2, skor2);	
		printf ("\n....................\n");
	
	    	printf ("\n%s bisa memasang 1 sampai 4 ranjau\n", player2);
	    	printf("1--2--3--4--5--6--7--8--9--10--11--12--13--14--15--16\n");

	    for (i=0; i<16; i++) 
	    	printf ("%c  ", sym[1][i]); 
	    	printf ("\nBerapa lubang yang mau diisi ranjau?\n");
	    	scanf("%d", &lubang);
	    	printf("\nLubang mana saja?\n");

	    while(lubang--){
		scanf("%d", &ranjau);
	    }

	    for (i=0; i<16; i++) 
	    	printf ("%c  ",sym[1][i]); 
	    	printf ("\n%s, tebak 4 lubang yang dipilih %s\n", player1, player2);

	    for (i=0; i<4; i++){
	 	scanf ("%d", &t);
		if (sym[1][t]=='o') 
		    skor1++;
		else 
		    skor2++;
	    }

	    status = 1;
	    
	    while (status!=0){
	    printf("\n");
	    }
	}
    }
}

void* check(void* arg){
	int x, y, i;;

	while(1){

	    x=0;
	    y=0;

	    while (status != 1)
		for (i=0; i<16; i++){
		    if (sym[0][i]=='x') x++;
		    if (sym[1][i]=='x') y++;
	   	}

		if (x==16 && y==16){
		    printf ("GAME OVER!");
		    exit(0);
		}

		else status = 0;
	}
}
void* gameEnd(void* arg){

	while(1){
	    while (status != 1){}
	    if (skor1 >= 10 || skor2 >= 10){
		printf ("GAME OVER!\n");
		exit(0);
	    }

	    else status = 0;
	}
}

int main(){

	pthread_create(&(tid1), NULL, &check, NULL);
	pthread_create(&(tid2), NULL, &gameEnd, NULL);
	pthread_create(&(tid3), NULL, &game, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
}
