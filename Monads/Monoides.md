## Definição de Monoid 

<div style="color:hsl(1000,20%,75%)"> <em>Um monoide é uma coleção de coisas + uma regra para combinar estas coisas entre si e esta regra deve satisfazer um outro conjunto de regras para ser válida. </em></div>

 De cara é possível compreender o poder latente por trás dos monoides. Pois eles nos permitem criar complexidade em nossos coódigos, partindo de conceitos mais simples. 

 começamos com funções puras e bem comportadas e através delas e como elas se juntam e interagem, podemos criar monoides para realizar ainda mais coisas com essas funções e podemos continuar compondo funções dessa forma, usando os monoides que definimos e as funções base para criar uma gam infinita de funções e complexidade em nosso código. 

Um exemplo fora do mundo da programação do que seria um monoide, temos um relógio. 

O conjunto de números em um relógio formam um monoide 
$$
    M = (N,\star)
$$

primeiro temos o conjunto $N=\{1,2,3,...,12\}$ este conjunto é nossa coleção de coisas. É o conjunto que contém as possíveis horas marcadas no relógio.

A nossa regra de associação $\star$ é a operação que nos permite pegar elementos do nosso conjunto e combiná-los de forma a permanecer dentro desta coleção. 

no caso de um relógio, seria a operação de somar as horas.
$$
    \star:x,y \in N \to N \\
    x \star y = x+y\bmod 12 
$$

ou seja o monoide $M = (N,\star)$

 é formado pelo conjunto $N$ e a regra de associação $\star$ 

 também poderiamos formar o Monoide $S(N,\bullet)$ onde $\bullet$ é a regra de associaciação válida envolvida com a subtração das horas do relógio. 

 é possivel notar também o conjunto de operações $\{\star,\bullet\}$ também formam um monoide $O$ das operações válidas dentro do contexto do monoide $M$ e assim poderiámos compor essas operações para criar operações mais complexas que ainda assim satisfariam o monoide $M$. 