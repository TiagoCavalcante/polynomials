# polynomials

Solve huge polynomials in milliseconds

## How to compile?

```sh
make
```

## How to use?

The coefficients are in degree-ascending order, that is: $x^0 + x^1 + x^2 + x^3 + \cdots$  
The coefficients are passed space-separated, therefore to solve the polynomial $3 - 9x + x^3$ you need to run the program the following way:
```sh
$ bin
3 -9 0 1
```

(note: don't forget the hidden coefficients)

## How it works?

The roots are found using the linear formula ($\frac{-b}{a}$), the quadratic formula ($\frac{-b \pm \sqrt{b^2 - 4 a c}}{2 a}$), or the [false position method](https://en.wikipedia.org/wiki/Regula_falsi) over the [Cauchy's bound](https://en.wikipedia.org/wiki/Geometrical_properties_of_polynomial_roots#Lagrange's_and_Cauchy's_bounds). It can solve any polynomials of any degree.