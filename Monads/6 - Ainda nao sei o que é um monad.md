# Definição de Monad 
## <span class="monad" style="color:hsl(1000,20%,75%)"><em>Um monad é um monóide na categoria dos endoFuntores</em></span>

Vamos destrinchar melhor essa descrição para uma melhor compreensão.

Um monad $M$ é um monóide, ou seja: 
$$
    M = (\bar F,\star)\\ onde:\\
    \bar F = \{F_1, F_2, F_3,\dots\} \\ sendo \, F_i\in\bar F \, \text{um endoFuntor}\\
    e \, \star \text{é nossa regra de associação dos elementos do monóide}\\
    \exist! \, F_e \in \bar F \,|\, F_i \star F_e = F_i \, ou\, F_e \star F_i = F_i
$$

Porém é importante salientar que $\bar F$ é uma **_categoria_** composta por endofuntores. Ou seja:
$$
    \bar F = (F,\bullet) \\
    f \bullet g \in Morph(F)\\
    (f \bullet g) \bullet h = f \bullet (g \bullet h)\\
    1_f \bullet f = f \bullet 1_f = f
$$

