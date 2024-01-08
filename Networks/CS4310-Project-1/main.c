#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// protoypes
int addNew(FILE *);            // adds a new student's info to database
int displayId(FILE *);            // sends id of student to server and server returns the info of the student
int displayScore(FILE *);         // sends score to server and server returns info of all students with scores greater than the sent score
int displayAll(FILE *, int);   // displays the info of all students in database
int deleteId(int);             // deletes the student entry with the id
int exitProgram();             // terminates the program
int getStudentCount(FILE *);   // returns the number of student entries in database
int getDatabase(FILE *, int);
int getDatabase2(FILE *, int);





int main()
{
  int menu_option = 0;

  while (menu_option != 1 && menu_option != 2 && menu_option != 3 && menu_option != 4 && menu_option != 5) {
    printf("\n\nWelcome to the Student Score Database. \nPlease select an option from the menu below: \n\n");
    printf("1  ADD NEW STUDENT ENTRY \n2  DISPLAY STUDENT INFO WITH ID \n3  DISPLAY STUDENT INFO WITH SCORE \n4  DISPLAY ALL STUDENT INFO \n5  DELETE STUDENT ENTRY WITH ID \n6  EXIT\n\n");
    printf("Menu selection: ");
    scanf("%d", &menu_option);

    FILE *fptr;
    fptr = fopen("database.txt", "r");
    int size = getStudentCount(fptr);
    printf("Student Count: %d\n", size);
    fclose(fptr);
    fptr = fopen("database.txt", "a+");
    
    switch(menu_option) {
      case 1 :
        printf("You selected option %d%s", menu_option, ".\n\n");
        addNew(fptr);
        break;
      case 2 :
        printf("You selected option %d%s", menu_option, ".\n\n");
        displayId(fptr);
        break;
      case 3:
        printf("You selected option %d%s", menu_option, ".\n\n");
        displayScore(fptr);
        break;
      case 4:
        printf("You selected option %d%s", menu_option, ".\n\n");
        displayAll(fptr, size);
        break;
      case 5:
        printf("You selected option %d%s", menu_option, ".\n\n");
        break;
    }
    menu_option = 0;
    fclose(fptr);
  }

  return 0;
}

// adds a new student's info to database
int addNew(FILE *fptr) {
  char id[6], fname[10], lname[10], score[3];
  printf("Add new student entry to the student score database:\n\n");
  while ((getchar()) != '\n');
  printf("Student ID: ");
  scanf("%s", &id);
  fprintf(fptr, "%s", id);
  printf("First name: ");
  scanf("%s", &fname);
  fprintf(fptr, " %s", fname);
  while ((getchar()) != '\n');
  printf("Last name: ");
  scanf("%s", &lname);
  fprintf(fptr, " %s", lname);
  printf("Score: ");
  scanf("%s", &score);
  fprintf(fptr, " %s\n", score);
  return 0;
}

