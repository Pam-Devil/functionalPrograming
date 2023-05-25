type TypeWithLog<Type> = {
    first: Type;
    second: string;
}
function log(text:string){
    console.log(text);
}
function WrapType<T>(x:T,y:string){
    return {
        first:x,
        second:y
    }
}
type FnWithLog<A,B> = (a: A) => TypeWithLog<B>

const negar: FnWithLog<boolean,boolean> = (x) => {
    return WrapType(!x,"Not");
}
const manter: FnWithLog<boolean, boolean> = (x) => {
    return WrapType(x,"Keep")
}
function compose<A,B>(call_foo:(x) => TypeWithLog<A>, call_bar:(y)=> TypeWithLog<B>, x:A,y:B):string {
    log("foo is being called")
    console.log(call_foo(x))
    log("bar is being called")
    console.log(call_bar(y))
    return "end of compose"
}
console.log(compose(negar, manter,true,false))
