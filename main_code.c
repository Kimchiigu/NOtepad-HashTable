#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

#define TABLE_SIZE 200

void mainMenu(){
	printf(" __    _  _______  _______  _______  _______  _______  ______\n");
    printf("|  |  | ||       ||       ||       ||       ||   _   ||      |\n");
    printf("|   |_| ||   _   ||_     _||    ___||    _  ||  |_|  ||  _    |\n");
    printf("|       ||  | |  |  |   |  |   |___ |   |_| ||       || | |   |\n");
    printf("|  _    ||  |_|  |  |   |  |    ___||    ___||       || |_|   |\n");
    printf("| | |   ||       |  |   |  |   |___ |   |    |   _   ||       |\n");
    printf("|_|  |__||_______|  |___|  |_______||___|    |__| |__||______|\n\n");

    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
}

void menuExit(){
	printf("                            .:^:.. ..^^:..\n");
    printf("                          ...   ...:.     .......    .\n");
    printf("                            .   . ^.   :..:~~77~~~::..::.. ..\n");
    printf("                          ::::..~..:..:~7~.: :^ ~^:~..:....:^~^:^~^\n");
    printf("                        ..      .. .^!777^~~!?~^~7:^::.  .5BGB##&#7.\n");
    printf("                             .:~!!. .:~^.77?P57P7!^::~::?5B&&#GGG5.\n");
    printf("                          .:^~~^^: YJJGBGP5YY7J7!^^^?7YG##P7^7#&B~:\n");
    printf("                        .^~~:  ~J55PJ~:.       ..~JPBBBY^. .:.JG!:!!^..\n");
    printf("                     ..^7~  .::???.         .~!JG&&#J:       .7!:.^77?!^..\n");
    printf("                   .:~7!:. ^Y^.  ..      .!JPB&&#Y:          .  :7!: ~G5?!:.\n");
    printf("                 .:~7?7..~!!       .:..^?YP&&&G7         .        ~J: .BP7J!:.\n");
    printf("               .:^777~^::7^          :JB&&#BG^ .                   .J! !YYYJ?^~!^.\n");
    printf("              .:!JJJJ: :7G.         ?#&&&&B~                         ?5..^!~~!!:.\n");
    printf("             .:!YYY5~ .J&Y      . .5BBBBBG^                           YP  :?J!~!^.\n");
    printf("             .:!J?YJ^..P&!        P&&&&&#!             ..              #7 .^55?^~:.\n");
    printf("              .^7!??^..P#? .  .   ~#&&&&&J:..   ...  .   ..  ...     . 5#..:J57~!:.\n");
    printf("              .:!J~~^.?G#5      .:.^JGBBBP5Y!^75GBGP5PJYPGPP5YYJ?!^    !&:.:??~?~:.\n");
    printf("               .^?5^:.JPBP!       .:::.. .!YYY&&&###&&&&YG##&&&&#B5:   !&:.^~!5J~.\n");
    printf("                .^??:.^^?77..                 ^:.  ..P&G:^&&&&&&&&7    PG ~7:JP7:.\n");
    printf("                .:^7? .~~J?7!                 .      7#^ P&&&&&&G^    :&^ 7?5?!:.\n");
    printf("                  .^J5.:!JPBBY            .:.       ^5^ 7###&#P^      G7..7G5!:.  \n");
    printf("                   .^?5~^~:~PBP~.?!~: ^^7~^!^     .7: ~#&&#5~        ~~:.:PY~:.\n");
    printf("                    .^!5J7..~!B&PJY?J^J?YGY?7!:..^^:?#@&G7.        .~.::^Y!^.\n");
    printf("                     .:^??J!77JY57 .: :?#BYGG!7~:7G&#5~.           ... ^?Y57:.\n");
    printf("                       .:~?JY~..... :.^!J^^!7~7PGPJ~.          ... ^?Y57:.\n");
    printf("                          :~75P~:.  ^^!!^~!JYJ57:..^^....:^!:  ...5GP7^.\n");
    printf("                          ::.:~^7.JY^?77Y5Y7^..::~??5J???5J: :?Y!J5!:.  \n");
    printf("                           .  .^.7G&###B5!^:.:.::......~?J?YB#BY7^:.\n");
    printf("                              .^^YJ5###BG5J7!7JYPPGYJ??YPPPY?7~:.\n");
    printf("                              ..:^~^^........^~!~!!!!~^^::...\n\n\n");
    printf("\t\t\to---------------------------------------------o\n");
    printf("\t\t\t|      Breaking and Overcoming Challenges     |\n");
    printf("\t\t\t|    Through Courage Hardwork and Persistence |\n");
    printf("\t\t\t|           ~~ Bluejackets 23-1 ~~            |\n");
    printf("\t\t\to---------------------------------------------o\n\n\n");
}

