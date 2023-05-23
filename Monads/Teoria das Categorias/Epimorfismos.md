# Isomorfismos 
Dado dois elementos $a,b$ em uma categoria $C$ e os morfismos $f,g$ entre eles. 
$$
    a,b \in C \\
    f: a \to b \\
    g: b \to a
$$
$f$ é dito um _isomorfismo_ se:
$$
    f \circ g = id_b \\
    g \circ f = id_a
$$

# Monomorfismos
considerando a categoria $C$ e os seus devidos objetos $a,b,c$
e sendo $f$ um morfismo em $C$:

tomando os morfismos: 
$$
    f:b \to c \\
    g_1:c \to a \\
    g_2: c \to a
$$
$f$ é dito um monomorfismo se:
$$
    \forall c \;\forall g_1,g_2:c \to a \\
    f \circ g_1 = f \circ g_2
    \implies g_1 = g_2 
$$
Em perspectiva de um conjunto, um monomorfismo é uma função injetora.

# Epimorfismos

considerando a categoria $C$ e os seus devidos objetos $a,b,c$
e sendo $f$ um morfismo em $C$:

tomando os morfismos: 
$$
    f:a \to b \\
    g_1:b \to c \\
    g_2: b \to c
$$
$f$ é dito um epimorfismo se:
$$
    \forall c \;\forall g_1,g_2:b \to c \\
    g_1 \circ f = g_2 \circ f
    \implies g_1 = g_2 
$$
Em perspectiva de um conjunto, um epimorfismo é uma função sobrejetora. 

