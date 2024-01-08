// NAME: Afton Schwendiman
// CS 4350 - 100 - Unix Systems Programming
// Assignment Number: 6
// Due Date: 11 / 15 / 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/utsname.h>
#include <sys/resource.h>
#include <errno.h>
#include <netdb.h>

// prototypes
void createFile(char[]);            // 2
int getPermission(char[]);          // 3 and 5 and 21
void changeMode(char[], int);       // 4
void appendFile(char[], char[]);    // 6 and 7 and 29
void displayFile(char[]);           // 8 and 11 and 30
const char* currentDateTime();      // 9
const char* lastFileAccess(char[]); // 10 and 31
const char* systemName();           // 12
const char* getlocalHost();         // 13
const char* getHost();              // 14
int getProcessID();                 // 15
int getParentProcessID();           // 16
int getPriority();                  // 17
const char* fileName(char[]);       // 18
int getDevice(char[]);              // 19
int getInode(char[]);               // 20
int getHardlinks(char[]);           // 22
int getOwnerID(char[]);             // 23
int getOwnerGroupID(char[]);        // 24
int getEffectiveUserID();           // 25
int getFileSize(char[]);            // 26
int getBlockSize(char[]);           // 27
int getBlocks(char[]);              // 28
void renameFile(char[], char[]);    // 32
// end of protoypes

// beginning of main function

int main(void) {
  printf("System / File Manipulation Program\n\n"); // program name
  char buffer[50];      // char array to hold user input
  // 1. Prompt user to enter name of text file that needs to be created
  printf("1.\tEnter File name to be created: ");
  scanf("%s", buffer);
  char filename[50];    // char array to process user input buffer as .txt file
  strcat(strcpy(filename, buffer), ".txt");

// 2. Using System Command, create a new input file
  createFile(filename);
  printf("2.\t%s%s", filename, " File is created.\n");

// 3. Use System Command, to list file permission status before changing the file mode.
  printf("3.\tFile permission status is: %o\n", getPermission(filename));

// 4. Change the mode of the program such that only the user has read/write/execute permission.
  changeMode(filename, S_IRWXU);
  printf("4.\tFile mode is changed.\n");

// 5. Use SC to list file info after changing the file mode.
  printf("5.\tFile permission status is: %o\n", getPermission(filename));

// 6. Append the following to text file: Texas State University, Fall 2021, Unix Programming
  appendFile(filename, "Texas State University, Fall 2021, Unix Programming");
  printf("6.\tText is appended to the file.\n");

// 7. Close the input file.
// file closed after previously called function, appendFile
  printf("7.\tFile is closed.\n");

// 8. Display the content of the file.
  printf("8.\tContent of the input file: \n");
  displayFile(filename);

// 9. Use SC to display the current date and time
  printf("\n9.\tCurrent date and time is: %s", currentDateTime());

// 10. Display time of last file access.
  printf("10.\tTime of last file access: %s", lastFileAccess(filename));

// 11. Use SC to display the content of the new created input file.
  printf("11.\tThe content of the created file is: \n");
  displayFile(filename);

// 12. Display System name.
  printf("\n12.\tSystem name: %s\n", systemName());

// 13. Display local host name.
  printf("13.\tLocal host name: %s\n", getlocalHost());

// 14. Display host name.
  printf("14.\tHost name: %s\n", getHost());

// 15. Display the process id.
  printf("15.\tThe process id: %d\n", getProcessID());

// 16. Display parent process id.
  printf("16.\tParent process id: %d\n", getParentProcessID());

// 17. Display priority level of the process.
  printf("17.\tPriority level of the process: %d\n", getPriority());

// 18. Display the file name.
  printf("18.\tThe file Name is %s\n", fileName(filename));

// 19. Display the device.
  printf("19.\tThe device is: %d\n", getDevice(filename));

// 20. Display the inode.
  printf("20.\tThe inode is: %d\n", getInode(filename));

// 21. Display the file protection
  printf("21.\tThe file protection: %o\n", getPermission(filename));

// 22. Display number of hard link
  printf("22.\tNumber of hard links: %d\n", getHardlinks(filename));

// 23. Display owner's user id
  printf("23.\tOwner's user ID: %o\n", getOwnerID(filename));

// 24. Display owner's group id
  printf("24.\tOwner's group ID: %o\n", getOwnerGroupID(filename));

// 25. Display owner's effective user id
  printf("25.\tOwner's effective user ID: %d\n", getEffectiveUserID());

// 26. Display size of text file
  printf("26.\tSize of %s%s%d\n", filename, " file: ", getFileSize(filename));

// 27. Display block size for text file
  printf("27.\tBlock size of %s%s%d\n", filename, " file: ", getBlockSize(filename));

// 28. Display number of blocks allocated to text file
  printf("28.\tNumber of blocks allocated to %s%s%d\n", filename, " file: ", getBlocks(filename));

// 29. Append the following line to the text file:  Last Step.
  appendFile(filename, "\nLast Step.");
  printf("29.\tNew text is appended to %s%s",filename, " file.\n");

// 30. Using SC, displaythe content of text file.
  printf("30.\tRedisplaying the content of %s%s", filename, " file.\n");
  displayFile(filename);

// 31. Display the time of last access of text file.
  printf("\n31.\tThe time of last access of %s%s%s", filename, " file: ", lastFileAccess(filename));

// 32. Rename the file to be textfilename-2.text
  char newfilename[50];               // char array to hold new filename
  strncpy(newfilename, buffer, 50);   // copies the filename from buffer into newfilename
  strcat(newfilename, "-2");          // processes newfilename to add -2 suffix
  strcat(newfilename, ".txt");        // processes newfilename to add .txt suffix
  renameFile(filename, newfilename);
  printf("32.\tRenamed The file to be %s%s\n", newfilename, ".");

// 33. Using SC, display the content of the new text file
  printf("33.\tThe content of the new %s%s\n", newfilename,  " file: ");
  displayFile(newfilename);

// 34. Use SC to display the current date and time
  printf("\n34.\tThe current date and time: %s", currentDateTime());

// 35. Remove the new text files from your current directory.
  remove(newfilename);
  printf("35.\tRemoved %s%s", newfilename, " files from current Directory.\n");

// 36. Using SC, display the content of deleted text file.
  printf("36.\tDisplaying the content of %s%s\n", newfilename, " file.");
  displayFile(newfilename);

// end of program comments
  printf("\nNovember - 2021\n");
  printf("Afton Schwendiman");
  return 0;
}
// end of main function


