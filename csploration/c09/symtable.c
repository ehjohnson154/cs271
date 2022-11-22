
#include "symtable.h"


Symbol* hashArray[SYMBOL_TABLE_SIZE]; 
//EXERCISE 3
//We need a hash function that maps from string to integer. 
//Implement the djb2 Links to an external site. hash function from the linked source. 
//As one addition to the provided hash function, 
//make sure you modulus your result by SYMBOL_TABLE_SIZE when returning. 
//This ensures we can use it as an index to the array without going out of bounds.

int hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    //printf("%lu\n", (hash % SYMBOL_TABLE_SIZE));
    return hash % SYMBOL_TABLE_SIZE;
}



//EXERCISE 4
//Write the symtable_insert function. Adapt from the provided tutorial. 
//Just remember, our key is a string and our data is a ROM address (a line number of the program).


void symtable_insert(char* key, hack_addr addr){

   Symbol *item = (Symbol*) malloc(sizeof(Symbol));
   item->addr = addr;  
   item->name = strdup(key);


   //get the hash 
   int hashIndex = hash(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SYMBOL_TABLE_SIZE;
   }
	
   hashArray[hashIndex] = item;
}



//EXERCISE 5
//Write the symtable_find function. 

Symbol *symtable_find(char *key) {
   //get the hash 
   int hashIndex = hash(key);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {//
	
      //if(hashArray[hashIndex]->name == key)//
      
      if(strcmp((hashArray[hashIndex]->name),key) == 0 )
         return hashArray[hashIndex]; 
			
      //go to next cell//
      ++hashIndex;//
		
      //wrap around the table
      hashIndex %= SYMBOL_TABLE_SIZE;
   }        
	
   return NULL;        
}


//EXERCISE 6
//Write the symtable_display_table function.

void symtable_display_table() {
   int i = 0;
	
   for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%s,%d)",hashArray[i]->name,hashArray[i]->addr);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}


//EXERCISE 7
//Add the symtable_display_table function. 
void symtable_print_labels() {
   int i = 0;    
   for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
        if(hashArray[i] != NULL){
             printf("{%s,%d}\n",hashArray[i]->name,hashArray[i]->addr);
        }
   }
} 

