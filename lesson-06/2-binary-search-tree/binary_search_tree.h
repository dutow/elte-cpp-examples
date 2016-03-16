
#pragma once

class binary_search_tree
{
public:
    typedef int value_type;
    struct node;

    binary_search_tree();
    ~binary_search_tree();

    binary_search_tree(binary_search_tree const& other) /* = delete */;
    binary_search_tree& operator=(binary_search_tree const& other) /* = delete */;

    binary_search_tree& insert(value_type const& v);
    bool has(value_type const& v) const;

    ////////////////////////////////

    const node* get_root() const;

private:

    node* root;

public:

    struct node {
        value_type value;

        node *left;
        node *right;

        node(value_type const& value);
        ~node();

        node(const node& other);

        node& operator=(node const& other) = delete;

        void insert(value_type const& new_value);
    };
};
