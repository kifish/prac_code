# -*- coding: utf-8 -*-
def complex_map_iterates(c,n):
    res = [0]
    for i in xrange(1, n+1):
        temp = pow(res[i-1],2) + c
        res.append(temp)
    return res
'''
# b
for i in range(0,100):
    i = i/100.0
    res = complex_map_iterates(i,10)
    print i,res[-1]
print complex_map_iterates(0.29,20)
'''
### 从结果可知
"""
 c< 0.1时，limit
c>0.1时，infinity

"""
#limit
#print complex_map_iterates(0.05,100)

#infinity
#print complex_map_iterates(2,10)

#bounded
#print complex_map_iterates(0.2,20)

def escape_time(c, nmax):
    res = [0]
    count = 0
    for i in range(1, nmax+1):
        temp = pow(res[i-1],2) + c
        count += 1
        res.append(temp)
        if abs(temp) > 2:
            break
    return count

#(d)
import numpy as np
import matplotlib.pyplot as plt
# set parameters
xmin = -1.5
xmax = 0.5
ymin = - 1.0
ymax = 1.0
npoints = 21
# calculate step sizes
xstep = (xmax - xmin)/float(npoints - 1)
ystep = (ymax - ymin)/float(npoints - 1)
# initialize array
et_array = np.zeros([npoints, npoints])
# nested loop
for x_index in xrange(npoints):
    # real part of c
    x = xmin + x_index * xstep
    for y_index in xrange(npoints):
        # imaginary part of c
        y = ymin + y_index * ystep
        # calculate c
        c = x+y*1j
        # calculate log of escape time and drop into array
        log_et = np.log(escape_time(c, 200))
        et_array[npoints-y_index-1, x_index] = log_et
# plot array as a bitmap
plt.imshow(et_array, extent = [xmin, xmax, ymin, ymax])
plt.show()

#(e)
def mandelbrot_array(xmin, xmax, ymin, ymax, npoints):
    # calculate step sizes
    xstep = (xmax - xmin)/float(npoints - 1)
    ystep = (ymax - ymin)/float(npoints - 1)
    # initialize array
    et_array = np.zeros([npoints, npoints])
    # nested loop
    for x_index in xrange(npoints):
        # real part of c
        x = xmin + x_index * xstep
        for y_index in xrange(npoints):
            # imaginary part of c
            y = ymin + y_index * ystep
            # calculate c
            c = x+y*1j
            # calculate log of escape time and drop into array
            log_et = np.log(escape_time(c, 200))
            et_array[npoints-y_index-1, x_index] = log_et
    return et_array

#(f)
def mandelbrot_plot(xmin,xmax, ymin,ymax, npoints):
    et_array = mandelbrot_array(xmin, xmax, ymin, ymax, npoints)
    plt.imshow(et_array, extent = [xmin, xmax, ymin, ymax])
    plt.show()

#mandelbrot_plot(-1.5, 0.5, -1.0, 1.0, 21)
#mandelbrot_plot(-1.5, 0.5, -1.0, 1.0, 201)
#mandelbrot_plot(-0.1, 0.1, -0.1, 0.1, 201)
#mandelbrot_plot(-0.01, 0.01, -0.01, 0.01, 201)
from sympy import *
import numpy as np
import matplotlib.pyplot as plt

#(a)
def plot_with_SPs(expr, var, xmin, xmax):
    dif = diff(expr,var)     # 求导
    result = solve(dif,var)  # 求解
    res1 = expr.subs(x,result[0])  #极值1
    res2 = expr.subs(x, result[1]) #极值2

    x_values = np.linspace(xmin, xmax, 201)
    values = []
    for i in x_values:
        values.append(expr.subs(x,i))
    y_values = np.array(values)
    plt.plot(x_values, y_values, color='g')
    #plt.plot(result,[res1,res2], 'ro')
    plt.show()

x = symbols('x')
plot_with_SPs(x**3 - 3*x, x, -3, 3)
plot_with_SPs(12*x**5+45*x**4+40*x**3-60*x**2-240*x, x, -3.0, 2.0)


#(a)
class RSACipher(object):
    'A public-key RSA Cipher'

    def __init__(self, n, e):
        self.n = n
        self.e = e

    def encrypt(self, plaintext):
        return pow(plaintext,self.e) % self.n

#(c)
class PrivateRSACipher(RSACipher):
    def __init__(self,primes,e):
        self.primespro=primes
        RSACipher.__init__(self,primes[0]*primes[1],e)

    @property
    def primes(self):
        return self.__primes

    @primes.setter
    def primes(self, primes):
        self.__primes = min(primes, max(primes))
        self.n = primes[0]*primes[1]

    def decrypt(self, crypt_text):
        self.fn=(self.primespro[0]-1)*(self.primespro[1]-1)
        def extended_hcf(a, b):
            # initialize
            p1, q1, h1 = 1, 0, a
            p2, q2, h2 = 0, 1, b

            # loop while h2 > 0
            while h2 > 0:
                r = h1 / h2
                p3, q3, h3 = p1 - r * p2, q1 - r * q2, h1 - r * h2
                p1, q1, h1, p2, q2, h2 = p2, q2, h2, p3, q3, h3

            return (p1, q1, h1)
        # (e)
        if extended_hcf(self.e,self.fn)[2] !=1:
            raise ValueError('Warning!   e is not coprime to (primes[0] - 1) * (primes[1] - 1)')
        self.d=1
        self.dtemp=1.0
        k = 2
        while True:
            self.dtemp = (1.0+k*self.fn)/self.e
            if abs(self.dtemp-round(self.dtemp))< 1e-9:
                break
            k+=1
        self.d = int(round(self.dtemp))
        return pow(crypt_text,self.d,self.n)


# (b)

my_cipher = RSACipher(7735534351, 79)
print my_cipher.encrypt(12345)

my_cipher = RSACipher(8254355281, 65537)
print my_cipher.encrypt(123456)

# (d)
my_cipher = PrivateRSACipher([93629,82619],79)
print my_cipher.encrypt(12345)
print my_cipher.decrypt(3305244447)