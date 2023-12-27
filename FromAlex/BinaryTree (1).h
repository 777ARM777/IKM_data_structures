//
// Created by Dell on 11/14/2023.

#pragma once

#include "Node.h"
#include <iostream>

#include <stack>
#include <queue>

#include <stack>
#include <queue>

template <typename T>
class BinaryTree
{
public:
    BinaryTree(Node<T>* root = nullptr);
    ~BinaryTree();

    void insertR(const T& data);
    void insertI(const T& data);

    void eraseR(const T& data);

    bool containsR(const T& data) const;
    bool containsI(const T& data) const;
    T findMinR() const;
    T findMinI() const;
    T findMaxI() const;
    T findMaxR() const;

    void inorderR() const;
    void preorderR() const;
    void postorderR() const;

    void preorderI() const;
    void inorderI() const;
    void postorderI() const;
    void levelorder() const;
    void zigzagorder() const;

    int countOfNodesR() const;
    int countOfNodesI() const;
    int countOfLeavesR() const; // Recursive
    int countOfLeavesI() const; // Iterative

    int heightR() const;
    int widthR() const;

    void clearR();

    // Tomser
    void maxOfLevelI() const;
    void maxOfLevelR() const;

    void minOfLevelI() const;
    void minOfLevelR() const;

    void maxCountLevelI() const;
    void maxCountLevelR() const;

    int countNodesWithTwoChildrenI() const;
    int countNodesWithTwoChildrenR() const;

    int countNodesWithOneChildI() const;
    int countNodesWithOneChildR() const;

    int height_preorderI() const;
    int height_levelorderI() const;

    void printLeavesInorderI() const;
    void printLeavesInorderR() const;

    void levelsWithZeroNodesInorderI() const;
    void levelsWithZeroNodesInorderR() const;

private:
    Node<T>* insertHelper(Node<T>* p, const  T& d);

    Node<T>* eraseHelper(Node<T>* p, const T& data);


    Node<T>* findR(Node<T>* p, const T& data) const;
    Node<T>* findI(const T& data) const;
    Node<T>* findMinNodeR(Node<T>* p) const;
    Node<T>* findMaxNodeI(Node<T>* p) const;
    T findMaxHelper(Node<T> *p) const;

    void inorderHelper(Node<T>* p) const;
    void preorderHelper(Node<T>* p) const;
    void postorderHelper(Node<T>* p) const;

    int countOfNodesHelper(Node<T>* p) const;
    int countOfLeavesHelper(Node<T>* p) const;

    int heightHelper(Node<T>* p) const;
    void clearHelper(Node<T>* p);



private:
    // Tomser
    T maxOfLevelHelper(Node<T>* p, int level) const;
    void maxCountLevelHelper(Node<T>* p, int level, int& maxCount, std::vector<int>& result) const;
    int countNodesWithTwoChildrenHelper(Node<T>* p) const;
    int countNodesWithOneChildHelper(Node<T>* p) const;
    void printLeavesInorderHelper(Node<T>* p) const;
    T minOfLevelHelper(Node<T>* p, int level) const;
    void levelsWithZeroNodesInorderHelper(Node<T>* p, int level) const;


private:
    Node<T>* m_root;
};

template <typename T>
BinaryTree<T>::BinaryTree(Node<T>* root)
        : m_root(root)
{}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    clearR();
}

template <typename T>
void BinaryTree<T>::insertR(const T& d)
{
    m_root = insertHelper(m_root, d);
}

template <typename T>
void BinaryTree<T>::insertI(const T& d)
{
    if (!m_root)
    {
        m_root = new Node<T>(d);
        return;
    }

    Node<T>* parent = nullptr;
    Node<T>* runner = m_root;

    while (runner)
    {
        parent = runner;

        if (d < runner->data)
        {
            runner = runner->left;
        }
        else if (d > runner->data)
        {
            runner = runner->right;
        }
        else
        {
            std::cout << "skipping data: " << d << std::endl;
            return;
        }
    }

    if (d < parent->data)
    {
        parent->left = new Node<T>(d);
    }
    else
    {
        parent->right = new Node<T>(d);
    }
}

template <typename T>
bool BinaryTree<T>::containsR(const T& data) const
{
    return findR(m_root, data) != nullptr;
}

template <typename T>
Node<T>* BinaryTree<T>::findR(Node<T>* p, const T& data) const
{
    if (!p) return nullptr;

    if (data < p->data)
    {
        return findR(p->left, data);
    }

    if (data > p->data)
    {
        return findR(p->right, data);
    }

    return p;
}

