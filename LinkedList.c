#include <stdio.h>
#include <stdlib.h>

// node yapısı 
struct Node {
    int data;
    struct Node* next;
};


struct Node* arrayToList(int arr[], int size) {
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        insertAtEnd(&head, arr[i]);
    }
    return head;
}
// Sona eleman ekleme (Insert)
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Eleman silme (Delete)
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Eğer silinecek eleman headse
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("%d degeri listeden silindi.\n", key);
        return;
    }

    // Elemanı listede ara
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Eğer eleman listede yoksa
    if (temp == NULL) {
        printf("%d degeri listede bulunamadi.\n", key);
        return;
    }

    // Bağlantıyı kopar ve belleği temizle
    prev->next = temp->next;
    free(temp);
    printf("%d degeri silindi.\n", key);
}

// Eleman arama (Search)
int searchNode(struct Node* head, int key) {
    struct Node* current = head;
    int index = 0;
    while (current != NULL) {
        if (current->data == key)
            return index; // Bulunduysa 
        current = current->next;
        index++;
    }
    return -1; // Bulunamadıysa -1 döndür
}

// Listeyi ekrana yazdırma
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Bagli Liste: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