void header(){
	printf(" __    _  _______  _______  _______  _______  _______  ______\n");
    printf("|  |  | ||       ||       ||       ||       ||   _   ||      |\n");
    printf("|   |_| ||   _   ||_     _||    ___||    _  ||  |_|  ||  _    |\n");
    printf("|       ||  | |  |  |   |  |   |___ |   |_| ||       || | |   |\n");
    printf("|  _    ||  |_|  |  |   |  |    ___||    ___||       || |_|   |\n");
    printf("| | |   ||       |  |   |  |   |___ |   |    |   _   ||       |\n");
    printf("|_|  |__||_______|  |___|  |_______||___|    |__| |__||______|\n\n");
}

enum UserType { WRITER, READER };

typedef struct Node {
    char nama[200];
    char password[200];
    enum UserType userType;
    struct Node *next;
} Node;

Node *table[TABLE_SIZE];

void initializeTable() {
    memset(table, 0, sizeof(table));
}

unsigned int hash(char *name) {
    unsigned int sum = 0;
    int i = 0;

    while (name[i] != '\0') {
        sum += (unsigned int)name[i];
        i++;
    }

    return sum % TABLE_SIZE;
}

void viewTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *temp = table[i];

        printf("[%d]: ", i);
        while (temp) {
            printf("(%s | %s | %s)->", temp->nama, temp->password, temp->userType == WRITER ? "Writer" : "Reader");
            temp = temp->next;
        }
        printf("\n");
    }
}

Node *createNewNode(char *name, char *password, enum UserType userType) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    strcpy(newNode->nama, name);
    strcpy(newNode->password, password);
    newNode->userType = userType;
    newNode->next = NULL;

    return newNode;
}

void insertData(Node *data) {
    unsigned int index = hash(data->nama);

    while (table[index] != NULL) {
        // Linear probing
        index = (index + 1) % TABLE_SIZE;
    }

    table[index] = data;
}

void promptForNamePassword(char *name, char *password) {
    printf("Input account name [4 - 30 characters, must be unique] (press 0 to exit): ");
    while (1) {
        scanf("%s", name);
        getchar();

        if (strcmp(name, "0") == 0) {
            return;
        }

        if (strlen(name) < 4 || strlen(name) > 30) {
            printf("Account name must be between 4 and 30 characters. Try again: ");
        } else {
            break;
        }
    }

    printf("Input account password [8 - 50 characters, must be alphanumeric] (press 0 to exit): ");
    while (1) {
        char c;
        int length = 0;
        int isAlphanumeric = 1;
        password[0] = '\0';

        while (1) {
            c = _getch();
            if (c == 13) {
                break;
            } else if (c == 8) {
                if (length > 0) {
                    printf("\b \b");
                    length--;
                }
            } else {
                if (isalnum(c) && length < 50) {
                    password[length] = c;
                    length++;
                    printf("*");
                } else {
                    isAlphanumeric = 0;
                }
            }
        }
        password[length] = '\0';

        if (strcmp(password, "0") == 0) {
            return;
        }

        if (length < 8 || length > 50 || !isAlphanumeric) {
            printf("\nPassword must be between 8 and 50 characters and be alphanumeric. Try again: ");
        } else {
            break;
        }
    }
}

int isNameUnique(char *name) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *temp = table[i];
        while (temp) {
            if (strcmp(temp->nama, name) == 0) {
                return 0;
            }
            temp = temp->next;
        }
    }
    return 1;
}

void searchData(char *name) {
    unsigned int index = hash(name);

    while (table[index] != NULL && strcmp(table[index]->nama, name) != 0) {
        // Linear probing
        index = (index + 1) % TABLE_SIZE;
    }

    if (table[index] == NULL) {
        printf("Data not found\n");
    } else {
        printf("Name: %s, Password: %s\n", table[index]->nama, table[index]->password);
    }
}

void deleteData(char *name) {
    unsigned int index = hash(name);

    while (table[index] != NULL && strcmp(table[index]->nama, name) != 0) {
        // Linear probing
        index = (index + 1) % TABLE_SIZE;
    }

    if (table[index] == NULL) {
        printf("Data not found\n");
    } else {
        free(table[index]);
        table[index] = NULL;
        printf("Data deleted\n");
    }
}

