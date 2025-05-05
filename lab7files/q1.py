class Queue:
    def __init__(self, size, start, end):
        self.array=[None]*size
        self.size= size
        self.start=start
        self.end=end
    def enqueue(self, item):
        if self.end>=self.size:
            self.end=0
        self.array[self.end]=item
        self.end+=1
        
    def dequeue(self):
        #return self.array.pop(0)
        ret=self.array[self.start]
        self.array[self.start]=None
        self.start+=1
        if self.start>=self.size:
            self.start=0
        return ret
    def __str__(self):
        res = ""
        i=0
        while i<self.size:
            if self.array[i]!=None:
                res+=str(self.array[i])
            if i!=self.end:
                res+="-> "
            i+=1
        return res
    def __lt__(self, other):
        return self.array[self.start]<other.array[other.start]
    def __repr__(self):
        res = ""
        i=0
        while i<self.size:
            if self.array[i]!=None:
                res+=str(self.array[i])
            if i!=self.end:
                res+="-> "
            i+=1
        return res

    #q2

if __name__=="__main__":
    q=Queue(5, 4, 4)
    q.enqueue(1)
    print(q)
    q.enqueue(2)
    print(q)
    q.dequeue()
    print(q)
    q.enqueue(3)
    print(q)
    q.dequeue()
    print(q)
    
    q1=Queue(5,1,1)
    q1.enqueue(2)
    q2=Queue(5,2,2)
    q2.enqueue(4)
    l_ofq=[q,q1,q2]
    l_ofq=sorted(l_ofq)
    print(l_ofq)
