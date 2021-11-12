#include <stdio.h>
#include <stdlib.h>

struct student
{
   int id;
   int score;
   int rank;
   struct student *next;
};

struct student *head = NULL;
struct student *current = NULL;

//display the list
void printList()
{
   struct student *ptr = head;
   printf("\n[ ");

   //start from the beginning
   while (ptr != NULL)
   {
      printf("(%d, %d, %d) ", ptr->id, ptr->score, ptr->rank);
      ptr = ptr->next;
   }

   printf("]\n");
}

//insert link at the first location
void insertStudent(int id, int score)
{
   //create a link
   struct student *link = (struct student *)malloc(sizeof(struct student));
   link->id = id;
   link->score = score;
   link->rank = 1;

   struct student *ptr = head, *ptrPrevious = head;
   if (head)
   {
      while (ptr != NULL)
      {
         if (ptr->score > link->score)
         {
            ptrPrevious = ptr;
            ptr = ptr->next;
         }
         else
         {
            break;
         }
      }
      ptrPrevious->next = link;
      link->next = ptr;
   }
   else {
      link->next = head;
      head = link;
   }
}

int main()
{
   int id, score;
   char buf[100]; // let us be generous with size.
   while (fgets(buf, sizeof buf, stdin) && buf[0] != '\n')
   {
      sscanf(buf, "%d %d", &id, &score);
      insertStudent(id, score);
   printList();
   }

   return 0;
}