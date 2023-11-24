```
a^p can be calculate in log a you just have to twice the base every time and reduce the power by half every time
```
---
```
to count no of divisior we use seive erothes using seive erothes we
caculate lowest prime factor of every no then everytime we divide the no with its lpf until no is greater than 1
```
----
```
Farmet theorem
if p is a prime number, then for any integer a, the number a^p − a is an integer multiple of p
If p is a prime and a is any integer not divisible by p, then a^( p − 1) − 1 is divisible by p.
```
----
```
no of divisior of any no x=(p1^a1)*(p2^a2)... = (a1+1)*(a2+1)*.... where p1 ,p2 are prime numbers
```
---
```
sum of all divisor of any no x=(p1^0+p1^1....)(p2^0+p2^1 ....)... =(geometric sum of p1)*(geometric sum of p2).... = (((p1^(a1+1))-1)/(p1-1))*(((p2^(a2+1))-1)/(p2-1))...
```
----
```
C(a/b)=C(b-1/a) +C(b-1/a-1) any binomial coefficent is sum of it top left and right parent
Hockey Stick Theorem sumation( C(b+i/i)) over 0<=i<=k => C(b+k+1/k)
```
```
no of string generated= n!/(a1!*a2!*a3...) where a1,a2 freq of each unique character
dearrangement formula=DN= N![1-1/1!+1/2!-1/3!…1/N!],
by recurrece realation !n=(n−1)⋅(!(n−1)+!(n−2))

no of ways to distribut b thing bw a => C(a+b-1/b-1)

Ck= (1/k+1) *(2kCk)  this is called Catalan no have many application like valid parenthes string count in string of length n    

Burnside's leema theorem of counting object when there is symmnetry 
    total distinct ways= sumation over 0<=i<=N-1 => ((M^gcd(i,N))/N);
```




 