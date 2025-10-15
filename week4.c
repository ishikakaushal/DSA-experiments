#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* next;
};
struct Node* last = NULL; // global pointer to the last node
// Insert at end
void insert(int value) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 if (last == NULL) {
 newNode->next = newNode; // first node points to itself
 last = newNode;
 } else {
    newNode->next = last->next;
 last->next = newNode;
 last = newNode;
 }
 printf("%d inserted.\n", value);
}
// Display list
void display() {
 if (last == NULL) {
 printf("List is empty.\n");
 return;
 }
 struct Node* temp = last->next;
 printf("Circular Linked List: ");
 do {
 printf("%d ", temp->data);
 temp = temp->next;
 } while (temp != last->next);
 printf("\n");
}
// Delete from beginning
void deleteBeginning() {
 if (last == NULL) {
 printf("List is empty.\n");
 return;
 }
 struct Node* temp = last->next;
 if (last->next == last) { // only one node
 last = NULL;
 } else {
 last->next = temp->next;
 }
 printf("%d deleted from beginning.\n", temp->data);
 free(temp);
}
// Delete from end
void deleteEnd() {
 if (last == NULL) {
 printf("List is empty.\n");
 return;
 }
 struct Node* temp = last->next;
 if (last->next == last) { // only one node
 printf("%d deleted from end.\n", last->data);
 free(last);
 last = NULL;
 return;
 }
 while (temp->next != last) {
 temp = temp->next;
 }
 temp->next = last->next;
  printf("%d deleted from end.\n", last->data);
 free(last);
 last = temp;
}
// Delete a given element
void deleteElement(int key) {
 if (last == NULL) {
 printf("List is empty.\n");
 return;
 }
 struct Node* curr = last->next;
 struct Node* prev = last;

 // Traverse until we come back to start
 do {
 if (curr->data == key) {
 if (curr == last && curr == last->next) { // only one node
 last = NULL;
 } else {
 prev->next = curr->next;
 if (curr == last) {
 last = prev; // update last if deleting last node
 }
 }
 printf("%d deleted.\n", key);
 free(curr);
 return;
  }
 prev = curr;
 curr = curr->next;
 } while (curr != last->next);
 printf("%d not found in list.\n", key);
}
// Main function to test
int main() {
 int choice, value;
 while (1) {
 printf("\n--- Circular Linked List Menu ---\n");
 printf("1. Insert\n");
 printf("2. Delete from Beginning\n");
 printf("3. Delete from End\n");
 printf("4. Delete given Element\n");
 printf("5. Display\n");
 printf("6. Exit\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value to insert: ");
 scanf("%d", &value);
 insert(value);
 break;
 case 2:
 deleteBeginning();
 break;
 case 3:
 deleteEnd();
 break;
 case 4:
 printf("Enter element to delete: ");
 scanf("%d", &value);
 deleteElement(value);
 break;
 case 5:
 display();
 break;
 case 6:
 exit(0);
 default:
 printf("Invalid choice.\n");
 }
 }
 return 0;
}