# Lidando com o construtor de tipos
Voltando para o nosso caso geral, temos o seguinte monoide:
$$
    \Omega^\star = (F^\star,\bullet) \\
    x \to a \\
    f:a \to Ma \\
    g:a \to Ma \\
    h:a \to Ma \\
$$
Onde $M$:
$$
    x \to a\\
    M:a \to Ma
$$

Precisamos então de uma forma de lidar com essa nova transformação $M$ de uma forma mais generalizada. Para isso vamos adotar a notação de funções lambda. Em typescript, funções lambda nao passam de arrow functions como já estamos acostumados a usar. 

```ts
    const lambda = (a) => {

    }
``` 

Em haskell e outras linguagens de programação funcionais a declaração de expressões lambda são bem mais parecidas com a da notação geral é com ela que vamos trabalhar primeiro. 

$$
    \lambda a \to (fa)\implies \lambda a \to (ga)
$$

Certo, olhando assim parece uma coisa de outro mundo, mas se olharmos para as tipagens do que está acontecendo, é bem simples. 
De um lado temos $\lambda a \to (fa)$ que por sim só retorna $Ma$. 

O outro lado temos a mesma coisa $\lambda a \to (ga)$ o que retorna $Ma$

ou seja do ponto de vista apenas dos tipos retornados nós temos: 
$$
    Ma \implies Ma
$$

O único mistério que nos resta agora é o que diabos é esse novo operador "$\implies$" entre as duas funções. 

Este operador comumente é chamado de bind, ou shove. 

A questão é que primeiramente a nossa expressão está incompleta. A real operação é essa: 
$$
    \lambda a \to (\,(fa)\implies \lambda a \to (ga)\,)
$$

Agora sim se analisarmos melhor os tipos sendo declarados e passados nos temos 
$$
    \lambda a \to (Ma \implies a \to Ma)\\
    \lambda a \to Ma
$$

Ou seja, por mais que esse novo operador exista entre eles, no fim a nossa nova expressão lambda ainda é um membro do nosso monoide $\Omega^\star$.

O real problema que temos aqui é o fato que há uma perda de simetria entre os dois lados da operação de bind. 

De um lado temos $Ma$ já do outro temos uma função que retorna $Ma$, ambos são essencialmente diferentes.

E é por esse motivo que precisamos envolver toda a expressão entre estes parenteses, pois note oque aconteceria caso a primeira chamada de $\lambda a$ fosse em $(fa)$ diretamente:
$$
    \lambda a \to (fa) \implies \lambda a \to (ga) \\
    \lambda a \to Ma \implies a \to Ma
$$

repare como os tipos simplesmente não batem. 
Ao envolver tudo com os parenteses, tornamos a primeira expressão lambda um ultimo passo que garante que nossos tipos batam e assim nos mantemos dentro do nosso monoide. 

E assim concluimos que, contanto que os tipos sejam compatíveis, garantimos que essas funções estejam em nosso monoide, enquanto os dados armazenados em $Ma$ vivam em um <span class="monad"> <strong>Monad!</strong></span>

<style>
    .monad {
        color: hsl(0,100%,70%);
    }
</style>