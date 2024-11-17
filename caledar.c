#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  char *dayName;
  int date;
  char *activity;
}week;
void create(week *day)
{
  day->dayName = (char *)malloc(sizeof(char) * 20);
  day->activity = (char *)malloc(sizeof(char) * 100);
  printf("Enter the day name: ");
  scanf("%s", day->dayName);
  printf("Enter the date: ");
  scanf("%d", &day->date);
  printf("Enter the activity for the day: ");
  scanf(" %[^\n]s", day->activity);
}
void read(week *calendar, int size)
{ 
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter details for Day %d:\n", i + 1);
    create(&calendar[i]);
  }
}

void display(week *calendar, int size)
{
  int i;
  printf("\nWeek's Activity Details:\n");
  printf("--------------------------------------------------\n");
  printf("Dayno\t\tDayname\t\tDate\t\tActivity\n");
  printf("--------------------------------------------------\n");
  for (i = 0; i < size; i++)
  {
    printf("%d\t\t", i + 1);
    printf("| %s |\t\t", calendar[i].dayName);
    printf("| %d |\t\t", calendar[i].date);
    printf("| %s |\t\t", calendar[i].activity);
    printf("\n");
  }
}
int main() {
  int size;
  week *calendar;
  printf("Enter the number of days in the week: ");
  scanf("%d", &size);
  calendar = (week *)malloc(sizeof(week) * size);
  if (calendar == NULL) {
    printf("Memory allocation failed. Exiting program.\n");
    return 1;
  }
  read(calendar, size);
  display(calendar, size);
  free(calendar);
  return 0;
}
