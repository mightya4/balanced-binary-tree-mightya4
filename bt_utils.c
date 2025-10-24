#include "bt_utils.h"

BTNode *add_btnode(int data) {
    BTNode *node = calloc(1, sizeof(BTNode));
    node->data = data;

    return node;
}

void inorder_dfs(BTNode *root) {
    if (root == NULL) {
        return;
    }

    inorder_dfs(root->left);

    printf("%d\n", root->data);

    dfs(root->right);
}

void insert(BTNode **root, int val) {
    BTNode **temp = root;
    while (*temp != NULL) {
        if (val >= (*temp)->data) {
            temp = &(*temp)->right;
        } else {
            temp = &(*temp)->left;
        }
    }

    *temp = add_btnode(val);
}

BTNode *search(BTNode *node, int val) {
    if (node == NULL || val == node->data) {
        return node;
    } else if (val > node->data) {
        return search(node->right, val);
    } else {
        return search(node->left, val);
    }
}

void release_tree(BTNode *node) {
    if (node != NULL) {
        release_tree(node->left);
        release_tree(node->right);
        free(node);
    }
}

/*
 * Builds a balanced Binary Search Tree given a list of unsorted integers.
 * 
 * Arguments:
 *   data: An array of integers.
 *   n: The number of integers in the array.
 * 
 * Returns:
 *   A pointer to the root node of the balanced BST.
 */
BTNode *build_balanced_bst(int *data, int n) {
    // TODO: Implement this function to build a balanced BST.
    int *root = NULL;
    int med_num = n / 2;
    int *sorted_data = { 0 };

    sorted_data = (int *)malloc(sizeof(data) * sizeof(int));

    if(sorted_data == NULL) {
        printf("Build Balanaced Binary Search Tree Function: Failed to allocate data on build");
        return 1;
    }
    sorted_data = qsort(data, sizeof(data)/sizeof(data[0]), sizeof(int *), compare_elem);


    return root;
}

int compare_int_elem(const void *elem_ptr, const void *nxt_elem_ptr) {
    const char *const one_int = elem_ptr;
    const char *const two_int = nxt_elem_ptr;

}