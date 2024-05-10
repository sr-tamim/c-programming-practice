#include <stdio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, int data)
{
    if (root == NULL)
    {
        return create_node(data);
    }
    if (data < root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void inorder_traversal(node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(node *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

int delete_node(node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return 1;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            free(temp);
            return 1;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            free(temp);
            return 1;
        }
        else
        {
            node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            delete_node(root->right, temp->data);
            return 1;
        }
    }
    if (root->data < data)
    {
        return delete_node(root->right, data);
    }
    return delete_node(root->left, data);
}

int search_node(node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        return 1;
    }
    if (root->data < data)
    {
        return search_node(root->right, data);
    }
    return search_node(root->left, data);
}

int main()
{
    node *root = NULL;
    root = insert_node(root, 5);
    insert_node(root, 3);
    insert_node(root, 10);
    insert_node(root, 1);
    insert_node(root, 6);
    insert_node(root, 14);
    insert_node(root, 4);
    insert_node(root, 7);
    insert_node(root, 13);
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");
    //delete_node(root, 10);
    printf("Inorder traversal after deleting 10: ");
    inorder_traversal(root);
    printf("\n");
    printf("Is 7 present in the tree? %s\n", search_node(root, 7) ? "Yes" : "No");
    printf("Is 10 present in the tree? %s\n", search_node(root, 10) ? "Yes" : "No");
    printf("\n");
    return 0;
}