void loadDataFromFile() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Failed to open file 'users.txt'. Existing data not loaded.\n");
        return;
    }

    char name[200];
    char password[200];
    int userType;
    while (fscanf(file, "%[^#]#%[^#]#%d", name, password, &userType) != EOF) {
        enum UserType userTypeEnum = (enum UserType)userType;
        insertData(createNewNode(name, password, userTypeEnum));
        printf("Loaded user: Name: %s, Password: %s, UserType: %s\n", name, password, userTypeEnum == WRITER ? "Writer" : "Reader");
    }

    fclose(file);
    printf("Data loaded from 'users.txt'.\n");
}


void saveDataToFile() {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Failed to open file 'users.txt' for writing. Data not saved.\n");
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *temp = table[i];
        while (temp) {
            fprintf(file, "%s#%s#%d\n", temp->nama, temp->password, temp->userType);
            temp = temp->next;
        }
    }

    fclose(file);
    printf("\nSuccessfully created account\n");
}

int login(char *name, char *password) {
    // Mengecek apakah data login sesuai yang ada di hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *temp = table[i];
        while (temp) {
            if (strcmp(temp->nama, name) == 0 && strcmp(temp->password, password) == 0) {
                return temp->userType; // Mengembalikan tipe akun
            }
            temp = temp->next;
        }
    }
    return -1; // Mengembalikan -1 jika tidak ada yang cocok
}

// BOOKLIST.TXT
enum Genre { FANTASY, MYSTERY, HORROR };

typedef struct Book {
    char bookId[6];
    char title[200];
    enum Genre genre;
    char description[200];
    float price;
    char author[200];
    struct Book *next;
} Book;


Book *bookTable[TABLE_SIZE];

void initializeBookTable() {
    memset(bookTable, 0, sizeof(bookTable));
}

unsigned int hashBookId(char *bookId) {
    unsigned int sum = 0;
    int i = 0;

    while (bookId[i] != '\0') {
        sum += (unsigned int)bookId[i];
        i++;
    }

    return sum % TABLE_SIZE;
}

Book *createBook(const char *bookId, const char *title, enum Genre genre, const char *description, float price, const char *author) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        return NULL;
    }

    strcpy(newBook->bookId, bookId);
    strcpy(newBook->title, title);
    newBook->genre = genre;
    strcpy(newBook->description, description);
    newBook->price = price;
    strcpy(newBook->author, author);
    newBook->next = NULL;

    return newBook;
}


void insertBook(Book *book) {
    unsigned int index = hashBookId(book->bookId);

    while (bookTable[index] != NULL) {
        // Linear probing
        index = (index + 1) % TABLE_SIZE;
    }

    book->next = bookTable[index];
    bookTable[index] = book;
}


void viewBooks() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Book *book = bookTable[i];
		
//		puts("===============================================================================================");
//		puts("| ID     | Title          | Genres         | Synopsis             | Price      | Author       |");
//		puts("===============================================================================================");
        while (book != NULL) {
            // Display book information without timestamp
            printf("| %-5s | %-7s | %-7s | %-7s | %-3.2f | %-5s |\n",
                   book->bookId, book->title, book->genre == FANTASY ? "Fantasy" : book->genre == MYSTERY ? "Mystery" : "Horror",
                   book->description, book->price, book->author);
            puts("================================================================");
            book = book->next;
        }
    }
}

void loadBooksFromFile() {
    FILE *file = fopen("booklist.txt", "r");
    if (file == NULL) {
        printf("Failed to open file 'booklist.txt'. Existing book data not loaded.\n");
        return;
    }

    char bookId[6];
    char title[200];
    int genre;
    char description[200];
    float price;
    char author[200];
    
    while (fscanf(file, "%[^#]#%[^#]#%d#%[^#]#%f#%[^#]", bookId, title, &genre, description, &price, author) != EOF) {
        enum Genre genreEnum = (enum Genre)genre;
        Book *newBook = createBook(bookId, title, genreEnum, description, price, author);
        if (newBook != NULL) {
            insertBook(newBook);
            printf("Loaded book: Book ID: %s, Title: %s, Genre: %s, Description: %s, Price: %.2f, Author: %s\n", bookId, title, genreEnum == FANTASY ? "Fantasy" : genreEnum == MYSTERY ? "Mystery" : "Horror", description, price, author);
        }
    }

    fclose(file);
    printf("Book data loaded from 'booklist.txt'.\n");
}