// function definitions

// 2. function takes filename and creates a file with that name
void createFile(char filename[]) {
  char cmd[50] = "touch ";
  strcat(cmd, filename);
  system(cmd);
}

// 3 and 5 and 21. function takes filename and returns value of octal permission status
int getPermission(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return file_stats.st_mode;
}

// 4. function takes filename and mode, and changes the file mode of the passed file with the passed mode
void changeMode(char filename[], int newMode) {
  struct stat file_stats;
  mode_t mode = newMode;
  chmod(filename, mode);
  stat(filename, &file_stats);
}

// 6 and 7 and 29. function takes filename and string, and appends the passed file with the passed string.  File is closed after the append is completed.
void appendFile(char filename[], char content[]) {
  FILE *fptr;
  fptr = fopen(filename, "a");
  fprintf(fptr, "%s", content);
  fclose(fptr);
}

// 8 and 11 and 30. function takes filename and displays the content of the file passed
void displayFile(char filename[]) {
  char cmd[50] = "cat ";
  strcat(cmd, filename);
  system(cmd);
}

// 9. function takes no arguments and returns the current date and time.
const char* currentDateTime() {
  time_t rawtime;
  struct tm* timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  return asctime(timeinfo);
}

// 10 and 31. function takes filename and returns the time of the last access of the passed file
const char* lastFileAccess(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return ctime(&file_stats.st_atime);
}

// 12.  function takes no arguments and returns the system name 
const char* systemName() {
  static struct utsname uts;   // allocation for struct
  uname(&uts);
  return uts.sysname;
}

// 13. function takes no arguments, and returns the local host name
const char* getlocalHost() {
  static char host[256];
  int hostname = gethostname(host, sizeof(host));;
  return host;
}

// 14. function takes no arguments, and returns the host name
const char* getHost() {
  static char host[256];
  int hostname = gethostname(host, sizeof(host));;
  return host;
}

// 15. function takes no arguments and returns the process ID
int getProcessID() {
  pid_t process_id;
  process_id = getpid();
  return process_id;
}

// 16. function takes no arguments and returns the parent process ID
int getParentProcessID() {
  pid_t ppid;
  ppid = getppid();
  return ppid;
}

// 17. function takes no arguments and returns the priority level of the process
int getPriority() {
  pid_t process_id = getpid();
  int priority;
  priority = getpriority(PRIO_PROCESS, process_id);
  return priority;
}

// 18. function takes the filename and returns the filename
const char* fileName(char filename[]) {
  return filename;
}

// 19. function takes filename and returns the device
int getDevice(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return file_stats.st_dev;
}

// 20. function takes filename and returns inode
int getInode(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return file_stats.st_ino;
}

// 22. function takes filename and returns number of hard links
int getHardlinks(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);  
  return file_stats.st_nlink;
}

// 23. function takes filename and returns owner's user ID
int getOwnerID(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return file_stats.st_uid;
}

// 24. function takes filename and returns owner's group ID
int getOwnerGroupID(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return file_stats.st_gid;
}

// 25. function takes no arguments and returns effective user ID
int getEffectiveUserID() {
  uid_t euid;
  euid = geteuid();
  return euid;
}

// 26. function takes filename and returns file size
int getFileSize(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return file_stats.st_size;
}

// 27. function takes filename and returns file block size
int getBlockSize(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return file_stats.st_blksize;
}

// 28.  function takes filename and returns number of blocks allocated to file
int getBlocks(char filename[]) {
  struct stat file_stats;
  stat(filename, &file_stats);
  return file_stats.st_blocks;
}

// 32. function takes filename and new filename and renames the passed filename with the passed new filename.  
void renameFile(char filename[], char newFilename[]) {
  rename(filename, newFilename);
}
// end of function definitions