
#include "binary_search_tree.h"

binary_search_tree::binary_search_tree()
        : root(nullptr)
{ }

binary_search_tree::~binary_search_tree()
{
    delete root;
}

binary_search_tree::binary_search_tree(binary_search_tree const& other)
        : root(other.root)
{ }

binary_search_tree& binary_search_tree::operator=(binary_search_tree const& other)
{
    if(root) delete root;
    root = new node(*other.root);

    return *this;
}

binary_search_tree& binary_search_tree::insert(binary_search_tree::value_type const& value)
{
    if (!root)
    {
        root = new node(value);
    }
    else
    {
        root->insert(value);
    }

    return *this;
}

bool binary_search_tree::has(binary_search_tree::value_type const& value) const
{
    node* curr = root;

    while(curr)
    {
        if(curr->value == value) return true;

        if(value < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return false;
}

const binary_search_tree::node* binary_search_tree::get_root() const
{
    return root;
}

binary_search_tree::node::node(binary_search_tree::value_type const& value)
        : value(value), left(nullptr), right(nullptr)
{
}

binary_search_tree::node::~node()
{
    if(left) delete left;
    if(right) delete right;
}

binary_search_tree::node::node(binary_search_tree::node const& other)
        : value(other.value)
        , left(other.left ? new node(*other.left) : nullptr)
        , right(other.right ? new node(*other.right) : nullptr)
{
}

void binary_search_tree::node::insert(binary_search_tree::value_type const& new_value)
{
    if (new_value < value)
    {
        if (left)
            left->insert(new_value);
        else
            left = new node(new_value);
    }
    else
    {
        if (right)
            right->insert(new_value);
        else
            right = new node(new_value);
    }
}