template <typename T>
Node<T>* BinaryTree<T>::insertHelper(Node<T>* p, const  T& d)
{
    if (!p)
    {
        p = new Node<T>(d);

        return p;
    }

    if (d < p->data)
    {
        p->left = insertHelper(p->left, d);
    }
    else if (d > p->data)
    {
        p->right = insertHelper(p->right, d);
    }
    else
    {
        std::cout << "skipping data: " << d << std::endl;
    }
    return p;
}
template <typename T>
void BinaryTree<T>::inorderR() const
{
    inorderHelper(m_root);
}

template <typename T>
void BinaryTree<T>::inorderHelper(Node<T>* p) const
{
    if (!p) return;

    inorderHelper(p->left);
    std::cout << p->data << " ";
    inorderHelper(p->right);
}

template <typename T>
void BinaryTree<T>::preorderR() const
{
    preorderHelper(m_root);
}

template <typename T>
void BinaryTree<T>::preorderHelper(Node<T>* p) const
{
    if (!p) return;

    std::cout << p->data << " ";
    preorderHelper(p->left);
    preorderHelper(p->right);
}

template <typename T>
void BinaryTree<T>::postorderR() const
{
    postorderHelper(m_root);
}

template <typename T>
void BinaryTree<T>::postorderHelper(Node<T>* p) const
{
    if (!p) return;

    postorderHelper(p->left);
    postorderHelper(p->right);
    std::cout << p->data << " ";
}

template <typename T>
void BinaryTree<T>::clearR()
{
    clearHelper(m_root);
    m_root = nullptr;
}

template <typename T>
void BinaryTree<T>::clearHelper(Node<T>* p)
{
    if (!p) return;

    clearHelper(p->left);
    clearHelper(p->right);
    delete p;
    p = nullptr;
}

template <typename T>
int BinaryTree<T>::countOfNodesR() const
{
    return countOfNodesHelper(m_root);
}

template <typename T>
int BinaryTree<T>::countOfNodesHelper(Node<T>* p) const
{
    if (!p) return 0 ;

    return 1 + countOfNodesHelper(p->right) + countOfNodesHelper(p->left);
}

template <typename T>
void BinaryTree<T>::preorderI() const
{
    std::stack<Node<T>*> s;
    Node<T>* p = m_root;

    while (true)
    {
        while (p)
        {
            std::cout << p->data << " ";

            if (p->right)
            {
                s.push(p->right);
            }

            p = p->left;
        }

        if (s.empty())
        {
            return;
        }

        p = s.top();
        s.pop();
    }
}

template <typename T>
void BinaryTree<T>::inorderI() const
{
    std::stack<Node<T>*> s;
    Node<T>* p = m_root;

    while (true)
    {
        while (p)
        {
            s.push(p);
            p = p->left;
        }

        if (s.empty())
            return;

        p = s.top();
        s.pop();
        std::cout << p->data << ' ';

        p = p->right;
    }
}

template <typename T>
void BinaryTree<T>::postorderI() const
{
    std::stack<Node<T>*> s;
    Node<T>* p = m_root;

    while (true)
    {
        while (p)
        {
            if (p->right)
            {
                s.push(p->right);
            }
            s.push(p);
            p = p->left;
        }

        if (s.empty())
        {
            return;
        }

        p = s.top();
        s.pop();
        if (p->right && !s.empty() && s.top() == p->right)
        {
            s.pop();
            s.push(p);
            p = p->right;
        }
        else
        {
            std::cout << p->data << ' ';
            p = nullptr;
        }
    }
}

