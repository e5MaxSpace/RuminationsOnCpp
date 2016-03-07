#ifndef EXPR_NODE_H
#define EXPR_NODE_H

#include <ostream>

class Expr_Node
{
    friend std::ostream& operator<<(std::ostream &os, const Expr_Node &node)
    {
        node.print(os);
        return os;
    }
    friend class Expr;

public:
    //protected:
    Expr_Node();
    virtual ~Expr_Node();
    virtual void print(std::ostream &os) const = 0;

    virtual int eval() const = 0;

    int m_use;
};

#endif // EXPR_NODE_H
