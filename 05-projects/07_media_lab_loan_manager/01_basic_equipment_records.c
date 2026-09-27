/*
=============================================================================
FILE: 01_basic_equipment_records.c

PURPOSE: Allows Media Lab staff to add equipment records to a file and display
         all saved records. Each record stores an item ID, asset tag, and status.
=============================================================================
*/

#include <stdio.h>
#include <string.h>

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

// Function prototypes
void addItem(void);
void displayItems(void);


int main(void) {

/* === STEP 1: ADD EQUIPMENT RECORDS ===

addItem() handles the user input and saves each item
to the file.

The function is called three times to demonstrate adding
at least three equipment records.
*/

    addItem();
    addItem();
    addItem();
    struct Item item; 

/* === STEP 2: DISPLAY ALL EQUIPMENT RECORDS ===

displayItems() reads the saved records from the file
and displays them.
*/

    displayItems();

    return 0;
}

/* === ADD ITEM ===

This function receives no parameters and returns no value.

It gets the item information directly from the user and
appends the record to assets.txt.

Opening the file with "a" adds new records to the end.
If the file does not already exist, it is created.
*/

void addItem(void) {

    struct Item item;

    FILE *fptr = fopen("assets.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter item ID: ");
    scanf("%d", &item.id);

    printf("Enter asset tag: ");
    scanf("%19s", item.assetTag);

    printf("Enter status (Available / Loaned / Under Maintenance): ");

    getchar(); // Clear the leftover newline from scanf()

    fgets(item.status, sizeof(item.status), stdin);

    // Remove the newline character added by fgets()
    item.status[strcspn(item.status, "\n")] = '\0';


    // Append the item record to the file
    fprintf(fptr, "Item ID: %d\n", item.id);
    fprintf(fptr, "Asset Tag: %s\n", item.assetTag);
    fprintf(fptr, "Status: %s\n", item.status);

    fclose(fptr);

    printf("Item details saved to file successfully.\n\n");
}


/* === DISPLAY ITEMS ===

This function receives no parameters and returns no value.

It opens assets.txt for reading and reads one complete
Item record at a time.

    %d       -> reads the item ID
    %19s     -> reads the asset tag
    %29[^\n] -> reads the status until a newline is reached

The loop continues until there are no more complete
records to read.
*/

void displayItems(void) {

    struct Item item;

    FILE *fptr = fopen("assets.txt", "r");

    if (fptr == NULL) {
        printf("No file found.\n");
        return;
    }

    printf("=== Asset List ===\n");

    while (fscanf(fptr,
        "Item ID: %d\nAsset Tag: %19s\nStatus: %29[^\n]\n",
        &item.id, item.assetTag, item.status) == 3) {

        printf("Item ID: %d\n", item.id);
        printf("Asset Tag: %s\n", item.assetTag);
        printf("Status: %s\n", item.status);
        printf("-------------------\n");
    }

    fclose(fptr);
}