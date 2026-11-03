#include <stdio.h>
#include <stdlib.h>

// Düğüm  Yapısı
struct Node {
    int data;
    struct Node* next;
};

//  Düğüm Oluşturma 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Bellek tahsis hatası!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Bağlı Liste Haline Getirme
struct Node* createListFromArray(int arr[], int size) {
    if (size == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

//  Insert
void insertNode(struct Node** head_ref, int newData) {
    struct Node* newNode = createNode(newData);
    
    // Liste boşsa yeni düğüm head olur
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d degeri listeye eklendi.\n", newData);
}

// Delete
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // Silinecek eleman head düğümündeyse
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("%d degeri listeden silindi.\n", key);
        return;
    }

    // Silinecek elemanı arama
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Eleman listede bulunamadıysa
    if (temp == NULL) {
        printf("%d degeri listede bulunamadi, silinemedi.\n", key);
        return;
    }

    // Bağlantıyı güncelle ve belleği serbest bırak
    prev->next = temp->next;
    free(temp);
    printf("%d degeri listeden silindi.\n", key);
}

//Search
int searchNode(struct Node* head, int key) {
    struct Node* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->data == key) {
            return index; // Bulunduğu indeksi döndürür
        }
        current = current->next;
        index++;
    }
    return -1; // Bulunamadıysa -1 döndürür
}

//  Listeyi Ekrana Yazdırma
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Liste: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Bellek Temizleme
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
   
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("--- Diziden Bagli Liste Olusturma ---\n");
    struct Node* head = createListFromArray(arr, size);
    printList(head);
    printf("\n");

    printf("---  (Insert) ---\n");
    insertNode(&head, 60);
    printList(head);
    printf("\n");


    printf("--- (Search) ---\n");
    int searchVal = 30;
    int result = searchNode(head, searchVal);
    if (result != -1) {
        printf("%d degeri listenin %d. indeksinde bulundu.\n", searchVal, result);
    } else {
        printf("%d degeri listede bulunamadi.\n", searchVal);
    }
    printf("\n");

    //
    printf("---  (Delete) ---\n");
    deleteNode(&head, 20);
    printList(head);
    printf("\n");

    // Belleği temizleme
    freeList(head);

    return 0;
}
