#include "picture.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

Picture::Picture() : m_height(0), m_width(0), m_content(0)
{

}

Picture::Picture(size_t h, size_t w, char c) : m_height(h), m_width(w), m_content(0)
{
    m_content = new char[m_height*m_width];
    memset(m_content, c, m_height*m_width);
}

Picture::Picture(char **ss, size_t num)
{
    m_height = num;

    m_width = 0;
    for (size_t i=0; i<num; ++i)
        m_width = std::max(m_width, strlen(ss[i]));

    m_content = new char[m_height*m_width];

    for (size_t row=0; row<m_height; ++row)
    {
        size_t len = strlen(ss[row]);
        for (size_t col=0; col<m_width; ++col)
        {
            size_t pos = row*m_width + col;
            if (col<len)
            {
                m_content[pos] = ss[row][col];
            }
            else
            {
                m_content[pos] = char(' '); // 空格符
            }
        }
    }

    std::cout << "m_height=" << m_height << " m_width="<< m_width << std::endl;
}

Picture::Picture(const Picture &other) :
    m_height(other.m_height), m_width(other.m_width)
{
    std::cout << "copy-ctor-m_height=" << m_height << " m_width="<< m_width << std::endl;
    m_content = new char[m_height*m_width];
    strncpy(m_content, other.m_content, m_height*m_width);

    std::cout << "copy-ctor-len=" << strlen(m_content) << std::endl;
}

Picture &Picture::operator=(const Picture &rhs)
{
    if (this != &rhs)
    {
        std::cout << "rhs.m_height=" << rhs.m_height << " rhs.m_width="<< rhs.m_width << std::endl;

        char *oldContent = m_content;
        char *newContent = new char[rhs.m_height*rhs.m_width];
        strncpy(newContent, rhs.m_content, rhs.m_height*rhs.m_width);

        m_height = rhs.m_height;
        m_width  = rhs.m_width;
        m_content = newContent;

        delete[] oldContent;
    }

    return *this;
}

Picture::~Picture()
{
    delete[] m_content;
}

void Picture::print(std::ostream &os) const
{
    for (size_t row=0; row<m_height; ++row)
    {
        for (size_t col=0; col<m_width; ++col)
        {
            size_t pos = row*m_width + col;
            os << m_content[pos];
        }
        os << std::endl;
    }
}

char &Picture::position(size_t row, size_t col)
{
    return m_content[row*m_width + col];
}

char Picture::position(size_t row, size_t col) const
{
    return m_content[row*m_width + col];
}


Picture frame(const Picture &p)
{
    size_t h = p.m_height + 2;
    size_t w = p.m_width  + 2;

    Picture fp(h, w, '*');
    for (size_t row=0; row<h; ++row)
    {
        if (row==0 || row==h-1)
        {
            for (size_t col=0; col<w; ++col)
            {
                if (col==0 || col==w-1)
                    fp.position(row, col) = '+';
                else
                    fp.position(row, col) = '-';
            }
        }
        else
        {
            for (size_t col=0; col<w; ++col)
            {
                if (col==0 || col==w-1)
                    fp.position(row, col) = '|';
                else
                    fp.position(row, col) = p.position(row-1, col-1);
            }
        }
    }

    return fp;
}

Picture operator |(const Picture &p, const Picture &q)
{
    size_t h = std::max(p.m_height, q.m_height);
    size_t w = p.m_width + q.m_width;

    Picture fp(h, w, '*');

    return fp;
}

Picture operator &(const Picture &p, const Picture &q)
{
    size_t h = p.m_height + q.m_height;
    size_t w = std::max(p.m_width, q.m_width);

    Picture fp(h, w, '*');

    return fp;
}
