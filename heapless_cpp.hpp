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

}

#endif // #ifndef HEAPLESS_CPP_HPP
