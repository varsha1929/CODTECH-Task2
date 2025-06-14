//This is the program to showcase the operations (Insertions,Deletion,Creation) of singly linked list.
#include <stdio.h>
#include <stdlib.h>

//Node
struct Node {
    int data;
    struct Node* nxt;
};

//function to create a node
struct Node* create_new_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->nxt = NULL;
    return new_node;
}

//function to insert a node at the beginning.
void push(struct Node** head, int data) {
    struct Node* new_node = create_new_node(data);
    new_node->nxt = *head;
    *head = new_node;
}

//function to insert a node at the end.
void push_back(struct Node** head, int data) {
    struct Node* new_node = create_new_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->nxt != NULL) {
        temp = temp->nxt;
    }
    temp->nxt = new_node;
}

//function to insert a node at a given position
void push_at(struct Node** head, int data, int pos) {
    if (pos == 0) {
        push(head, data);
        return;
    }
    struct Node* new_node = create_new_node(data);
    struct Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->nxt;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(new_node);
        return;
    }
    new_node->nxt = temp->nxt;
    temp->nxt = new_node;
}

//function to print the list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->nxt;
    }
    printf("NULL\n");
}

//function to delete a node from beginning.
void pop(struct Node** head) {
    if (*head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->nxt;
    free(temp);
}

//function to delete a node from end.
void pop_back(struct Node** head) {
    if (*head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->nxt == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->nxt->nxt != NULL) {
        temp = temp->nxt;
    }
    free(temp->nxt);
    temp->nxt = NULL;
}

//function to delete a node from a position.
void pop_at(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    if (pos == 0) {
        pop(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->nxt;
    }
    if (temp == NULL || temp->nxt == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node* next = temp->nxt->nxt;
    free(temp->nxt);
    temp->nxt = next;
}
//Main function
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        system("cls");
        printf("\n==== Singly Linked List Menu ====\n");
        printf("[1] Insert at Front\n");
        printf("[2] Insert at End\n");
        printf("[3] Insert at Position\n");
        printf("[4] Delete from Front\n");
        printf("[5] Delete from End\n");
        printf("[6] Delete from Position\n");
        printf("[7] Display List\n");
        printf("[0] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                push(&head, data);
                printf("Updated List : ");
                print(head);
                printf("\n\n");
                system("pause");
                break;

            case 2:
                system("cls");
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                push_back(&head, data);
                printf("Updated List : ");
                print(head);
                printf("\n\n");
                system("pause");
                break;

            case 3:
                system("cls");
                printf("Enter data and position (space-separated) : ");
                scanf("%d %d", &data, &pos);
                push_at(&head, data, pos);
                print(head);
                printf("\n\n");
                system("pause");
                break;

            case 4:
                system("cls");
                pop(&head);
                printf("Updated List : ");
                print(head);
                printf("\n\n");
                system("pause");
                break;

            case 5:
                system("cls");
                pop_back(&head);
                printf("Updated List : ");
                print(head);
                printf("\n\n");
                system("pause");
                break;

            case 6:
                system("cls");
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                pop_at(&head, pos);
                printf("Updated List : ");
                print(head);
                printf("\n\n");
                system("pause");
                break;

            case 7:
                system("cls");
                printf("Linked List: ");
                print(head);
                printf("\n\n");
                system("pause");
                break;

            case 0:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
