#include <iostream>
namespace ds
{
    template <class T>
    struct linked_list
    {
        ds::linked_list<T> *next{nullptr};
        T *val{new T{0}};
        char *key{};
        linked_list() { *val = 0; };
        linked_list(T e) { *val = e; };
        linked_list(linked_list &e)
        {
            if (e.next)
            {
                next = e.next;
                *next->val = e.next->val;
            };
            *val = *e.val;
            std::cout << "copied\n";
        };
        linked_list(linked_list &&e) noexcept
        {
            if (e.next)
            {
                next = std::move(e.next);
                *next->val = *e.next->val;
            };
            *val = *e.val;
            std::cout << "moved\n";
        };
        linked_list(linked_list *&&e) noexcept
        {
            if (e->next)
            {
                next = std::move(e->next);
            };
            *val = *e->val;
            std::cout << "moved ptr\n";
        };
        ~linked_list() = default;
        friend std::ostream &operator<<(std::ostream &out, ds::linked_list<T> &ll)
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
        ds::linked_list<T> &address_h_realloc(alloc_status a_status = alloc_status::realloc)
        {
            try
            {
                switch (a_status)
                {
                case alloc_status::realloc:
                    if (this->borrowed_addresses > sizeof(address_holder) / sizeof(int) + 1)
                    {
                        this->borrowed_addresses *= 2;
                        ds::linked_list<T> *ll_buffer{new ds::linked_list<T>[this->borrowed_addresses] {}};
                        for (size_t i = 0; i < this->borrowed_addresses; i++)
                        {
                            *ll_buffer[i].val = *address_holder[i].val;
                            ll_buffer[i].key = address_holder[i].key;
                            if (address_holder[i].next)
                            {
                                ll_buffer[i].next = address_holder[i].next;
                                *ll_buffer[i].next->val = *address_holder[i].next->val;
                            };
                        };
                        delete[] (this->address_holder);
                        this->address_holder = std::move(ll_buffer);
                        return address_holder[0];
                    };
                    return address_holder[0];
                case alloc_status::dealloc:
                    std::cout << "deallocated";
                    break;
                };
            }
            catch (size_t tries)
            {
                std::cout << "too many tries\n";
            };
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
                    for (size_t i = 0; i < this->csize; i++)
                    {
                        if (!&ll_mem_con[i])
                        {
                            *ll_buffer[i].val = *this->ll_mem_con[i].val;
                            ll_buffer[i].key = this->ll_mem_con[i].key;
                            ds::linked_list<T> *current_next = ll_mem_con[i].next;
                            if (current_next->next)
                            {
                                ll_buffer[i].next = this->ll_mem_con[i].next;
                                ll_buffer[i].next->key = ll_mem_con[i].key;
                                *ll_buffer[i].next->val = *ll_mem_con[i].val;
                            };
                            current_next = current_next->next;
                        };
                    };
                    delete[] (this->ll_mem_con);
                    this->ll_mem_con = std::move(ll_buffer);
                    return *ll_mem_con;
                };
                return *ll_mem_con;
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
                            ll_buffer[i].next->key = ll_mem_con[i].key;
                            *ll_buffer[i].next->val = *this->ll_mem_con[i].next->val;
                        };
                    };
                    delete[] (this->ll_mem_con);
                    this->ll_mem_con = ll_buffer;
                    return *ll_mem_con;
                };
                return *ll_mem_con;
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
            unsigned int i = this->hash(s_v);
            if (ll_mem_con[i].key == s_v)
            {
                return *ll_mem_con[i].val;
            }
            else
            {
                try
                {
                    ds::linked_list<T> *current_next = ll_mem_con[i].next;
                    size_t re_tries{0};
                re:
                    if (re_tries > borrowed_addresses)
                    {
                        throw(re_tries);
                    };
                    if (current_next->key == s_v)
                    {
                        return *current_next->val;
                    }
                    else
                    {
                        current_next = current_next->next;
                        goto re;
                    };
                }
                catch (size_t tries)
                {
                    std::cout << "too many tries\n";
                }
            };
        };

        ds::linked_list<T> &operator()(char *key, T e)
        {
            this->clength += 1;
            realloc(alloc_status::realloc);
            unsigned int i = this->hash(key);
            size_t re_tries{0};
            try
            {
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
                            current_next->next->key = key;
                            *current_next->next->val = e;
                            return *current_next->next;
                        };
                        current_next = current_next->next;
                        goto re;
                    };
                    ll_mem_con[i].next = std::move(&address_holder[borrowed_addresses]);
                    address_holder[borrowed_addresses].key = key;
                    *address_holder[borrowed_addresses++].val = e;
                    return ll_mem_con[i];
                };
                ll_mem_con[i].key = key;
                *ll_mem_con[i].val = e;
                return ll_mem_con[i];
            }
            catch (size_t tries)
            {
                std::cout << "too many tries, limit:" << tries << "/" << borrowed_addresses;
            };
        };
    };
};