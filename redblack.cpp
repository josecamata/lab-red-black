#include "redblack.h"

// Construtors
RBNode::RBNode(int key): key(key), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}


RBNode::RBNode(int key, RBNode* parent, RBNode* left, RBNode* right, bool color):
    key(key), parent(parent), left(left), right(right), color(RED) {
}

RBNode::RBNode(const RBNode& other):
    key(other.key), parent(other.parent), left(other.left), right(other.right), color(other.color) {
}

RBNode::~RBNode() {

}

int RBNode::getKey() {
    return key;
}

RBNode* RBNode::getParent() {
    return parent;
}

RBNode* RBNode::getLeft() {
    return left;
}

RBNode* RBNode::getRight() {
    return right;
}


RBTree::RBTree(): root(nullptr) {
    nil = new RBNode(0, nullptr, nullptr, nullptr, BLACK);
}

void RBTree::insert(int key) {
   RBNode* tmp = this->root;
   RBNode* parent = nil;
    // arvore esta vazia
    // Cria um novo nó com a chave passada como argumento
    // e insere o novo nó na raiz da árvore
   if(tmp == nullptr)
    {
         this->root = new RBNode(key);
         this->root->parent = nil;
         this->root->left = nil;
         this->root->right = nil;
         this->root->color = BLACK;
         return;
    }

    // procura o nó onde a chave deve ser inserida
    while(tmp != nil)
    {
        parent = tmp;
        if(key < tmp->key)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    // cria um novo nó com a chave passada como argumento
    // e insere o novo nó na árvore
    RBNode* newNode = new RBNode(key, parent, nil, nil, RED);
    if(key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    // corrige a árvore a partir do novo nó inserido    
    //this->Fixup(newNode);
}

RBNode* RBTree::minimum()
{
    return minimum(this->root);
}

RBNode* RBTree::minimum(RBNode* node) {
    RBNode* tmp = node;
    if(tmp == nullptr)
        return nullptr;
    while(tmp->left != nil)
        tmp = tmp->left;
    return tmp;
}

RBNode* RBTree::maximum()
{
    return maximum(this->root);
}

RBNode* RBTree::maximum(RBNode* node) {
    RBNode* tmp = node;
    if(tmp == nullptr)
        return nullptr;
    while(tmp->right != nil)
        tmp = tmp->right;
    return tmp;
}

RBNode* RBTree::successor(RBNode* node) {
    if(node->right != nil)
        return minimum(node->right);
    RBNode* tmp = node->parent;
    while(tmp != nil && node == tmp->right)
    {
        node = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

RBNode* RBTree::search(int key) {
    RBNode* tmp = this->root;
    while(tmp != nil)
    {
        if(key < tmp->key)
            tmp = tmp->left;
        else if(key > tmp->key)
            tmp = tmp->right;
        else
            return tmp;
    }
    return nullptr;
}

 void RBTree::remove(int key){
    RBNode *y;
    RBNode *x;
    RBNode* z = search(key);
    if(z == nullptr || z == nil)
        return;

    if(z->left == nil || z->right == nil)
        y = z;
    else
        y = successor(z);
    
    if(y->left != nil)
        x = y->left;
    else
        x = y->right;
    x->parent = y->parent;
    if(y->parent == nil)
        this->root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    if(y != z)
        z->key = y->key;
    if(y->color == BLACK)   // se o nó a ser removido for vermelho, então ocorre uma remoção de nós vermelhos
        this->deleteFixUp(x);
    ///return y;
    delete y;

}

void RBTree::rotateLeft(RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    if(y->left != nil)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == nil)
        this->root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RBTree::rotateRight(RBNode* x) {
    RBNode* y = x->left;
    x->left = y->right;
    if(y->right != nil)
        y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == nil)
        this->root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
}

// TODO: implementar o método insertFixUp
void RBTree::insertFixUp(RBNode *node)
{


}

// TODO: implementar o método deleteFixUp
void RBTree::deleteFixUp(RBNode *node)
{

}



