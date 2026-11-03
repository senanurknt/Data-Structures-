#include <stdio.h>
#include <stdlib.h>

// Düğüm (Node) Yapısı
struct Node {
    int data;
    struct Node* next;
};

// Diziyi dinamik olarak  Linked List'e dönüştüren fonksiyon
struct Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    // Head için malloc ile bellek ayırma
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Bellek tahsis hatası!\n");
        exit(1);
    }
    head->data = arr[0];
    head->next = NULL;

    struct Node* current = head;

    // Dizinin kalan elemanları için döngüde malloc ile yeni düğümler oluşturma
    for (int i = 1; i < size; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Bellek tahsis hatası!\n");
            exit(1);
        }
        newNode->data = arr[i];
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;
    }

    return head;
}

// Bağlı liste elemanlarını ekrana yazdırma fonksiyonu
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List Elemanlari: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Belleği serbest bırakma (free)
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {

    int arr[] = {5, 12, 28, 43, 99};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Dizi Elemanlari: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");


    struct Node* head = arrayToLinkedList(arr, size);

    printList(head);

    freeList(head);

    return 0;
}
