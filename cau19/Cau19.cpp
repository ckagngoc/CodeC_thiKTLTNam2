#include <malloc.h>

typedef int type;
struct Node{
    type data;
    Node* left;
    Node* right;
};
typedef Node* tree;

void createTree(tree*root,type v){
    if(*root==NULL){
        tree t;
        t = new(Node);
        t->data = v;
        t->left = t->right = NULL;
    } else if(v<(*root)->data) createTree(&(*root)->left,v);
    else createTree(&(*root)->right,v);
}

void NLR(tree root){
    if(root!=NULL){
        printf("%d ",root->data);
        NLR(root->left);
        NLR(root->right);
    } else return;
}

void LNR(tree root){
	if(root!=NULL){
		LNR(root->left);
		if(root!=NULL){
			printf("%d ",root->data);
		}
		LNR(root->right);
	}
}

void LRN(tree root){
	if(root!=NULL){
		LRN(root->left);
		LRN(root->right);
		if(root!=NULL){
			printf("%d ",root->data);
		}
	}
}

tree search(tree root,type v){
    if (root == NULL || root->data == v)
       return root;
    else if (root->data < v)
       return search(root->right, v);
    else return search(root->left, v);
}

tree FindMax(tree root)
{
	while(root->right != NULL) root = root->right;
	return root;
}

void Delete(tree *root,type v) {
	if(*root==NULL) return; 
	else if (v < (*root)->data) Delete(&(*root)->left,v);
	else if (v > (*root)->data) Delete(&(*root)->right,v);
	else {
		/* Case 1:  Node lá, không có con */
		if((*root)->left == NULL && (*root)->right == NULL) { 
			delete *root;
			*root = NULL;
		}
		/* Case 2: Có một con  */
		else if((*root)->left == NULL) {
			tree temp = *root;
			*root = (*root)->right;
			delete temp;
		}
		else if((*root)->right == NULL) {
			tree temp = (*root);
			*root = (*root)->left;
			delete temp;
		}
		/* case 3: Có hai con */
		else { 
			tree temp = FindMax((*root)->left);
			(*root)->data = temp->data;
			Delete(&(*root)->left,temp->data);
		}
	}
}

int main(){
    tree (*root) = NULL;
    createTree(&(*root),19);
    createTree(&(*root),12);
    createTree(&(*root),11);
    createTree(&(*root),10);
    return 0;
}