#include "gerador.cpp"
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int dado;
    struct node *left;
    struct node *right;
} no;

no *novoNo(int dado) {
    no *node = (no *)malloc(sizeof(no));
    node->dado = dado;
    node->left = 0;
    node->right = 0;
    return node;
}

no *insert(no *node, int dado) {
    if (node == 0) {
        return novoNo(dado);
    }
    if (dado < node->dado) {
        node->left = insert(node->left, dado);
    } else if (dado > node->dado) {
        node->right = insert(node->right, dado);
    }

    return node;
}

void emOrdem(no *node) {
    if (node == 0) {
        return;
    }
    emOrdem(node->left);
    printf("%d ", node->dado);
    emOrdem(node->right);
}

void posOrdem(no *node) {
    if (node == 0) {
        return;
    }
    posOrdem(node->left);
    posOrdem(node->right);
    printf("%d ", node->dado);
}

void preOrdem(no *node) {
    if (node == 0) {
        return;
    }
    printf("%d ", node->dado);
    preOrdem(node->left);
    preOrdem(node->right);
}

void emDesordem(no *node) {
    if (node == 0) {
        return;
    }
    printf("%d ", node->dado);
    emDesordem(node->right);
    emDesordem(node->left);
}

int main() {
    // Assinatura da prova:
    int mat1 = 1234567890;
    int mat2 = 1234567890;
    int mat3 = 1234567890;
    int seed = hash(mat1, mat2, mat3);
    int *res = gerador(seed);

    no *raiz = 0;
    for (size_t i = 0; i < 30; i++) {
        raiz = insert(raiz, res[i]);
    }

    //printf("Em posOrdem: ");
    //posOrdem(raiz);
    printf("\n");

    return 0;
}