// sends id of student to server and server returns the info of the student
int displayId(FILE *fptr) {
  
  char id[6];
  printf("Request student information with student ID.\n");
  printf("Student ID: ");
  scanf("%s", &id);

  printf("\n\nStudent Score Database\n\n");
  printf("%-15s", "ID");
  printf("%-15s", "First Name");
  printf("%-15s", "Last Name");
  printf("%-15s", "Score\n------------------------------------------------------------\n");
  
  char c;
  char buffer[10];
  int i = 0;
  int idFound = 0;
  c = fgetc(fptr);
  while (c != EOF) {
    while (c != ' ' && c != '\n' && c != EOF) {
      buffer[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;

    if (idFound > 0 && idFound < 4) {
      printf("%-15s", buffer);
      idFound++;
    }
    if (idFound == 4) {
      break;
    }
    if (strcmp(buffer, id) == 0) {
      printf("%-15s", buffer);
      idFound++;
    }
    bzero(buffer, 10);
    c = fgetc(fptr);
  }
  return 0;
}
  

// sends score to server and server returns info of all students with scores greater than the sent score
int displayScore(FILE *fptr) {
  
  char buffer[3];
  printf("Request student information with score.\n");
  printf("Student score: ");
  scanf("%s", &buffer);

  printf("\n\nStudent Score Database\n\n");
  printf("%-15s", "ID");
  printf("%-15s", "First Name");
  printf("%-15s", "Last Name");
  printf("%-15s", "Score\n------------------------------------------------------------\n");
  
  char c;

  char id[6];
  char fname[10];
  char lname[10];
  char score[3];
  
  int i = 0;
  int idFound = 0;
  c = fgetc(fptr);
  while (c != EOF) {
    
    while (c != ' ' && c != '\n' && c != EOF) {
      id[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;
    c = fgetc(fptr);
    while (c != ' ' && c != '\n' && c != EOF) {
      fname[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;
    c = fgetc(fptr);
    while (c != ' ' && c != '\n' && c != EOF) {
      lname[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;
    c = fgetc(fptr);
    while (c != ' ' && c != '\n' && c != EOF) {
      score[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;

    if (strcmp(score, buffer) == 0) {
      printf("%-15s", id);
      printf("%-15s", fname);
      printf("%-15s", lname);
      printf("%-15s", score);
    }
    
    bzero(id, 10);
    bzero(fname, 10);
    bzero(lname, 10);
    bzero(score, 10);
    c = fgetc(fptr);
  }
  return 0;
}

/*

// deletes the student entry with the id
int deleteId(int id) {
  return 0;
}

// terminates the program
int exitProgram() {
  return 0;
}
*/

// displays the info of all students in database
int displayAll(FILE *fptr, int size) {
  printf("\n\nStudent Score Database\n\n");
  printf("Student Count: %d\n\n", size);
  printf("%-15s", "ID");
  printf("%-15s", "First Name");
  printf("%-15s", "Last Name");
  printf("%-15s", "Score\n------------------------------------------------------------\n");

  char c;
  char buffer[10];
  int i = 0;
  c = fgetc(fptr);
  while (c != EOF) {
    while (c != ' ' && c != '\n' && c != EOF) {
      buffer[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;
    printf("%-15s", buffer);
    bzero(buffer, 10);
    if (c == '\n') {
      printf("\n");
    }
    c = fgetc(fptr);
  }
  return 0;
}



// Returns the number of students in the database
int getStudentCount(FILE *fptr) {
  int student_count = 0;
  char c;
  
  c = fgetc(fptr);
  while (c != EOF) {
    if (c == '\n') {
      student_count++;
    }
    c = fgetc(fptr);
  }

  return student_count;
}

int getDatabase(FILE *fptr, int size) {

  printf("\n\nStudent Score Database\n\n");
  printf("%-15s", "ID");
  printf("%-15s", "First Name");
  printf("%-15s", "Last Name");
  printf("%-15s", "Score\n------------------------------------------------------------\n");
  
  char c;
  
  char id[size][6];
  char fname[size][10];
  char lname[size][10];
  char score[size][3];
  
  int row = 0;
  int col = 0;
  int i = 0;
  
  c = fgetc(fptr);

  while (c != EOF) {
    if (c == ' ') {
      col++;
      i = 0;
    } else if (c == '\n') {
      col = 0;
      row++;
    } else {
      switch(col) {
        case 0 :
          id[row][i] = c;
          break;
        case 1 :
          fname[row][i] = c;
          break;
        case 2 :
          lname[row][i] = c;
          break;
        case 3 :
          score[row][i] = c;
          break;
      }
      i++;
    }
    c = fgetc(fptr);
  }
  
  
  for (int j = 0; j < size; j++) {
    printf("%s\n", id[j]);
  }
  return 0;
}

int getDatabase2(FILE *fptr, int size) {
  printf("\n\nStudent Score Database\n\n");
  printf("Student Count: %d\n\n", size);
  printf("%-15s", "ID");
  printf("%-15s", "First Name");
  printf("%-15s", "Last Name");
  printf("%-15s", "Score\n------------------------------------------------------------\n");

  char id[size][6];
  char fname[size][10];
  char lname[size][10];
  char score[size][3];
  int col = 0;
  
  int student = 0;
  
  char c;
  char buffer[10];
  int i = 0;
  
  c = fgetc(fptr);
  while (c != EOF) {
    while (c != ' ' && c != '\n' && c != EOF) {
      buffer[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;
    strcpy(id[student], buffer);
    bzero(buffer, 10);
    c = fgetc(fptr);
    while (c != ' ' && c != '\n' && c != EOF) {
      buffer[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;
    strcpy(fname[student], buffer);
    bzero(buffer, 10);
    c = fgetc(fptr);
    while (c != ' ' && c != '\n' && c != EOF) {
      buffer[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;
    strcpy(lname[student], buffer);
    bzero(buffer, 10);
    c = fgetc(fptr);
    while (c != ' ' && c != '\n' && c != EOF) {
      buffer[i] = c;
      i++;
      c = fgetc(fptr);
    }
    i = 0;
    strcpy(score[student], buffer);
    bzero(buffer, 10);
    student++;
    c = fgetc(fptr);
  }
  
  for (int s = 0; s < size; s++) {
    printf("%-15s", id[s][0]);
    printf("\n");
  }
  return 0;
}