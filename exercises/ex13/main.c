#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "soccer.h"

const int TEAMSIZE = 11;
int date_is_after(const Date *a, const Date *b) {
  if (a->year > b->year) {return 1;}
  if (a->year < b->year) {return 0;}

  if (a->month > b->month) {return 1;}
  if (a->month < b->month) {return 0;}

  return (a->day > b->day); 
}

int main() {
  Player team[TEAMSIZE];
  Stat * new_stat = (Stat *) malloc(sizeof(Stat)); //malloc a stat
  create_team(team, TEAMSIZE);
  printf("Before Update:\n\n");
  print_team(team, TEAMSIZE);
  printf("\nEnter valid number of goals and assists, pass accuracy, minutes played, number of shots, and shot accuracy:\n");

  // Read Stat info using scanf
  scanf(" %d%d%f%d%d%f", &new_stat->num_of_goals, &new_stat->num_of_assists, &new_stat->pass_accuracy, &new_stat->min_played, &new_stat->num_of_shots, &new_stat->shot_accuracy);

  //TODO 2: FIND THE INDEX OF PLAYER IN THE ARRAY team WITH THE LATEST SIGNED DATE. IF THERE ARE MORE THAN ONE PLAYERS WITH THE SAME SIGNED DATE, SELECT THE ONE THAT APPEARS FIRST IN THE ARRAY.
  int index = 0;
  // WRITE CODE HERE
  for (int i = 1; i < TEAMSIZE; i++) {
    if (date_is_after(team[i].date, team[index].date)) { 
      index = i; 
    }
  } 

  //TODO 3: UPDATE THE PLAYER WITH THE LATEST SIGNED DATE WITH new_stat

  // WRITE CODE HERE
  team[index].stat = new_stat;  

  printf("\nAfter Update:\n\n");
  print_team(team, TEAMSIZE);

  // TODO 4: clean up - free the allocated memory before exit
  for (int i = 0; i < TEAMSIZE; i++) {
    free(team[i].stat); 
    free(team[i].date);  
  } 
  free(new_stat); 

  return 0;
}
