#include<stdio.h> 
#include<stdlib.h> 
FILE*fptr;
void welcome();
void high_scorer();
void place_rand_mines(char mine_board[12][12]);
void print_board(int r,char my_board[12][12]);
int process(char mine_board[12][12],int r,int c,char my_board[12][12]);

void main()

{
    welcome();
    char mine_board[12][12] = {{'0'}};      
    int i,r,c,option,score=0,count=0;
    char my_board[12][12] = {{'0'}};
    place_rand_mines(mine_board);  
    printf("\t\t\t\t\t\t\t\t\tTHIS IS YOUR MINE FIELD\n\n");
    print_board(12,my_board); 
    printf("Where is your first guess?\n");
    printf("Enter your location between 1 - 11.\n");
    printf("Enter x variable:\t");
    scanf("%d",&r);
    printf("Enter y variable:\t");
    scanf("%d",&c);
	i = process(mine_board,r,c,my_board);
    while(i == 1)     
    {
     printf("\t\t\t\t\t\t\tLucky Guy!!!!!!! %c mines surrounding you!!!! be careful!!!!\n\n",mine_board[r][c]);	
     print_board(12,my_board);    
     score=score+10;
     if(score==1010)
        break;
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t||||SCORE:%d\n",score);
     printf("press \n* 1 to quit \n* any number to continue\n* your option-");
     scanf("%d",&option);
     if(option==1)
        break;
     else
      {
	  printf("Enter your location between 1 - 11.\n");
      printf("Enter x variable:\t");
      scanf("%d",&r);
      printf("Enter y variable:\t");
      scanf("%d",&c);
	    i=0; 
        i = process(mine_board,r,c,my_board);
	   }
    }
	if(score==1010)
       {
	     printf("\t\t\t\t\t\twhat a guy you are!!!! fantabulous!!!!! you win the game\n");
         printf("\t\t\t\t\t\t\tAWESOME 1010!!!!");
         high_scorer();
       }
	if(option==1)
	  {
	  printf("\t\t\t\t\t\t\t\tALAS!!!you are missing the game!!!!!\n");
	  printf("\t\t\t\t\t\t\t\t\tYOUR SCORE IS %d\n\n",score);
	  }  
    if(i==0)
	    {
	    my_board[r][c]='@';
	    printf("\t\t\t\t\t\t\t\t\t\tOOOPS!!!!\n");
	    print_board(12,my_board);
		printf("\t\t\t\t\t\t\t\tGame OVER, ta ta. you stepped on a MINE !!\n");
	    printf("\t\t\t\t\t\t\t\t\t\tFANTABULOUS your score is %d\n\n",score);
     	}
     	
}
void welcome()
{
    char op;
    printf("\t\t\t\t\t\t\t\t\tWELCOME TO MINESWEEPER\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\tpress\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*i-instruction\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*any key to enter game\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*your option-");
    scanf("%c",&op);
    if(op == 'i')
    {
    printf("\t\t\t\t\t\t\t\t\t**INSTRUCTIONS**\n\n");
    printf("\t\t\t\t\t\t\tOH DEAR, what a shock you are unfortunatly in the  mine field.\n");
    printf("\t\t\t\t\t\t\tEnter the coordinates of the x and y plane between 1 to 11\n");   
    printf("\t\t\t\t\t\t\t\tAre you destined to DIE or live ?\n");
    printf("\t\t\t\t\t\t\t\tdont think it of as luck based game\n");
    printf("\t\t\t\t\t\t\t\t\tmind based game!!!\n");
    printf("\t\t\t\t\t\t\t\ttotal successful moves 101;mines20\n");
    printf("\t\t\t\t\t\t\t\t\tmaximum score 505\n");
    printf("\t\t\t\t\t\t\t\t\tHA ha ha hah, GOOD LUCK\n");	  
	printf("\t\t\t\t\t\t\t\t\t\tclear???\n");
	printf("====================================================================================================================================================================\n\n");
	printf("\t\t\t\t\t\t\t\t\tGAME STARTS!!!\n\n"); 
   
    }
    else
    return;    
}
void place_rand_mines(char mine_board[12][12])
{
    int r,c,m;
    for(m=0;m<20;m++) 
    {
    r = rand() % 13; 
    c = rand() % 13; 
    mine_board[r][c] ='@'; 
    }  
    return;
}
void print_board(int r,char my_board[12][12])
{
    int i,j;    
    printf("\t\t\t\t\t\t\t\t");
    printf(" |1|2|3|4|5|6|7|8|9|10|11|\n");
    for(i=1;i<r;i++)
    {
	   printf("\n\t\t\t\t\t\t\t\t");	
       if(i>=0&&i<=9)
          {
		    printf("%d",i);
            printf("|");
          }
        if(i==10)
          {
          	printf("0|");
		  }
		if(i==11)
		  {
			printf("1|");
		  }
    for(j=1;j<12;j++)   
    {
        printf("%c"" ",my_board[i][j]);
    }
	printf(" ""|");
	printf("%d",i);
    printf("\n");
	printf("\t\t\t\t\t\t\t\t");  
    }
    printf("\n\t\t\t\t\t\t\t\t"); 
    printf(" |1|2|3|4|5|6|7|8|9|10|11|\n"); 
    return;    
}
int process(char mine_board[12][12],int r,int c,char my_board[12][12])
{
    int i=r,j=c,b=0;    
    char C;
    if(mine_board[r][c] == '@')   
    { 
    return 0;
    }
    else
    {
    if(mine_board[i-1][j-1] =='@' )    
        b++;  
    if(mine_board[i-1][j] =='@' )    
        b++;  
    if(mine_board[i-1][j+1] =='@' )    
        b++;  
    if(mine_board[i][j-1] == '@')    
        b++;  
    if(mine_board[i][j+1] =='@')    
        b++;  
    if(mine_board[i+1][j-1] =='@' )    
        b++;  
    if(mine_board[i+1][j] == '@')   
        b++;  
    if(mine_board[i+1][j+1] == '@')    
        b++;  
    C = (char)(((int)'0')+b);
    mine_board[r][c] = C;
    my_board[r][c] = C;
    return 1;  
   }
}
void high_scorer()
    {
        	char name[20];
    	    fptr=fopen("scorer.txt","a+");
		    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tgood name please!!!\t");
		    scanf("%s",name);
		    fprintf(fptr,"NAME :\t%s",name);
		    fclose(fptr);
	}
