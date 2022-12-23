#include <iostream>
#include <map>
#include <functional>
#include "linked.hpp"
#include <algorithm>
#include <array>
#include <fstream>
#include <vector>
#define log(x) std::cout << x << "\n"
// template <typename T>
// auto bauto() -> T{};
// static int &function(int &r)
// {
//     r = 10;
//     return r;
// };
// int basted{1};
// void printFront_a()
// {
//     ::bauto<int>();
//     int new_b{::basted};
//     double casted{9.9};
//     log(casted);
//     int *new_c{(int *)&casted};
//     *new_c = 10;
//     int ptr_a[5]{97, 2, 3, 4, 5};
//     std::cout << ptr_a << std::endl;
//     std::cout << *ptr_a << std::endl;
//     std::cout << ptr_a[0] << std::endl;
//     std::cout << &ptr_a[0] << std::endl;
// };
// const int
// func(const int n)
// {
//     return n;
// };
// namespace Structures
// {
//     struct C
//     {
//         int x, y;
//     };
// }
// static int *memAllocInit(int amount, int bytes, int vals = 0)
// {
//     int *ptr{(int *)::calloc(amount, sizeof(bytes))};
//     for (int i = 0; i < amount; ++i)
//     {
//         ptr[i] = vals;
//     }
//     return ptr;
// };
// namespace enums
// {
//     enum class enumerator
//     {
//         i,
//         j,
//         k,
//     };
//     enum bnum
//     {
//         a,
//         l,
//     };
// }
// namespace Structures
// {
//     struct Build
//     {
//     private:
//         int b;

//     public:
//         int z;
//         void set_b()
//         {
//             Structures::Build::b = 10;
//         };
//         int *get_n()
//         {
//             return &b;
//             // return Structures::Build::&b;
//         };
//         int Build::create_n(){

//         };
//     };
// }
// Structures::Build makee(Structures::Build x)
// {
//     return x;
// };
// Structures::Build bb{};
// Structures::Build bbb = makee(bb);

// namespace mem_f
// {
//     auto mal_f(std::int64_t a) -> std::int64_t *&
//     {
//         std::int64_t *mal{(std::int64_t *)::calloc(10, sizeof(int))};
//         std::int64_t *ptr_a[10]{};
//         for (std::int64_t i = 0; i < std::size(ptr_a); ++i)
//         {
//             *&ptr_a[i] = &i;
//             std::cout << *ptr_a[i] << std::endl;
//         }
//         delete (mal);
//         return mal;
//     };
// }

// namespace DS
// {
//     template <typename T>
//     struct Stack
//     {
//         Stack(std::string s)
//         {
//             log(s);
//         };
//         ~Stack()
//         {
//             log("dead");
//         }
//         T array[10]{};
//         int count{0};
//         void push(T i)
//         {
//             array[count] = i;
//             count++;
//         }
//         int pop()
//         {
//             int temp{array[count]};
//             array[count] = array[count + 1];
//             count--;
//             return temp;
//         }
//         T peek()
//         {
//             return array[count];
//         }
//         void setZero()
//         {
//             for (int i = 0; i < std::size(Stack::array); ++i)
//             {
//                 Stack::array[i] = 0;
//             }
//         }
//     };
// }
class get_s
{
public:
    static int val;
    get_s()
    {
        get_s::val++;
    };
    static int get()
    {
        return val;
    };
};

template <typename T>
std::vector<T> *return_fv(std::ifstream &fStream)
{
    std::cout << "enter file"
              << "\n";
    std::string st;
    std::cin >> st;
    std::vector<T> *vector{new std::vector<T>};
    fStream.open(st);
    if (fStream.fail())
    {
        std::cout << "Failed" << std::endl;
    }
    else
    {
        while (!fStream.eof())
        {
            std::string ch{};
            fStream >> ch;
            vector->push_back(ch);
        };
    };
    fStream.close();
    return vector;
};
// using String = std::string;
// typedef std::string str;
bool func(int x, bool (*cb)(int), std::function<int(int, int)> new_cb)
{
    log(new_cb(100, 100));
    return cb(x);
};

