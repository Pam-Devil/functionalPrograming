#include <iostream>
#include <utility>
#include <functional>
#include <string>
using namespace std;

template <typename T>
struct TypeWithLog{
    pair<T,string> unwrap;
};

TypeWithLog<bool> negar(bool x){
    TypeWithLog<bool> type_wrap;
    type_wrap.unwrap = make_pair(!x,"Not!");
    return type_wrap;
};
TypeWithLog<bool> manter(bool x){
    TypeWithLog<bool> type_wrap;
    type_wrap.unwrap = make_pair(x,"Keep");
    return type_wrap;
};
template<typename A, typename B>
function<TypeWithLog<bool>(A a)> 
    compose(function<TypeWithLog<B>(A a)>foo,function<TypeWithLog<bool>(B b)>bar){
        return [foo,bar](A x){
            auto p1 = foo(x).unwrap;
            auto p2 = bar(p1.first).unwrap;
            return make_pair(p2.first,p1.second+p2.second);
        };
    };
int main(){
    compose(negar(false),manter(true));
    return 0;
};