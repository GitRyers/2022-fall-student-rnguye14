//Hopkins ID: 1945C9
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
  
  //Initializing starting prices, inventory, and payment essentials 
  const float price_cola = 0.75;
  const float price_bar = 1.25;
  const float price_pop = 0.50;

  int num_cola = 5;
  int num_bar = 5;
  int num_pop = 5;

  int input; 
  int item;
  float pay; 
  float profit = 0.00;
  float change = 0.00; 

  //Welcomes and instructs user
  printf("Welcome to the Vending Machine!\n");
  printf("Enter your choice by # and input cash amount, repeatedly (^d to end).\n");
  printf("[0] %d cola left: cost is $%.2f\n", num_cola, price_cola);
  printf("[1] %d candy bars left: cost is $%.2f\n", num_bar, price_bar);
  printf("[2] %d popcorn left: cost is $%.2f\n", num_pop, price_pop);
  printf("Money made so far is $0.00\n");
  
  while ((input = scanf(" %d %f", &item, &pay)) == 2) {
    //Syntax Check
    if ((item < 0) || (pay < 0)) {
      printf("malformed expression\n");
      return 1;
    }
      
    //Item Selection
    switch(item) {
      case 0:
	//Check if in stock
	if (num_cola < 1) {
	  printf("invalid item\n");
	  return 2;
	  break; 
	}
	//Check if pay is enough
	if (pay < price_cola) {
	  printf("not enough money\n");
	  return 3;
	  break;
	}
	//Updates inventory and profit and returns change
	num_cola--;
	change = pay - price_cola;
	profit += price_cola;
	printf("cola is dispensed and $%.2f returned\n", change);
	break;
      case 1:
	//Check if in stock
	if (num_bar < 1) {
	  printf("invalid item\n");
	  return 2;
	  break;
	}
	//Check if pay is enough
	if (pay < price_bar) {
	  printf("not enough money\n");
	  return 3;
	  break;
	}
	//Updates inventory and profit and returns change
	num_bar--;
	change = pay - price_bar;
	profit += price_bar;
	printf("candy is dispensed and $%.2f returned\n", change);
	break; 
      case 2:
	//Check if in stock
	if (num_pop < 1) {
	  printf("invalid item\n");
	  return 2;
	  break; 
	}
	//Check if pay is enough
	if (pay < price_pop) {
	  printf("not enough money\n");
	  return 3;
	  break;
	}
	//Updates inventory and profit and returns change
	num_pop--;
	change = pay - price_pop;
	profit += price_pop;
	printf("popcorn is dispensed and $%.2f returned\n", change);
	break;
      default:
	//Tells user item is not on menu
        printf("invalid item\n");
	return 2;
	break; 
    }
    
    //Lists Menu and Profit
    printf("[0] %d cola left: cost is $%.2f\n", num_cola, price_cola);
    printf("[1] %d candy bar left: cost is $%.2f\n", num_bar, price_bar);
    printf("[2] %d popcorn left: cost is $%.2f\n", num_pop, price_pop);
    printf("Money made so far is $%.2f\n", profit);
   }

  //Checks for valid # of inputs 
  if (input != 2) {
    printf("malformed expression\n");
    return 1;
  }
  else {
    printf("Thanks for your patronage!\n");
  }
  
  return 0;
}
