--sqrt.py

```PY
def average(x, y):
    return (x+y)/2


def improve(update, close, guess=1):
    while not close(guess):
        guess = update(guess)
    return guess


def approx_eq(x, y, tolerance=1e-3):
    return abs(x-y) < tolerance


def mysqrt(a):
    def sqrt_update(x):
        return average(x, a / x)
    #x*a/x  = a

    def sqrt_close(x):
        return approx_eq(x*x, a)
    return improve(sqrt_update, sqrt_close)


print(mysqrt(2))

```
----newton.py

```PY
def improve(update, close, guess=1):
    while not close(guess):
        guess = update(guess)
    return guess


def approx_eq(x, y, tolerance=1e-3):
    return abs(x-y) < tolerance


def newton_update(f, df):
    def update(x):
        return x - f(x)/df(x)
    return update


def find_zero(f, df):
    def near_zero(x):
        return approx_eq(f(x), 0)
    return improve(newton_update(f, df), near_zero)


def square_root_newton(a):
    def f(x):
        return x*x - a

    def df(x):
        return 2*x
    return find_zero(f, df)


def power(x, n):
    product, k = 1, 0
    while k < n:
        product, k = product*x, k+1
    return product


def nth_root_of_a(n, a):
    def f(x):
        return power(x, n)-a

    def df(x):
        return n*power(x, n-1)
    return find_zero(f, df)


print(square_root_newton(64))
print(nth_root_of_a(2, 64))
print(nth_root_of_a(3, 64))
print(nth_root_of_a(6, 64))
```