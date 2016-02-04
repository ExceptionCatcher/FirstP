#include <iostream>
#include <typeinfo>
#include "mingw.thread.h"
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
struct F
{
    F(T a)
    {
    }
};

template<typename... R>
class Variadic{
public:
    static const std::size_t value = sizeof...(R);
    int tomb[value];
    template<typename T>
    int func(T t){
        //cout<<t<<endl;
        //cout<<typeid(T).name()<<endl;
        return t;
    }

    Variadic(R... r){
        //cout<<value<<endl;
        int tomb[] = {(func<R>(r))...}; //{0, (func<R>(r), 0)...};
        for (int i = 0; i < value; i++){
            cout<<tomb[i]<<endl;
            this->tomb[i] = tomb[i];
        }

    }
};


template<typename... T>
void adder(T... t){
    const int s = sizeof...(t);
    int values[s] = {t...};
    int sum = 0;
    for (unsigned i = 0; i < s; i++){
        sum+=values[i];
    }
    cout<<sum<<endl;
}

void fv(){
    cout<<"Hello";
}


class Functor {
public:
    int x;
    Functor(int x){
        this->x=x;
    }

    int operator()(int y){
        cout<<"RUN"<<endl;
       return this->x + y;
    }

    double operator() (double d){
        return this->x + d;
    }

    int operator [] (int y){
        return this->x + y;
    }
    bool operator < (Functor functor){
        return functor.x > this->x ? true:false;
    }
};

struct A{
    int a;
    double b;
    string c;
    A(int a, double b, string c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};


class Comparator {
    public:
        char attribute;
        Comparator(char attribute):attribute(attribute){}
    bool operator()(const A & a1, const A & a2){
        if (attribute == 'a')
            return a1.a < a2.a;
        else if (attribute == 'b')
            return a1.b < a2.b;
        else
            return a1.c < a2.c;
    }
};

void get_primes(const unsigned & n){
    vector<unsigned> primes;
    int i = 2;
    while (i < n){
        bool isPrime = true;
        int j = 2;
        while (j < i && isPrime){
            if (i % j == 0){
                isPrime = false;
            }
            j++;
        }
        if (isPrime)
            cout<<"Prime: " <<i<<endl;
        i++;
    }
}

void int_printer(int n){
    int i = 0;
    while (i < n){
        cout<<i<<endl;
        i++;
    }
}

int main()
{
    //F<int> s(10);
    /*Variadic<int, int, int, int, int, int> v(10, 13, 3, 1, 99, -1);
    adder(10,10,10);

    cout<<"--------Functor------------"<<endl;
    Functor functor(5);
    cout<<functor(10)<<endl;
    cout<<functor(12)<<endl;
    cout<<functor(3.12)<<endl;
    cout<<functor[-5]<<endl;
    Functor functor2(6);
    bool res = functor<functor2;
    cout<<res<<endl;*/


    /*cout<<"--------Comp----------"<<endl;
    A a1(10,1.2,"asd");
    A a2(9,2.2,"xd");
    A a3(111,0.11,"de");
    vector<A> a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    //std::thread t(fv);
    Comparator comparator('b');
    std::sort(a.begin(), a.end(), comparator);
    for (size_t i = 0; i < a.size(); i++){
        cout<<a[i].a<< " " << a[i].b << " " << a[i].c<<endl;
    }



    auto func = [] (int q, int w) -> int{
        return q + w;
    };
    int q = 110;
    int w = 70;
    cout<<func(q, w)<<endl;

    int total = 0;
    for_each(a.begin(), a.end(), [&total] (A i) {
             total+=i.a;
             });*/
    /*
    thread t1(get_primes, 100000);
    thread t2(int_printer, 100000);
    t1.join();
    t2.join();*/




    return 0;
}
