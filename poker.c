#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
/************************************
 * Declaration of various variables *
 ************************************/

int k, c, j, i, a, n, pairs, num_consec, command, num_amount;
int storage[10][10], num[50], suit, rank, num_in_suit[23][4] = {0}, num_in_rank[23][13] = {0}, amount[23] ,bet[23] = {0}, raise[23] = {0};
bool arr[52] = {false}, pattern[23][8], in_game[23] = {false};

printf("\n\n\n");
printf("		****    ***   *   *  *****  *****	\n");
printf("		*   *  *   *  *   *  *      *   *	\n");
printf("		****   *   *  ****   *****  ****  	\n");
printf("		*      *   *  *   *  *      *   * 	\n");
printf("		*       ***   *   *  *****  *   *	\n");
printf("						- A Rockstar Game production\n\n\n\n");

printf("			LET THE GAME BEGIN!!!!		\n\n\n");

printf("Enter number of players(n<24): ");   /*user enters number of players*/
scanf("%d", &n);

printf("Enter amount you want each player to start with: $");
scanf("%d", &num_amount);

printf("\n\n");



/*  num[] - stores the original non repeating cards in the form of numbers from 1 to 52
	num_in-suit[][] - stores the number of cards in each suit for each player
	num_in_rank[][] - stores the number of cards in each rank for each player, there are overall 13 ranks starting from 2 and ending at 				ace
	pattern[][] - used for checking the various patterns and stores each pattern in the form of 0 (not present) and 1 (present)
	formulae used for giving number to-
		a) suit = (num[] - 1)/13 { values are 0 = clubs ,1 = diamonds ,2 = hearts ,3 = spades }
		b) rank = (num[] - 1)%13 { values are 0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 ,11 ,12 }
	symbol code for various suits - clubs : \u2663 ; diamonds : \u2666 ; hearts : \u2665 ; spades : \u2660 
	assign() - function for assigning numerical cards their suit and rank
	print() - function for printing cards
	betting() - funtion for betting
*/	 


/***********************************************************************************
 * function for assigning of card and suit to every digitised card for each player *
 ***********************************************************************************/
void assign(void) {
	    /****************************************
         * assigns suit to every digitised card *
         ****************************************/

		suit = (num[k]-1)/13;
		switch(suit) {                           
            case 0: num_in_suit[i][suit]++;                                        
				break;
			case 1: num_in_suit[i][suit]++;
				break;
			case 2: num_in_suit[i][suit]++;
				break;
			case 3: num_in_suit[i][suit]++;
				break;	
		}

        /*****************************************
         * assigns rank to every digitised card  *
         *****************************************/

		rank = (num[k]-1)%13;
		switch(rank) {
			case 0: num_in_rank[i][rank]++;
				break;
			case 1: num_in_rank[i][rank]++;
				break;
			case 2: num_in_rank[i][rank]++;
				break;
			case 3: num_in_rank[i][rank]++;
				break;
			case 4: num_in_rank[i][rank]++;
				break;
			case 5: num_in_rank[i][rank]++;
				break;
			case 6: num_in_rank[i][rank]++;
				break;
			case 7: num_in_rank[i][rank]++;
				break;
			case 8: num_in_rank[i][rank]++;
				break;
			case 9: num_in_rank[i][rank]++;
				break;
			case 10: num_in_rank[i][rank]++;
				break;
			case 11: num_in_rank[i][rank]++;
				break;
			case 12: num_in_rank[i][rank]++;
				break;
		}
}

/************************
 * Function for betting *
 ************************/

