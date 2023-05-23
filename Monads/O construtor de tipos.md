# Construtor de Tipos
Agora vamos começar a generalizar um pouco mais o conceito dos monoides para podermos utilizar ainda mais esse conceito em nossas aplicações e também, introduzir de fato os monads. 
$$
    \Omega = (F,\circ) \\
    x \to a \\
    f:a \to a \\
    g:a \to a \\
    h:a \to a \\
$$

Desta forma fica bem claro que o nosso monoide 
$$
    \Omega^\star = (F^\star,\bullet) \\
    x \to a \\
    f:a \to Ma \\
    g:a \to Ma \\
    h:a \to Ma \\
$$

Certo o que exatamente aconteceu aqui? Vamos por partes. 
$Ma$ é um novo tipo, que está associado a uma certa transformação $M$ que está sendo aplicada em $x \to a$
em outras palavras: 
$$
    x \to a\\
    M:a \to Ma
$$
A natureza de $M$ é de fato desconhecida, ela pode ser qualquer função, externa ao nosso monoide $\Omega$, a única característica que nos interessa nessa função de fato é que ela tem como como entrada um tipo $a$ e retorna um novo tipo $Ma$ sendo ele algum tipo de transformação, alteração ou adição ao nosso tipo original.

Podemos pensar em $M$ num sentido de programação em por exemplo uma função que busca e extrai dados de um banco de dados.

A essa função $M$ damos o nome de _"construtor de tipos"_.

Assim x pode ser do tipo usuario por exemplo e enquanto M pode ser o acesso ao banco de dados buscando pelo nome do usuário por exemplo.

Então neste caso estamos passando como parâmetro um objeto do tipo usuário e tendo como retorno uma string com seu nome por exemplo. Basicamente transformamos um tipo em outro.
- - - 
Veja o exemplo:
```ts
    interface IUser {
        //implementação
    }
    function get_name(user:IUser): String{
        let user_name: string;
        //implementação
        return user_name;
    }
    function get_data(user:IUser): String {
        //implementação
        user_data = get_name(user);
        return user_data;
    }
```
Por esse exemplo fica bem claro o que está acontecendo aqui, a função get_data recebe o parâmetro user, porém não é responsabilidade dela fazer uma busca especifica, para aumentarmos a flexibilidade do código nós entregamos essa responsabilidade para outra função get_name, que esta sim, através do parâmetro user devolve especificamente o nome associado a ele. 

As duas funções permanecem puras pois apesar de get_name estar sendo chamado dentro de get_data, get_name é uma função pura e portanto não causa nenhum tipo de efeito colateral no código. Assim que get_name e get_data saírem de escopo todos os dados obtidos serão deletados da memória e o programa continuará rodando como se as duas nunca sequer tivessem sido executadas.

assim da mesma forma poderíamos ter outras funções como: 

```ts
    interface IUser {
        //implementação
    }
    function get_name(user:IUser): String{
        let user_name: string;
        //implementação
        return user_name;
    }
    function get_data(user:IUser): String {
        //implementação
        user_data = get_name(user);
        return user_data;
    }
    function get_id(user:IUser): String{
        //implementação
        return user_email;
    }
```
Então o metodo get_data que implementamos com get_name também poderia implementar get_id e por ai vai. 
Porém esse codigo é meio merda. 

Com essa ideia porém naturalmente já poderiamos usar uma implementação de inversão de dependência com Monoides e funções puras:

### Inversão de dependência com Monoides 

```ts
    interface IDataBase {
        get_name(user:IUser):String;
        get_email(user:IUser):String;
        get_address(user:IUser):String
    };
    class MongoDB: IDatabase {
        get_name(){/**...**/}
        get_email(){/** **/}
        get_address(){/** **/}
    }
    function access_database(token:String):IDatabase{
        //do stuff...
        new_database = validate_access(token:String)i
        return new_database;
    };
    function validate_access(token:String):IDatabase{
        //validation script
        return new MongoDB();
    };

    const user = new User("Pamella",etc);
    const token = process.env.token;
    const MongoDB = access_database(token);
    MongoDB
        .get_name(user);
        .get_email(user);
```