void saveBooksToFile() {
    FILE *file = fopen("booklist.txt", "w");
    if (file == NULL) {
        printf("Failed to open file 'booklist.txt' for writing. Book data not saved.\n");
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        Book *book = bookTable[i];
        while (book) {
            fprintf(file, "%s#%s#%d#%s#%.2f#%s\n", book->bookId, book->title, book->genre, book->description, book->price, book->author);
            book = book->next;
        }
    }

    fclose(file);
    printf("Book data saved to 'booklist.txt'.\n");
}


void displayBookList() {
    system("cls");
    printf("Book List\n");
    printf("==========\n");
    viewBooks(); // Display the book list
    printf("\n");
    system("pause");
}

// Add this function to revise a book
void reviseBook() {
    system("cls");
    viewBooks();
	printf("Revise a Book\n");
    printf("Enter Book ID to revise: ");
    char revisedBookId[6];
    scanf("%s", revisedBookId);
    Book *book = NULL;

    // Find the book to revise
    for (int i = 0; i < TABLE_SIZE; i++) {
        Book *temp = bookTable[i];
        while (temp != NULL) {
            if (strcmp(temp->bookId, revisedBookId) == 0) {
                book = temp;
                break;
            }
            temp = temp->next;
        }
    }

    if (book != NULL) {
        char title[200];
        enum Genre genre;
        char description[200];
        float price;
        char author[200];

        printf("Enter Title: ");
        scanf("%s", title);
        printf("Choose Genre:\n");
        printf("[1] Fantasy\n");
        printf("[2] Mystery\n");
        printf("[3] Horror\n");
        printf("> ");
        int genreChoice;
        scanf("%d", &genreChoice);
        genre = (enum Genre)(genreChoice - 1);
        printf("Enter Description: ");
        scanf("%s", description);
        printf("Enter Price: ");
        scanf("%f", &price);
        printf("Enter Author: ");
        scanf("%s", author);

        // Update the book's information
        strcpy(book->title, title);
        book->genre = genre;
        strcpy(book->description, description);
        book->price = price;
        strcpy(book->author, author);

        // Save the updated book list to the file
        saveBooksToFile();

        printf("\nBook revised and saved in the book list.\n");
    } else {
        printf("\nBook not found. Cannot revise.\n");
    }

    system("pause");
}

