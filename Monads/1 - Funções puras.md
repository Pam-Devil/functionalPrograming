# Por quê Monads?  
Sabemos que na vida, tudo em excesso é ruim e na programação não seria diferente. O excesso de programação orientada a objetos traz consigo alguns grandes problemas e enormes armadilhas para a real sustentabilidade e manutenção do código, além de trazer consigo uma grande carga de complexidade sem as devidas ferramentas para se controlar tal complexidade. 

Nesse sentido, abstraimos e usamos de padrões de design, estruturas de dados e outras coisas desse tipo para tentar controlar o crescimento do codigo e os efeitos colaterais da manutenção dos estados dos objetos. 

Injeção de dependência, inversão de controle, segregação de interfaces são todos principios e tecnicas realmente uteis e boas práticas que melhoram o bem estar do código, porém, rápidamente criam camadas e mais camadas de complexidade que devem sim ser endereçadas. 

## A programação funcional: 
O principal recurso da programação funciona é o das funções puras. funções puras são funções as quais operam apenas em variaveis passadas a elas como parâmetro ou limitadas dentro de seu escopo e retornam algum tipo de valor, sem causar qualquer tipo de efeito colateral à nada fora de seu escopo. 

Assim podemos definir as regas de definição de uma função pura da seguinte maneira:

* ###  Uma função pura afeta apenas as variáveis em seu interior e não causará nenhum tipo de efeito colateral.
* ### Uma função pura deve retornar sempre o mesmo resultado para uma mesma entrada. (Assim, funções que geral resultados aleatorios são por definição, impuras)
* ### Uma função pura pode operar apenas em variáveis passadas a ela como parâmetro via cópia ou novas variáveis definidas em seu interior.
  

- - - 
### Exemplo de função impura:
```ts
    const object = {
        number:3
    };
    function impure(x) {
        x.number = 0;
    }
    impure(object);
    console.log(object, object.number); // {number:0}, 0
```
- - - 
### Exemplo de funçao pura:
```ts
    const object = {
        number:3
    };
    function pure(x:any, new_number:int) {
        let new_x = x;
        new_x.number = new_number;
        return new_x;
    }
    const new_object = pure(object, 0);
    console.log(object, object.number); // {number:3}, 3
    console.log(new_object, new_object.number) // {number: 0}, 0
```
---
Na primeira função, ao modificarmos o atributo number do objeto, este que é passado como referência acaba alterando o seu valor mesmo fora do escopo da função.

Já na segunda função, por ser pura, primeiro evitamos alterar diretamente o valor da propriedade number do objeto passado. Isso por que em javascript parametros são passados via copia, mas as propriedades são passadas via referência
<span class="fuck">
    <strong>_(essa merda não faz nenhum sentido!!)_</strong>
</span>

Como apenas retornamos o valor da variável new_x que foi criada e essa é passada na declaração de um novo objeto new_objet, não há efeito colateral algum em nosso código e a variável object original permanece intacta. 

Se inserirmos sempre o mesmo objeto, com o mesmo valor de new_number, ela sempre irá retornar o mesmo objeto, logo essa função é pura.

# Tipos genéricos

Antes de entrarmos no assunto Monads e Monoides em si, primeiro precisamos entender que a construção da programação funcional se dá em cima de tipos e retorno de tipos. 

Afinal, para que um código possa ser sustentável, ele precisa ser o mais desacoplado quanto possível, tendo partes moveis, adaptáveis e substituíveis e a melhor forma de alcançar isso é via injeção de depedência e tipos. 

Daqui pra frente então adotaremos duas notações diferentes para declararmos funções e seus tipos. 

A primeira notação é a padrão do Typescript

- - -
Notação funcional:
```ts
    function foo (x:T):T {
        //...
    }
```
Notação genérica
$$x \to a \\
f:a \to a \\
\text{lê-se que x é uma variável do tipo a} \\
\text{ f é uma função qualquer que recebe uma variável do tipo a} \\
\text{que retorna um valor do tipo a}
$$

----

com tais noções em mãos podemos começar a estruturar então o que compõe o padrão de design Monad. 

* ### Funções
* ### Monoids
* ### Funções/ Espaço Monádico
* ### Monads 

<style>
    .fuck {
        color:hsl(5,60%,60%);
    }
</style>