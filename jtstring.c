#include <stdio.h>
#include "jtstring.h"

int jtstrlen(char *str) {
  char *strIter = str - 1;
  while (*++strIter);
  return strIter - str;
}

char *jtstrcpy(char *dest, char *src) {
  char *destIter = dest;
  while (*destIter++ = *src++);
  return dest;
}

char *jtstrncpy(char *dest, char *src, int n) {
  char *destIter = dest;
  while (*destIter++ = *src++ && n-->0);
  return dest;
}

char *jtstrcat(char *dest, char *src) {
  char *destIter = dest;
  while (*destIter++);
  jtstrcpy(--destIter, src);
  return dest;
}

char *jtstrncat(char *dest, char *src, int n) {
  char *destIter = dest;
  while (*destIter++);
  jtstrncpy(--destIter, src, n);
  return dest;
}

int jtstrcmp(char *one, char *two) {
  while (*one == *two) {
    if (!*one)
      return 0;
    one++;
    two++;
  }
  return *one - *two;
}

char *jtstrchr(char *str, char chr) {
  while (*str != chr) {
    if (!*str)
      return NULL;
    str++;
  }
  return str;
}

char *jtstrstr(char *str, char *sub) {
  char *strIter = str - 1;
  while(*++strIter) {
    if (*strIter == *sub) {
      char *subIter = sub;
      char *strIter2 = strIter;
      while (*++subIter == *++strIter2);
      if (!*subIter)
	return strIter;
    }
  }
  return NULL;
}

