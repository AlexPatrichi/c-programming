/*
=============================================================================
FILE: 02_equipment_search.c

PURPOSE: Allows Media Lab staff to add, display, and search equipment records.
         The program also prevents duplicate item IDs from being saved.
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
int idExists(int id);
void addItem(int id, char assetTag[], char status[]);
void displayItems(void);
void searchItemById(int id);


int main(void) {

/* === STEP 1: GET ITEM DETAILS ===

Unlike the basic_equipment_records version, the item details are now collected
inside main().

These values are then passed as arguments to addItem().
*/

    int id;
    char assetTag[20];
    char status[30];

    printf("Enter item ID: ");
    scanf("%d", &id);

    printf("Enter asset tag: ");
    scanf("%19s", assetTag);

    printf("Enter status (Available / Loaned / Under Maintenance): ");

    getchar(); // Clear the leftover newline from scanf()

    fgets(status, sizeof(status), stdin);

    // Remove the newline character added by fgets()
    status[strcspn(status, "\n")] = '\0';


/* === STEP 2: ADD THE EQUIPMENT RECORD ===

The values entered by the user are passed to addItem()
as arguments.

Before adding the record, addItem() checks whether the
item ID already exists.
*/

    addItem(id, assetTag, status);


/* === STEP 3: DISPLAY ALL EQUIPMENT RECORDS === */

    displayItems();


/* === STEP 4: SEARCH FOR AN ITEM BY ID ===

The user enters an ID and the value is passed to
searchItemById().

The function searches the file and displays the matching
equipment record if it is found.
*/

    int searchId;

    printf("\nEnter item ID to search: ");
    scanf("%d", &searchId);

    searchItemById(searchId);

    return 0;
}


/* === CHECK FOR DUPLICATE ID ===

This function searches the file for an existing item ID.

It returns:

    1 -> ID already exists
    0 -> ID does not exist
*/

int idExists(int id) {

    struct Item item;

    FILE *fptr = fopen("assets.txt", "r");

    if (fptr == NULL) {
        return 0;
    }

    while (fscanf(fptr,
        "Item ID: %d\nAsset Tag: %19s\nStatus: %29[^\n]\n",
        &item.id, item.assetTag, item.status) == 3) {

        if (item.id == id) {
            fclose(fptr);
            return 1;
        }
    }

    fclose(fptr);

    return 0;
}


/* === ADD ITEM ===

Unlike the Grade D version, this function receives the item
information through parameters instead of asking the user
for the information itself.

Before adding the item, idExists() checks whether the ID
is already stored in the file.

If the ID already exists, the new record is not added.
*/

void addItem(int id, char assetTag[], char status[]) {

    if (idExists(id)) {
        printf("An item with this ID already exists. Item not added.\n\n");
        return;
    }

    FILE *fptr = fopen("assets.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fptr, "Item ID: %d\n", id);
    fprintf(fptr, "Asset Tag: %s\n", assetTag);
    fprintf(fptr, "Status: %s\n", status);

    fclose(fptr);

    printf("Item details saved to file successfully.\n\n");
}


/* === DISPLAY ITEMS ===

This function reads each equipment record from the file
and displays it.
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


/* === SEARCH ITEM BY ID ===

This function receives an item ID as a parameter and searches
through the saved equipment records.

If a matching ID is found, the equipment record is displayed.
Otherwise, a "not found" message is shown.
*/

void searchItemById(int id) {

    struct Item item;
    int found = 0;

    FILE *fptr = fopen("assets.txt", "r");

    if (fptr == NULL) {
        printf("No file found.\n");
        return;
    }

    while (fscanf(fptr,
        "Item ID: %d\nAsset Tag: %19s\nStatus: %29[^\n]\n",
        &item.id, item.assetTag, item.status) == 3) {

        if (item.id == id) {

            printf("\nEquipment record found:\n");
            printf("Item ID: %d\n", item.id);
            printf("Asset Tag: %s\n", item.assetTag);
            printf("Status: %s\n", item.status);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Equipment record with ID %d not found.\n", id);
    }

    fclose(fptr);
}