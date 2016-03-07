#ifndef EXPR_H
#define EXPR_H

#include "expr_node.h"

// Expr_Node �ľ����
class Expr
{
    friend std::ostream& operator<<(std::ostream &os, const Expr &expr)
    {
        expr.m_node->print(os);
        return os;
    }

public:
    /*explicit*/ Expr(int n); // ��������n��Expr����ʽת��
    /*explicit*/ Expr(const std::string &op, const Expr &exp);
    /*explicit*/ Expr(const std::string &op, const Expr &left, const Expr &right);
    /*explicit*/ Expr(const std::string &op, const Expr &left, const Expr &mid, const Expr &right);
    ~Expr();

    Expr(const Expr &rhs);

    Expr &operator=(const Expr &rhs);

    int eval() const;

private:
    Expr_Node *m_node;
};

#endif // EXPR_H
