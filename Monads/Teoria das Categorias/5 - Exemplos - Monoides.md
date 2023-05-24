# Exemplos de Monoides 
# Concatenador de Strings
O ato de concatenar duas strings por si só forma um monoide.

Basta pensarmos, se temos duas strings "hello" e "world" ao concatenarmos as duas (i.e juntá-las) nós formamos uma nova string "HelloWold" o que permanece sendo uma string. 

Considerando que estejamos operando então na categoria dos tipos, podemos então pegar um dos objetos dessa categoria, as strings, que é um conjunto e montarmos um monoide com ela. 
$$
    S = (String, +)
$$
Onde $String$ se refere a qualquer variável do tipo $String$ e $+$ é a operação de concatenar as duas variáveis. Em javascript/typescript é exatamente esse mesmo operador que é usado para concatenar strings. 

### Associatividade:
É facil provar que a associatividade está presente pois se temos as seguites strings:
```ts
    "Hello", "World", "!"
```
Contanto que operemos as duas na mesma ordem, a operação de concatenação pode acontecer da mesma maneira 
```ts
    "Hello"+"World"+"!" = "HelloWorld"+"!" = "HelloWorld!"
```
```ts
    "Hello"+"World"+"!" = "Hello"+"World!" = "HelloWorld!"
```
### Identidade 
O elemento identidade/unidade é amplamente utilizado em strings, se trata justamente da string vazia ""
```ts
    "hello"+"" = "hello"
```
- - - 
## Listas e Arrays
Considerando que em sua essência, strings são uma array de caracteres, considerando que strings formam um monoide é natural considerar que arrays também formam um monoide. 

O ato de concatenar Strings é análogo ao de "acrescentar"/"anexar" novos valores a uma array. 

basta considerarmos que uma string "hello" em sua essência é uma array de caractéres e um elemento null:
```ts
    "hello" == [c1,c2,c3,c4,c5,null]
```
Assim o ato de concatenar duas strings nada mais é o mesmo que dar append de uma string na outra usando o elemento null como guia para onde é o fim da string
```ts
    "hello" == [c1,c2,c3,c4,c5,null]
    "World" == [k1,k2,k3,k4,k5,null]
    "hello"+"world" ==
    [c1,c2,c3,c4,c5,null].append([k1,k2,k3,k4,k5,null])
    == [c1,c2,c3,c4,c5,k1,k2,k3,k4,k5,null]
    == "helloWorld"
```
Assim na categoria dos tipos, as arrays também formam um monoide
$$
    A = (Arr_T, append)
$$

