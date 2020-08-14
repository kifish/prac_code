class Queue(object):
    def __init__(self,size = 8):
        self.queue = []
        self.size = size
        self.front = 0
        self.rear = -1
    def isFull(self):
        return True if self.rear == self.size -1 else False

    def isEmpty(self):
        return True if self.rear == -1 else False

    def enqueue(self,data):
        if self.isFull():
            raise Exception("QueueOverFlow")
        self.queue.append(data)
        self.rear += 1

    def dequeue(self):
        if self.isEmpty():
            raise Exception("QueueIsEmpty")
        res = self.queue.pop(0)
        self.rear -= 1
        return res
    def first(self):
        return self.queue[0]
    def last(self):
        return self.queue[self.rear]
    def show(self):
        print(self.queue)


if __name__ == "__main__":
    q = Queue()
    for i in range(8):
        q.enqueue(i)

    print(q.dequeue())
    print(q.dequeue())
    print(q.first())
    print(q.last())
    q.show()



"""

0
1
2
7
[2, 3, 4, 5, 6, 7]

"""