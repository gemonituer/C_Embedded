#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumeration for book languages
enum language {
    ENGLISH,
    GERMAN,
    FRENCH,
    SPANISH
};

// Function to convert language enum to string
const char* get_language_name(enum language lang) {
    switch (lang) {
        case ENGLISH: return "English";
        case GERMAN:  return "German";
        case FRENCH:  return "French";
        case SPANISH: return "Spanish";
        default:      return "Unknown";
    }
}

// Book structure (node of the linked list)
struct book {
    char title[100];         // Book title
    float price;             // Price of the book
    int pages;               // Number of pages
    enum language lang;      // Language (using enum)
    float weight;            // Weight in kilograms
    int year;                // Publication year

    struct book* next;       // Pointer to next book in the list
};

// Creates a new book node with given details
struct book* create_book(const char* title,
                         float price,
                         int pages,
                         enum language lang,
                         float weight,
                         int year) {
    struct book* new_book = (struct book*)malloc(sizeof(struct book));
    if (new_book == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    snprintf(new_book->title, sizeof(new_book->title), "%s", title);
    new_book->price = price;
    new_book->pages = pages;
    new_book->lang = lang;
    new_book->weight = weight;
    new_book->year = year;
    new_book->next = NULL;

    return new_book;
}

// Adds a new book to the end of the linked list
void add_book(struct book** head, struct book* new_book) {
    if (*head == NULL) {
        *head = new_book;
    } else {
        struct book* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_book;
    }
}

// Prints details of all books in the linked list
void print_books(struct book* head) {
    struct book* current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Price: $%.2f\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", get_language_name(current->lang));
        printf("Weight: %.2f kg\n", current->weight);
        printf("Year: %d\n", current->year);
        printf("---------------------------\n");
        current = current->next;
    }
}

// Frees the memory allocated for all books in the list
void delete_books(struct book* head) {
    struct book* current = head;
    while (current != NULL) {
        struct book* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function
int main() {
    struct book* book_list = NULL;  // Initialize empty linked list of books

    // Create books with details
    struct book* book1 = create_book("Harry Potter and the Philosopher's Stone", 14.19, 320, ENGLISH, 0.7, 1997);
    struct book* book2 = create_book("Harry Potter and the Chamber of Secrets", 12.0, 352, ENGLISH, 1.05, 1998);
    struct book* book3 = create_book("Harry Potter and the Prisoner of Azkaban", 38.77, 480, ENGLISH, 1.05, 1999);
    struct book* book4 = create_book("Harry Potter and the Goblet of Fire", 15.08, 752, ENGLISH, 1.18, 2000);
    struct book* book5 = create_book("Harry Potter and the Order of the Phoenix", 14.62, 896, ENGLISH, 1.22, 2003);
    struct book* book6 = create_book("Harry Potter and the Half-Blood Prince", 17.36, 672, ENGLISH, 1.0, 2005);
    struct book* book7 = create_book("Harry Potter and the Deathly Hallows", 17.5, 784, ENGLISH, 1.18, 2007);

    // Add books to the linked list
    add_book(&book_list, book1);
    add_book(&book_list, book2);
    add_book(&book_list, book3);
    add_book(&book_list, book4);
    add_book(&book_list, book5);
    add_book(&book_list, book6);
    add_book(&book_list, book7);

    // Print details of each book in the linked list
    print_books(book_list);

    // Free the allocated memory before exiting
    delete_books(book_list);

    return 0;
}
