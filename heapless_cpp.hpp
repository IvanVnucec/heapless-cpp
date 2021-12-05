#ifndef HEAPLESS_CPP_HPP
#define HEAPLESS_CPP_HPP

namespace hlcpp
{

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

    unsigned len()
    {
        return L;
    }

    T& operator[](unsigned i)
    {
        return m_buffer[i];
    }
};


template <unsigned L, typename T=char>
class String : public Array<T, L>
{
private:
    unsigned m_len;

public:
    String()
    {
        this->m_buffer[0] = '\0';
        m_len = 0u;
    }

    ~String()
    {
    }

    unsigned len()
    {
        return m_len;
    }

};

}

#endif // #ifndef HEAPLESS_CPP_HPP
