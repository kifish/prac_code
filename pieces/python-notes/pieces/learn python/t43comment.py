import random #
from sys import exit

class Scene(object): #在子类的也将定义enter（）函数，因此子类中的enter函数将会继承覆盖那父类中的enter（）函数，此类中此程序中并无实际意义
    def enter(self):
        print"this scene is not yet configured. subclass it and implement enter()"
class engine(object):
    def __init__(self,scene_map): #scene_map是Map类的对象，将一个对象用作其他类的参数
        self.scene_map=scene_map
    def play(self):   #相当于游戏的开始按键
        current_scene=self.scene_map.opening_scene()   #self.scene_map.opening_scene（）最后会返回一个类的对象，即返回一个场景类的对象
        while True:
            print "\n"
            next_sence_name=current_scene.enter()  通过场景类对象来调用场景类中定义的enter（）函数
            #enter()函数最后会返回一个新的场景（这次返回的不是场景对象，而是场景字符串）
            #current_scene对象会调用场景类中的enter（）函数，此时的next_scene_name是一个字符串类型
            current_scene=self.scene_map.next_sence(next_scene_name)#current_scene变成下一个场景的对象了，然后循环

class Death(scene):
       #子类场景中定义的enter（）函数最后会返回一个新场景的字符串，那这个字符串将作为Map类的新参数，进行下一步操作
        quips=["you died. you kinda suck at this",
        "your mom would be proud...if she were smarter",
        "such a loser",
        "i have a small puppy that's better at this"]
    def enter(self):
        print Death.quips[randint(0,len(self.quips)-1)]
        exit(1)
class Central_corridor(scene):#中央控制走廊
    def enter(self):
        print"the Gothons of planet percal #25 have invaded your ship and destroyed"
        print"your entire crew.you are the last surviving member and your last"
        print"mission is to get the neutrn destruct bomb from the weapons armory"
        print"put it in the bridge,and blow the ship up after getting into an"
        print"escape pod"
        print"\n"
        print"you are running down the central corridor to the weapons armory when"
        print"a Gothons jumps out ,red scaly skin,dark grimy teeth,and evil clown costume"
        print"flowing around his hate filled body,he's blocking the door to the"
        print"armory and about to pull a weapon to blast you"

    action=raw_input("")
    if action=="shoot":
        print"quick on the draw you yank out your blaster and fire it at the Gothons" #哈哈，铁血战士的剧情，不过铁血战士可是不会吃人肉的
        print"his clown costume is flowing and moving around his body,which throws"
        print"off you aim. your laser hits his costume but misser him entirely . this"
        print"completely ruins his brand new costume his mother bought him, which"
        print"makes him fly into a rage and blast you repeatedly in the face until"
        print"you are died. then he eats you"
        return"death"
    elif action=="dodge!":
        print "like a world class boxer you dodge,weave,slip and slider right"
        print"as the Gothons's blaster cranks a loser past your head"
        print"in the middle of you areful dodge your foot slips and you "
        print"bang you head on the metal wall and pass out"
        print"your wake up shortly after only to die as the Gothons stomps on"
        print"you head and eats you "
        return "death"
    elif action=="tell a joke":
        print"lucky for you they made you learn Gothons insults in the academy"
        print"you tell the one Gothons joke you kown"
        print"从前有一只猪，它很笨所以它死了"
        print"what cold ,the Gothon man will decide to killl you and eat you head"
        print"but write minutes,the Gothon man fell wrong,and let you go"
        return"laser_weapon_armory"
    else:
        return"central_corridor"

class Laser_weapon_armory(scene):#激光武器库
    def enter(self):
        print"you do a live"
        print"虽然你活下来了，但是你很快会死亡，因为我是gothons"
        print""


class The_bridge(scene):#飞船主控舱
    def enter(self):
        print"恭喜你，你将进入飞船的主控仓，还有一步，你将逃过gothons人的追杀，祝你好运"
class Escape_pod(scene):#救生舱
    def enterself):
        print"恭喜你，你已经逃出生天了"

class Map(object):
    scenes={"central_corridor":Centralcorridor(),                 #通过字典来调用类，从而实际上返回的是一个对象，！！！！！很巧妙
    "laser_weapon_armory":Laserweaponarmory(),
    "the_bridge":TheBridge(), #字典也可用来调用函数，但是必须字典的键和值是可哈希的！！！！
    "escape_pod":EscapePod(),
    "death":Death()}

    def __init__(self,start_scene):   #确定开始场景，即你开始所在飞船的位置
        self.start_scene=start_scene
    def next_sence(self,scene_name):
        return Map.scenes.get(scene_name) #返回字典的键，实质上是返回一个类的对象！！！！！

    def opening_scene(self):
        return self.next_scene(self.start_scene)    #此函数并无实质意义，实质上只是调用next-sence()函数

a_map=Map('central_corridor')   #创建一个map类的对象
a_game=Engine(a_map) #将map类的对象作为参数传递给engine类
a_game.play
#python的灵活性将体现在这里，可以将对象用作参数，并且利用通过字典来调用类，从而返回对象，不过python中一切皆是对象~