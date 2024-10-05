#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int d)
{
    if (root == nullptr)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insert(root->right, d);
    }
    else
    {
        root->left = insert(root->left, d);
    }
    return root;
}
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxValue(Node *root)
{
    Node *temp = root;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp;
}

Node *inpre(Node *root, int d)
{
    Node *succeser = nullptr;
    while (root != nullptr)
    {
        if (d > root->data)
        {
            succeser = root;
            root = root->right;
        }
        else
        {

            root = root->left;
        }
    }
    return succeser;
}

Node *inSuc(Node *root, int d)
{
    Node *succeser = nullptr;
    while (root != nullptr)
    {
        if (d >= root->data)
        {
            root = root->right;
        }
        else
        {
            succeser = root;
            root = root->left;
        }
    }
    return succeser;
}
Node *del(Node *root, int d)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == d)
    {
        // 0 child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // 1 child
        if (root->left != nullptr && root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != nullptr && root->right != nullptr)
        {
            Node *min = minValue(root->right);
            root->data = min->data;
            root->right = del(root->right, min->data);
            return root;
        }
    }
    else if (root->data > d)
    {
        root->left = del(root->left, d);
    }
    else
    {
        root->right = del(root->right, d);
    }
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 100);
    root = insert(root, 70);
    root = insert(root, 200);
    root = insert(root, 150);
    root = insert(root, 80);
    root = insert(root, 11);
    root = insert(root, 222);
    // levelOrder(root);
    cout << "Inorder :" << endl;
    inorder(root); 
    cout << endl;
    // cout << "Preorder :" << endl;
    // preorder(root);
    // cout << endl;
    // cout << "Postorder :" << endl;
    // postorder(root);
    // cout << "MinValue is :" << minValue(root)->data << endl;
    // cout << "MaxValue is :" << maxValue(root)->data << endl;
    // cout << "Succeser of 150 " << inSuc(root, 150)->data << endl;
    // cout << "Predecessor of 200 " << inpre(root, 200)->data << endl;
    return 0;
}