void betting(void) {
	void input(void) {
	a = 1;
	for(j=0 ;j<n ;j++) {	
		printf("PLAYER %d: \n", a);
		a++;
		if(in_game[j]) {
			printf("You already folded!!\n\n");
		}
		else {
			printf("What do you want to do (0 = raise; 1 = check; 2 = fold): ");
			scanf("%d", &command);
			if(command != 0 && command != 1 && command != 2) {
				printf("Enter a valid command!!\n");
				printf("What do you want to do (0 = raise; 1 = check; 2 = fold): ");
				scanf("%d", &command);
			}
		
			switch (command) {
				case 0: printf("Enter amount by which you want to raise: ");
				  	scanf("%d", &raise[j]);
					bet[j] = bet[j] + raise[j];
					amount[j] = amount[j] - raise[j];
			  		printf("You have $%d on the table and your balance is $%d", bet[j], amount[j]);		
			  		break;
		
				case 1: if((bet[j] < bet[j-1]) && j>=1) {
						printf("You cannot check!! You must place at least $%d on the table\n", bet[j-1]);
						printf("Enter amount you want on the table: ");
			  			scanf("%d", &raise[j]);
			  			amount[j] = amount[j] - raise[j];
			  			printf("You have $%d on the table and your balance is $%d", bet[j], amount[j]);		
			  		}
				  	else {
						printf("You have checked and your balance is $%d", amount[j]);
				  	}
					break;
	
				case 2: printf("You are out of the game!!");
			    		in_game[j] = true;
			  		break;
			}
			printf("\n\n");
		}
	}
	}	


	input();
	for(;;) {	
		printf("Are all bets equal? (0 = No; 1 = Yes): ");
		scanf("%d", &command);
		for(;;)	{	
			if(command != 0 && command != 1) {
				printf("Enter a valid command!!\n");
				printf("Are all bets equal? (0 = No; 1 = Yes): ");
				scanf("%d", &command);
			}
			else {
				break;
			}
		}
		switch (command) {
			case 0: input();
				break;
			case 1: goto bet_equal;
		}

	}
	bet_equal: printf("\n");
}


/*******************************
 * function for printing cards *
 *******************************/
void print(void) {
	    /****************************************
         * prints symbol for each suit for table*
         ****************************************/
		suit = (num[k]-1)/13;
		switch(suit) {                           
                	case 0: printf("\u2663 ");                                        
				break;
			case 1: printf("\u2666 ");
				break;
			case 2: printf("\u2665 ");
				break;
			case 3: printf("\u2660 ");
				break;	
		}

        /**************************************
         * prints rank for each card on table *
         **************************************/

		rank = (num[k]-1)%13;
		switch(rank) {
			case 0: printf("2 ");
				break;
			case 1: printf("3 ");
				break;
			case 2: printf("4 ");
				break;
			case 3: printf("5 ");
				break;
			case 4: printf("6 ");
				break;
			case 5: printf("7 ");
				break;
			case 6: printf("8 ");
				break;
			case 7: printf("9 ");
				break;
			case 8: printf("10 ");
				break;
			case 9: printf("J ");
				break;
			case 10: printf("Q "); 
				break;
			case 11: printf("K ");
				break;
			case 12: printf("A ");
				break;
		}
}

/*************************
 * Initialising amount[] *
 *************************/
for(j=0 ;j<23 ;j++) {
	amount[j] = num_amount;
}


/****************************************************
 * code for generating random non repeating numbers *
 ****************************************************/ 

srand(time(0));
k = 0;
for(;;) {
	c = (rand()%52) + 1;
	if(arr[c-1]==0) {
		num[k] = c; 
		k++;
		arr[c-1] = true;
	}
	if(k==2*n+5) {
		break;
	}
}

/***********************************************************************
 * Assignment of card and suit to every digitised card for each player *
 ***********************************************************************/

for(i=0 ;i<n ;i++) {
	for(k=0 ;k<5 ;k++) {
		assign();
	}
}

k = 5;
for(i=0 ;i<n ;i++) {
	while(k<2*n+5) {
		assign();
		k++;
		if(k%2==1) {
			break;
		}
	}
}


/***********************************
 * initialisation of pattern array *
 ***********************************/
for(i=0 ;i<23 ;i++) {
	for(j=0 ;j<10 ;j++) {
		pattern[i][j] = false;
	}
}

