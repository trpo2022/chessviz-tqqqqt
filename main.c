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

void printtable(int tab[Weight][Height])
{
    int p = 1;
    printf("  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d", p);
        for (int j = 0; j < 8; j++) {
            if (tab[i][j] == 0)
                printf(" ");
            if (tab[i][j] == 1 && i < 2)
                printf(" p");
            else if (tab[i][j] == 1 && i > 5)
                printf(" P");
            if (tab[i][j] == 2 && i < 2)
                printf(" r");
            else if (tab[i][j] == 2 && i > 5)
                printf(" R");
            if (tab[i][j] == 3 && i < 2)
                printf(" n");
            else if (tab[i][j] == 3 && i > 5)
                printf(" N");
            if (tab[i][j] == 4 && i < 2)
                printf(" b");
            else if (tab[i][j] == 4 && i > 5)
                printf(" B");
            if (tab[i][j] == 5 && i < 2)
                printf(" q");
            else if (tab[i][j] == 5 && i > 5)
                printf(" Q");
            if (tab[i][j] == 6 && i < 2)
                printf(" k");
            else if (tab[i][j] == 6 && i > 5)
                printf(" K");
        }
        p++;
        printf("\n");
    }
}

int main()
{
    int tab[Weight][Height];
    starttable(tab);
    printtable(tab);
    return 0;
}

