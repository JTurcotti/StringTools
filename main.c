#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "jtstring.h"
#define SIZE 10

char bowl[SIZE];
void reset() {
  int i;
  for (i = 0; i < SIZE; i++)
    bowl[i] = '\0';
}

void fill() {
  int i;
  for (i = 0; i < SIZE; i++)
    bowl[i] = rand();
}

void print() {
  printf("Current bowl: ");
  int i;
  for (i = 0; i< SIZE; i++)
    printf("%c", bowl[i]);
  printf("\n");
}

char *jtstrcpytest(char *src);

int main() {
  srand(time(NULL));
  reset();
  
  char *empty = "";
  char *fruit = "apple";
  char *vegetable = "cauliflower";
  printf("\njtstrlen:\nResult: %d, %d, %d;\tExpected: %d, %d, %d;\n", jtstrlen(empty), jtstrlen(fruit), jtstrlen(vegetable), (int)strlen(empty), (int)strlen(fruit), (int)strlen(vegetable));

  //tests for copying into both array full of \0 and array full of random values
  printf("\njtstrcpy into empty:\nResult: ");
  reset();
  printf("\"%s\", ", jtstrcpy(bowl, empty));
  reset();
  printf("\"%s\", ", jtstrcpy(bowl, fruit));
  reset();
  printf("\"%s\";\t", jtstrcpy(bowl, vegetable));
  printf("Expected: ");
  reset();
  printf("\"%s\", ", strcpy(bowl, empty));
  reset();
  printf("\"%s\", ", strcpy(bowl, fruit));
  reset();
  printf("\"%s\";\n", strcpy(bowl, vegetable));

  printf("\njtstrcpy into full:\nResult: ");
  fill();
  printf("\"%s\", ", jtstrcpy(bowl, empty));
  fill();
  printf("\"%s\", ", jtstrcpy(bowl, fruit));
  fill();
  printf("\"%s\";\tExpected: ", jtstrcpy(bowl, vegetable));
  fill();
  printf("\"%s\", ", strcpy(bowl, empty));
  fill();
  printf("\"%s\", ", strcpy(bowl, fruit));
  fill();
  printf("\"%s\";\n", strcpy(bowl, vegetable));

  printf("\njtstrcat:\nResults: ");
  jtstrcpy(bowl, fruit);
  printf("\"%s\", ", jtstrcat(bowl, " pie"));
  jtstrcpy(bowl, vegetable);
  printf("\"%s\";\tExpected: ", jtstrcat(bowl, " pie"));
  strcpy(bowl, fruit);
  printf("\"%s\", ", strcat(bowl, " pie"));
  strcpy(bowl, vegetable);
  printf("\"%s\";\n", strcat(bowl, " pie"));

  reset();

  printf("\njtstrcmp:\nResults: ");
  printf("\"%s\" %c \"%s\", ", fruit, jtstrcmp(fruit, vegetable) >= 0? '>': '<', vegetable);
  printf("\"%s\" %c \"%s\";\tExpected: ", vegetable, jtstrcmp(vegetable, fruit) >= 0? '>': '<', fruit);
  printf("\"%s\" %c \"%s\", ", fruit, strcmp(fruit, vegetable) >= 0? '>': '<', vegetable);
  printf("\"%s\" %c \"%s\";\n", vegetable, strcmp(vegetable, fruit) >= 0? '>': '<', fruit);

  printf("\njtstrchr:\nResult: %s, %s, %s;\tExpected: %s, %s, %s;\n", jtstrchr(vegetable, 'c'), jtstrchr(vegetable, 'f'), jtstrchr(vegetable, 'z'), strchr(vegetable, 'c'), strchr(vegetable, 'f'), strchr(vegetable, 'z'));  
}

