def curried_pow(x):
    def h(y):
        return pow(x, y)
    return h


print(curried_pow(2)(3))


def map_to_range(start, end, f):
    while start < end:
        print(f(start))
        start += 1


map_to_range(0, 10, curried_pow(2))


def curry2(f):
    """Return a curried version of the given two-argument function."""
    def g(x):
        def h(y):
            return f(x, y)
        return h
    return g


def uncurry2(g):
    """Return a two-argument version of the given curried function."""
    def f(x, y):
        return g(x)(y)
    return f


pow_curried = curry2(pow)
print(pow_curried(2)(5))
map_to_range(0, 10, pow_curried(2))

print('------')
res = uncurry2(pow_curried)(2, 5)  # == pow(2,5)
print(res)


def compose1(f, g):
    return lambda x: f(g(x))
# ==   compose1 = lambda f,g: lambda x: f(g(x)) 从右往左理解


f = compose1(lambda x: x*x,
             lambda y: y+1)
print(f(12))


#-----------decorators.py
def trace(fn):
    def wrapped(x):
        print('->', fn, '(', x, ')')
        return fn(x)
    return wrapped


@trace
def triple(x):
    return 3*x


triple(12)
print('-----')
print(triple(12))
