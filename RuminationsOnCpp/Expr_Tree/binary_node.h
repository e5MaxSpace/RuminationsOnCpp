#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include "expr_node.h"
#include "expr.h"

class Binary_Node : public Expr_Node
{
public:
    Binary_Node(const std::string &op, const Expr &left, const Expr &right);

protected:
    virtual void print(std::ostream &os) const;

    virtual int eval() const;

private:
    std::string m_op;
    Expr m_left;
    Expr m_right;
};

#endif // BINARY_NODE_H
