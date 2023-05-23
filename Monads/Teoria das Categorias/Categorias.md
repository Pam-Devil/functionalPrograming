# Definição de categoria 

Uma categoria é um amontoado de objetos e os morfismos entre estes objetos. Onde duas propriedades principais definem uma categoria. 

* Composição
* Identidade
* Associatividade

## O que é um objeto? 

Objetos não podem ser realmente definidos, eles são um alto nivel de abstração, sem reais propriedades onde a unica razão deles existirem na categoria é para firmarmos as relações entre seus morfismos 

## E o que é um morfismo? 

Morfismos assim como objetos são o mais alto nivel de abstração até aqui, sendo assim eles não possuem propriedades especificas ou intrinsecas a eles. Eles apenas apontam como um objeto se relaciona com o outro. 
$$
    f:a \to b
$$

Ao definir uma categoria, você especifica que tipos de objetos estão nela e então especifica para cada par de objetos os morfismos que existem entre eles. 

Então em uma categoria entre os objetos $a,b$ pode haver um morfismo, nenhum morfismo, infinitos morfismos ou até uma quantidade incontável de morfismos que relacionam os dois. 

É importante salientar que também podem haver morfismos de um objeto nele mesmo:
$$
    f:a \to a
$$
Até mesmos infinitos morfismos que relacionam um objeto com ele próprio. 

Assim uma categoria é uma grande generalização e abstração do conceito de relações entre objetos. 

## Composição

Dentro de uma categoria, se temos objetos $a,b,c$ que se relacionam da seguinte forma:
$$
    f:a \to b \\
    g:b \to c
$$
$$
    a \to _f b \to _g c \\
    a \to _h c
$$

Deve haver nesta categoria um morfismo entre $a,c$
$$
    h:a \to c
$$
Onde $h$ é resultado da composição entre $f,g$ 
$$
    h = g \circ f
$$

## Identidade
Em uma categoria, para todo e cada objeto existe um morfismo identidade:
$$
    id_a: a \to a
$$
onde a composição da identidade por qualquer outro morfismo associado a esse objeto, é o próprio morfismo:
$$
    f:b \to a \\
    id_a \circ f = f
$$
$$
    a \to _{f} b \leftarrow _{id} b \\
    a \to _f b
$$

## Associatividade
Em uma categoria no seguinte caso:
$$
    a \to _{g \circ f} c \\
    a \to _f b \to _g c \to _h d \\
$$
Deve haver então:
$$
    h \circ (g \circ f): a \to d
$$
Ao mesmo tempo também há:
$$
    (h \circ g): b \to d
$$
E assim podemos compor mais uma vez:
$$
    (h \circ g) \circ f: a \to d
$$

Assim podemos concluir que: 
$$
    (h \circ g) \circ f = h \circ (g \circ f)
$$