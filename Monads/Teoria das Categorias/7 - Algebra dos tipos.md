# Algebra dos tipo
Vimos anteriormente que em um monoide a ideia de produto está sempre bem definida. Mas e quando falamos de produtos entre tipos? Como podemos correlacionar multiplicação com tipos de dados em uma linguagem de programação? Para isso surge a algebra dos tipos. 

## Multiplicação

podemos correlacionar a ideia de multiplicação com pares por exemplo. 

mas tomando os devidos cuidados. 

afinal na multiplicação:
$$
    a * b = b*a
$$
agora em código um par $(a,b)$ não é igual a um par $(b,a)$. 

Mas! Há um isomorfismo entre eles. 
Ou seja, existe um morfismo que nos leva de um par ao outro e esse morfismo é invertível. 
chamaremos-o de swap. 
$$
    swap:(a,b) \to (b,a)
$$
em implementação podemos fazer algo assim em c++:
```cpp
using namespace std;
template<typename A,typename B>
pair<B,A> swap(pair<A,B> p){
    return make_pair(p.second,p.first);
};
```
e algo assim em Typescript:
```ts
type pair<A,B> = {
    first:A;
    second:B;
}
function make_pair<A,B>(x:A,y:B):pair<A,B>{
    return {
        first:x, second:y
    };
}
function swap<A,B>(p:pair<A,B>):pair<B,A> {
    return {
        first:p.second,
        second:p.first
    };
}
```
Mas ai pode surgir a pergunta, swap possui associatividade com uma multiplicação? e a resposta é... não! Ao menos não normalmente. 
Afinal uma função que recebe como parâmetros $((a,b),c)$ não vai aceitar $(a,(b,c))$ mas novamente, os dois casos contém a mesma informação, ela apenas foi mudada de posição, neste caso então há um isomorfismo entre elas. 
Ou seja podemos escrever uma função por exemplo... assoc:
$$
    assoc: ((a,b),c) \to (a,(b,c))
$$
e novamente essa função apesar de um pouco mais complicada não é tão difícil assim de implementar. 

em c++:
```cpp
using namespace std;
template<typename A,typename B>
pair<A,pair<B,C>> assoc(pair<pair<A,B>,C> p ){
    return make_pair(p.first.first,make_pair(p.first.second,p.second));
};
```
em typescript:
```ts
type pair<A,B> = {
    first:A;
    second:B;
}
function make_pair<A,B>(x:A,y:B):pair<A,B>{
    return {
        first:x, second:y
    };
}
function assoc<A,B,C>(x:pair<pair<A,B>,C>):pair<A,pair<B,C>> {
    const new_pair = make_pair(x.first.second,x.second)
    return {
        first:x.first.first,
        second: new_pair
    };
}
```
Agora a ultima coisa que falta para definirmos um monoide neste caso é a unidade, a identidade. 

Qual seria o tipo que quando pareado com um outro tipo, devolve esse outro? 
Em multiplicação seria o número 1 certo? 
$$
    a*1 = a
$$
Mas no caso da categoria dos tipos, o que seria ele? seria o tipo unitario! 
então teriamos algo da forma $(a,())$ onde novamente isso não é equivalente a $a$, mas há um isomorfismo entre eles. digamos... m_unit. 
$$
    m\_unit: (a,()) \to a
$$
e uma inversa 
$$
    m\_unit_{invert}:a \to (a,())
$$
que a implementação é ainda mais trivial. 

Assim sendo, nós conseguimos definir que de fato temos um monoide formato em cima dos pares de 2 elementos. 

Mas esse conceito pode ser expandido para estruturas ainda maiores, pois se observarmos um par $(a,(b,c))$ é a mesma coisa que um trio $(a,b,c)$ apenas tendo mais etapas para acessar seus elementos internos. ja que para acessar c precisamos usar $par.second.second$ já se pegarmos uma estrutura maior como uma struct, usariamos simplesmente $struct.third$, onde $third$ apenas abrevia o caminho. 

Então em suma, estruturas maiores como structs com inúmeros elementos são montadas a partir da composição de pares. um par da forma $((a,b),(c,d))$ configura em uma estrutura $(a,b,c,d)$, se quisermos 5 elementos basta adicionar uma composição a um destes elementos. 
$((a,b),(c,(d,e)))$ por exemplo. 

Então assim finalizamos de definir este monoide em relação a multiplicação. 

Mas e quanto a soma?

## Soma

A correlação do código em relação a uma soma, pensando no ponto de vista de uma categoria e como seus morfismos conectam os objetos, a correlação mais direta seria com o operador Either.
$$
    Either: a,b \to a \;or\; b
$$
ou até com tipos como o triple. 
$$
    triple: a,b,c \to left\_a \lor middle\_b \lor right\_c
$$
em código, principalmente em haskell seriam implementações assim:
```ts
data Triple a b c = Left a | Middle b | Right c
``` 
para termos um monoide, precisariamos de uma identidade, qual seria o equivalente ao 0 da adição neste caso? void. 
$$
    Either: a,Void \to a
$$

O que nos permite então termos 2 monoides, um relacionado a adição e um com a multiplicação. 

E agora podemos combinar os dois. 
Vamos tentar reproduzir a distributividade da multiplicação em cima da adição. 
$$
    a*(b+c) = a*b + a*c
$$
em termos de código usando as funções que construímos teríamos algo como: 
$$
    (a,Either\, b,c) \to Either (a,b)\,(a,c)
$$
O que parando para pensar... sim faz todo o sentido. Afinal, Either retorna $b$ ou $c$, logo so há 2 pares possíveis $(a,b)$ ou $(a,c)$

Mas sim temos um problema, relacionado ao fato que não sabemos nem dividir nem subtrair, afinal obtemos tudo isso nos relacionando apenas com a ideia dos morfismos. 

Em matemática uma estrutura que possui adição e multiplicação desta maneira é chamada de "anel", no nosso caso um "semi-anel" pois não possuímos subtração nem divisão.

Mas vamos nos focar em mais correlações, qual seria a correção entre $2 = 1+1$ no nosso monoide de tipos? um booleano. 

Agora e quanto a algo mais geral como... $1+a$?

neste caso teremos um tipo de dado bem mais interessante. 

$$
    a+1 = b\\
    Either \; a,()
$$
Podemos então criar um novo tipo de dado chamado Maybe 
```cs
    data Maybe a = Nothing | Just a
```
Aqui apenas renomeamos alguns termos para uma forma que é mais comum de serem encontrados por ai. Just a é apenas o tipo a sem alteração, enquanto Nothing é... nada.
O que seria a implementação de Maybe em typescript? é bem simples. 
```ts
function Maybe<A>(x:A): void | A {
    if (x){
        return x;
    }
    console.error(`Error: Type error, entry has value ${x}`);
    return 
}
