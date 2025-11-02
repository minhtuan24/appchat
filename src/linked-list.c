#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không đủ bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void prepend(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head)
        (*head)->prev = newNode;
    *head = newNode;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    while (temp && temp->data != data)
        temp = temp->next;
    if (!temp) {
        printf("Không tìm thấy phần tử %d\n", data);
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        *head = temp->next; // Xóa đầu danh sách

    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

void printForward(Node* head) {
    Node* temp = head;
    printf("Danh sách xuôi: ");
    while (temp) {
        printf("%d ", temp->data);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("\n");
}

// Duyệt từ cuối về đầu
void printBackward(Node* head) {
    Node* temp = head;
    if (!temp) return;
    while (temp->next)
        temp = temp->next;

    printf("Danh sách ngược: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void freeList(Node** head) {
    Node* temp = *head;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    prepend(&head, 5);

    printForward(head);
    printBackward(head);

    deleteNode(&head, 20);
    printForward(head);

    freeList(&head);
    return 0;
}
