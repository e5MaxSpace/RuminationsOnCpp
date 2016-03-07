#ifndef USECOUNT_H
#define USECOUNT_H

class UseCount
{
public:
    UseCount();
    UseCount(const UseCount &other);
    ~UseCount();

    bool only() const;

    bool reattach(const UseCount &u);

    bool makeonly();

private:
    int *p;

    UseCount &operator=(const UseCount &other);
};

#endif // USECOUNT_H
