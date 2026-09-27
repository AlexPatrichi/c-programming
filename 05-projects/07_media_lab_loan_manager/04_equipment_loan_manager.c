/*
=============================================================================
FILE: 04_equipment_loan_manager.c

PURPOSE: Manages Media Lab equipment records using an in-memory array,
         file persistence, and a menu for adding, viewing, searching,
         updating, deleting, and saving equipment records.
=============================================================================
*/

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100


/* === ITEM STRUCTURE ===

The Item structure groups the information that belongs
to one piece of equipment:

    id       -> unique item number
    assetTag -> equipment tag, such as "CAM-104"
    status   -> Available, Loaned, or Under Maintenance
*/

struct Item {
    int id;
    char assetTag[20];
    char status[30];
};


// Global data shared by the program
const char FILE_NAME[] = "assets.txt";

struct Item items[MAX_ITEMS];
int itemCount = 0;


// Function prototypes
void clearNewline(char text[]);
void loadItemsFromFile(void);
void saveItemsToFile(void);

int searchItemById(int id);
int addItem(int id, char assetTag[], char status[]);
void displayItems(void);

int updateItem(int id, const char newAssetTag[], const char newStatus[]);
int deleteItem(int id);


int main(void) {

/* === STEP 1: LOAD SAVED EQUIPMENT RECORDS ===

When the program starts, existing records are loaded
from assets.txt into the items[] array.

    assets.txt
        ↓
    items[]

The program then works with the records stored in memory.
*/

    loadItemsFromFile();


/* === STEP 2: DISPLAY THE MAIN MENU ===

The menu repeats until the user chooses option 7.

    1 -> Add
    2 -> View
    3 -> Search
    4 -> Update
    5 -> Delete
    6 -> Save
    7 -> Exit
*/

    int choice;
    int id;

    char assetTag[20];
    char status[30];

    do {

        printf("\n=== Media Lab Equipment System ===\n");
        printf("1. Add item\n");
        printf("2. View all items\n");
        printf("3. Search item\n");
        printf("4. Update item\n");
        printf("5. Delete item\n");
        printf("6. Save\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);


/* === STEP 3: PROCESS THE SELECTED MENU OPTION === */

        if (choice == 1) {

            printf("Enter item ID: ");
            scanf("%d", &id);

            printf("Enter asset tag: ");
            scanf("%19s", assetTag);

            printf("Enter status (Available / Loaned / Under Maintenance): ");

            getchar();

            fgets(status, sizeof(status), stdin);
            clearNewline(status);

            addItem(id, assetTag, status);
        }

        else if (choice == 2) {

            displayItems();
        }

        else if (choice == 3) {

            printf("Enter item ID to search: ");
            scanf("%d", &id);

            int index = searchItemById(id);

            if (index != -1) {

                printf("Equipment record found:\n");
                printf("Item ID: %d\n", items[index].id);
                printf("Asset Tag: %s\n", items[index].assetTag);
                printf("Status: %s\n", items[index].status);
                printf("Record position: %d\n", index);

            } else {

                printf("Equipment record with ID %d not found.\n", id);
            }
        }

        else if (choice == 4) {

            printf("Enter item ID to update: ");
            scanf("%d", &id);

            printf("Enter new asset tag: ");
            scanf("%19s", assetTag);

            printf("Enter new status (Available / Loaned / Under Maintenance): ");

            getchar();

            fgets(status, sizeof(status), stdin);
            clearNewline(status);

            updateItem(id, assetTag, status);
        }

        else if (choice == 5) {

            printf("Enter item ID to delete: ");
            scanf("%d", &id);

            deleteItem(id);
        }

        else if (choice == 6) {

            saveItemsToFile();
        }

        else if (choice == 7) {

            saveItemsToFile();

            printf("Program closed.\n");
        }

        else {

            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}


/* === CLEAR NEWLINE ===

fgets() normally stores the newline entered by the user.

This helper function replaces that newline with '\0'
so that only the entered text remains.
*/

void clearNewline(char text[]) {

    text[strcspn(text, "\n")] = '\0';
}


/* === LOAD ITEMS FROM FILE ===

This function opens assets.txt and loads the saved
equipment records into the items[] array.

itemCount keeps track of how many records were loaded.

If the file does not exist yet, the function simply
returns and the program starts with an empty array.
*/

void loadItemsFromFile(void) {

    FILE *fptr = fopen(FILE_NAME, "r");

    if (fptr == NULL) {
        return;
    }

    itemCount = 0;

    while (itemCount < MAX_ITEMS &&
           fscanf(fptr,
               "Item ID: %d\nAsset Tag: %19s\nStatus: %29[^\n]\n",
               &items[itemCount].id,
               items[itemCount].assetTag,
               items[itemCount].status) == 3) {

        itemCount++;
    }

    fclose(fptr);
}


/* === SAVE ITEMS TO FILE ===

This function writes all records currently stored in
items[] back to assets.txt.

Opening the file with "w" replaces the old file contents
with the current in-memory records.

    items[]
        ↓
    assets.txt
*/

void saveItemsToFile(void) {

    FILE *fptr = fopen(FILE_NAME, "w");

    if (fptr == NULL) {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {

        fprintf(fptr, "Item ID: %d\n", items[i].id);
        fprintf(fptr, "Asset Tag: %s\n", items[i].assetTag);
        fprintf(fptr, "Status: %s\n", items[i].status);
    }

    fclose(fptr);

    printf("Data saved successfully.\n");
}


/* === SEARCH ITEM BY ID ===

This function searches the in-memory items[] array
for a matching item ID.

It returns:

    0, 1, 2, ... -> position of the record
    -1           -> record was not found
*/

int searchItemById(int id) {

    for (int i = 0; i < itemCount; i++) {

        if (items[i].id == id) {
            return i;
        }
    }

    return -1;
}


/* === ADD ITEM ===

This function adds a new record to the in-memory array.

Before adding the item, it checks:

    1. The array still has space.
    2. The item ID does not already exist.

It returns:

    1 -> item was added
    0 -> item was not added
*/

int addItem(int id, char assetTag[], char status[]) {

    if (itemCount >= MAX_ITEMS) {
        printf("Storage is full. Item not added.\n");
        return 0;
    }

    if (searchItemById(id) != -1) {
        printf("An item with this ID already exists. Item not added.\n");
        return 0;
    }

    items[itemCount].id = id;

    strcpy(items[itemCount].assetTag, assetTag);
    strcpy(items[itemCount].status, status);

    itemCount++;

    printf("Item added successfully.\n");

    return 1;
}


/* === DISPLAY ITEMS ===

This function displays every equipment record currently
stored in the in-memory array.
*/

void displayItems(void) {

    if (itemCount == 0) {
        printf("No equipment records available.\n");
        return;
    }

    printf("\n=== Asset List ===\n");

    for (int i = 0; i < itemCount; i++) {

        printf("Item ID: %d\n", items[i].id);
        printf("Asset Tag: %s\n", items[i].assetTag);
        printf("Status: %s\n", items[i].status);
        printf("-------------------\n");
    }
}


/* === UPDATE ITEM ===

This function searches for the requested item ID.

If the record exists, its asset tag and status are
changed directly in the in-memory array.

It returns:

    1 -> record was updated
    0 -> record was not found
*/

int updateItem(int id, const char newAssetTag[], const char newStatus[]) {

    int index = searchItemById(id);

    if (index == -1) {
        printf("Equipment record with ID %d not found. Update cancelled.\n", id);
        return 0;
    }

    strcpy(items[index].assetTag, newAssetTag);
    strcpy(items[index].status, newStatus);

    printf("Equipment record updated successfully.\n");

    return 1;
}


/* === DELETE ITEM ===

This function searches for the requested item ID.

If the item is found, every record after it is shifted
one position to the left.

For example:

    [Item A] [Item B] [Item C] [Item D]
                  ↓ delete
    [Item A] [Item C] [Item D]

itemCount is then reduced by 1.

The updated array is written to the file when the user
chooses Save or Exit.

It returns:

    1 -> record was deleted
    0 -> record was not found
*/

int deleteItem(int id) {

    int index = searchItemById(id);

    if (index == -1) {
        printf("Equipment record with ID %d not found. Delete cancelled.\n", id);
        return 0;
    }

    for (int i = index; i < itemCount - 1; i++) {
        items[i] = items[i + 1];
    }

    itemCount--;

    printf("Equipment record deleted successfully.\n");

    return 1;
}