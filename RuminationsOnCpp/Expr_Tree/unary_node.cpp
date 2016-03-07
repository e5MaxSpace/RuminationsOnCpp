#include "unary_node.h"

Unary_Node::Unary_Node(const std::string &op, const Expr &expr) : m_op(op), m_expr(expr)
{
}

void Unary_Node::print(std::ostream &os) const
{
    os << m_op << m_expr;
}

int Unary_Node::eval() const
{
    if ( m_op == "-")
        return -m_expr.eval();

    throw "error operator. op=" + m_op + " in unary";
}
