#include <stdio.h>
    
struct Node {
    char letter;
    struct Node* next;
};

void initializeEnd(struct Node* newNode, char newLetter) {
    newNode->letter = newLetter;
    newNode->next = NULL;
}

void initializeNodeWithNext(struct Node* newNode, char newLetter, struct Node* nextNode) {
    newNode->letter = newLetter;
    newNode->next = nextNode;
}

void incorporateNewNode(struct Node*newNode, struct Node* previousNode, struct Node*nextNode, char newLetter) {
    previousNode->next = newNode;
    newNode->letter = newLetter;
    newNode->next = nextNode;
}

void changeNodeNext(struct Node*currentNode, struct Node*newNode) {
    currentNode->next = newNode;
}


void printList(struct Node* node) {
    while(node != NULL) {
        printf("Letter is %c\n", node->letter);
        node = node->next;
    }
}

int main() {
    printf("Hello word, starting our linked list ...\n");

    struct Node head;
    struct Node middle;
    struct Node tail;

    struct Node newComer;
    struct Node bisHead;
    struct Node bisTail;

    initializeNodeWithNext(&head, 'a', &middle);
    initializeNodeWithNext(&middle, 'c', &tail);
    initializeEnd(&tail, 'd');

    // Add in the middle
    incorporateNewNode(&newComer, &head, &middle, 'b');
    
    // Change head
    initializeNodeWithNext(&bisHead, 'z', &head);
    
    // Change tail
    initializeEnd(&bisTail, 'e');
    changeNodeNext(&tail, &bisTail);


    printList(&bisHead);

    return 0;
}