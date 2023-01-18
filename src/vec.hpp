#include <iostream>
#include <initializer_list>
#include <string>
namespace ds
{
    template <class T, size_t init_s = 2>
    class vec
    {
    public:
        enum class alloc_status
        {
            realloc,
            dealloc
        };
        friend std::ostream &operator<<(std::ostream &out, ds::vec<T> &v)
        {
            for (size_t i = 0; i < v.get_length(); i++)
            {
                out << v[i] << ", ";
            };
            return out;
        };

    private:
        size_t length{0};
        size_t cap{2};
        T *container{new T[this->cap]};
        void drealloc(alloc_status s)
        {
            switch (s)
            {
            case alloc_status::realloc:
                if ((*this).length >= (*this).cap)
                {
                    std::cout << "realloc\n";
                    this->cap *= 2;
                    T *new_container{new T[this->cap]};
                    for (int i = 0; i < this->length; i++)
                    {
                        new_container[i] = std::move(container[i]);
                    };
                    delete[] (this->container);
                    this->container = new_container;
                    return;
                };
            case alloc_status::dealloc:
                if ((*this).cap - (*this).length >= (*this).length * 2)
                {
                    std::cout << "dealloc\n";
                    this->cap = this->length + 1;
                    T *new_container{new T[this->cap]};
                    for (int i = 0; i < this->length; i++)
                    {
                        new_container[i] = std::move(container[i]);
                    };
                    delete[] (this->container);
                    this->container = new_container;
                    return;
                };
            };
        };

    public:
        T &operator[](T i)
        {
            return this->container[i];
        };
        vec() : cap(init_s)
        {
            this->drealloc(alloc_status::realloc);
        };
        vec(std::initializer_list<T> l)
        {
            int i{0};
            for (auto e : l)
            {
                container[i] = e;
                i++;
                cap++;
                length++;
            };
        };
        vec(vec &v) : length(v.length), cap(v.cap)
        {
            std::cout << "copied\n";
        }
        vec(vec &&v)
        {
            std::cout << "moved\n";
        }
        ~vec()
        {
            delete[] (container);
        };
        size_t get_cap() const
        {
            return this->cap;
        };
        size_t get_length() const
        {
            return this->length;
        };
        vec &push(T e)
        {
            if (length >= cap)
            {
                this->drealloc(alloc_status::realloc);
            };
            container[length++] = e;
            return *this;
        };
        T pop()
        {
            T temp_e = container[length];
            this->container[length] = 0;
            length--;
            this->drealloc(alloc_status::dealloc);
            return temp_e;
        };
    };
}