#include <iostream>
#include<string>

template <class T>
concept explicit_bool = std::same_as<T,bool>;

template <explicit_bool T>
std::pair<bool,std::string> negate(T x) {
    
    return std::make_pair(!x,"Not!");
};
template<explicit_bool T>
std::pair<bool,std::string> keep (T x){
  return std::make_pair(x,"Keep!");  
};
template<typename T>
std::pair<T,std::string> wrap (T x){
  return std::make_pair(x,"Wrap type!");  
};

template<typename A, typename B>
std::pair<A,std::string> compose(A a, B b, std::pair<A,std::string> (*func)(A)){
    return std::make_pair(func(a).first,"Composed!");
}

int main(){

    auto newcomposed =  wrap(15);
    std::cout << "The first element of newcompose is: " << newcomposed.first <<'\n';
    std::cout <<"The second element of newcompose is: " << newcomposed.second <<'\n';
    
    auto composed =  compose(false, true, &negate);
    std::cout <<std::boolalpha << "The first element of compose is: " << composed.first <<'\n';
    std::cout <<"The second element of compose is: " << composed.second <<'\n';
    
    
    return 0;
}