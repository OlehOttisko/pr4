#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    float price;
    int pages;
    char language[50];
    float weight;
    int year;
    struct Book* next;  // Вказівник на наступну книгу в списку
};

// Функція для створення нової книги
struct Book* createBook(char *title, float price, int pages, char *language, float weight, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

// Функція для додавання книги в список
void addBook(struct Book** head, char *title, float price, int pages, char *language, float weight, int year) {
    struct Book* newBook = createBook(title, price, pages, language, weight, year);
    if (*head == NULL) {
        *head = newBook;
    } else {
        struct Book* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

// Функція для виведення списку книг
void displayBooks(struct Book* head) {
    struct Book* temp = head;
    while (temp != NULL) {
        printf("Title: %s\n", temp->title);
        printf("Price: %.2f\n", temp->price);
        printf("Pages: %d\n", temp->pages);
        printf("Language: %s\n", temp->language);
        printf("Weight: %.2f\n", temp->weight);
        printf("Year: %d\n\n", temp->year);
        temp = temp->next;
    }
}

int main() {
    struct Book* head = NULL;
    
    // Додаємо книги
    addBook(&head, "Harry Potter and the Philosopher's Stone", 15.99, 309, "English", 0.45, 1997);
    addBook(&head, "Harry Potter and the Chamber of Shadows", 16.99, 341, "English", 0.47, 1998);
    addBook(&head, "Harry Potter and the Dark Lord's Secret", 17.99, 452, "English", 0.50, 2000);
    addBook(&head, "Harry Potter and the Goblet of Fire", 18.99, 636, "English", 0.65, 2001);
    
    // Виводимо список книг
    displayBooks(head);
    
    return 0;
}