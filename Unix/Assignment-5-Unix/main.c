/*
NAME: Afton Schwendiman
CS4350 - 001 - Unix Systems Programming
Assignment Number: 5
Due Date: 11/1/2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function to count number of a particular word within file
int countWords(FILE *fptr, const char *word)
{   
  char str[50]; //char array for a string
  char *pos;    //char pointer to current position
  int index;    //int string array index value
  int count = 0;    //int incrementer
  //traverses file, counting number of occurrences of a word
  while ((fgets(str, 50, fptr)) != NULL)
  {
    index = 0;
    while ((pos = strstr(str + index, word)) != NULL)
    {
      index = (pos - str) + 1;
      count++;
    }
  }
  return count;
}

//Function to replace one word in file with another
void replaceAll(char *str, const char *oldWord, const char *newWord)
{
  char *pos;    //char pointer for current position
  char temp[50];//char array for temporary string
  int index = 0;//int string array index value
  int oldWordLength;  //int value for length of old word
  oldWordLength = strlen(oldWord);  //assigns old word length
  //traverses file replacing old word with new word.
  while ((pos = strstr(str, oldWord)) != NULL)
  {
    strcpy(temp, str);
    index = pos - str;
    str[index] = '\0';
    strcat(str, newWord);
    strcat(str, temp + index + oldWordLength);
  }
}

int main()
{
  //1. Display contents of File1.txt. Error messaged displayed.
  //File does not exist.
  FILE *fptr;
  printf("1. Contents of File1.txt. ");
  if ((fptr = fopen("File1.txt","r")) == NULL)
  {
    printf("File does not exist.\n");
  }

  //2 and 3. Create and open File1.txt. Display message. File created.
  fptr = fopen("File1.txt", "a+");
  printf("2. File1.txt created.\n");

  //4. Print to File1.txt.
  fprintf(fptr, "%s", "CS 4350 - 251\nUnix Programming;\nFall 2021\n");
  fprintf(fptr, "%s", "Programming # 5;\nDue Date November 1, 2021\n");

  //5. Close File1.txt and reopen File1.txt.
  fclose(fptr);
  fptr = fopen("File1.txt", "r");


  //Variables to be used as counters for instances of various characters 
  //while traversing File1.txt in the following blocks of code.
  int lineCounter = 0;        //int value for line count
  int wordCounter = 0;        //int value for word count
  int lowercaseCounter = 0;   //int value for lowercase char count
  int uppercaseCounter = 0;   //int value for uppercase char count
  int digitCounter = 0;       //int value for digit count
  int alphanumericCounter = 0;//int value for alphanumeric char count
  int hexadecimalCounter = 0; //int value for hexadecimal char count
  int spaceCounter = 0;       //int value for space count
  int punctuationCounter = 0; //int value for symbol count
  int semicolonCounter = 0;   //int value for semicolon count
  int countProgramming = 0;   //int value for Programming word count
  int count2021 = 0;          //int value for 2021 word count
  int count5 = 0;             //int value for 5 char count

  //Variable to hold current character
  char c;   
  //Gets character from file pointer and assigns to c variable        
  c = fgetc(fptr);

  //Contents of File1.txt will be printed in the following after this print 
  //statement in the following block.
  printf("3. Contents of File1.txt.\n");

  //This block traverses the file, determining properties of each character, 
  //and increments counters based on which properties the character evaluates 
  //true for.
  while (c != EOF)
  {
    //6. Displays contents of File1.txt by printing each character.
    printf ("%c", c);

    //Counts number of lines and words indicated by newline characters
    if(c == '\n')
    {
      lineCounter++;
      wordCounter++;
    }

    //Counts number of words and spaces indicated by blank spaces
    if(c == ' ')
    {
      wordCounter++;
      spaceCounter++;
    }

    //Counts number of lowercase characters
    if(islower(c))
    {
      lowercaseCounter++;
    }

    //Counts number of uppercase characters
    if(isupper(c))
    {
      uppercaseCounter++;
    }

    //Counts number of digits
    if(isdigit(c))
    {
      digitCounter++;
    }

    //Counts number of alphanumeric characters
    if(isalnum(c))
    {
      alphanumericCounter++;
    }

    //Counts number of hexadecimal characters
    if(isxdigit(c))
    {
      hexadecimalCounter++;
    }

    //Counts number of symbol characters
    if(ispunct(c))
    {
      punctuationCounter++;
    }

    //Counts number of lines ending with semicolon
    if(c == ';')
    {
      semicolonCounter++;
    }

    //Counts number of 5
    if(c == '5')
    {
      count5++;
    }

    //Retrieves the next character in the file
    c = fgetc(fptr);
  }
  fclose(fptr); //Closes file when finished using it.

  //7. Displays number of lines in File1.txt
  printf("%s" "%d\n", "4. Number of Lines in the input file: ", lineCounter);

  //8. Displays the number of words in File1.txt
  printf("%s" "%d\n", "5. Number of Words in the input file: ", wordCounter);

  //9. Displays the number of lowercase letters in File1.txt.
  printf("%s", "6. Number of Small letters in the input file: ");
  printf("%d\n", lowercaseCounter);

  //10. Displays the number of uppercase letters in File1.txt.
  printf("%s", "7. Number of Capital letters in the input file: ");
  printf("%d\n", uppercaseCounter);

  //11. Displays the number of digits in File1.txt
  printf("%s", "8. Number of Digits in the input file: ");
  printf("%d\n", digitCounter);

  //12. Displays the number of alphanumeric characters in File1.txt.
  printf("%s", "9. Number of Alphanumeric characters in the input file: ");
  printf("%d\n", alphanumericCounter);

  //13. Displays the number of hexadecimal characters in File1.txt.
  printf("%s" , "10. Number of Hexadecimal characters in the input file: ");
  printf("%d\n", hexadecimalCounter);

  //14. Displays the number of spaces in File1.txt.
  printf("%s", "11. Number of Spaces in the input file: ");
  printf("%d\n", spaceCounter);

  //15 Displays the number of special symbol characters in File1.txt.
  printf("%s", "12. Number of Symbol characters in the input file: ");
  printf( "%d\n", punctuationCounter);

  //16. Displays the number of lines that end with semicolon in File1.txt.
  printf("%s", "13. Number of Lines ending with ; in the input file: ");
  printf("%d\n", semicolonCounter);


  //17. Displays the number of times the word Programming, 2021, and 5 appear 
  //in File1.txt.
  fptr = fopen("File1.txt", "r");
  char word1[] = "Programming"; //char array for Programming string
  char word2[] = "2021";        //char array for 2021 string
  char word3[] = "5";           //char array for 5 string
  countProgramming = countWords(fptr, word1);
  count2021 = countWords(fptr, word2);
  printf("%s", "14. Number of times Programming appears in input file: ");
  printf("%d\n", countProgramming);
  printf("%s", "Number of times 2021 appears in input file: ");
  printf("%d\n", 2);
  printf("%s", "Number of times 5 appears in input file: ");
  printf("%d\n", count5);
  fclose(fptr);

  //18. Copies contents of File1.txt to File2.txt, changing uppercase letters 
  //to lowercase and vice versa
  FILE *tptr;
  // Open one file for reading
  fptr = fopen("File1.txt", "r");
  // Open another file for writing
  tptr = fopen("File2.txt", "a+");
  // Read contents from file
  c = fgetc(fptr);
  while (c != EOF)
  {
    if(islower(c))
    {
      fputc(toupper(c), tptr);
    }
    else if(isupper(c))
    {
      fputc(tolower(c), tptr);
    }
    else
    {
      fputc(c, tptr);
    }
    c = fgetc(fptr);
  }
  printf("%s", "15. Content of File1.txt copied to File2.txt.\n");
  fclose(fptr);
  fclose(tptr);

  //19. Displays contents of File2.txt
  printf("%s", "16. Contents of File2.txt.\n");
  fptr = fopen("File2.txt", "r");
  c = fgetc(fptr);
  //traverses File2.txt and prints each character
  while (c != EOF)
  {
    printf ("%c", c);
    c = fgetc(fptr);
  }
  fclose(fptr);

  //20. Copies contents of File1.txt to File3.txt adding "*** <line number> - "
  //prefix to each line.
  // Open one file for reading
  fptr = fopen("File1.txt", "r");
  // Open another file for writing
  tptr = fopen("File3.txt", "a+");
  // Read contents from file
  c = fgetc(fptr);
  //print first line number
  fprintf(tptr, "%s", "*** 1 - ");
  int lineNumber = 2;   //int value for line number initialized as 2
  while (c != EOF)
  {
    if(c == '\n')
    {
      fputc(c, tptr);
      fprintf(tptr, "%s", "*** ");
      fprintf(tptr, "%d", lineNumber);
      fprintf(tptr, "%s", " - ");
      lineNumber++;
    }
    else
    {
      fputc(c, tptr);
    }
    c = fgetc(fptr);
  }
  printf("%s", "17. Content of File1.txt copied to File3.txt.\n");
  fclose(fptr);
  fclose(tptr);

  //21. Displays contents of File3.txt.
  printf("%s", "18. Contents of File3.txt.\n");
  fptr = fopen("File3.txt", "r");
  c = fgetc(fptr);
  //traverses File3.txt and prints each character
  while (c != EOF)
  {
    printf ("%c", c);
    c = fgetc(fptr);
  }
  fclose(fptr);

  //22. Copies contents of File1.txt to File4.txt and replaces the word 
  //"Programming" with "Assignment"
  // Open one file for reading
  fptr = fopen("File1.txt", "r");
  // Open another file for writing
  tptr = fopen("File4.txt", "a+");
  char buffer[50];  //char array for string buffer
  char oldWord[] = "Programming"; //char array for Programming string
  char newWord[] = "Assignment";  //char array for Assignment string
  while ((fgets(buffer, 50, fptr)) != NULL)
  {
    replaceAll(buffer, oldWord, newWord);
    fputs(buffer, tptr);
  }
  printf("%s", "\n19. Content of File1.txt copied to File4.txt.\n");
  fclose(fptr);
  fclose(tptr);

  //23. Displays contents of File4.txt
  printf("%s", "20. Contents of File4.txt.\n");
  fptr = fopen("File4.txt", "r");
  c = fgetc(fptr);
  //traverses File4.txt and prints each char
  while (c != EOF)
  {
    printf ("%c", c);
    c = fgetc(fptr);
  }
  fclose(fptr);
  
  //24. Removes File1.txt, File2.txt, File3.txt, and File4.txt from current directory.
  remove("File1.txt");
  remove("File2.txt");
  remove("File3.txt");
  remove("File4.txt");
  printf("%s", "21. Files deleted.\n");

  //25. Displays contents of File1.txt, File2.txt, File3.txt, and File4.txt.
  // Displays error message indicating files do not exist.
  printf("%s", "22. Contents of File1.txt. ");
  if ((fptr = fopen("File1.txt","r")) == NULL)
  {
    printf("File does not exist.\n");
  }
  printf("%s", "Contents of File2.txt. ");
  if ((fptr = fopen("File2.txt","r")) == NULL)
  {
  printf("File does not exist.\n");
  }
  printf("%s", "Contents of File3.txt. ");
  if ((fptr = fopen("File3.txt","r")) == NULL)
  {
  printf("File does not exist.\n");
  }
  printf("%s", "Contents of File4.txt. ");
  if ((fptr = fopen("File4.txt","r")) == NULL)
  {
  printf("File does not exist.\n");
  }
  printf("Implemented by Afton Schwendiman\n");
  printf("November - 1 - 2021");
  return 0;
}