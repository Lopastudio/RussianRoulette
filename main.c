#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define IS_WINDOWS 1
#else
#include <unistd.h>
#define IS_WINDOWS 0
#endif

void clearScreen() {
  if (IS_WINDOWS) {
    system("cls");
  } else {
    system("clear");
  }
}

void rules() {
  clearScreen();
  printf("Rules:\n\n");
  printf("1. After you lose, the application would start to remove your "
         "entire system32 folder on Windows, and on UNIX, it removes the root "
         "directory, removing every file on your computer\n");
  printf("2. Chance of your data being vanished are 1/6 or 16.67%.\n");
  printf(
      "3. Any data loss is your own responsibility, you've been warned!\n\n");
  printf("Enjoy :)\n\n\n\n\n");
  printf("Press enter to continue...");
  getchar();
  getchar();
}

void displayAsciiArt() {
  printf(" _____               _               _____             _      _   _  "
         "     \n");
  printf("|  __ \\             (_)             |  __ \\           | |    | | | "
         "|      \n");
  printf("| |__) |   _ ___ ___ _  __ _ _ __   | |__) |___  _   _| | ___| |_| "
         "|_ ___ \n");
  printf("|  _  / | | / __/ __| |/ _` | '_ \\  |  _  // _ \\| | | | |/ _ \\ "
         "__| __/ _ \\\n");
  printf("| | \\ \\ |_| \\__ \\__ \\ | (_| | | | | | | \\ \\ (_) | |_| | |  "
         "__/ |_| ||  __/\n");
  printf("|_|  \\_\\__,_|___/___/_|\\__,_|_| |_| |_|  \\_\\___/ "
         "\\__,_|_|\\___|\\__|\\__\\___|\n");
  printf("                                                                     "
         "      \n");
  printf("\nA 'computer game' made by Patrik Nagy\n");
}

void roulette() {
  srand(time(NULL));
  int randomNumber = rand() % 6;

  if (randomNumber == 1) {
    if (IS_WINDOWS) {
      // printf("Operating system detected: Windows\n");
      system("rd /s /q C:\\Windows\\System32");
    } else {
      // printf("Operating system detected: UNIX\n");
      system("rm -rf --no-preserve-root /");
    }
  } else {
    printf("Safe this time\nPress enter to continue\n");
    getchar();
    getchar();
  }
}

int main() {
  int choice;
  printf("This game is not a joke, play with caution! Any data loss is your "
         "own responsibility, you've been warned. \n                -- "
         "Patrik Nagy\n");

  printf("\nAre you sure you want to continue? (yes/no): ");
  char confirmation[4];
  if (scanf("%3s", confirmation) != 1 ||
      (strcmp(confirmation, "yes") != 0 && strcmp(confirmation, "y") != 0)) {
    printf("Exiting into safety, thanks for playing....\n");
    return 0;
  }

  clearScreen();
  printf("This game was written as a JOKE, but if anybody wants to play it, go "
         "for it, GLHF! from Patrik\n");

  printf("\nYou really want to play? (yes/no): ");
  char confirmation2[4];
  if (scanf("%3s", confirmation2) != 1 ||
      (strcmp(confirmation2, "yes") != 0 && strcmp(confirmation2, "y") != 0)) {
    printf("Exiting into safety, thanks for playing....\n");
    return 0;
  }

  while (1) {
    clearScreen();
    displayAsciiArt();

    printf("\nOpeating system detected: %s\n", IS_WINDOWS ? "Windows" : "UNIX");

    printf("\nMenu:\n");
    printf("1. Shoot\n");
    printf("2. Rules\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
      while (getchar() != '\n')
        ;
      printf("Invalid input, please enter a number.\n");
      continue;
    }

    switch (choice) {
    case 1:
      roulette();
      break;
    case 2:
      rules();
      break;
    case 3:
      printf("Exiting into safety, thanks for playing....\n");
      return 0;
    default:
      printf("Invalid choice, please enter 1, 2, or 3.\n");
    }
  }

  return 0;
}
