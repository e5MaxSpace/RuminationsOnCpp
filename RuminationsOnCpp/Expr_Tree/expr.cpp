#include "expr.h"

#include "int_node.h"
#include "unary_node.h"
#include "binary_node.h"
#include "ternary_node.h"

Expr::Expr(int n) : m_node(new Int_Node(n))
{
}

Expr::Expr(const std::string &op, const Expr &exp) : m_node(new Unary_Node(op, exp))
{

}

Expr::Expr(const std::string &op, const Expr &left, const Expr &right) :
    m_node(new Binary_Node(op, left, right))
{

}

Expr::Expr(const std::string &op, const Expr &left, const Expr &mid, const Expr &right) :
    m_node(new Ternary_Node(op, left, mid, right))
{

}

Expr::~Expr()
{
    if (--m_node->m_use == 0)
        delete m_node;
}

Expr::Expr(const Expr &rhs) : m_node(rhs.m_node)
{
    ++m_node->m_use;
}

Expr &Expr::operator=(const Expr &rhs)
{
    if (this != &rhs)
    {
        ++(rhs.m_node->m_use);
        if (--(m_node->m_use) == 0)
            delete m_node;

        m_node = rhs.m_node;
    }

    return *this;
}

int Expr::eval() const
{
    return m_node->eval();
}
