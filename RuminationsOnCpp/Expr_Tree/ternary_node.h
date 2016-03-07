#ifndef TERNARY_NODE_H
#define TERNARY_NODE_H

#include "expr_node.h"
#include "expr.h"

class Ternary_Node : public Expr_Node
{
public:
    Ternary_Node(const std::string &op, const Expr &left, const Expr &mid, const Expr &right);

    virtual void print(std::ostream &os) const;

    virtual int eval() const;

private:
    std::string m_op;
    Expr m_left;
    Expr m_middle;
    Expr m_right;
};

#endif // TERNARY_NODE_H
