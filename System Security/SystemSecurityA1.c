#include <stdio.h>

typedef struct {
unsigned int uid; // owner id
unsigned int gid; // group id
unsigned char u; // owner's permission
unsigned char g; // group's permission
unsigned char o; // other's permission
}Permission;

int accesscheck(unsigned int uid, unsigned int gid, unsigned int p, int f)
{
  Permission permission = getPermission(f); //obtain permissions for the desired file
  //if user == owner: check user permission: grant or deny access.
  if(uid == permission.uid){ //if the requester's uid matches the owner's uid, continue:
    if (p == 4) {
      if (permission.u >= 4) {
        return 1;
      }
    }
    else if (p == 2) {
      if (permission.u == 2 || permission.u == 3 || permission.u == 6 || permission.u == 7) {
        return 1;
      }
    }
    else if (p == 1) {
      if (permission.u == 1 || permission.u == 3 || permission.u == 5 || permission.u == 7){
        return 1;
      }
    }
  }
  

  //else (user not owner): if user guid is same as file: check gid permission: grant or deny access.
  else if (gid == permission.gid) {
    if (p == 4) {
      if (permission.g >= 4) {
        return 1;
      }
    }
    else if (p == 2) {
      if (permission.g == 2 || permission.g == 3 || permission.g == 6 || permission.g == 7) {
        return 1;
      }
    }
    else if (p == 1) {
      if (permission.g == 1 || permission.g == 3 || permission.g == 5 || permission.g == 7){
        return 1;
      }
    }
  }

  //else (neither owner or same group): check other permission: grant or deny access

  else {
    if (p == 4) {
      if (permission.o >= 4) {
        return 1;
      }
    }
    else if (p == 2) {
      if (permission.o == 2 || permission.o == 3 || permission.o == 6 || permission.o == 7) {
        return 1;
      }
    }
    else if (p == 1) {
      if (permission.o == 1 || permission.o == 3 || permission.o == 5 || permission.o == 7){
        return 1;
      }
    }
  }
  return 0;
}
  Permission getPermission(int f); //given: gets the permission of the file f.
  //if getPermission returns: rwxr-xr-x 1000(uid) 2000(gid)
  //then accesscheck(1000, 1000, 6, f) returns 1, but accesscheck(2000, 2000, 6, f) returns 0.
  

int main(void) {
  printf("Hello World\n");
  return 0;
}