/*******************
 * check for flush *
 *******************/
for(i=0 ;i<n ;i++) {
	for(j=0 ;j<4 ;j++) {
		if(num_in_suit[i][j] == 5) {
			pattern[i][3] = true;
		}
	}
}

/**********************
 * check for straight *
 **********************/
for(i=0 ;i<n ;i++) {
	num_consec = 0;
	j = 0;
	while(num_in_rank[i][j] == 0) {
		j++;
	}
	for( ;j<13 && num_in_rank[i][j]==1 ;j++) {
		num_consec++;
	}
	if(num_consec >= 5) { 
		pattern[i][4] = true;
		break;
	}
}

/*************************************************
 * check for 4-of-a-kind, 3-of-a-kind, and pairs *
 *************************************************/

for(i=0 ;i<n ;i++) {
	pairs = 0;
	for(j=0 ;j<13 ;j++) {
		if(num_in_rank[i][j] == 4) {
			pattern[i][1] = true;
		}
		if(num_in_rank[i][j] == 3) {
			pattern[i][5] = true;
		}
		if(num_in_rank[i][j] == 2) {
			pairs++;
			if(pairs == 1) {
				pattern[i][6] = true;
			}
			if(pairs >=2) {
				pattern[i][7] = true;
			} 			
		}
	}
}


/************************************************************************
 * 		          REAL CODE FOR THE INTERFACE OF THE GAME			    *
 ************************************************************************/



printf("Do your betting for the Ist Round:\n");

betting();

printf("\n\n\n");

printf("First 3 cards on the table are		");

for(k=0 ;k<3 ;k++) {
	print();
}
printf("\n\n\n");

printf("Do your betting for the IInd Round:\n");

betting();

printf("\n\n\n");

printf("4th card on the table opens now!!	");

for(k=0 ;k<4 ;k++) {
	print();
}
printf("\n\n\n");

printf("Do your betting for the IIIrd Round:\n");

betting();

printf("\n\n\n");

printf("5th and the last card on the table opens now!!		");

for(k=0 ;k<5 ;k++) {
	print();
}
printf("\n\n\n");

printf("Enter your last bet!\n");

betting();

printf("\n\n\n");

printf("All the cards (player + table) and the pattern are!!!\n\n");

/*************************************************
 * printing of cards on table and of each player *
 *************************************************/
printf("Cards on the table are: ");
for(k=0 ;k<5 ;k++) {
	print();
}

printf("\n");

a = 1;
k = 5;
for(i=0 ;i<n ;i++) {
	printf("Cards of player %d are: ", a);
	a++;
	while(k<2*n+5) {
		print();
		k++;
		if(k%2==1) {
			break;
		}
	}
	printf("\n");
}

printf("\n");

/************************************************************
 * assigning and printing of which player got which pattern *
 ************************************************************/

a = 1;
for(i=0 ;i<n ;i++) {		
	if(pattern[i][4] && pattern[i][3]) {
		printf("Player %d got Straight Flush\n", a);
	}
	else if(pattern[i][1]) {
		printf("Player %d got Four of a kind\n", a);
	}	
	else if(pattern[i][5] && pattern[i][6]) {
		printf("Player %d got Full House\n", a);
	}
	else if(pattern[i][3]) {
		printf("Player %d got Flush\n", a);
	}
	else if(pattern[i][4]) {
		printf("Player %d got Straight\n", a);
	}
	else if(pattern[i][5]) {
		printf("Player %d got Three of a kind\n", a);
	}
	else if(pattern[i][7]) {
		printf("Player %d got Two Pairs\n", a);
	}
	else if(pattern[i][6]) {
		printf("Player %d got Pair\n", a);
	}
	else {
		printf("Player %d got High Card\n", a);
	}
	a++;
}
printf("\n\n");

printf("THANK YOU!!!!\n");
return 0;
}






























