/**********************************samiAaribA3Main.c******************************************* 

Student Name: Aarib Sami 
Email Id: asami01
Due Date: November 27th, 2023
Course Name: CIS*1300

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity.
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any and all
material that I have used, whether directly quoted or paraphrased. Furthermore,
I certify that this assignment was prepared by me specifically for this course.

*****************************************************************************************/
/***************************************************************************************** 

Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall samiAaribA3Main.c
Running: ./a.out

OR
gcc -std=c99 -Wall samiAaribA3Main.c -o assn1
Running the Program: ./assn1
*****************************************************************************************/


#include "givenA3.h"

int main () {

    char courseName[NUMBER_COURSES][MAX_STR];
    char profName [NUMBER_PROFS][MAX_STR];
    int courseID[NUMBER_COURSES];
    int coursesTaught [NUMBER_PROFS][NUMBER_COURSES];
    char cNameFound [MAX_STR];
    int cNumFound;
    int choice;
    char coursesFile[MAX_STR] = "courses.txt";
    char dataFile[MAX_STR] = "data.txt";
    int n;
    int num; 
    char name[MAX_STR]; 
    
    readCourse(coursesFile, courseName, courseID);
    readProfs(dataFile, courseID, profName, coursesTaught);

    do {
        printf ("\nHere is the menu - enter a number between 1 and 7 \n\n");
        printf ("1. Task 3 – find the total number of professors who teach n or more courses\n");
        printf ("2. Task 4 – find course name, given its course number\n");
        printf ("3. Task 5 – find course number, given its course name\n");
        printf ("4. Task 6 – find all professors teaching a given course \n");
        printf ("5. Task 7 – find the average number of courses taught by a professor \n");
        printf ("6. Task 8 – display a horizontal histogram showing the number of courses taught by each professor\n");
        
        printf ("7. Exit\n");
        
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        
        if (choice < 1 || choice > 7) {
            printf("Invalid choice.\n");
            continue; 
        }
       
        switch (choice) {
            case 1:
                printf("Please enter n: \n");
                scanf("%d", &n);

                nCourses(n, profName, coursesTaught);
                break;
            case 2:
                printf("Please enter course number: \n");
                scanf("%d", &num);

                getCourseName(num, cNameFound, courseName, courseID);
                break;
            
            case 3:
                printf("Please enter course name: \n");
                getchar();
                fgets(name, MAX_STR, stdin);
                name[strlen(name)-1] = '\0';
                getCourseNum(name, &cNumFound, courseName, courseID);
                break;

            case 4:
                printf("Please enter course number: \n");
                scanf("%d", &num);
                profsTeachingCourse(num, profName, coursesTaught);
                break;

            case 5:
                avgNumCourses(coursesTaught);
                break;

            case 6:
                hhistogram(profName, coursesTaught);
                break;

            default: printf ("That is an invalid choice\n");                
        }
    } while (choice != 7);
    
   return 0;
}

