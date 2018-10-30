```py
class Fruit(object):
    total = 0   # 这是一个类属性

    @classmethod
    def print_total(cls):
        print('this is the ', cls, '.total:', cls.total, ' and its id: ', id(cls.total))    # cls是类本身，打印类属性total的值
        print('this is the Fruit.total:', Fruit.total, 'and its id: ', id(Fruit.total))
        print("=======================")
    @classmethod
    def set(cls, value):
        cls.total = value


class Apple(Fruit):
    pass

class Orange(Fruit):
    pass

app1 = Apple()
app1.set(10)
app1.print_total()
Apple.print_total()
Fruit.set(2)
app1.print_total()
Fruit.print_total()

"""
output:
this is the  <class '__main__.Apple'> .total: 10  and its id:  1355201264
this is the Fruit.total: 0 and its id:  1355200944
=======================
this is the  <class '__main__.Apple'> .total: 10  and its id:  1355201264
this is the Fruit.total: 0 and its id:  1355200944
=======================
this is the  <class '__main__.Apple'> .total: 10  and its id:  1355201264
this is the Fruit.total: 2 and its id:  1355201008
=======================
this is the  <class '__main__.Fruit'> .total: 2  and its id:  1355201008
this is the Fruit.total: 2 and its id:  1355201008
=======================
"""
```


```py
class Demo(object):

    def instance_method(self, your_para):
        """
        this is an instance_method
        you should call it like the follow:
        a = Demo()
        a.instance_method(your_para)

        plus: in python, we denote 'cls' as latent para of Class
        while 'self' as latent para of the instance of the Class

        :param your_para: 
        :return: 
        """
        print("call instance_method and get:", your_para)

    @classmethod
    def class_method(cls, your_para):
        """
        this is a class_method
        you can call it like the follow:
        method1:
        a = Demo()
        a.class_method(your_para)
        method2:
        Demo.class_method


        plus: in python, we denote 'cls' as latent para of Class
        while 'self' as latent para of the instance of the Class
        :param your_para: 
        :return: 
        """
        print("call class_method and get:", your_para)

    @staticmethod
    def static_method(your_para):
        """
        this is a static_method and you can call it like the 
        methods of class_method

        :param your_para: 
        :return: 
        """
        print("call static_method and get:", your_para)

```

