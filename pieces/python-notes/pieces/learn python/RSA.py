
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
        RSACipher.__init__(self,primes[0]*primes[1],e)

    @property
    def primes(self):
        return self.__primes

    @primes.setter
    def primes(self, primes):
        self.__primes = min(primes, max(primes))
        self.n = primes[0]*primes[1]

    def decrypt(self, crypt_text):
        self.fn=(self.__primes[0]-1)*(self.__primes[1]-1)
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

        if extended_hcf(e,fn)[2] !=1:
            raise ValueError('Warning!   e is not coprime to (primes[0] - 1) * (primes[1] - 1)')
        d=1
        while True:
            if (e*d)%fn==1:
                break
            d+=1
        return pow(crypt_text,d,n)


# (b)
my_cipher = RSACipher(7735534351, 79)
print my_cipher.encrypt(12345)

my_cipher = RSACipher(8254355281, 65537)
print my_cipher.encrypt(123456)


my_cipher = PrivateRSACipher([93629,82619],79)
print my_cipher.encrypt(12345)
print my_cipher.decrypt(3305244447)