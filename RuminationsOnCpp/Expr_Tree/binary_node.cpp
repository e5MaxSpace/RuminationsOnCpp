#include "binary_node.h"

Binary_Node::Binary_Node(const std::string &op, const Expr &left, const Expr &right) :
    m_op(op), m_left(left), m_right(right)
{
}

void Binary_Node::print(std::ostream &os) const
{
    os << "(" << m_left << m_op << m_right << ")" ;
}

int Binary_Node::eval() const
{
    if (m_op == "+")
        return m_left.eval() + m_right.eval();

    if (m_op == "-")
        return m_left.eval() - m_right.eval();

    if (m_op == "*")
        return m_left.eval() * m_right.eval();

    if (m_op == "/" && m_right.eval() != 0)
        return m_left.eval() / m_right.eval();

    throw "error operator. op=" + m_op + " in binary.";
}
