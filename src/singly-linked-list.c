#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    // dữ liệu
    int data;
    // con trỏ tới phần tử tiếp theo
    struct Node* next;
} Node;

Node* createNode(int data) {
    // Cấp phát bộ nhớ
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không đủ bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Thêm vào sau list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    // Nếu chưa có node (phần tử) nào
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Thêm vô đầu list
void prepend(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Xoá nút có giá trị data
void deleteNode(Node** head, int data) {
    if (*head == NULL)
        return;

    Node* temp = *head;
    Node* prev = NULL;

    if (temp->data == data) {
        *head = temp->next;
        // Giải phóng bộ nhớ
        free(temp);
        return;
    }

    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Tìm ko thấy Node có data phù hợp
    if (!temp) return;

    prev->next = temp->next;
    free(temp);
}

// In toàn bộ danh sách
void printList(Node* head) {
    Node* temp = head;
    printf("Danh sách: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Giải phóng bộ nhớ
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

    printList(head);

    deleteNode(&head, 20);
    printList(head);

    freeList(&head);
    return 0;
}
