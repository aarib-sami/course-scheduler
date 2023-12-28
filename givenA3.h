#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER_PROFS 6
#define NUMBER_COURSES 10
#define MAX_STR 50


/* Task 1 */
int readCourse (
   char filename [MAX_STR],
   char courseName [NUMBER_COURSES][MAX_STR],
   int courseID [NUMBER_COURSES]
);


/* Task 2 */
int readProfs (
   char filename [MAX_STR],
   int courseID [NUMBER_COURSES],
   char profName [NUMBER_PROFS][MAX_STR],
   int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]
 );


/* Task 3 */
int nCourses (
   int n,
   char profName [NUMBER_PROFS][MAX_STR],
   int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]
);


/* Task 4 */
int getCourseName (
   int courseNum,
   char cNameFound [MAX_STR],
   char courseName [NUMBER_COURSES][MAX_STR],
   int  courseID [NUMBER_COURSES]
);


/* Task 5 */
int getCourseNum (
   char cName [MAX_STR],
   int * cNumFound,
   char courseName [NUMBER_COURSES][MAX_STR],
   int courseID [NUMBER_COURSES]
);


/* Task 6 */
int profsTeachingCourse (
   int courseNum,
   char profName [NUMBER_PROFS][MAX_STR],
   int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]
);

/* Task 7 */
float avgNumCourses (
      int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]
 );



/*Task 8 */
void hhistogram (
   char profName [NUMBER_PROFS][MAX_STR],
   int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]
);

