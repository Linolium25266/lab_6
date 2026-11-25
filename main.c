#include <stdbool.h>
#include <stdio.h>

#include "tasks.h"

void menu() {
  int choice;

  while (true) {
    puts("Select a task:");
    puts("1. Task 960");
    puts("2. Task 977");
    puts("3. Task 1000");
    puts("4. Task 927");
    puts("5. Task 995");
    puts("6. Exit");
    printf("Enter choice: ");

    scanf_s("%d", &choice);

    printf("\n");

    switch (choice) {
    case 1:
      task960();
      break;
    case 2:
      task977();
      break;
    case 3:
      task1000();
      break;
    case 4:
      task927();
      break;
    case 5:
      task995();
      break;
    case 6:
      return;
    default:
      puts("Invalid choice, please try again.");
    }

    printf("\nPress Enter to continue...");
    clearInputBuffer();
    getchar();
    printf("\n");
  }
}

int main(void) {
  menu();
  return 0;
}
