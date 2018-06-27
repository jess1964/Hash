#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class Hash
{
private:
    struct Hashlib
    {
        string a;
        Hashlib *next;
    };
/////////////////////////////////////////////////////
    Hashlib **table;
    int len; // capacity
////////////////////////////////////////////////////
    int HASH(string s)
    {
        int sum = 0;
        for(int i = 0; i < s.length();i++)
        {
            sum+= (s[i] + 0);
        }
        sum = sum%len;
        return sum;
    }
////////////////////////////////////////////////////
public:
    Hash(int i)
    {
        table = new Hashlib*[i];
        for(int x = 0; x < i; x++)
        {
            table[x] = NULL;
        }
        len = i;
    }
///////////////////////////////////////////////////////
    Hash(Hash &rhs)
    {
        operator=(rhs);
    }
///////////////////////////////////////////////////////
    ~Hash()
    {
               Hashlib *ender;
        Hashlib *holder;
        for(int i = 0; i < len; i++)
        {
            ender = table[i];
            while(ender)
            {
                holder = ender;
                ender = ender->next;
                delete holder;
            }
        }
        delete [] table;
    }
///////////////////////////////////////////////////////
    Hash& operator=(Hash& rhs)
    {
            delete []table;
            table = new Hashlib*[rhs.len];
            for(int x = 0; x < rhs.len; x++)
            {
                table[x] = NULL;
            }
            len = rhs.len;
            table = new Hashlib*[rhs.len];
            for(int x = 0; x < rhs.len; x++)
            {
                table[x] = NULL;
            }
        Hashlib *holder;
        for(int i = 0; i < rhs.len;i++)
        {
            holder = rhs.table[i];
            while(holder)
            {
                insert(holder->a);
                holder = holder->next;
            }
        }
        return *this;
    }
///////////////////////////////////////////////////////
    bool operator == (const Hash & rhs)
    {
        int num[2];
        num[0] = size();
        num[1] = rhs.size();
        if(num[0] == num[1])
        {
            return 1;
        }
        return 0;
    }
///////////////////////////////////////////////////////
    bool operator <(const Hash& rhs)
    {
        int num[2];
        num[0] = size();
        num[1] = rhs.size();
        if(num[0] < num[1])
        {
            return 1;
        }
        return 0;
    }
///////////////////////////////////////////////////////
    int insert(string s)
    {
        int location = HASH(s);
        Hashlib *marker;
        Hashlib *newNode;
        newNode = new Hashlib;
        newNode->a = s;
        newNode->next = NULL;
        if(table[location])
        {
            marker = table[location];
            while(marker->next)
            {
                marker = marker->next;
            }
            marker->next = newNode;
            return 0;
        }
        if(!table[location])
        {
            table[location] = newNode;
            return 0;
        }
        return -1;
    }
///////////////////////////////////////////////////////
    int remove(string s)
    {
        int locate;
        locate = HASH(s);
        Hashlib *hold;
        Hashlib *deleter;
        hold = table[locate];
        if(hold->a == s)
        {
            if(hold->next)
            {
                deleter = hold;
                table[locate] = hold->next;
                deleter = NULL;
                delete deleter;
                return 0;
            }
            if(!hold->next)
            {
                deleter = hold;
                table[locate] = NULL;
                deleter = NULL;
                delete deleter;
                return 0;
            }

        }
        if(hold->a != s)
        {
            while(hold->next)
            {
                if(hold->next->a == s)
                {
                   deleter = hold->next;
                   if(!hold->next->next)
                   {
                       hold->next = NULL;
                       deleter = NULL;
                       delete deleter;
                       return 0;
                   }
                   if(hold->next->next)
                   {
                       hold->next = hold->next->next;
                       deleter = NULL;
                       delete deleter;
                       return 0;
                   }
                }
                hold = hold->next;
            }
        }
        return -1;
    }
///////////////////////////////////////////////////////
    bool find(string s)
    {
        Hashlib *holder;
        int finder = HASH(s);
        if(table[finder]->a == s)
        {
            return 1;
        }
        if(table[finder]->a != s)
        {
            holder = table[finder];
            while(holder)
            {
                if(holder->a == s)
                {
                    return 1;
                }
                holder = holder->next;
            }
            return 0;
        }
        return 0;
    }
///////////////////////////////////////////////////////
    void clear()
    {
        Hashlib *ender;
        Hashlib *holder;
        for(int i = 0; i < len; i++)
        {
            ender = table[i];
            while(ender)
            {
                holder = ender;
                ender = ender->next;
                delete holder;
            }
        }

        for(int i = 0; i < len; i++)
        {
            table[i] = NULL;
        }
    }
///////////////////////////////////////////////////////
    bool isFull()const
    {
        for(int i = 0; i < len; i++)
        {
            if(!table[i])
            {
                return 0;
            }
        }
        return 1;
    }
///////////////////////////////////////////////////////
    bool isEmpty()const
    {
        for(int i = 0; i < len; i++)
        {
            if(table[i])
            {
                return 0;
            }
        }
        return 1;
    }
///////////////////////////////////////////////////////
    int size() const
    {
        Hashlib *ptr;
        int counter = 0;
        for(int i = 0; i < len; i++)
        {
          ptr = table[i];
          while(ptr)
          {
              ptr = ptr->next;
              counter++;
          }
        }
        return counter;
    }
///////////////////////////////////////////////////////
    void print()
    {
        Hashlib *printer;
        for(int i = 0; i < len; i++)
        {
            printer = table[i];
            while(printer)
            {
                cout << printer->a << "\n";
                printer = printer->next;
            }
        }
        cout << endl;
    }
///////////////////////////////////////////////////////
};
