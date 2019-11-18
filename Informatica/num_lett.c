#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void gotoxy(int x,int y){
 printf("%c[%d;%df",0x1B,y,x);
 }


 int main()
 {
 	int n, m, c, d, u, r;
  char risp;
  do{
     	do{
        system("clear");
     		gotoxy(31,1);
     		printf("DA NUMERO A LETTERE");
     		gotoxy(24,3);
     		printf("Inserire un numero tra 1 e 10000 .....");
     		gotoxy(57,3);
     		scanf("%d", &n);
     	}while(n<1||n>10000);

     	m = n / 1000;
     	r = n%1000;

     	c = r / 100;
     	r = n%100;

     	d = r / 10;
     	r = n%100;

     	u = n%10;
//    printf("%d %d %d %d\n", m, c, d, u);

    printf("\nIl numero %d in lettere e' ", n);
    //Controllo per vedere la cifra delle migliaia e stampare il valore in lettere
     	switch(m)
    	 {
     		case 1:{
     			printf("mille");
    			break;
    		 }
    		 case 2: {
     			printf("duemila");
    			break;
    		 }
    		 case 3:{
     			printf("tremila");
    			break;
    		 }
    		 case 4:{
     			printf("quattromila");
    			break;
    		 }
    		 case 5:{
     			printf("cinquemila");
    			break;
    		 }
    		 case 6:{
     			printf("seimila");
    			break;
    		 }
    		 case 7:{
     			printf("settemila");
    			break;
    		 }
    		 case 8:{
     			printf("ottomila");
    			break;
    		 }
    		 case 9:{
     			printf("novemila");
    			break;
    		 }
    		 case 10:{
     			printf("diecimila");
    			break;
    		 }
    	 }
    //Controllo per vedere la cifra delle centinaia e stampare il valore in lettere
        if(d == 8) {
          switch(c)
          {
            case 1: {
              printf("cent");
              break;
            }
            case 2: {
             printf("duecent");
             break;
            }
            case 3:{
             printf("trecent");
             break;
            }
            case 4:{
             printf("quattrocent");
             break;
            }
            case 5:{
             printf("cinquecent");
             break;
            }
            case 6:{
             printf("seicent");
             break;
            }
            case 7:{
             printf("settecent");
             break;
            }
            case 8:{
             printf("ottocent");
             break;
            }
            case 9:{
             printf("novecent");
             break;
            }
          }
        }
        else{
          switch(c)
          {
            case 1: {
              printf("cento");
              break;
            }

            case 2: {
              printf("duecento");
              break;
            }
            case 3:{
              printf("trecento");
              break;
            }
            case 4:{
              printf("quattrocento");
              break;
            }
            case 5:{
              printf("cinquecento");
              break;
            }
            case 6:{
              printf("seicento");
              break;
            }
            case 7:{
              printf("settecento");
              break;
            }
            case 8:{
              printf("ottocento");
              break;
            }
            case 9:{
              printf("novecento");
              break;
            }
          }
        }
    //Controllo dei casi speciali (unità 1 oppure 8)
    	if((u==1 || u==8) && d!=1){

        	switch(d)
        	 {
        		 case 2: {
         			printf("vent");
        			break;
        		 }
        		 case 3:{
         			printf("trent");
        			break;
        		 }
        		 case 4:{
         			printf("quarant");
        			break;
        		 }
        		 case 5:{
         			printf("cinquant");
        			break;
        		 }
        		 case 6:{
         			printf("sessant");
        			break;
        		 }
        		 case 7:{
         			printf("settant");
        			break;
        		 }
        		 case 8:{
         			printf("ottant");
        			break;
        		 }
        		 case 9:{
         			printf("novant");
        			break;
        		 }
        	}
            if (u==1) {//Controllo per capire se l'unità è 1 oppure 8
              printf("uno");
            }else{
              printf("otto");
            }
         }
         else if(d==1){  //Controllo casi speciali (11-->19)
           switch(u){
             case 0:{
               printf("dieci");
               break;
             }
             case 1:{
               printf("undici");
               break;
             }
             case 2:{
                printf("dodici");
               break;
             }
             case 3:{
                printf("tredici");
               break;
             }
             case 4:{
                printf("quattordici");
               break;
             }
             case 5:{
                printf("quindici");
               break;
             }
             case 6:{
                printf("sedici");
               break;
             }
             case 7:{
                printf("diciassette");
               break;
             }
             case 8:{
                printf("diciotto");
               break;
             }
             case 9:{
                printf("diciannove");
               break;
             }
           }


         } else {


           switch(d)
           {
         		 case 2: {
          			printf("venti");
         			break;
         		 }
         		 case 3:{
          			printf("trenta");
         			break;
         		 }
         		 case 4:{
          			printf("quaranta");
         			break;
         		 }
         		 case 5:{
          			printf("cinquanta");
         			break;
         		 }
         		 case 6:{
          			printf("sessanta");
         			break;
         		 }
         		 case 7:{
          			printf("settanta");
         			break;
         		 }
         		 case 8:{
          			printf("ottanta");
         			break;
         		 }
         		 case 9:{
          			printf("novanta");
         			break;
         		 }
         	}


            switch(u)
            {
               case 2: {
                printf("due");
                break;
               }
               case 3:{
                printf("tre");
                break;
               }
               case 4:{
                printf("quattro");
                break;
               }
               case 5:{
                printf("cinque");
                break;
               }
               case 6:{
                printf("sei");
                break;
               }
               case 7:{
                printf("sette");
                break;
               }
               case 9:{
                printf("nove");
               }
            }

        }

        printf("\n\nSi vuole uscire? (scrivere s o S)");
        scanf(" %c", &risp);
        system("clear");
  }while(risp!='S' && risp!='s');
}
