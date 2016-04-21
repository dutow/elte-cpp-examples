
#pragma once

namespace mystd
{
    template<typename T>
    class vector
    {
    public:
        vector();
        ~vector();
        
		vector(vector const& other) = delete;

        vector& operator=(vector const&) = delete;

        T& operator[](int idx);
        T const& operator[](int idx) const;

        void push_back(T item);
    private:
        T* data;
        int reservedSize;
        int realSize;
    };
}



#include "vector.inc"
