set& operator= (const set& other)
{
    if (this != &other)
    {
        for (treeNode<T>* i = t->begin(); i != t->end();i = t->inorderNext())
        {
            t->deleteElement(i->data);
        }

        for (treeNode<T>* i = other.t->other.begin(); i != other.t->other.end(); i = other.t->other.inorderNext())
        {
            t->insert(i->data);
        }
    }
    return *this;
}
