//Ex04: gpa_simple.c

/* The purpose of this program is to compute GPAs for simple letter
   grades - no +/-, only A, B, C, D, F. Credits may be rational
   numbers.  Also determine and display notices for Dean's List
   (>=3.5) and Academic Probation (< 2.0).

SAMPLE RUN:

Welcome to the GPA calculator!
Enter grade and credits for each course below (ctrl-d to end):
course 1: A 4.0
course 2: b 2.7
course 3: B 3.5
course 4: c 3.0
course 5: f 1
course 6: a 3
course 7: 
Your GPA is 3.06

-----
PSEUDOCODE:

point_sum gets 0
credit_sum gets 0
points gets 0
gpa gets 0

display “Welcome to GPA calculator!”
prompt for list of grade/credits pairs

count gets 1
display "course #", count

repeat while there is a grade and credits to read
    convert grade to points
    add points * credits to point_sum
    add credits to credit_sum
    add 1 to count
    display "course #", count

if credit_sum > 0
   set gpa to point_sum / credit_sum
   display "GPA is ", gpa
   if gpa >= 3.5
      display "Dean's List"
   otherwise if gpa <= 2.0
      display "Uh-oh, Academic Probation..."
otherwise
   display "No credits attempted; no GPA to report"

*/


#include <stdio.h>

int main() {

  //TO DO: add your code here so that your program
  //produces output that would be identical to the
  //given sample run when provided the same input

  float point_sum = 0.0;
  float credit_sum = 0.0; 
  float gpa = 0.0;
  
  printf("Welcome to GPA calculator!"); 
  printf("Enter grade and credits for each course below (ctrl-d to end):\n");

  int course_num = 1;
  char grade = '\0';
  float grade_points = 0.0;
  float credits = 0.0;
  int read_count = 0;

  do {
    printf("course %d:\n", course_num);

  while(scanf(" %c %f", &grade, &credit)){
      switch(grade){
      case 'A' :
	points = 4;
	point_sum += points * credit;
	credit_sum += credit;
	break;
      case 'B' :
	points = 3;
	point_sum += points * credit;
	credit_sum += credit;
	break;
      case 'C' :
	points = 2;
	point_sum += points * credit;
	credit_sum += credit;
	break;
      case 'D' :
	points = 1;
	point_sum += points * credit;
	credit_sum += credit;
	break;
      case 'F' :
	points = 0;
	point_sum += points * credit;
	credit_sum += credit;
	break;
      default :
	printf("Invalid grade!");
	break;
      }
      ++count;
      printf("course %d:\n", count);	
   }
    
   if (credit_sum > 0.0) {
     gpa = point_sum / credit_sum;
     printf("GPA is %f", gpa);
   }
    
   if (gpa >= 3.5) {
     printf("Dean's List");
   }
    
   else if (gpa <= 2.0) {
     printf("Uh-oh, Academic Probation...");

   }
   else {
     printf("No credits attempted; no GPA to report");
   }
    
 return 0;
}
