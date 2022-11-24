#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *left, *right;
} node_t;

int num;
int count = 0;

void inorder(node_t* node) {
    if (node) {
        inorder(node-> left);
        if (count < num - 1) {
            printf("%d ", node-> data);
            count++;
        } else printf("%d", node-> data);
        inorder(node-> right);
    }
}

void preorder(node_t* node) {
    if (node) {
        if (count < num - 1) {
            printf("%d ", node-> data);
            count++;
        } else printf("%d", node-> data);
        preorder(node-> left);
        preorder(node-> right);
    }
}

void postorder(node_t* node) {
    if (node) {
        postorder(node-> left);
        postorder(node-> right);
        if (count < num - 1) {
            printf("%d ", node-> data);
            count++;
        } else printf("%d", node-> data);
    }
}

int main() {
    scanf("%d", &num);
    node_t* tree[num];
    for (int i = 0; i < num; i++) {
        int tmp;
        scanf("%d", &tmp);
        tree[i] = malloc(sizeof(node_t));
        tree[i]-> data = tmp;
        tree[i]-> left = NULL;
        tree[i]-> right = NULL;
        // printf("1");
    }

    for (int i = 0; i < num / 2; i++) {
        if ((i + 1) * 2 - 1 < num) {
            tree[i]-> left = tree[(i + 1) * 2 - 1];
            tree[i]-> right = tree[(i + 1) * 2];
        }
        //printf("2");
    }

    printf("DLR:");
    preorder(tree[0]);
    printf("\n");
    count = 0;

    printf("LDR:");
    inorder(tree[0]);
    printf("\n");
    count = 0;

    printf("LRD:");
    postorder(tree[0]);
    printf("\n");
    count = 0;
}
