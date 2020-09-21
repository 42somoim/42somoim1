#include <cstdio>

char tree[26][2] = { '.', };

void preorder(char root)
{
    if (root == '.') return;
    else {
        printf("%c", root);
        preorder(tree[root-'A'][0]);
        preorder(tree[root-'A'][1]);
    }
}

void inorder(char root)
{
    if (root == '.') return;
    else {
        inorder(tree[root-'A'][0]);
        printf("%c", root);
        inorder(tree[root-'A'][1]);
    }
}

void postorder(char root)
{
    if (root == '.') return;
    else {
        postorder(tree[root-'A'][0]);
        postorder(tree[root-'A'][1]);
        printf("%c", root);
    }
}

int main()
{
    int n, i;
    char root, left, right;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf(" %c %c %c", &root, &left, &right);
        tree[root-'A'][0] = left;
        tree[root-'A'][1] = right;
    }

    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
    printf("\n");

    return 0;
}