#include <stdio.h>
#include <stdlib.h>

#define Weight 8
#define Height 8

void starttable(int tab[Weight][Height]){
	for(int i=0;i<8;i++){
		switch(i){
			case 0:
				tab[i][0]=2; tab[i][1]=3; tab[i][2]=4;
				tab[i][3]=5; tab[i][4]=6; tab[i][5]=4;
				tab[i][6]=3; tab[i][7]=2;
				break;
			case 7:
				tab[i][0]=20; tab[i][1]=30; tab[i][2]=40;
				tab[i][3]=50; tab[i][4]=60; tab[i][5]=40;
				tab[i][6]=30; tab[i][7]=20;
				break;
			case 1:
				for(int j=0;j<8;j++){
					tab[i][j]=1;
				}
				break;
			case 6:
				for(int j=0;j<8;j++){
					tab[i][j]=10;
				}
				break;
			case 2: case 3: case 4: case 5: default:
				for(int j=0;j<8;j++){
					tab[i][j]=0;
				}
				break;
		}
	}
}

void printtable(int hod, char text[], int znak, int znak1, int tab[Weight][Height], FILE *ofile){
	int p=1;
	printf("\n"); fprintf(ofile,"\n");
	if(hod!=0){ printf(" %d. ",hod); fprintf(ofile," %d. ",hod); }
	if(znak!=0 && znak1!=0) for(int i=znak;i<=znak1;i++){ printf("%c",text[0+i]); fprintf(ofile,"%c",text[0+i]); }
	printf(" \n"); fprintf(ofile," \n");
	for(int i=0;i<8;i++){
		printf("%d",p); fprintf(ofile,"%d",p);
		for(int j=0;j<8;j++){
			if(tab[i][j]==0){ printf("  "); fprintf(ofile,"  ");}
			if(tab[i][j]==1){ printf(" p"); fprintf(ofile," p");}
			else if(tab[i][j]==10){ printf(" P"); fprintf(ofile," P");}
			if(tab[i][j]==2){ printf(" r"); fprintf(ofile," r");}
			else if(tab[i][j]==20){ printf(" R"); fprintf(ofile," R");}
			if(tab[i][j]==3){ printf(" n"); fprintf(ofile," n");}
			else if(tab[i][j]==30){ printf(" N"); fprintf(ofile," N");}
			if(tab[i][j]==4){ printf(" b"); fprintf(ofile," b");}
			else if(tab[i][j]==40){ printf(" B"); fprintf(ofile," B");}
			if(tab[i][j]==5){ printf(" q"); fprintf(ofile," q");}
			else if(tab[i][j]==50){ printf(" Q"); fprintf(ofile," Q");}
			if(tab[i][j]==6){ printf(" k"); fprintf(ofile," k");}
			else if(tab[i][j]==60){ printf(" K"); fprintf(ofile," K");}
		}
		p++; printf("\n"); fprintf(ofile,"\n");
	}
	printf("  a b c d e f g h\n"); fprintf(ofile,"  a b c d e f g h\n");
}



void erormes(int *er, FILE *ofile){
	switch(*er){
		case 1:
			printf(" \nViolation of the rules for the movement of figures.\n ");
			fprintf(ofile," \nViolation of the rules for the movement of figures.\n ");
		break;
		case 2:
			printf(" \nThe piece that was supposed to move was not in position.\n ");
			fprintf(ofile," \nThe piece that was supposed to move was not in position.\n ");
		break;
		case 3:
			printf(" \nWith a quiet move, a figure appeared on the way.\n ");
			fprintf(ofile," \nWith a quiet move, a figure appeared on the way.\n ");
		break;
		case 4:
			printf(" \nWhen capturing, there was no piece to capture.\n ");
			fprintf(ofile," \nWhen capturing, there was no piece to capture.\n ");
		break;
		case 5:
			printf(" \nExceeding the field boundaries or non-existent position.\n ");
			fprintf(ofile," \nExceeding the field boundaries or non-existent position.\n ");
		break;
		case 6:
			printf(" \nThe sequence of moves is broken.\n ");
			fprintf(ofile," \nThe sequence of moves is broken.\n ");
		break;
		default:
			printf(" \nThe party is over. There are no errors.\n ");
			fprintf(ofile," \nThe party is over. There are no errors.\n ");
		break;
	}
}

int main()
{
    int x=8, y=8, ex=0, c=0, er=0, hod=1;
	int tab[Weight][Height];
	char line[20];
	
	FILE *file = fopen("text.txt","r");
	if(file==NULL){
		printf("Error. Text file do not opened. Check text.txt file.");
		return -3;
	}
	
	FILE *ofile = fopen("output.txt","w");
	if(ofile==NULL){
		printf(" Errore. Output file do not opened. Check output.txt file. ");
		return -3;
	}
	
	starttable(tab); printtable(0,line,0,0,tab,ofile);
	printf("\n \n"); fprintf(ofile,"\n \n");
	while(ex<2){
		while((c=fgetc(file)) != EOF){ 
			fgets(line,20,file); 
			move(hod,line,tab,&er,ofile); 
			printf("\n \n");
			fprintf(ofile,"\n \n");
			hod++;
			if(er>0)break;
		}
		erormes(&er,ofile);
		if(er>0) {
			return -3;
		}
		ex+=20;
	}
	fclose(file); fclose(ofile);
	return 0;
}

