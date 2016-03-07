#include "int_node.h"

Int_Node::Int_Node(int n) : m_n(n)
{
}

void Int_Node::print(std::ostream &os) const
{
    os << m_n;
}

int Int_Node::eval() const
{
    return m_n;
}
