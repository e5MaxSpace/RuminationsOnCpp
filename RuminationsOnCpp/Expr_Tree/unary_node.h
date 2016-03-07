#ifndef UNARY_NODE_H
#define UNARY_NODE_H

#include "expr_node.h"
#include "expr.h"

class Unary_Node : public Expr_Node
{
public:
    explicit Unary_Node(const std::string &op, const Expr &expr);

protected:
    virtual void print(std::ostream &os) const;

    virtual int eval() const;

private:
    std::string m_op;
    Expr m_expr;
};

#endif // UNARY_NODE_H
