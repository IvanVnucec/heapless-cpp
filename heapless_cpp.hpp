#ifndef HEAPLESS_CPP_HPP
#define HEAPLESS_CPP_HPP

namespace hlcpp
{

template <typename T, unsigned L>
class Array
{
private:
    T m_buffer[L];
    unsigned m_len = L;

public:
    Array()
    {
    }

    ~Array()
    {
    }

    unsigned len()
    {
        return m_len;
    }

};

}

#endif // #ifndef HEAPLESS_CPP_HPP
