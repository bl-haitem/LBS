#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100  
#define MAX_TITLE 100
#define MAX_NAME 50


typedef enum { Algo, Archi, Algb, SE } Category;


typedef enum { Available, Unavailable } State;


typedef struct {
    int isbn;
    Category category;
    char title[MAX_TITLE];
    char authorFirstName[MAX_NAME];
    char authorLastName[MAX_NAME];
    int publicationYear;
    State state;
    int copies;
} Book;

Book books[MAX_BOOKS];

void createBooks(Book books[], int *n) {
    printf("Enter the number of books: ");
    scanf("%d", n);
    
    for (int i = 0; i < *n; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("ISBN: ");
        scanf("%d", &books[i].isbn);
        
        printf("Category (0: Algo, 1: Archi, 2: Algb, 3: SE): ");
        int cat;
        scanf("%d", &cat);
        books[i].category = (Category)cat;
        
        printf("Title: ");
        scanf(" %[^\n]", books[i].title);
        
        printf("Author First Name: ");
        scanf("%s", books[i].authorFirstName);
        
        printf("Author Last Name: ");
        scanf("%s", books[i].authorLastName);
        
        printf("Publication Year: ");
        scanf("%d", &books[i].publicationYear);
        
        printf("State (0: Available, 1: Unavailable): ");
        int st;
        scanf("%d", &st);
        books[i].state = (State)st;
        
        printf("Number of copies: ");
        scanf("%d", &books[i].copies);
    }
}

void displayRecentBooks(Book books[], int n, int year) {
    printf("\nBooks published after %d:\n", year);
    int found = 0;
    
    for (int i = 0; i < n; i++) {
        if (books[i].publicationYear > year) {
            printf("ISBN: %d, Title: %s, Author: %s %s\n", 
                   books[i].isbn, books[i].title, 
                   books[i].authorFirstName, books[i].authorLastName);
            found = 1;
        }
    }

    if (found!=1) {
        printf("No books found.\n");
    }
}
int countAvailableBooks(Book books[], int n, Category category) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (books[i].category == category && books[i].state == Available) {
            count += books[i].copies;
        }
    }
    
    return count;
}
int main() {
    Book books[MAX_BOOKS];
    int n, year, category;
    
 
    createBooks(books, &n);
    
    
    printf("\nEnter the year to filter recent books: ");
    scanf("%d", &year);
    displayRecentBooks(books, n, year);
    
 
    printf("\nEnter category to count available books (0: Algo, 1: Archi, 2: Algb, 3: SE): ");
    scanf("%d", &category);
    int availableBooks = countAvailableBooks(books, n, (Category)category);
    printf("Number of available books in this category: %d\n", availableBooks);
    
    return 0;
}
