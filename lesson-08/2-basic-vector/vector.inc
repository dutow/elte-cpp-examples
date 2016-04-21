

namespace mystd
{
    template<typename T>
    vector<T>::vector()
            : data(nullptr)
            , reservedSize(0)
            , realSize(0)
    {

    }
    template<typename T>
    vector<T>::~vector()
    {
        delete[] data;
    }

    template<typename T>
    void vector<T>::push_back(T item)
    {
        if (reservedSize < realSize + 1)
        {
                int newReservedSize = reservedSize;
               if (reservedSize == 0)
               {
                    newReservedSize = 1;
               } else {
                    newReservedSize *= 2;
               }

               T* newData = new T[newReservedSize];

               for(int i =0;i<reservedSize;++i)
               {
                    newData[i] = data[i];
               }

               delete[] data;
               data = newData;
               reservedSize = newReservedSize;
        }

        data[realSize++] = item; // realSize+=1;
    }

    template<typename T>
    T& vector<T>::operator[](int idx)
    {
        return data[idx];
    }

    template<typename T>
    T const& vector<T>::operator[](int idx) const
    {
    }
}