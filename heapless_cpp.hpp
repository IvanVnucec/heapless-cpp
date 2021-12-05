#ifndef HEAPLESS_CPP_HPP
#define HEAPLESS_CPP_HPP

namespace hlcpp
{

#include <cstring>

template <typename T, unsigned L>
class Array
{
protected:
    T m_buffer[L];

public:
    Array()
    {
    }

    ~Array()
    {
    }

    Array(const Array& t)
    {
        for (unsigned i = 0u; i<t.len(); i++)
            m_buffer[i] = t[i];
    }

    unsigned len() const
    {
        return L;
    }

    T& operator[](unsigned i)
    {
        return m_buffer[i];
    }

    T operator[](unsigned i) const
    {
        return m_buffer[i];
    }

    Array& operator=(const Array& t)
    {
        for (unsigned i = 0u; i<t.len(); i++)
            m_buffer[i] = t[i];

        return *this;
    }

};


template <unsigned L, typename T=char>
class String : public Array<T, L>
{
    static_assert(L >= 1);
private:
    unsigned m_len;

public:
    String()
    {
        this->m_buffer[0] = '\0';
        m_len = 0u;
    }

    String(const char* str)
    {
        std::strcpy(this->m_buffer, str);
        m_len = std::strlen(this->m_buffer);
    }

    ~String()
    {
    }

    unsigned len()
    {
        return m_len;
    }

    const char* to_cstr()
    {
        return this->m_buffer;
    }

};

}

#endif // #ifndef HEAPLESS_CPP_HPP
