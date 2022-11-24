#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *left, *right;
} node_t;

int num , count = 0;

void preorder(node_t* node)
{
    if (node) {
        if (count < num - 1) {
            printf("%d ", node-> data);
            count++;
        } else {
            printf("%d", node-> data);
        }
        preorder(node-> left);
        preorder(node-> right);
    }
}

int main() {
    int value, target;
    scanf("%d", &num);
    node_t *tree[num];

    for (int i = 0; i < num; i++) {
        scanf("%d", &value);
        tree[i] = malloc(sizeof(node_t));
        tree[i]-> data = value;
        tree[i]-> left = NULL;
        tree[i]-> right = NULL;
    }

    scanf("%d", &target);
    for (int i = 0; i < num; i++) {
        if (tree[i]-> data == target){
            tree[i]-> data = -999;
        }
    }

    for (int i = 0; i < num / 2; i++) {
        if ((i + 1) * 2 - 1 < num) {
            if (tree[(i + 1) * 2 - 1]-> data != -999) {
                tree[i]-> left = tree[(i +1) * 2 - 1];
            }
            if (tree[(i + 1) * 2]-> data != -999) {
                tree[i]-> right = tree[(i +1) * 2];
            }
        }
    }
    preorder(tree[0]);
    printf("\n");
}
