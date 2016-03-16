
#include <iostream>

#include "binary_search_tree.h"

std::ostream& operator<<(std::ostream& out, binary_search_tree::node const& node)
{
    out << "v: " << node.value;
    if (node.left)
        out << " l:[" << *node.left << "]";
    if (node.right)
        out << " r:[" << *node.right << "]";

    return out;
}

std::ostream& operator<<(std::ostream& out, binary_search_tree const& bst)
{
    if(bst.get_root())
        out << "[" << *bst.get_root() << "]";
    else
        out << "[]";

    return out;
}

int main(int argc, char** argv)
{
    binary_search_tree bst;

    bst
        .insert(5)
        .insert(2)
        .insert(4)
        .insert(6)
        ;

    std::cout << bst << std::endl;

    for(int i =0;i<10;++i) {
        std::cout << "containts " << i << "? : " << bst.has(i) << std::endl;
    }

    return 0;
}
