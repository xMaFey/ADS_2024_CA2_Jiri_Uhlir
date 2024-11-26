#ifndef BSTNODE_H
#define BSTNODE_H

template <class T>
class BSTNode {
private:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode<T>* parent;

public:
    BSTNode() : left(nullptr), right(nullptr), parent(nullptr) {}

    BSTNode(const T& item) : data(item), left(nullptr), right(nullptr), parent(nullptr) {}

    BSTNode(const BSTNode<T>& other)
        : data(other.data), left(nullptr), right(nullptr), parent(nullptr) {
        if (other.left != nullptr)
            left = new BSTNode<T>(*other.left);
        if (other.right != nullptr)
            right = new BSTNode<T>(*other.right);
    }

    ~BSTNode() {
        delete left;
        delete right;
    }

    T& getItem() { return data; }
    void setItem(const T& item) { data = item; }

    BSTNode<T>* getLeft() const { return left; }
    BSTNode<T>* getRight() const { return right; }

    void setLeft(BSTNode<T>* node) { left = node; }
    void setRight(BSTNode<T>* node) { right = node; }

    void add(T& item) {
        if (item < data) {
            if (left == nullptr) {
                left = new BSTNode<T>(item);
            }
            else {
                left->add(item);
            }
        }
        else if (item > data) {
            if (right == nullptr) {
                right = new BSTNode<T>(item);
            }
            else {
                right->add(item);
            }
        }
    }

    int count() {
        int leftCount = (left == nullptr) ? 0 : left->count();
        int rightCount = (right == nullptr) ? 0 : right->count();
        return 1 + leftCount + rightCount;
    }
};

#endif // BSTNODE_H
