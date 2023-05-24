# Categoria de Kleisli
### Motivação:
Vamos começar com um problema real que encontramos no dia a dia na programação e que naturalmente nos leva para essa categoria. 

O código será escrito inicialmente em C++ por motivos de generalidade e depois o refatoraremos em Typescript. 

Imagine que estamos trabalhando em uma biblioteca de funções ou uma nova API e um dia seu chefe chega até você e diz "Então, tem um novo requerimento pra nossa API que eu não te informei antes, o requerimento é um sistema de auditoria das funções." 

E ele então te explica que por razões diversas, você é forçado a fazer com que todas as funções nessa biblioteca devem possuir ele sistema de auditoria, que basicamente ela deve criar pequeno um log dizendo que ela foi invocada e com quais argumentos ela foi invocada e qual argumento foi retornado por ela. 

Então agora você precisa reescrever toda a sua biblioteca de funções de modo que toda função gere esse log. 

nesse log terão as seguintes informações presentes: 
* O Nome da função invocada
* Os parâmetros que ela recebeu
* O que ela retornou
  
Como você implementaria esse tipo de função? 

Bom inicialmente a solução mais simples que poderíamos pensar seria de ter uma variável global log e que iriamos modificando ela conforme ela vai sendo usada. 
Vamos supor que temos a seguinte função negate em nosso código:

```cpp
    bool negate(bool x){
        return !x;
    }
```
Para refatorarmos isso na nova versão bastaria então por exemplo: 

```cpp
    string log = "";
    bool negate(bool x){
        log += "negate received x and returned not x"
        return !x;
    }
```

Mas claramente tem <strong>muita</strong> coisa errada com esse código. O primeiro é que ele está mutando o valor de um variável globalmente e tal variável não está nem mesmo sendo declarada como sendo parte do escopo da função. 

A função que tinha papel apenas inverter o valor de um bool, agora também modifica o valor de uma variável do tipo string que nem ao menos faz parte de seu escopo, ela está em um escopo global. 
Criamos uma dependência invisivel entre a função negate e a variável log. 

E para piorar, se essa implementação for realizada em absolutamente todas as funções da nossa biblioteca ou API, caso essa variável log seja deletada de alguma forma na hora de limpar o codigo para produção, de repente todas as nossas funções simplesmente parariam de funcionar! O que é simplesmente um grande desastre. 

E para piorar ainda, imagine que mais tarde o seu chefe chegue até você e te peça para que essa biblioteca funcione em multi-threads, você acaba de gerar um desastre maior ainda! 

Bom um primeiro passo pra arrumar essa bagunça seria primeiro retornar ao nosso estado original onde tinhamos funções puras. 
```cpp
pair<bool,string> negate(bool x){
        return make_pair(!x,"not")
    }
```
Mas aqui temos outro problema, pois agora apesar de nossa função ser pura e esse código ser muito mais funcional, estamos modificando o tipo de retorno da função negate de bool para pair<bool, string\>, ou seja qualquer função que dependesse do retorno da negate, pararia de funcionar pois não está recebendo o valor devido e teríamos que refatorar todo o código para modificar os tipos de entradas de todas as funções dependentes de negate... 

Essa solução... também é uma merda.

Para uma solução melhor vamos voltar ao que funções devem fazer de fato... composições! vamos compor uma função na outra para gerarmos a complexidade desejada. 

```cpp
    function<C(A)> compose(function<B(A))>f,function<C(B)>g){
        //
    }
``` 
Para podermos invocar as funções rapidamente dentro da nossa nova função, vamos usar um recurso chamado funções anônimas, ou "funções lambda". 

```cpp
    function<C(A)> compose(function<B(A))>f,function<C(B)>g){
        return [f,g](a x){
            auto p1 = f(x);
            auto p2 = g(p1);
            return p2;
        }
    }
``` 
Bom, até aqui tudo que fizemos foi implementar uma composição de funções convencional, nada mudou realmente na forma como compomos as funções. É agora que vamos adicionar algo novo aqui. 

Porque o que queremos é compor funções que retornem pares de tipos, não mais tipos únicos, então modificamos a função da seguinte maneira inicialmente:

```cpp
    function<pair<c,string>(A)>
    compose(function<pair<b,string>(A))>foo,
    function<pair<c,string>(B)>bar){
        return [foo,bar](a x){
            auto p1 = foo(x);
            auto p2 = bar(p1.first);
            return make_pair(p2.first, p1.second+p2.second);
        }
    }
``` 
bom o que fizemos aqui foi criar uma nova forma de compor funções, compondo funções que retornem pares de um tipo qualquer e uma string de log. 

Assim o papel de compor essas funções e unir os logs não é de fato da função, mas sim da nossa função especifica de composição. 

A solução ainda é uma bagunça e não resolve o problema de modificar o tipo de retorno de nossa função? Sim. Mas ao menos mantém nosso codigo com funções puras e respeitando a regra da responsabilidade única. 

Pois bem, nós acabamos de definir uma nova categoria! A categoria das funções que recebem um tipo a e retornam um tipo pair<b,string/>

porém essa é uma categoria especial pois ela não é uma categoria de morfismos do tipo:
$$
    f:a \to b
$$
Mas sim do tipo:
$$
    f:a \to P(b,string)
$$

Meus parabéns, pois acabamos de definir um Monad! E de fato, estas funções só são possiveis de serem compostas pois essa transformação sendo aplicada em B é um monad.

Ainda não somos capazes de entender o que é um monad de fato ainda, mas podemos já deixar claro que um monad é apenas uma forma de compor tipos especiais de funções. 

Se em algum momento em nosso código estamos redefinindo as regras de composição entre funções para ganhar esse novo grau de liberdade para sermos capazes de compor essas funções que normalmente não poderiam ser compostas, então de fato, nós já estamos usando um Monad.

Vamos reescrever esse Monad usando typescript agora. 

```ts
interface ITypeLogger <Type> {
    type:<T>;
    Log: String;
}
const typelog = {
    first:<type>,
    second:String
}

function negate(x:bool){
    return ITypeLogger
}