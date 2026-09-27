/*
=============================================================================
FILE: 03_equipment_update.c

PURPOSE: Allows Media Lab staff to add, display, search, and update equipment
         records using functions that return useful values.
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


// Function prototypes
int idExists(int id);
int addItem(int id, char assetTag[], char status[]);
void displayItems(void);
int searchItemById(int id);
int updateItem(int id, const char newAssetTag[], const char newStatus[]);


int main(void) {

/* === STEP 1: GET ITEM DETAILS ===

The item details are collected inside main() and passed
as arguments to addItem().

Unlike the equipment_search version, addItem() now returns:

    1 -> item was added
    0 -> item was not added
*/

    int id;
    char assetTag[20];
    char status[30];

    int addResult;

    printf("Enter item ID: ");
    scanf("%d", &id);

    printf("Enter asset tag: ");
    scanf("%19s", assetTag);

    printf("Enter status (Available / Loaned / Under Maintenance): ");

    getchar();

    fgets(status, sizeof(status), stdin);
    status[strcspn(status, "\n")] = '\0';

    addResult = addItem(id, assetTag, status);

    if (addResult == 1) {
        printf("Add function returned 1: item was added.\n");
    } else {
        printf("Add function returned 0: item was not added.\n");
    }


/* === STEP 2: DISPLAY ALL EQUIPMENT RECORDS === */

    displayItems();


/* === STEP 3: SEARCH FOR AN ITEM BY ID ===

searchItemById() searches through the file and returns:

    0, 1, 2, ... -> position of the record
    -1           -> record was not found
*/

    int searchId;
    int searchResult;

    printf("\nEnter item ID to search: ");
    scanf("%d", &searchId);

    searchResult = searchItemById(searchId);

    if (searchResult != -1) {
        printf("Search function returned index: %d\n", searchResult);
    } else {
        printf("Search function returned -1.\n");
    }


/* === STEP 4: UPDATE AN EQUIPMENT RECORD ===

The user enters the ID of the item to update, together
with a new asset tag and status.

updateItem() reads all records into an array, finds the
matching ID, updates the record, and rewrites the file.

It returns:

    1 -> record was updated
    0 -> record was not updated
*/

    int updateId;
    char newAssetTag[20];
    char newStatus[30];

    int updateResult;

    printf("\nEnter item ID to update: ");
    scanf("%d", &updateId);

    printf("Enter new asset tag: ");
    scanf("%19s", newAssetTag);

    printf("Enter new status (Available / Loaned / Under Maintenance): ");

    getchar();

    fgets(newStatus, sizeof(newStatus), stdin);
    newStatus[strcspn(newStatus, "\n")] = '\0';

    updateResult = updateItem(updateId, newAssetTag, newStatus);

    if (updateResult == 1) {
        printf("Update function returned 1: record was updated.\n");
    } else {
        printf("Update function returned 0: record was not updated.\n");
    }


/* === STEP 5: DISPLAY UPDATED EQUIPMENT RECORDS === */

    displayItems();

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

This function adds a new equipment record to the file.

Before adding the item, idExists() checks whether the ID
is already stored.

It returns:

    1 -> item was added successfully
    0 -> duplicate ID or file error
*/

int addItem(int id, char assetTag[], char status[]) {

    if (idExists(id)) {
        printf("An item with this ID already exists. Item not added.\n\n");
        return 0;
    }

    FILE *fptr = fopen("assets.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    fprintf(fptr, "Item ID: %d\n", id);
    fprintf(fptr, "Asset Tag: %s\n", assetTag);
    fprintf(fptr, "Status: %s\n", status);

    fclose(fptr);

    printf("Item details saved to file successfully.\n\n");

    return 1;
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

    printf("\n=== Asset List ===\n");

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

This function searches the file for a matching item ID.

An index variable keeps track of the position of each record:

    first record  -> index 0
    second record -> index 1
    third record  -> index 2

It returns the index if the item is found, or -1 if the
item is not found.
*/

int searchItemById(int id) {

    struct Item item;

    int index = 0;

    FILE *fptr = fopen("assets.txt", "r");

    if (fptr == NULL) {
        printf("No file found.\n");
        return -1;
    }

    while (fscanf(fptr,
        "Item ID: %d\nAsset Tag: %19s\nStatus: %29[^\n]\n",
        &item.id, item.assetTag, item.status) == 3) {

        if (item.id == id) {

            printf("Equipment record found:\n");
            printf("Item ID: %d\n", item.id);
            printf("Asset Tag: %s\n", item.assetTag);
            printf("Status: %s\n", item.status);

            fclose(fptr);

            return index;
        }

        index++;
    }

    fclose(fptr);

    printf("Equipment record with ID %d not found.\n", id);

    return -1;
}


/* === UPDATE ITEM ===

This function first reads all equipment records from the
file into an array of Item structures.

    assets.txt
        ↓
    items[]

The array is searched for the requested ID.

If the item is found, its asset tag and status are changed
in memory.

    find ID
       ↓
    update items[i]
       ↓
    rewrite assets.txt

Opening the file with "w" replaces the old file contents
with the updated records.

The function returns:

    1 -> record was updated
    0 -> record was not found or a file error occurred
*/

int updateItem(int id, const char newAssetTag[], const char newStatus[]) {

    struct Item items[MAX_ITEMS];

    int count = 0;
    int found = 0;

    FILE *fptr = fopen("assets.txt", "r");

    if (fptr == NULL) {
        printf("No file found.\n");
        return 0;
    }


    // Load all records into the array
    while (count < MAX_ITEMS &&
           fscanf(fptr,
               "Item ID: %d\nAsset Tag: %19s\nStatus: %29[^\n]\n",
               &items[count].id,
               items[count].assetTag,
               items[count].status) == 3) {

        count++;
    }

    fclose(fptr);


    // Find and update the requested item
    for (int i = 0; i < count; i++) {

        if (items[i].id == id) {

            strcpy(items[i].assetTag, newAssetTag);
            strcpy(items[i].status, newStatus);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Equipment record with ID %d not found. Update cancelled.\n", id);
        return 0;
    }


    // Rewrite the file with all records, including the updated one
    fptr = fopen("assets.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    for (int i = 0; i < count; i++) {

        fprintf(fptr, "Item ID: %d\n", items[i].id);
        fprintf(fptr, "Asset Tag: %s\n", items[i].assetTag);
        fprintf(fptr, "Status: %s\n", items[i].status);
    }

    fclose(fptr);

    printf("Equipment record updated successfully.\n\n");

    return 1;
}