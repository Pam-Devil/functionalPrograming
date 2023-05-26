type TypeWithLog<Type> = {
    first: Type;
    second: string;
}
function log(text:any){
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
function compose<A,B>(call_foo:(x:any) => TypeWithLog<A>, call_bar:(y:any)=> TypeWithLog<B>, x:A) {
    return () => {
        log(`foo is being called:`);
        const p1 = call_foo(x);
        log(`bar is being called:`);
        const p2 = call_bar(p1.first);
        return {
            first: p2.first,
            second: p1.second +' '+ p2.second
        };
    };
}
console.log(compose(negar, manter,true)());