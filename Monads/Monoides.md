# Definição de Monoid 

<div style="color:hsl(1000,20%,75%)"> <em>Um monoide é uma coleção de coisas + uma regra para combinar estas coisas entre si e esta regra deve satisfazer um outro conjunto de regras para ser válida. </em></div>

 De cara é possível compreender o poder latente por trás dos monoides. Pois eles nos permitem criar complexidade em nossos códigos, partindo de conceitos mais simples. 

 começamos com funções puras e bem comportadas e através delas e como elas se juntam e interagem, podemos criar monoides para realizar ainda mais coisas com essas funções e podemos continuar compondo funções dessa forma, usando os monoides que definimos e as funções base para criar uma gama infinita de funções e complexidade em nosso código.

Em termos formais e gerais um monoide é definido da seguinte maneira:

$$
    M = (A,\circ)\\ \text{é dito um monoide se e somente se:} \;\\
     \forall x,y,z \in A \\ x \circ (y \circ z) = (x \circ y) \circ z \;\text{(associatividade)}\\
     \exists\, z\in A\,|\, x \circ z = x, z \circ x = x; \text{(identidade)}
$$

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

ou seja o monoide 
$$M = (N,\star)$$

 é formado pelo conjunto $N$ e a regra de associação $\star$ 

 também poderíamos formar o Monoide $S(N,\bullet)$ onde $\bullet$ é a regra de associação válida envolvida com a subtração das horas do relógio. 

 é possivel notar também o conjunto de operações $\{\star,\bullet\}$ também formam um monoide $O$ das operações válidas dentro do contexto do monoide $M$ e assim poderíamos compor essas operações para criar operações mais complexas que ainda assim satisfariam o monoide $M$.

 ## O monoide das funções

 Tendo isso em mente, podemos então compreender de forma mais geral e genérica o nosso monoide de funções. Lembrando que nós começamos como: 

$$
    x \to a \\
    f:a \to a \\
    g:a \to a
$$

Depois nós criamos a operação de composição e com ela obtivemos uma nova função:

$$
    h = f \circ g
$$
E provamos que esta nova função h vive n omesmo universo que as outras duas. 

$$
    x \to a \\
    f:a \to a \\
    g:a \to a \\
    h:a \to a \\
$$

Desta forma fica bem claro que o nosso monoide 
$$
    M = (F,\circ)
$$
é composto por $F = \{f,g,h,\dots\}$ o conjunto de nossas funções simples e a associação $\circ$ que compõe estas funções em novas funções pertencentes a $F$