bool cb(int x)
{
    if (x)
    {
        log(x);
        return true;
    };
    return false;
};
void take_f(int (*cb)(int, int))
{
    cb(10, 10);
};
int cb_o(int x, int y)
{
    return x + y;
};
int (*fn_ptr)(int, int);
std::function<int(int, int)> func_ptr{nullptr};
struct exe_s
{
    int m_x;
    exe_s(int x) : m_x{x}
    {
        std::cout << "made exe_s"
                  << "\n";
    };
};
exe_s *take(exe_s *ptr)
{
    log(ptr->m_x);
    return ptr;
};
std::vector<int> v_fn(int i, std::vector<int> (*fn)(std::vector<int> v))
{
    std::vector<int> *v = new std::vector<int>;
    fn(*v);
    return *v;
};
std::function<int(int, int)> fn_()
{
    return {[](int x, int y) -> int
            {log("from cb"); return 0; }};
};
namespace fn
{
    static const int *re_const()
    {
        static const int *c_int{new int};
        return c_int;
    };
    std::function<int(int)> take_c(int (*cb_fn)(int))
    {
        cb_fn(100);
        return cb_fn;
    };
};
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
        int &operator[](int i)
        {
            return this->container[i];
        };
        friend std::ostream &operator<<(std::ostream &out, vec &v)
        {
            for (int i = 0; i < v.get_length(); i++)
            {
                out << v[i] << ", ";
            };
            return out;
        };
        vec() : cap(init_s)
        {
            this->drealloc(alloc_status::realloc);
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
    template <class T>
    struct linked_list
    {
        ds::linked_list<T> *next{};
        T *val{new T};
        linked_list() { *val = 0; };
        linked_list(T e) { *val = e; };
        linked_list(linked_list &e)
        {
            if (e.next)
            {
                this->next = e.next;
            };
            *val = *e.val;
            log("copied");
        };
        linked_list(linked_list &&e) noexcept
        {
            log("moved");
            if (e.next)
            {
                next = std::move(e.next);
            };
            *val = std::move(*e.val);
        };
        linked_list(linked_list *&&e) noexcept
        {
            log("moved pointer");
            if (e->next)
            {
                next = std::move(e->next);
            };
            *val = std::exchange(*e->val);
        };
        ~linked_list()
        {
            delete (val);
            next = nullptr;
            log("deleted");
        };
        friend std::ostream &operator<<(std::ostream &out, ds::linked_list<T> ll)
        {
            ds::linked_list<T> *ll_next{&ll};
            while (ll_next->next)
            {
                if (*ll_next->next->val == 0)
                {
                    out << *ll_next->val << "";
                    break;
                };
                out << *ll_next->val << " -> ";
                ll_next = ll_next->next;
            };
            out << *ll_next->val;

            return out;
        };
        ds::linked_list<T> &operator=(ds::linked_list<T> &ll)
        {
            if (this == &ll)
            {
                return *this;
            };
            *val = *ll.val;
            next = ll.next;
        };
    };
    template <class T, size_t init_s = 10, size_t init_address_slots = 3>
    class hash_map
    {
    private:
        size_t clength{0};
        size_t csize{init_s};

    public:
        enum class alloc_status
        {
            realloc,
            dealloc,
        };
        size_t borrowed_addresses{0};
        ds::linked_list<T> *ll_mem_con{new ds::linked_list<T>[init_s] {}};
        ds::linked_list<T> *address_holder{new ds::linked_list<T>[init_address_slots] {}};
        hash_map(){
            // this->realloc(alloc_status::realloc);
        };
        hash_map(size_t new_init_s) : csize(new_init_s){};
        hash_map(hash_map &h_m)
        {
            std::cout << "copied\n";
            h_m.clength = this->clength;
            h_m.csize = this->csize;
        };
        ~hash_map()
        {
            delete[] (ll_mem_con);
            delete[] (address_holder);
        };
        size_t get_csize() const
        {
            return this->csize;
        };
        size_t get_clength() const
        {
            return this->clength;
        };
        ds::linked_list<T> &realloc(alloc_status a_status)
        {
            switch (a_status)
            {
            case alloc_status::realloc:
                std::cout << "tried to realloc\n";
                if (this->clength >= this->csize)
                {
                    std::cout << "reallocated\n";
                    this->csize *= 2;
                    ds::linked_list<int> *ll_buffer{new ds::linked_list<int>[csize] {}};
                    for (size_t i = 0; i < this->clength; i++)
                    {
                        if (*ll_mem_con[i].val != 0)
                        {
                            *ll_buffer[i].val = std::move(*this->ll_mem_con[i].val);
                            if (!!this->ll_mem_con[i].next)
                            {
                                ll_buffer[i].next = std::move(this->ll_mem_con[i].next);
                                ll_mem_con[i].val = 0;
                                ll_mem_con[i].next = nullptr;
                            };
                        };
                    };
                    delete[] (this->ll_mem_con);
                    this->ll_mem_con = std::move(ll_buffer);
                    return *ll_mem_con;
                };
                break;
            case alloc_status::dealloc:
                std::cout << "tried to dealloc\n";
                if (this->clength - this->csize >= this->clength * 2)
                {
                    std::cout << "deallocated\n";
                    this->csize = this->clength + 2;
                    ds::linked_list<int> *ll_buffer{new ds::linked_list<int>[csize] {}};
                    for (size_t i = 0; i < this->clength; i++)
                    {
                        *ll_buffer[i].val = std::move(*this->ll_mem_con[i].val);
                        if (!!this->ll_mem_con[i].next)
                        {
                            ll_buffer[i].next = this->ll_mem_con[i].next;
                        };
                    };
                    delete[] (this->ll_mem_con);
                    this->ll_mem_con = ll_buffer;
                    return *ll_mem_con;
                };
                break;
            };
        };
        // ds::hash_map &delete_e(char *sv_i)
        // {
        //     this->csize *= 2;
        //     ds::linked_list<int> *ll_buffer{new ds::linked_list<int>[csize] {}};
        //     for (size_t i = 0; i < this->clength; i++)
        //     {
        //         ll_buffer[i].val = this->ll_mem_con[i].val;
        //         // re:
        //         if (!!this->ll_mem_con[i].next)
        //         {
        //             ll_buffer[i].next = this->ll_mem_con[i].next;
        //             // if
        //         };
        //     };
        //     delete[] (this->ll_mem_con);
        //     this->ll_mem_con = ll_buffer;
        //     return *this;
        // };
        unsigned int hash(char *s_val)
        {
            assert(std::strlen(s_val) != 0);
            if (!s_val)
            {
                return 0;
            };
            unsigned int hash_v{0};
            for (size_t i = 0; i < std::strlen(s_val); i++)
            {
                hash_v += s_val[i];
                hash_v = (hash_v * s_val[i]) % this->csize;
            };
            return hash_v;
        };
        void zero_init()
        {
            for (int i = 0; i < 10; i++)
            {
                *this->ll_mem_con[i].val = i;
                this->ll_mem_con[i].next = &this->ll_mem_con[i + 1];
            };
            return;
        };
        int &operator[](char *s_v)
        {
            if (ll_mem_con[hash(s_v)].next)
            {
                if (*ll_mem_con[hash(s_v)].val != *ll_mem_con[hash(s_v)].next->val)
                {
                    unsigned int i = this->hash(s_v);
                    return *this->ll_mem_con[i].next->val;
                };
            }
            unsigned int i = this->hash(s_v);
            return *ll_mem_con[i].val;
        };

        ds::linked_list<T> &operator()(char *key, T e)
        {
            this->clength += 1;
            unsigned int i = this->hash(key);
            size_t re_tries{0};
            try
            {
                // if (*ll_mem_con[i].val != 0)
                // {
                //     size_t iter{1};
                //     if (*ll_mem_con[i + iter].val == 0)
                //     {
                //         *ll_mem_con[i].val = e;
                //     };
                // rel:
                //     if (*ll_mem_con[iter - iter - iter].val == 0)
                //     {
                //         *ll_mem_con[iter - iter - iter].val = e;
                //     };
                //     iter++;
                //     goto rel;
                // };
                if (*ll_mem_con[i].val && *ll_mem_con[i].val != e)
                {
                    ds::linked_list<T> *current_next = ll_mem_con[i].next;
                re:
                    if (re_tries > this->borrowed_addresses)
                    {
                        throw(re_tries);
                    };
                    re_tries++;
                    if (current_next)
                    {
                        if (!current_next->next)
                        {
                            current_next->next = std::move(&address_holder[borrowed_addresses++]);
                            *current_next->next->val = e;
                            return *current_next->next;
                        };
                        current_next = current_next->next;
                        goto re;
                    };
                    ll_mem_con[i].next = std::move(&address_holder[borrowed_addresses]);
                    *address_holder[borrowed_addresses++].val = e;
                    return ll_mem_con[i];
                };
                *ll_mem_con[i].val = e;
                return ll_mem_con[i];
            }
            catch (size_t tries)
            {
                std::cout << "too many tries, limit:" << tries << "/" << borrowed_addresses;
            };
        };
    };

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
std::ostream &operator<<(std::ostream &out, std::vector<int> &a)
{
    // marker:
    for (int j = 0; j < std::size(a); ++j)
    {
        if (j == std::size(a) - 1)
        {
            out << "[" << a[j] << "]\n";
            // goto marker;
            break;
        };
        out << "[" << a[j] << "],";
    };
    return out;
};
std::ostream &operator<<(std::ostream &out, std::vector<std::string> *a)
{
    for (int j = 0; j < std::size(*a); ++j)
    {
        if (j == std::size(*a) - 1)
        {
            out << "" << (*a)[j] << "\n";
            break;
        };
        out << "" << (*a)[j] << ", ";
    };
    return out;
};
int main(int argc, char *argv[])
{
    ds::hash_map<int> test_hash{};
    ds::linked_list<int> new_ll{10};
    ds::linked_list<int> copy_ll{std::move(new_ll)};
    *copy_ll.val = 1;
    log(*copy_ll.val);
    log(*new_ll.val);
    std::cin.get();
    test_hash.ll_mem_con[1].next = &test_hash.ll_mem_con[8];
    *test_hash.ll_mem_con[1].next->val = 10;
    log(*test_hash.ll_mem_con[1].next->val);
    // log(*test_hash.ll_mem_con[1].next->val);
    // log(*test_hash.ll_mem_con[1].next->val);
    std::cin.get();
    log(test_hash.hash("jessica"));
    log(test_hash.hash("lessica"));
    log(test_hash.hash("pessica"));
    log(test_hash.hash("vessica"));
    log("------------");
    std::cin.get();
    // test_hash.zero_init();
    //  test_hash["yoo"] = 1;
    //  log(test_hash["yoo"]);
    // log(*test_hash.ll_mem_con[test_hash.hash("jessica")].val);
    test_hash("jessica", 8008);
    // log(test_hash["jessica"]);
    test_hash("lessica", 9999);
    test_hash("pessica", 7777);
    test_hash("vessica", 5555);
    //   test_hash.adress_holder[0].next = &test_hash.ll_mem_con[6];
    //   log(*test_hash.adress_holder[0].next->next->next->val);
    std::cout << test_hash.address_holder[0];
    log("\n-------");
    log(test_hash.ll_mem_con[6]);
    log("-------");
    log(*test_hash.ll_mem_con[test_hash.hash("jessica")].val);
    log(*test_hash.ll_mem_con[test_hash.hash("jessica")].next->val);
    log(*test_hash.ll_mem_con[test_hash.hash("jessica")].next->next->val);
    log(*test_hash.ll_mem_con[test_hash.hash("jessica")].next->next->next->val);
    log("-------");
    test_hash.ll_mem_con[test_hash.hash("jessica")].next = &test_hash.ll_mem_con[1];
    *test_hash.ll_mem_con[1].val = 64;
    log(*test_hash.ll_mem_con[test_hash.hash("jessica")].next->val);
    log(test_hash["jessica"]);
    log("-------");
    test_hash.ll_mem_con[0].next = &test_hash.ll_mem_con[1];
    *test_hash.ll_mem_con[1].val = 10;
    std::cout << *test_hash.ll_mem_con[0].next->val << "\n"
              << std::endl;
    std::cin.get();
    log("------------");
    log(test_hash.hash("hey"));
    log(test_hash.hash("theyyy"));
    log(test_hash.hash("ayo"));
    log("------------");
    std::cout << *test_hash.ll_mem_con->next->val << std::endl;
    log("--------------");
    // ds::hash_map<int> hash_m{};
    // hash_m["new"] = 10000;
    // log(hash_m["new"]);
    // log("-----------");
    // log(hash_m["hey"]);
    // log("-----------");
    std::cin.get();
    exit(0);
    ds::vec<int> new_vec{};
    log(new_vec.get_cap());
    log(new_vec.get_length());
    new_vec.push(100);
    new_vec.push(64);
    new_vec.push(999);
    new_vec.push(80);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.push(72);
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    new_vec.pop();
    log("--------------");
    log(new_vec[0]);
    log(new_vec[1]);
    log(new_vec[2]);
    log(new_vec[3]);
    log(new_vec[4]);
    log(new_vec[5]);
    log("--------------");
    log(new_vec.get_cap());
    log(new_vec.get_length());
    log(new_vec[2]);
    log(new_vec);
    std::cin.get();
    exit(1);
    std::int_fast64_t *al_i{(std::int_fast64_t *)::calloc(10, 8)};
    *(al_i + 1) = 64;
    *(al_i + 2) = 999;
    log(al_i[2]);
    free(al_i);
    log(std::cout.binary);
    int arg{10};
    [argc, &arg]()
    {
        arg = 1000;
        log(argc);
    }();
    log(arg);
    std::ifstream new_if{};
    // std::vector<std::string> *r_fv{return_fv<std::string>(new_if)};
    // std::ostream *new_o{};
    std::vector<int> v_int{1, 1, 1, 1, 1, 1};
    operator<<(std::cout, v_int);
    // log(r_fv);
    new_if.close();
    // delete[](r_fv);
    const int *inty_p = fn::re_const();
    int *new_int_p = (int *)inty_p;
    *new_int_p = 19;
    log(*new_int_p);
    log(*inty_p);
    std::vector<int> arr_t{64, 256, 999, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 11};
    // log(arr_t);
    //  log(arr_t[0]);
    ds::stack s{};
    s.push(s, 200);
    s.push(s, 100);
    s.pop(s);
    s.data(s);
    log("stack---------");
    // s.pop();
    std::map<int, int> new_map{};
    new_map[1] = 10;
    log(new_map[1]);
    std::function<int(int)> new_f = fn::take_c([](int x)
                                               {
    std::cout << x * x << std::endl; 
    return 0; });
    log("fn--------------");
    new_f(10);
    log("fn--------------");
    std::vector<int> ve;
    v_fn(10, [](std::vector<int> vec)
         { return vec; });
    [&](std::vector<int> v) -> std::vector<int> *
    {
        std::vector<int> *vec{new std::vector<int>};
        return vec; }(ve);
    log(argc);
    int h = 10;
    int h_l = 9;
    for (int i{0}; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    };
    std::fstream new_fstream_f{};
    new_fstream_f.open(argv[1]);
    while (!new_fstream_f.eof())
    {
        std::string ch{};
        new_fstream_f >> ch;
        std::cout << ch << "\n";
    };
    new_fstream_f.close();
    {
        std::ofstream new_ostream_f{};
        new_ostream_f.open(argv[1]);
        std::cout << "write to file " << argv[1] << std::endl;
        std::string str_v;
        std::cin >> str_v;
        new_ostream_f << str_v;
        new_ostream_f << str_v;
        new_fstream_f.close();
    };
    exe_s *e_s = new exe_s{10};
    std::map<char *, int> map;
    map["first"] = 64;
    map["idk"] = 83;
    map["truth"] = 91;
    map["maoo"] = 26;
    map["bkeh"] = 77;
    std::cout << map["idk"] << std::endl;
    std::cout << "from map" << std::endl;
    take(e_s)->m_x = 20;
    log(e_s->m_x);
    delete (e_s);
    fn_ptr = [](int x, int y) -> int
    {
        log(x << y);
        return 0; };
    fn_ptr(90, 90);
    func_ptr = &cb_o;
    std::cout << func_ptr(20, 20) << std::endl;
    func(10, cb, [](int x, int y) -> int
         { return x + y; });
    int ptr_ar[10]{};
    int *i_ptr = ptr_ar;
    int size{(int)std::size(ptr_ar)};
    for (int i = 0; i < size; ++i)
    {
        ptr_ar[i] = i + 17;
        std::cout << ptr_ar[i] << std::endl;
    };
    for (int *ptr{ptr_ar}; *ptr < (ptr_ar[0] + size); ++ptr)
    {
        std::cout << "\n%v" << *ptr << std::endl;
    };
    for (int i{0}; i < size; ++i)
    {
        std::cout << *(ptr_ar + i) << std::endl;
    };
    log(*ptr_ar + 0);
    ptr_ar[1] = 10;
    log(*(ptr_ar + 1));
    std::ifstream newIFS;
    std::vector<std::string> *vec{return_fv<std::string>(newIFS)};
    for (int i = 0; i < vec->size(); ++i)
    {
        std::cout << (*vec)[i] << std::endl;
    };
    delete (vec);
    // newIFS.open("nums.txt");
    // if (newIFS.fail())
    // {
    //     std::cout << "failed"
    //               << "\n";
    // }
    // else
    // {
    //     while (!newIFS.eof())
    //     {
    //         char ch[]{};
    //         newIFS >> ch;
    //         std::cout << ch << std::endl;
    //     };
    // };
    const char *heyy = "hety";
    log(heyy);
    std::string val1, val2;
    newIFS >> val1 >> val2;
    log(val1);
    log(val2);
    // get_s *new_s1{new get_s{}};
    // get_s *new_s2{new get_s{}};
    // get_s *new_s3{new get_s{}};
    // log(get_s::val);
    show_l("hey");
    // this_t new_t{1, 2};
    // this_t new_t2{1, 2};
    // this_t new_t3{1, 2};
    // log(this_t::instiances);
    // std::cout << new_t3.x << "\n";
    // show_l("hey it worked");
    std::cin.get();
    // {
    //     ::DS::Stack<::Structures::Build> stacky{"he"};
    //     ::Structures::Build new_b{};
    //     ::Structures::Build new_b2{};
    //     ::Structures::Build *build_o = new Structures::Build{};
    //     build_o->set_b();
    //     *build_o->get_n() = 245;
    //     log(*build_o->get_n());
    //     log("----------");
    //     *new_b.get_n() = 4893;
    //     log(*new_b.get_n());
    //     log("----------");
    //     printFront_a();
    //     log("----------");
    // }
    // std::int64_t *test_p{mem_f::mal_f(1)};
    // for (int i{0}; i < 10; ++i)
    // {
    //     test_p[i] = i;
    //     std::cout << test_p[i] << "\n";
    // };
    // DS::Stack<int> stack{"hello world"};
    // for (int i = 0; i < std::size(stack.array); ++i)
    // {
    //     std::cout << stack.array[i] << "\n";
    // }
    // log("--------");
    // log(stack.count);
    // log("--------");
    // log(*mem_f::mal_f(10) + 10);
    //  int i = 10;
    //  int newI = 82;
    //  log(func(newI));
    //  int newT = bbb.z;
    //  log(newT);
    //  struct system
    //  {
    //      std::int64_t s;
    //      std::int64_t b;
    //      void task(int take)
    //      {
    //          std::cout << take << "\n";
    //      };
    //  };
    //  enums::enumerator val{enums::enumerator::k};
    //  int *newval = &(int &)val;
    //  int *newptr = (int *)val;
    //  log(*newval);
    //  system *newS = new system{};
    //  system newSts{.b{123}};
    //  system *newerSts{&newSts};
    //  log(newerSts->b);
    //  newerSts->task(98);
    //  newS->b = 104893;
    //  system *msp[]{};
    //  system *news = new system{};
    //  int fjd = (*news).b;
    //  int dhjks = (*msp[0]).b;
    //  int from = msp[0]->b;
    //  system ms[3]{{
    //                   .b{},
    //                   .s{},
    //               },
    //               {.b{}, .s{}},
    //               {.b{}, .s{}}};
    //  for (int i = 0; i < std::size(ms); i++)
    //  {
    //      std::cout << ms[i].s << "\n";
    //  };
    //  int arr[10]{};
    //  std::size(arr);
    //  log(newS->b);
    //  delete (newS);
    //  system doer{};
    //  doer.task(232);
    //  std::cout << *&*&(*(int *)(&newptr)) << std::endl;
    //  system l{.s = 64, .b = 94};
    //  std::cout << l.s << "\n";
    //  std::cout << static_cast<int>(val) << "\n";
    //  std::cout << (int)(val) << "\n";
    // Structures::C c = {64, 32};
    // printf("vals are %d, %d\n", c.x, c.y);
    // int *malloced = memAllocInit(10, sizeof(int), 10);
    // free(malloced);
    // for (int i = 0; i < 10; ++i)
    // {
    //     std::cout << malloced + i << "\n";
    //}
    return 0;
}