template <typename T>
void BinaryTree<T>::levelorder() const
{
    std::queue <Node<T>*> q;
    q.push(m_root);
    while (!q.empty())
    {
        Node<T>* p = q.front();
        q.pop();

        std::cout << p->data << ' ';

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
}

template <typename T>
int BinaryTree<T>::widthR() const
{
    std::queue<Node<T>*> q;
    q.push(m_root);
    int width = 0;

    while (!q.empty())
    {
        const int s = q.size();
        width = std::max(s, width);
        for (int i = 0; i < s; i++)
        {
            Node<T>* p = q.front();
            q.pop();

            if (p->left)
            {
                q.push(p->left);
            }

            if (p->right)
            {
                q.push(p->right);
            }
        }
    }
    return width;
}

template <typename T>
bool BinaryTree<T>::containsI(const T& data) const
{
    return findI(data) != nullptr;
}

template <typename T>
Node<T>* BinaryTree<T>::findI(const T& data) const
{
    Node<T>* p = m_root;
    while (p)
    {
        if (data == p->data)
        {
            return p;
        }
        if (data < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return nullptr;
}

template <typename T>
T BinaryTree<T>::findMinR() const
{
    return findMinNodeR(m_root)->data;
}

template <typename T>
Node<T>* BinaryTree<T>::findMinNodeR(Node<T>* p) const
{
    if (!p)
    {
        return nullptr;
    }
    if (!p->left)
    {
        return p;
    }
    return findMinNodeR(p->left);
}

template <typename T>
T BinaryTree<T>::findMaxI() const
{
    return findMaxNodeI(m_root)->data;
}

template <typename T>
Node<T>* BinaryTree<T>::findMaxNodeI(Node<T>* p) const
{
    while (p && p->right)
    {
        p = p->right;
    }
    return p;
}

template <typename T>
void BinaryTree<T>::eraseR(const T& data)
{
    m_root = eraseHelper(m_root, data);
}

template <typename T>
Node<T>* BinaryTree<T>::eraseHelper(Node<T>* p, const T& data)
{
    if (!p)
    {
        return nullptr;
    }

    if (data < p->data)
    {
        p->left = eraseHelper(p->left, data);
    }
    else if (data > p->data)
    {
        p->right = eraseHelper(p->right, data);
    }
    else
    {
        if (p->left == nullptr && p->right == nullptr)
        {
            std::cout << "deleting leaf" << std::endl;
            delete p;
            return nullptr;
        }
        if(!p->left)
        {
            std::cout << "deleting node with right child" << std::endl;
            Node<T>* tmp = p->right;
            delete p;
            return tmp;
        }

        if (!p->right)
        {
            std::cout << "deleting node with left child" << std::endl;
            Node<T>* tmp = p->left;
            delete p;
            return tmp;
        }

        std::cout << "deleting node with two children" << std::endl;
        Node<T>* min = findMinNodeR(p->right);
        p->data = min->data;
        p->right = eraseHelper(p->right, min->data);
    }
    return p;
}

template <typename T>
int BinaryTree<T>::countOfNodesI() const
{
    if (!m_root)
    {
        return 0;
    }
    std::stack<Node<T>*> s;
    s.push(m_root);
    int count = 0;
    while(!s.empty())
    {
        Node<T>* curr = s.top();
        s.pop();
        ++count;

        if (curr->left)
        {
            s.push(curr->left);
        }
        if(curr->right)
        {
            s.push(curr->right);
        }
    }

    return count;
}


template <typename T>
T BinaryTree<T>::findMinI() const
{
    if(!m_root)
    {
        return T{};
    }

    Node<T>* curr = m_root;

    while (curr->left)
    {
        curr = curr->left;
    }

    return curr->data;
}

template <typename T>
T BinaryTree<T>::findMaxR() const
{
    return findMaxHelper(m_root);
}

template <typename T>
T BinaryTree<T>::findMaxHelper(Node<T> *p) const
{
    if (!p)
    {
        return T{};
    }

    T rightMax = findMaxHelper(p->right);
    return std::max(p->data, rightMax);
}

template <typename T>
void BinaryTree<T>::zigzagorder() const {
    if (!m_root) {
        return;
    }

    std::queue<Node<T>*> q;
    std::stack<T> s;
    bool b = true;
    q.push(m_root);

    while (!q.empty()) {
        int s_l = q.size();

        for (int i = 0; i < s_l; ++i)
        {
            Node<T>* current = q.front();
            q.pop();

            if (b)
            {
                std::cout << current->data << " ";
            }
            else
            {
                s.push(current->data);
            }

            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }

        while (!s.empty())
        {
            std::cout << s.top() << " ";
            s.pop();
        }

        if (b)
        {
            b = false;
        }
        else
        {
            b = true;
        }
    }
}

// Start mijankyal tomser

// Ոչ ռեկուրսիվ եղանակով արտածել տրված դրական տարրերով ծառի յուրաքանչյուր մակարդակում պարունակվող մաքսիմալ տարրը
template <typename T>
void BinaryTree<T>::maxOfLevelI() const
{
    std::queue <Node<T>*> q;
    q.push(m_root);
    while (!q.empty())
    {
        int size = q.size();
        int max_level = 0;
        for(int i = 0; i < size; ++i)
        {
            Node<T> *p = q.front();
            q.pop();

            if (p->data > max_level)
            {
                max_level = p->data;
            }
            if (p->left) {
                q.push(p->left);
            }
            if (p->right) {
                q.push(p->right);
            }
        }
        std::cout << max_level << ' ';
    }
}

// Ռեկուրսիվ եղանակով արտածել տրված դրական տարրերով ծառի յուրաքանչյուր մակարդակում պարունակվող մաքսիմալ տարրը
template <typename T>
void BinaryTree<T>::maxOfLevelR() const
{
    int level = heightR();
    for (int i = 1; i <= level + 1; ++i)
    {
        std::cout << maxOfLevelHelper(m_root, i) << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
T BinaryTree<T>::maxOfLevelHelper(Node<T>* p, int level) const
{
    if (!p)
    {
        return 0;
    }
    if (level == 1)
    {
        return p->data;
    }
    T left_max = maxOfLevelHelper(p->left, level - 1);
    T right_max = maxOfLevelHelper(p->right, level - 1);
    return std::max(left_max, right_max);
}

// Ոչ Ռեկուրսիվ եղանակով արտածել տրված բինար ծառի այն մակարդակների համարները, որոնցում կան ամենաշատ թվով գագաթներ
template <typename T>
void BinaryTree<T>::maxCountLevelI() const
{
    if (!m_root)
    {
        std::cout << "The tree is empty." << std::endl;
        return;
    }
    std::queue<Node<T>*> q;
    q.push(m_root);
    int max_count = 0;
    std::vector<int> v;

    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        if (size > max_count)
        {
            max_count = size;
            v.clear();
            v.push_back(level);
        }
        else if (size == max_count)
        {
            v.push_back(level);
        }

        for (int i = 0; i < size; ++i)
        {
            Node<T>* p = q.front();
            q.pop();

            if (p->left)
            {
                q.push(p->left);
            }
            if (p->right)
            {
                q.push(p->right);
            }
        }

        level++;
    }

    for (int i : v)
    {
        std::cout << i << ' ';
    }
}

// Ռեկուրսիվ եղանակով արտածել տրված բինար ծառի այն մակարդակների համարները, որոնցում կան ամենաշատ թվով գագաթներ
template <typename T>
void BinaryTree<T>::maxCountLevelR() const
{
    if (!m_root)
    {
        std::cout << "The tree is empty." << std::endl;
        return;
    }

    int maxCount = 0;
    std::vector<int> result;
    maxCountLevelHelper(m_root, 0, maxCount, result);

    for (size_t i = 0; i < result.size(); ++i)
    {
        if (result[i] == maxCount)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::maxCountLevelHelper(Node<T>* p, int level, int& maxCount, std::vector<int>& result) const
{
    if (!p)
    {
        return;
    }

    if (level == result.size())
    {
        result.push_back(0);
    }

    result[level]++;

    if (result[level] > maxCount)
    {
        maxCount = result[level];
    }

    maxCountLevelHelper(p->left, level + 1, maxCount, result);
    maxCountLevelHelper(p->right, level + 1, maxCount, result);
}

// Ոչ ռեկուրսիվ եղանակով գտնել տրված բինար ծառի տերևների քանակը կարարելով ծառի ուղիղ շրջանցում
template <typename T>
int BinaryTree<T>::countOfLeavesI() const
{
    if(!m_root)
    {
        return 0;
    }

    std::stack<Node<T>*> s;
    s.push(m_root);
    int count = 0;
    while(!s.empty())
    {
        Node<T>* current = s.top();
        s.pop();
        if(!current->left and !current->right)
        {
            ++count;
        }
        if(current->left)
        {
            s.push(current->left);
        }
        if(current->right)
        {
            s.push(current->right);
        }
    }

    return count;
}

// Ռեկուրսիվ եղանակով գտնել տրված բինար ծառի տերևների քանակը կարարելով ծառի ուղիղ շրջանցում
template <typename T>
int BinaryTree<T>::countOfLeavesR() const
{
    return countOfLeavesHelper(m_root);
}

template <typename T>
int BinaryTree<T>::countOfLeavesHelper(Node<T>* p) const
{
    if (!p) return 0;

    if (!p->left && !p->right) return 1;

    return countOfLeavesHelper(p->right) + countOfLeavesHelper(p->left);
}

// Ոչ ռեկուրսիվ եղանակով գտնել տրված բինար ծառի բարձրությունը կարարելով ուղիղ շրջանցում
template <typename T>
int BinaryTree<T>::height_preorderI() const
{
    if (!m_root)
    {
        return -1;
    }
    std::stack<Node<T>*> s;
    std::stack<int> heights;
    Node<T>* p = m_root;
    int height = 0;
    int current = 0;

    while (true)
    {
        while (p)
        {
            if (p->right)
            {
                s.push(p->right);
                heights.push(current + 1);
            }

            p = p->left;
            if (p)
            {
                current++;
            }
        }

        if (current > height)
        {
            height = current;
        }

        if (s.empty())
        {
            return height;
        }

        p = s.top();
        s.pop();

        current = heights.top();
        heights.pop();
    }
}

// Ոչ ռեկուրսիվ եղանակով գտնել տրված բինար ծառի բարձրությունը կարարելով լայնակի շրջանցում
template <typename T>
int BinaryTree<T>::height_levelorderI() const
{
    std::queue<Node<T>*> q;
    if (!m_root)
    {
        return -1;
    }
    q.push(m_root);
    int height = -1;

    while (!q.empty())
    {
        height++;
        const int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node<T>* p = q.front();
            q.pop();

            if (p->left)
            {
                q.push(p->left);
            }

            if (p->right)
            {
                q.push(p->right);
            }
        }
    }
    return height;
}

// Ռեկուրսիվ եղանակով գտնել տրված բինար ծառի բարձրությունը
template <typename T>
int BinaryTree<T>::heightR() const
{
    return heightHelper(m_root) - 1;
}

template <typename T>
int BinaryTree<T>::heightHelper(Node<T>* p) const
{
    if (p == nullptr)
    {
        return 0;
    }

    if (!p->left && !p->right)
    {
        return 1;
    }

    return 1 + std::max(heightHelper(p->left), heightHelper(p->right));
}

// Ոչ ռեկուրսիվ եղանակով  գտնել տրված բինար ծառի 2 որդի ունեցող հանգույցների քանակը
template <typename T>
int BinaryTree<T>::countNodesWithTwoChildrenI() const
{
    if (!m_root)
    {
        return 0;
    }

    int count = 0;
    std::queue<Node<T>*> q;
    q.push(m_root);

    while (!q.empty())
    {
        Node<T>* current = q.front();
        q.pop();

        if (current->left && current->right)
        {
            count++;
        }

        if (current->left)
        {
            q.push(current->left);
        }

        if (current->right)
        {
            q.push(current->right);
        }
    }

    return count;
}

// Ռեկուրսիվ եղանակով  գտնել տրված բինար ծառի 2 որդի ունեցող հանգույցների քանակը
template <typename T>
int BinaryTree<T>::countNodesWithTwoChildrenR()const
{
    return countNodesWithTwoChildrenHelper(m_root);
}

template <typename T>
int BinaryTree<T>::countNodesWithTwoChildrenHelper(Node<T>* p) const
{
    return (!p) ? 0 : ((p->left && p->right) ? 1 : 0) + countNodesWithTwoChildrenHelper(p->left) + countNodesWithTwoChildrenHelper(p->right);
}

// Ոչ ռեկուրսիվ եղանակով  գտնել տրված բինար ծառի 1 որդի ունեցող հանգույցների քանակը
template <typename T>
int BinaryTree<T>::countNodesWithOneChildI() const
{
    if (!m_root)
    {
        return 0;
    }

    int count = 0;
    std::queue<Node<T>*> q;
    q.push(m_root);

    while (!q.empty())
    {
        Node<T>* current = q.front();
        q.pop();

        if ((current->left && !current->right) || (!current->left && current->right))
        {
            count++;
        }

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }

    return count;
}

//Ռեկուրսիվ եղանակով  գտնել տրված բինար ծառի 1 որդի ունեցող հանգույցների քանակը
template <typename T>
int BinaryTree<T>::countNodesWithOneChildR() const
{
    return countNodesWithOneChildHelper(m_root);
}

template <typename T>
int BinaryTree<T>::countNodesWithOneChildHelper(Node<T>* p) const
{
    return (!p) ? 0 : (((p->left && !p->right) || (!p->left && p->right)) ? 1 : 0) + countNodesWithOneChildHelper(p->left) + countNodesWithOneChildHelper(p->right);
}

// Տպել տրված բինար ծառի տերևներում պարունակվող արժեքները, կատարելով ծառի սիմետրիկ շրջանցում՝ ոչ ռեկուրսիվ եղանակով
template <typename T>
void BinaryTree<T>::printLeavesInorderI() const
{
    if (!m_root)
    {
        return;
    }

    std::stack<Node<T>*> stack;
    Node<T>* current = m_root;

    while (current || !stack.empty())
    {
        while (current)
        {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        if (!current->left && !current->right)
        {
            std::cout << current->data << " ";
        }

        current = current->right;
    }

    std::cout << std::endl;
}

// Տպել տրված բինար ծառի տերևներում պարունակվող արժեքները, կատարելով ծառի սիմետրիկ շրջանցում՝ ռեկուրսիվ եղանակով
template <typename T>
void BinaryTree<T>::printLeavesInorderR() const
{
    if (!m_root)
    {
        return;
    }

    printLeavesInorderHelper(m_root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printLeavesInorderHelper(Node<T>* p) const
{
    if (!p)
    {
        return;
    }

    printLeavesInorderHelper(p->left);

    if (!p->left && !p->right)
    {
        std::cout << p->data << " ";
    }

    printLeavesInorderHelper(p->right);
}

// Ոչ Ռեկուրսիվ եղանակով արտածել տրված դրական տարրերով ծառի յուրաքանչյուր մակարդակում պարունակվող փոքրագույն տարրը
template <typename T>
void BinaryTree<T>::minOfLevelI() const
{
    std::queue<Node<T>*> q;
    q.push(m_root);

    while (!q.empty())
    {
        int size = q.size();
        T min_level = INT_MAX;
        for (int i = 0; i < size; ++i)
        {
            Node<T>* p = q.front();
            q.pop();

            if (p->data < min_level)
            {
                min_level = p->data;
            }

            if (p->left)
            {
                q.push(p->left);
            }
            if (p->right)
            {
                q.push(p->right);
            }
        }

        std::cout << min_level << ' ';
    }
}

// Ռեկուրսիվ եղանակով արտածել տրված դրական տարրերով ծառի յուրաքանչյուր մակարդակում պարունակվող փոքրագույն տարրը
template <typename T>
void BinaryTree<T>::minOfLevelR() const
{
    int level = heightR();
    for (int i = 1; i <= level + 1; ++i)
    {
        std::cout << minOfLevelHelper(m_root, i) << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
T BinaryTree<T>::minOfLevelHelper(Node<T>* p, int level) const
{
    if (!p)
    {
        return INT_MAX;
    }
    if (level == 1)
    {
        return p->data;
    }
    T left_min = minOfLevelHelper(p->left, level - 1);
    T right_min = minOfLevelHelper(p->right, level - 1);
    return std::min(left_min, right_min);
}

// Ոչ ռեկուրսիվ եղանակով գտնել բինար ծառի այն մակարդակների համարները, որոնք պարունակում են զրոյական արժեքով հանգույցմեր
template <typename T>
void BinaryTree<T>::levelsWithZeroNodesInorderI() const
{
    if (!m_root)
    {
        return;
    }

    std::queue<Node<T>*> nodesQueue;
    nodesQueue.push(m_root);

    std::queue<int> levelsQueue;
    levelsQueue.push(0);

    while (!nodesQueue.empty())
    {
        Node<T>* current = nodesQueue.front();
        nodesQueue.pop();

        int current_level = levelsQueue.front();
        levelsQueue.pop();

        if (current->left)
        {
            nodesQueue.push(current->left);
            levelsQueue.push(current_level + 1);
        }

        if (current->data == 0)
        {
            std::cout << current_level << " ";
        }

        if (current->right)
        {
            nodesQueue.push(current->right);
            levelsQueue.push(current_level);
        }
    }
}

// ռեկուրսիվ եղանակով գտնել բինար ծառի այն մակարդակների համարները, որոնք պարունակում են զրոյական արժեքով հանգույցմեր
template <typename T>
void BinaryTree<T>::levelsWithZeroNodesInorderR() const
{
    if (!m_root)
    {
        return;
    }

    levelsWithZeroNodesInorderHelper(m_root, 0);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::levelsWithZeroNodesInorderHelper(Node<T>* p, int level) const
{
    if (!p)
    {
        return;
    }

    levelsWithZeroNodesInorderHelper(p->left, level + 1);

    if (p->data == 0)
    {
        std::cout << level << " ";
    }

    levelsWithZeroNodesInorderHelper(p->right, level + 1);
}