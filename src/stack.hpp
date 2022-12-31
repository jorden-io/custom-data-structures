#include <iostream>
#include <map>
#include <vector>
namespace ds
{
    class stack
    {
    private:
        int count{0};
        std::map<int, int> m_container{};

    public:
        void push(stack &, int);
        int pop(stack &);
        void data(stack &);
        stack() = default;
        stack(int init)
        {
            m_container[count] = init;
            count++;
        };
        ~stack(){};

    private:
    };
    void ::ds::stack::data(ds::stack &s)
    {
        for (int i = 0; i < s.count; ++i)
        {
            std::cout << s.m_container[i] << std::endl;
        };
    };
    void ::ds::stack::push(ds::stack &s, int v)
    {
        s.m_container[count] = v;
        s.count++;
    };
    int ::ds::stack::pop(ds::stack &s)
    {
        if (s.m_container[s.count - s.count + 1] == 0 && s.count >= 0)
        {
            std::cout << "stack empty" << std::endl;
            return 0;
        };
        int emplace_v = s.m_container[s.count];
        s.m_container.erase(s.count);
        s.count--;
        return emplace_v;
    };
    // std::ostream &operator<<(std::ostream &out, std::vector<int> &a)
    // {
    //     for (int j = 0; j < std::size(a); ++j)
    //     {
    //         if (j == std::size(a) - 1)
    //         {
    //             out << "[" << a[j] << "]\n";
    //             break;
    //         };
    //         out << "[" << a[j] << "],";
    //     };
    //     return out;
    // };
    // std::ostream &operator<<(std::ostream &out, std::vector<std::string> *a)
    // {
    //     for (int j = 0; j < std::size(*a); ++j)
    //     {
    //         if (j == std::size(*a) - 1)
    //         {
    //             out << "" << (*a)[j] << "\n";
    //             break;
    //         };
    //         out << "" << (*a)[j] << ", ";
    //     };
    //     return out;
    // };
};