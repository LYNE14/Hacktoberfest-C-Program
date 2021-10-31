/*make an electronic agenda to manage cultural events - move forward in an incremental way in this project
-Declare a Time structure containing the following numeric fields: hour, minutes.
-Declare a Date structure containing the fields: day, month, year
-Declare a new Event structure containing the following fields:
-DateEvent of type Date structure
-TimeEvent of type Time
-Nameof type string of characters
-Locationof type string of characters
-maxSpacesof type integer
-placesPrisesof type integer
-Write a function EventsEntryEvent( ) which allows to enter all the fields of a new event then to return it
-Write a function voiddisplayEvent(Event) which allows to display the fields of the event passed in parameter.

-Write a function inttrouveEvenement(char name[], EvenementtabEvents[], intnbEvents)which will allow to return the index in the array of events passed as argument of an event whose name is also passed as argument to the function. The parameter nbEvents represents the number of events in the array tabEvents. If the event does not exist, return -1. Use the library function (#include<string.h>) strcmp to compare two strings.
-Write a main program that allows you to enter a list of events to put in an array (using the previous functions)
-After the input, display only the events for which there are still free places while displaying the number of remaining places.
-Ask the user to enter the name of an event of interest and then use the findEvent function to check if the event exists in the event table and if there are still places available. If so, increment the placesPrisessin field to display a no places available message to the user.
-To finalise this project, create a menu allowing the entry, display and search of an event according to the user's requests. To do this, use the switch case statement.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ************************************DATA STRUCTURE DECLARATION*******************************************//
typedef struct time{
	
	int h,m;
	
}time;
	
	typedef struct date{
	int jj ,mm ,an;}date;
	
	typedef struct ev {
		
		char n[30], l[30]; int max ,prise; date d ; time heur;
	}ev;
	
  // **********************************************DFUNCTION DECLARATION*************************************************
	
	// FONCTION SAISI DES DONNEE
	
	ev saisi(){
	ev var;                     
  	printf("enter the event name : "); gets(var.n);	 gets(var.n);
 	printf("enter the location of the event ");gets(var.l);
 	do{
 	printf("enter the max namber of places: "); scanf("%d",&var.max);
 	}while(var.max<0);
 do{
	printf("the number of places taken : ");scanf("%d",&var.prise);
	 }while(var.prise >var.max );
	 	 do{
 	printf("enter the year of the event  :");scanf("%d",&var.d.an);
 		 }while(var.d.an<1950);
	 do{
 	printf("enter the month of the event : ");scanf("%d",&var.d.mm);
 	 }while(var.d.mm>12 || var.d.mm<1);
	 do{
 	printf("enter the day of the event  :");scanf("%d",&var.d.jj);
 	 }while(var.d.jj>31 || var.d.jj<1);
 	
    	do{
 	printf("enter the hour of the event : ");scanf("%d",&var.heur.h);
 	}while(var.heur.h>23 || var.heur.h<0);
 	
 	do{	 
 	printf("enter the minute of the event  :");scanf("%d",&var.heur.m);
 	}while(var.heur.m>59 || var.heur.m<0);
 
		
		
		return var;
	
	};
	
	//DISPLAY FONCTION
	
	void afich (ev patata){
	
	if(patata.max-patata.prise>0){
   
	
 		printf("the event name is : ");
 	puts(patata.n);
 		printf("the location of the event is : ");
 	puts(patata.l);
 	
 	printf("the max namber of places is: %d \n",patata.max);
 	printf("the number of places taken is : %d \n",patata.prise);
 	printf("the year of the event : %d \n",patata.d.an);
 	printf("the month of the event : %d \n",patata.d.mm);
 	printf("the day of the event : %d \n",patata.d.jj);
 	
 	printf("the hour of the event: \n",patata.heur.h);
 	printf("the minute of the event : %d \n",patata.heur.m);
 
    printf("the number of places remaining is : %d \n",patata.max-patata.prise);
    
    printf("\n\n");
			}
		
	};
	
	//SEARSH FONCTION
	
	
	int trouv(char nom[], ev tabEvents[], int nb){
	int i=-1,v=1,c=-1;
	
	do{
		
	i++;
	v=strcmp(tabEvents[i].n, nom);
	
	if (v==0){ c=i;};
	
	
	}while(i<nb && v!=0 );
	
	return c;
	   	
};


	// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  MAIN FONCTION  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 
 int main(void){
 	
 	int c,Z=0,d,i;  ev tab[100]; 
 	
	 do {
	 
	int ta7,toto,tompo=0;
 	
 	char ch[50];
 	
 	
 	
 	do{
	 
 	printf ("choose the operation to be executed 0 for the input, 1 for the display 2 for the search of an event \n ");
 	
 	scanf("%d",&toto);
 	} while (toto !=0 && toto !=1 && toto !=2);
 	
 	switch(toto){

 	
 	case 0 :
 	
 	
 	
 	// INPUT OF INFORMATION
 	
 	d=Z;  //the variable d is to avoid overwriting the events in the table each time the user decides to add events
 
	 do{
 	printf (" too many events for you (max event 100)\n"); scanf("%d",&tompo);
 	if(tompo+Z>100) printf("becoup trop d'evenment pour vous(max evenment 100)\n");
   }while(tompo+Z>100);

 
 
 	 Z=Z+tompo;
 	 
 	for(i=d;i<Z;i++){
 		
 		printf("enter the information of the %d event\n",i+1);
 		
 		tab[i]=saisi();
 		
	 };
 	d=Z;
    printf ("well remembered information\n");
 	 break;
 	 
 	case 1 :
 		
 		
 		
 	
 	
 	
 	// DISPLAY
 	
 	printf ("information events display \n \n"); 
 	
 	if(Z==0) {printf("no events to display\n");}
               	for(i=0;i<Z;i++){
 		
 		
 		
 		afich(tab[i]);
 		
 		
	 };
 	 break;
 	 
 	 
 	 // EVENT SERCH
 	 	 case 2 :
 	 	 	                  
         printf ("search for an event\n");
		 int u;
		 printf("enter event nember\n"); scanf ("%d",&u);gets ( ch);
		 
		 
	 ta7= trouv(ch, tab, Z)  ;                              
        
		                                      
         if (ta7==-1){ printf("no existing event\n");
		 
		 
		 }  else if(ta7!=-1){ printf("existing event \n");
		 };
		 
		 
		 
		 if(ta7!=-1){
		 
		 
		 if(tab[ta7].max-tab[ta7].prise>0){ tab[ta7].prise=tab[ta7].prise+1;printf("Risirvation well done\n");
		 
		 } else printf("no places available\n");
		 }
		 
		 
		 	  break;
		 
		  };
		 
		 // FOR RIPITITION
		 
		 do{
		
		   printf ("do you want to continue the process 0 for no 1 for yes \n");
		   
		   scanf("%d",&c);
		    }while(c!=0 &&c!=1);
		   
		   } while( c ==1);
		   
		                              
	return 0;
}