void deleteBook(char *bookId) {
    unsigned int index = hashBookId(bookId);

    Book *prev = NULL;
    Book *current = bookTable[index];

    while (current != NULL && strcmp(current->bookId, bookId) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book not found\n");
        return;
    }

    if (prev == NULL) {
        // Book to be deleted is the first in the list
        bookTable[index] = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Book deleted\n");
}


int main() {
    int option = 0;
    char name[200], password[200];
    enum UserType userType = WRITER; // Default user type
	
	initializeBookTable();
    loadBooksFromFile();
    initializeTable();
    loadDataFromFile();

    do {
        system("cls");
        puts("");
        mainMenu();
        printf(">> ");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                system("cls");
                int loginChoice;
                printf("Login\n");
                printf("[1] Writer\n");
                printf("[2] Reader\n");
                printf("> ");
                scanf("%d", &loginChoice);

                if (loginChoice == 1) {
                    userType = WRITER;
                } else if (loginChoice == 2) {
                    userType = READER;
                } else {
                    break;
                }

                printf("Enter your username (0 to exit): ");
                scanf("%s", name);
                if (strcmp(name, "0") == 0) {
                    break;
                }

                printf("Enter your password (0 to exit): ");
                char c;
                int length = 0;
                int isAlphanumeric = 1;
                password[0] = '\0';

                while (1) {
                    c = _getch();
                    if (c == 13) {
                        break;
                    } else if (c == 8) {
                        if (length > 0) {
                            printf("\b \b");
                            length--;
                        }
                    } else {
                        if (isalnum(c) && length < 50) {
                            password[length] = c;
                            length++;
                            printf("*");
                        } else {
                            isAlphanumeric = 0;
                        }
                    }
                }
                password[length] = '\0';

                if (strcmp(password, "0") == 0) {
                    break;
                }

                int loginResult = login(name, password);
				if (loginResult != -1) {
				    userType = loginResult == 0 ? WRITER : READER;
				    printf("\nLogin successful. You are now in the Home menu.\n");
				    system("pause");
				    int homeOption;
				
				    do {
				        system("cls");
				        puts("");
				        if (userType == WRITER) {
				            header();
				            printf("\n");
				            printf("1. Publish a book\n");
				            printf("2. Revise a book\n");
				            printf("3. Delete a book\n");
				            printf("4. Exit (Log out)\n");
				        } else if (userType == READER) {
				            header();
				            printf("\n");
				            printf("1. View a book\n");
				            printf("2. Buy a book\n");
				            printf("3. Top up\n");
				            printf("4. Exit (Log out)\n");
				        }
				        printf("> ");
				        scanf("%d", &homeOption);
				
				        switch (homeOption) {
				            case 1: {
					            if (userType == WRITER) {
					                system("cls");
					                char bookId[6];
					                char title[200];
					                enum Genre genre;
					                char description[200];
					                float price;
					                char author[200];
					
					                printf("Publish a Book\n");
					                printf("Enter Book ID: ");
					                scanf("%s", bookId);
					                printf("Enter Title [only one word]: ");
					                scanf("%s", title);
					                printf("Choose Genre:\n");
					                printf("[1] Fantasy\n");
					                printf("[2] Mystery\n");
					                printf("[3] Horror\n");
					                printf("> ");
					                int genreChoice;
					                scanf("%d", &genreChoice);
					                genre = (enum Genre)(genreChoice - 1);
					                printf("Enter Description [only one word]: ");
					                scanf("%s", description);
					                printf("Enter Price: ");
					                scanf("%f", &price);
					                printf("Enter Author: ");
					                scanf("%s", author);
					
					                Book *newBook = createBook(bookId, title, genre, description, price, author);
					                if (newBook != NULL) {
					                    insertBook(newBook);
					                    printf("\nBook published and stored in the book list.\n");
					                    saveBooksToFile();
					                } else {
					                    printf("\nFailed to publish the book. Memory allocation error.\n");
					                }
					                system("pause");
					            } else if (userType == READER) {
					                viewBooks();
					                system("pause");
					            }
					            break;
					        }
					        case 2: {
					            if (userType == WRITER) {
					                reviseBook();
					            } else if (userType == READER) {
					                viewBooks();
					                printf("Insert Book ID to buy: ");
					                char bookID[10];
									scanf("%s", bookID);
									
									unsigned int index = hashBookId(bookID);
							        Book *prev = NULL;
							        Book *current = bookTable[index];
							
							        while (current != NULL && strcmp(current->bookId, bookID) != 0) {
							            prev = current;
							            current = current->next;
							        }
							
							        if (current == NULL) {
							            printf("Book not found\n");
							        } else {
							            // Proses pembelian buku
							            printf("You have successfully purchased the following book:\n");
							            printf("Book ID: %s\n", current->bookId);
							            printf("Title: %s\n", current->title);
							            printf("Price: $%.2f\n", current->price);
							
							            free(current);
							        }
					                system("pause");
					            }
					            break;
					        }
					        case 3: {
					            if (userType == WRITER) {
					                char bookIdToDelete[6];
					                viewBooks();
					                printf("Enter the Book ID to delete: ");
					                scanf("%s", bookIdToDelete);
					                deleteBook(bookIdToDelete);
					                system("pause");
					            } else if (userType == READER) {
					                int money = 0;
									printf("Input top up amount [1 - 2.000.000]: ");
					                scanf("%d", &money);
					                getchar();
					                
					                printf("Successfully topped up %d\n\n", money);
					                system("pause");
					            }
					            break;
					        }
					        case 4: {
					            if (userType == WRITER) {
					                
					            } else if (userType == READER) {
					                
					            }
					            break;
					        }
				        }
				    } while (homeOption != 4);
				    
				}
				system("pause");
				break;
            }
            case 2: {
                system("cls");
                int createAccountChoice;
                do{
                	printf("What kind of account do you want to make:\n");
	                printf("1. Writer\n");
	                printf("2. Reader\n");
	                printf("[Choose 1 - 2] (press 0 to exit): ");
	                scanf("%d", &createAccountChoice);
	                getchar();
				}while(createAccountChoice != 1 && createAccountChoice != 2 && createAccountChoice != 0);
				

                if (createAccountChoice == 1) {
                    userType = WRITER;
                } else if (createAccountChoice == 2) {
                    userType = READER;
                } else if (createAccountChoice == 0){
                	break;
				}

                promptForNamePassword(name, password);

                if (strcmp(name, "0") == 0 || strcmp(password, "0") == 0) {
                    break;
                }

                if (!isNameUnique(name)) {
                    printf("\nAccount name already exists. Please choose another name.\n");
                } else {
                    insertData(createNewNode(name, password, userType));
					saveDataToFile();
                }
                system("pause");
                break;
            }
            case 3: {
                system("cls");
				menuExit();
                system("pause");
				break;
            }
        }
    } while (option != 3);

    return 0;
}
