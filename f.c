#include <stdio.h>
#include <string.h>
#define MAX 1000
#define LEN 1000

char todo[MAX][LEN];
int count = 0;

void showList() {
    if (count == 0) {
        printf("empty\n");
        return;
    }
    for (int i = 0; i<count; i++) {
        printf("%d. %s\n",i+1,todo[i]);
    }
}

void addItem() {
    if (count >= MAX) {
        printf("full capacity\n");
        return;
    }
    printf("to do?");
    getchar(); 
    fgets(todo[count], LEN, stdin);
    todo[count][strcspn(todo[count], "\n")] = 0;
    count++;

    printf("done\n");
}

void editItem() {
    int n;
    showList();
    printf("edit? ");
    scanf("%d", &n);
    if (n < 1 || n > count) {
        printf("error\n");
        return;
    }


    printf("new: ");
    getchar();
    fgets(todo[n - 1], LEN, stdin);
    todo[n - 1][strcspn(todo[n - 1], "\n")] = 0;
    printf("edited.\n");
}
void deleteItem() {
    int n;
    showList();
    printf("delete? ");
    scanf("%d", &n);

    if (n < 1 || n > count) {
        printf("error.\n");
        return;
    }
     for (int i = n - 1; i < count - 1; i++) {
        strcpy(todo[i], todo[i + 1]);
    }
    count--;

    printf("delete.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nTo do list\n");
        printf("1.list\n");
        printf("2.add\n");
        printf("3.edit\n");
        printf("4.delete\n");
        printf("choice:");
        scanf("%d", &choice);

       if (choice == 1) {
    showList();
}
else if (choice == 2) {
    addItem();
}
else if (choice == 3) {
    editItem();
}
else if (choice == 4) {
    deleteItem();
}
else {
    printf("error \n");
}
        }
    }
