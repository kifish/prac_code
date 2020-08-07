def sum_digits(n):
    if n < 10:
        return n
    else:
        all_but_last, last = n//10, n % 10
        return sum_digits(all_but_last)+last


print(sum_digits(18117))


def is_even(n):
    if n == 0:
        return True
    else:
        return is_odd(n-1)


def is_odd(n):
    if n == 0:
        return False
    else:
        return is_even(n-1)


print(is_even(4))


def is_even_mutual(n):
    if n == 0:
        return True
    else:
        if n-1 == 0:
            return False
        else:
            return is_even((n-1)-1)


print(is_even_mutual(4))


def cascade(n):
    if n < 10:
        print(n)
    else:
        print(n)
        cascade(n//10)
        print(n)


cascade(2013)


def cascade_equal(n):
    print(n)
    if n >= 10:
        cascade(n//10)
        print(n)


cascade_equal(2013)

#play_...(n) means there is n pebbles on the table now and this turn is ...


def play_alice(n):
    if n == 0:
        print("Bob wins!")
    else:
        play_bob(n)


def play_bob(n):
    if n == 0:
        print("Alice wins!")
    else:
        if is_even(n):
            play_alice(n-2)
        else:
            play_alice(n-1)


play_alice(20)

#tree recursion重复计算了子问题


def fib(n):
    if n == 2:
        return 1
    if n == 1:
        return 0
    else:
        return fib(n-1) + fib(n-2)


print(fib(6))


def count_partitions(n, m):
    if n == 0:
        return 1
    elif n < 0:
        return 0
    elif m == 0:
        return 0
    else:
        return count_partitions(n-m, m) + count_partitions(n, m-1)
