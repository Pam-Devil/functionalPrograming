# Monoides
## Como categoria
 <div style="color:hsl(1000,20%,75%)"> <em> Um monoide é uma categoria com um único elemento e qualquer número arbitrário de morfismos</em></div>

$$
    \Omega = (a,F)
$$
onde leva a todos os morfismos nesta categoria serem do tipo
$$
    f:a \to a
$$
o que os caracteriza como morfismos de indentidade.

Uma consequência importante de um monoide, é que pelo fato de haver apenas um único elemento, logo todos seus morfismos são aptos para composição. 
$$
    \forall f,g : a \to a \\ 
    f \circ g = h \in F
$$

## Como um conjunto:
 <div style="color:hsl(1000,20%,75%)"> <em> Um monoide é um conjunto de elementos associado a uma operação binária entre estes elementos fechada ao conjunto. </em></div>

 $$
    \Omega = (A,\star) \\
    \forall a,b \in A\\ a \star b = c \in A \\
 $$

 O operador deve seguir as regras de associatividade e identidade. 
 $$
    (a \star b) \star c = a \star (b \star c) \\
    \exist e \,\forall a \,|\, a\star e = a 
 $$