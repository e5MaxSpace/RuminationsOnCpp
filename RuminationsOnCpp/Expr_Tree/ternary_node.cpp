#include "ternary_node.h"

Ternary_Node::Ternary_Node(const std::string &op, const Expr &left, const Expr &mid, const Expr &right)
    : m_op(op), m_left(left), m_middle(mid), m_right(right)
{
}

void Ternary_Node::print(std::ostream &os) const
{
    os << "(" << m_left <<"?" << m_middle << ":" << m_right << ")";
}

int Ternary_Node::eval() const
{
    if (m_left.eval())
        return m_middle.eval();
    else
        return m_right.eval();
}
