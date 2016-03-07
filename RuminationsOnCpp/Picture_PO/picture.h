#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>

class Picture
{
    friend std::ostream& operator<<(std::ostream &os, const Picture &p)
    {
        p.print(os);
        return os;
    }

    friend Picture frame(const Picture &p);

    friend Picture operator | (const Picture &p, const Picture &q);

    friend Picture operator & (const Picture &p, const Picture &q);

    public:
        Picture();
    Picture(size_t h, size_t w, char c = ' ');
    Picture(char **ss, size_t num);
    Picture(const Picture &other);
    Picture& operator=(const Picture &rhs);
    ~Picture();

    void print(std::ostream &os) const;

    char &position(size_t row, size_t col);
    char position(size_t row, size_t col) const;

private:
    size_t m_height;
    size_t m_width;
    char *m_content;
};

#endif // PICTURE_H
