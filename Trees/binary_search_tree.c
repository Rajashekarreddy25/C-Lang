#include<stdio.h>
#include<stdlib.h>

struct node *root = NULL;

struct node{
        int data ;
        struct node *left;
        struct node *right;
};


struct node *createNode(int val){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
}

struct node *insert(struct node *root,int val){

        if (root == NULL)
                return createNode(val);

        if (val < root->data)
                root -> left = insert(root->left,val);

        else if (val > root->data)
                root -> right = insert(root->right,val);

        return root;

}
void inorder(struct node *root){

        if (root == NULL)
                return;

        inorder(root->left);

        printf("%d ", root->data);

        inorder(root -> right);

}

void preorder(struct node *root)
{
        if (root == NULL)
                return ;

        printf("%d ",root->data);

        preorder(root->left);

        preorder(root->right);


}

void postorder(struct node *root){

        if(root == NULL)
               return ;

        postorder(root->left);

        postorder(root->right);

        printf("%d ",root->data);
}

int main(){


        int arr[] = {3,6,2,5,8};

        for(int i = 0; i<5 ; i++){
              root =  insert(root,arr[i]);
        }

        printf("The inorder traversal is :\n");
        inorder(root);
        printf("\n");

        printf("The preorder traversal is :\n");
        preorder(root);
        printf("\n");

        printf("The postorder traversal is :\n");
        postorder(root);
        printf("\n");

        return 0;
}

~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
~                                                    
