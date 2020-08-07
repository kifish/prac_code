#https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/00143191629979802b566644aa84656b50cd484ec4a7838000
mydict.py
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 27 16:32:34 2018
@author: k
"""
class Dict(dict):
    def __init__(self,**kw):
        super().__init__(**kw)
        
    def __getattr__(self,key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Dict' object has no attribute '%s'"%key)
    
    def __setattr__(self,key,value):
        self[key] = value
 
test.py
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 27 22:51:23 2018
@author: k
"""
import unittest
from mydict import Dict
class TestDict(unittest.TestCase):
    def test_init(self):
        d = Dict(a=1,b='test')
        self.assertEqual(d.a,1)
        self.assertEqual(d.b,'test')
        self.assertTrue(isinstance(d,dict))
    
    def test_key(self):
        d = Dict()
        d['key'] = 'value'
        self.assertEqual(d.key,'value')
        
    def test_attr(self):
        d = Dict()
        d.key = 'value'
        self.assertTrue('key' in d)
        self.assertEqual(d['key'],'value')
        
    def test_keyerror(self):
        d = Dict()
        with self.assertRaises(KeyError):
            value = d['empty']
    def test_attrerror(self):
        d = Dict()
        with self.assertRaises(AttributeError):
            value = d.empty
if __name__=='__main__':
    unittest.main()
    
            
 
python  test.py
 
 
mystu.py
import unittest
class Student(object):
    def __init__(self,name,score):
       # if score>=0 and score<=100: 如果不注释掉这行，单元测试不会通过。因为是AttrubuteError而不是ValueError。
            self.name = name
            self.score = score
        
    def get_grade(self):
        if self.score>=60 and self.score<80:
            return 'B'
        if self.score >=80 and self.score<=100:
            return 'A'
        if self.score>=0 and self.score<60:
            return 'C'
        raise ValueError('ValueError!')
 
test.py
import unittest
from mystu import Student
class TestStudent(unittest.TestCase):
    def setUp(self):
        print('setUp...')
    def test_80_to_100(self):
        s1 = Student('Bart',80)
        s2 = Student('Lisa',100)
        
        self.assertEqual(s1.get_grade(),'A')
        self.assertEqual(s2.get_grade(),'A')
    
    def test_60_to_80(self):
        s1 = Student('Bart',60)
        s2 = Student('Lisa',79)
        self.assertEqual(s1.get_grade(),'B')
        self.assertEqual(s2.get_grade(),'B')
        
        
    def test_0_to_60(self):
        s1 = Student('Bart',0)
        s2 = Student('Lisa',59)
        self.assertEqual(s1.get_grade(),'C')
        self.assertEqual(s2.get_grade(),'C')
        
        
    def test_invalid(self):
        s1 = Student('Bart',-1)
        s2 = Student('Lisa',101)
        with self.assertRaises(ValueError):
            s1.get_grade()
        with self.assertRaises(ValueError):
            s2.get_grade()
    
    def tearDown(self):
        print('tearDown...')
        
if __name__=='__main__':
    unittest.main()
    
            
 
