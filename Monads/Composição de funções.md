## Compondo funções
primeiramente, para compreendermos a natureza dos monoids, primeiro vamos entender sobre composição de funções. 

Suponhamos a seguinte situação:
$$
    x \to a \\
    f:a \to a \\
    g:a \to a
$$

Temos então duas funções f e g, que recebem um parâmetro x do tipo a e retornam algo também de tipo a. 

Agora considerando que funções e variáveis são... a mesma coisa na visão da programação funcional, isso significa que podemos passar f \text{ou} g como argumento uma da \text{ou}tra. 

Afinal, se o retorno de f e g são ambos do tipo a e ambas são funções puras, logo é natural tratar f e g como sendo dados do tipo a .

em notação normal poderiamos representar como algo assim:
- - - 
```ts
    let x:Type;
    function f(x:a): a {
        //...
    }
    function g(x:a): a {
        //...
    }
```
- - -
então de forma generalizada, a composição das duas funçoes f e g seria representada  da seguinte forma:
$$
    f(g(x \to a))
    \text{ ou }
    g(f(x \to a))
$$
Porém, esse notação viraria uma bagunça rapidamente, então amos simplificar ela um pouco.

$$
    f(g(a))
    \text{ ou }
    g(f(a))
$$

\text{ou} se quisermos simplificar ainda mais:

$$
    f(g\,a) 
    \text{ ou }
    g(fa) 
$$

Essa notação é muito usada em linguagens de programação funcional como o F# e o Haskell. 
- - - 
Em notação normal esse codigo seria representado da seguinte forma:


```ts
    let x:a;
    function f(x:a): a {
        //...
    };
    function g(x:a): a {
        //...
    };
    let composition = f(g(x));

/** Considerando que como f sempre retorna algo do tipo a,
    logo composition também é do tipo a . 
**/
```
- - -
Até o momento representamos a composição das duas funções e f e g apenas como dados, mas também é possível realizar composições que resultam em novas funções! E é ai que a brincadeira toda da programação funcional começa. 

assim vamos introduzir na nossa notação genérica um novo conceito que é o de composição de funções em novas funções. 

$$
    (f \circ g)\,a = f(g\,a)
$$ 
Se quisermos expandir a definição dessa nova função podemos chamá-la de $h$. Devemos lembrar que como $h$ por definição é igual a composição logo $h$:
$$
    h = (f \circ g) \\
    h(x \to a) = (f(g(x \to a))) \\ 
    let \; g(x \to a) = y \implies y \to a \\
    h(x \to a) = (f(y \to a)) \\
    \text{Usando da mesma lógica:}\\ 
    h(x \to a) = (f(a)\to a) \\ 
    h(x \to a) \to a
$$

$$h:a \to a$$
- - - 

Repare só numa coisa, nós pegamso duas funções iniciais, com um mesmo tipo em comum e usamos as duas para construir uma nova função que é do exato mesmo tipo. 

Basicamente usamos dois conceitos bases e usamos os dois em conjunto para construir um novo conceito mais avançado, mas que herda da principal caracteristica dos anteriores, o seu tipo de entrada e retorno. 

Pois meus parabéns, pois acabamos de criar um monoide! 
