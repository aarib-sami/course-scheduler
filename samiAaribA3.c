/**********************************samiAaribA3.c******************************************* 

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
gcc -std=c99 -Wall samiAaribA3.c
Running: ./a.out

OR
gcc -std=c99 -Wall samiAaribA3.c -o assn1
Running the Program: ./assn1
*****************************************************************************************/

#include "givenA3.h"


// Reads a file containing course names and course ID's and populate two characters arrays respectively 
int readCourse(char filename [MAX_STR], char courseName [NUMBER_COURSES][MAX_STR], int courseID [NUMBER_COURSES])
{
    FILE *courseFile;
    courseFile = fopen(filename, "r");

    if (courseFile == NULL) {
      printf("Error! File was not created!");
      return -1;
    }

    for (int i = 0; i < NUMBER_COURSES; i++)
    {
        fgets(courseName[i], MAX_STR, courseFile);
        courseName[i][strlen(courseName[i])-1] = '\0';
    }

    for (int i = 0; i < NUMBER_COURSES; i++)
    {
        fscanf(courseFile, "%d", &courseID[i]);
    }
    return 1;
}


// Reads a file containing profs and the courses that they teach and populates two character arrays respectively
int readProfs (char filename [MAX_STR], int courseID [NUMBER_COURSES], char profName [NUMBER_PROFS][MAX_STR], int coursesTaught [NUMBER_PROFS][NUMBER_COURSES])
{
    FILE *dataFile;
    dataFile = fopen(filename, "r");

    if (dataFile == NULL) {
      printf("Error! File was not created!");
      return -1;
    }

    for (int i = 0; i < NUMBER_PROFS; i++)
    {
        fscanf(dataFile, "%s", profName[i]);
    }

    fgetc(dataFile);

    for (int i = 0; i < NUMBER_PROFS; i++)
    {
        for (int j = 0; j < NUMBER_COURSES; j++)
        {
            fscanf(dataFile, "%d", &coursesTaught[i][j]);
            if (coursesTaught[i][j] != 0)
            {
                coursesTaught[i][j] = courseID[j];
            }
        }
    }
    return 1;
}

// This function takes as input a value of n and returns the total number of professors who teach n or more courses. It also prints the professor names for professors who teach n or more courses
int nCourses (int n, char profName [NUMBER_PROFS][MAX_STR], int coursesTaught [NUMBER_PROFS][NUMBER_COURSES])
{
    int nCoursesTaught = 0;
    int numCoursesTaught = 0;
    
    for (int i = 0; i < NUMBER_PROFS; i++)
    {
        for (int j = 0; j < NUMBER_COURSES; j++)
        {
            if(coursesTaught[i][j] != 0)
            {
                numCoursesTaught++;
            }
        }
        if (numCoursesTaught >= n)
        {
            nCoursesTaught++;
            printf("%s", profName[i]);
            printf("\n");
        }
        numCoursesTaught = 0;
    }
    printf("%d", nCoursesTaught);
    return nCoursesTaught;
}


// This function, takes a course number as input, searches for its course name and stores it in a string parameter
int getCourseName (int courseNum, char cNameFound [MAX_STR], char courseName [NUMBER_COURSES][MAX_STR], int  courseID [NUMBER_COURSES])
{
    for (int i = 0; i < NUMBER_COURSES; i++)
    {
        if (courseID[i] == courseNum)
        {
            cNameFound = courseName[i];
            printf("Found! %s", cNameFound); 
            printf("\n");
            return 1;
        }
    }
    printf("Not found!\n");
    return 0;
}

// This function, takes a course name as input, searches for its course ID and stores it in a int parameter
int getCourseNum (char cName [MAX_STR], int * cNumFound, char courseName [NUMBER_COURSES][MAX_STR], int courseID [NUMBER_COURSES])
{
    char currentCourseName[MAX_STR];
    for (int i = 0; i < NUMBER_COURSES; i++)
    {
        strcpy(currentCourseName, courseName[i]);
        currentCourseName[strlen(currentCourseName)] = '\0';

        if (strcmp(cName, currentCourseName) == 0)
        {
            *cNumFound = courseID[i];
            printf("\n");
            printf("Found! %d", *cNumFound); 
            printf("\n");
            return 1;
        } 
    }
    printf("Not Found!\n"); 
    return 0;
}

// This function takes a course number as input, and prints names of all profs teaching it
int profsTeachingCourse (int courseNum, char profName [NUMBER_PROFS][MAX_STR], int coursesTaught [NUMBER_PROFS][NUMBER_COURSES])
{
    int totalProfs = 0;

    for (int i = 0; i < NUMBER_PROFS; i++)
    {
        for (int j = 0; j < NUMBER_PROFS; j++)
        {
            if (coursesTaught[i][j] == courseNum)
            {
                printf("%s \n", profName[i]);
                totalProfs++;
            }
        }
        
    }
    printf("%d \n\n", totalProfs);
    return totalProfs;
}

// This function returns the average number of courses taught by a professor in the given course allocation scheme.
float avgNumCourses (int coursesTaught [NUMBER_PROFS][NUMBER_COURSES])
{
    int totalCoursesTaught = 0;
    float avg;
    for(int i = 0; i < NUMBER_PROFS; i++)
    {
        for (int j = 0; j < NUMBER_COURSES; j++)
        {
            if (coursesTaught[i][j] != 0)
            {
                totalCoursesTaught++;   
            }
        }
    }

    avg = (float)totalCoursesTaught/NUMBER_PROFS;
    printf("Average: %.2f \n", avg);
    return avg;

}

// This function displays a horizontal histogram showing the number of courses taught by each professor, where each course is represents by one star.
void hhistogram(char profName[NUMBER_PROFS][MAX_STR], int coursesTaught[NUMBER_PROFS][NUMBER_COURSES])
{
    int totalTaught = 0;
    int maxNameLength = 0;

    for (int i = 0; i < NUMBER_PROFS; i++)
    {
        int currentLength = strlen(profName[i]);
        if (currentLength > maxNameLength)
        {
            maxNameLength = currentLength;
        }
    }
    
    for (int i = 0; i < NUMBER_PROFS; i++)
    {
        printf("%-*s", maxNameLength + 2, profName[i]);
        for (int j = 0; j < NUMBER_COURSES; j++)
        {
            if (coursesTaught[i][j] != 0)
            {
                printf("*");  
                totalTaught++;
            }
        }
        printf("(%d)\n", totalTaught);
        totalTaught = 0;
    }
}
