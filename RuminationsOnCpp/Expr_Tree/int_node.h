#ifndef INT_NODE_H
#define INT_NODE_H

#include "expr_node.h"

class Int_Node : public Expr_Node
{
public:
    explicit Int_Node(int n);

protected:
    virtual void print(std::ostream &os) const;

    virtual int eval() const;

private:
    int m_n;
};

#endif // INT_NODE_H
