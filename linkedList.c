#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
    } ListNode;

ListNode* newListNode(int data) {
    ListNode* node = malloc(sizeof *node);
    assert(node != NULL);
    node-> data = data;
    return node;
}

// Insert node
void insert(ListNode* targetNode, int value) {
    ListNode* temp = malloc(sizeof *temp);
    temp-> data = value;
    temp-> link = targetNode-> link;
    targetNode-> link = temp;
}

void printList(ListNode* firstNode, int times) {
    for (int i = 0; i < times; i++) {
        printf("%d ", firstNode-> data);
        firstNode = firstNode-> link;
    }
    printf("\n");
}

int main(void) {
    int terms, target, insertion, value = 0;
    scanf("%d", &terms);

    ListNode* firstNode = NULL;
    ListNode* lastNode = NULL;
    for (int i = 0; i < terms; i++) {
        scanf("%d", &value);
        if (firstNode == NULL) {
            firstNode = newListNode(value);
            lastNode = firstNode;
        } else {
            ListNode* newNode = newListNode(value);
            (*lastNode).link = newNode;
            lastNode = newNode;
        }
    }

    scanf("%d", &target);
    scanf("%d", &insertion);
    int currentIndex = 0;
    ListNode* currentNode = firstNode;
    while (currentNode != NULL) {
        if (currentNode-> data == target) {
            printf("%d\n", currentIndex);
            insert(currentNode, insertion);
            break;
        } else {
            currentIndex++;
            currentNode = currentNode-> link;
            continue;
        }
    }
    printList(firstNode, terms + 1);
    
    return  0;
}
