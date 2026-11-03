#include <stdio.h>
#include <stdlib.h>

// Düğüm (Node) Yapısı
struct Node {
    int data;
    struct Node* next;
};

// Diziyi Malloc ile Circular Linked List'e Dönüştüren Fonksiyon
struct Node* createCircularList(int arr[], int size) {
    if (size == 0) return NULL;

    // İlk düğümü (head) oluşturma
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Bellek hatasi!\n");
        exit(1);
    }
    head->data = arr[0];
    head->next = NULL;

    struct Node* current = head;

    // Kalan elemanları oluşturup birbirine bağlama
    for (int i = 1; i < size; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Bellek hatasi!\n");
            exit(1);
        }
        newNode->data = arr[i];
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;
    }

    // Son düğümün next'ini başa (head) bağlayarak dairesel yapıyoruz
    current->next = head;

    return head;
}

// Dairesel Liste Elemanlarını Ekrana Yazdırma
void printCircularList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    printf("Circular Linked List: ");
    
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(HEAD: %d)\n", head->data);
}

// Belleği Temizleme (free)
void freeCircularList(struct Node* head) {
    if (head == NULL) return;

    // Dairesel döngüyü kırıp normal liste gibi temizlemek için
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = NULL;

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

    // Dairesel liste oluşturma
    struct Node* head = createCircularList(arr, size);

    // Listeyi ekrana yazdırma
    printCircularList(head);

    // Belleği serbest bırakma
    freeCircularList(head);

    return 0;
}
