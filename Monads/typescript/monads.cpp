#include <iostream>
#include <utility>
#include <functional>
#include <string>
using namespace std;


template <typename T>
struct TypeWithLog{
    pair<T,string> unwrap;
};

pair<bool, string> negar(bool x){
    TypeWithLog<bool> type_wrap;
    type_wrap.unwrap = make_pair(!x,"Not!");
    return type_wrap.unwrap;
};
pair<bool, string> manter(bool x){
    TypeWithLog<bool> type_wrap;
    type_wrap.unwrap = make_pair(x,"Keep");
    return type_wrap.unwrap;
};
template<typename A, typename B>
function<TypeWithLog<bool>(A a)> 
    compose(function<TypeWithLog<B>>(A a)>foo,function<TypeWithLog<bool>>(B b)>bar){
        return [foo,bar](A x){
            auto p1 = foo(x).unwrap;
            auto p2 = bar(p1.first).unwrap;
            return make_pair(p2.first,p1.second+p2.second);
        };
    };

int main(){
    printf("%d",negar(false));
};