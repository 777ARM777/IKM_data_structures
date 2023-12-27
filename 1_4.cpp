friend set union_sets(set& s1, set& s2) {
    set result = s1;
    for (treeNode<T>* i = s2.t->begin(); i != s2.t->end(); i = s2.t->inorderNext()) {
        result.t->insert(i->data);
    }
    return result;
}
