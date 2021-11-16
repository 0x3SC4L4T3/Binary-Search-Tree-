#pragma once
template <typename ItemType, typename KeyType>
class BinarySearchTreeInterface
{
public:
    virtual ~BinarySearchTreeInterface() {}
    virtual void add(ItemType entry) = 0; //throws std::runtime_error if duplicate added
    virtual ItemType search(KeyType key) const = 0; //throws std::runtime_error if not in tree
    virtual void clear() = 0; //Empties the tree
    virtual void remove(KeyType key) = 0; //throws std::runtime_error if not in tree

    //For the following methods, each method will take a function as a parameter
    //These function then call the provided function on every entry in the tree in the appropriate order (i.e. pre, in, post)
    //The function you pass in will need to a static method
    virtual void visitPreOrder(void visit(ItemType)) const = 0; //Visits each node in pre order
    virtual void visitInOrder(void visit(ItemType)) const = 0; //Visits each node in in order
    virtual void visitPostOrder(void visit(ItemType)) const = 0; //Visits each node in post order
};