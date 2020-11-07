class Node:
    def __init__(self,date):
        self.Date=date
        self.next=None
        self.pr=None

class list:
    def __init__(self):
        self.head=None;
        self.tail=None;
        self.middle=None;
        self.size=-1;
        self.midIndex=0;

    def addNode(self, data):
        # Create a new node
        newNode = Node(data);

        # If list is empty
        if (self.head == None):
            # Both head and tail will point to newNode
            self.head = self.tail = self.middle = newNode;
            # head's previous will point to None
            self.head.pr = None;
            # tail's next will point to None, as it is the last node of the list
            self.tail.next = None;
        else:
            # newNode will be added after tail such that tail's next will point to newNode
            self.tail.next = newNode;
            # newNode's previous will point to tail
            newNode.pr = self.tail;
            # newNode will become new tail
            self.tail = newNode;
            # As it is last node, tail's next will point to None
            self.tail.next = None;
            # Size will count the number of nodes present in the list
        self.size = self.size + 1;
        if (self.midIndex < (int)(self.size / 2)):
            self.middle = self.middle.next;
            self.midIndex += 1;

    def display(self):
        # Node current will point to head
        current = self.tail;
        if (self.size == -1):
            print();
            return;
        while (current != None):
            # Prints each node by incrementing pointer.
            print(current.Date, end=" "),
            current = current.pr;

        print();

    def pop(self):
        if (self.size == -1):
            return
        else:
            if(self.tail.pr is None):
                self.head=None
                self.tail=None
            else:
                self.tail.pr.next = None;
                self.tail = self.tail.pr;
            self.size -= 1;
            if (self.midIndex < (int)(self.size / 2)):
                self.middle = self.middle.next;
                self.midIndex += 1;
            elif (self.midIndex > (int)(self.size / 2)):
                self.middle = self.middle.pr;
                self.midIndex -= 1;

    def removeMiddle(self):
        if (self.size == -1 ):
            return
        else:
            if(self.middle.pr==None and self.size==1):
                self.head=self.middle.next
                self.head.pr=None;
                self.tail=self.head;

            elif(self.middle.pr==None and self.size==0):
                self.head=None
                self.tail=None

            else:
                self.middle.pr.next = self.middle.next;
                self.middle.next.pr = self.middle.pr;
            self.size -= 1;
            if (self.midIndex < (int)(self.size / 2)):
                self.middle = self.middle.next;
                self.midIndex += 1;
            elif(self.midIndex == (int)(self.size / 2)):
                self.middle=self.middle.next
            elif (self.midIndex > (int)(self.size / 2)):
                self.middle = self.middle.pr;
                self.midIndex -= 1;

    def findMiddle(self):
        if (self.size==-1):
            print(-1)
        else:
            print(self.middle.Date)


input1=(input())
nums=list()

while(input1!="finish"):

    if "push" in input1:
        x=input1.split()
        nums.addNode(x[1])
    if "findMiddle" in input1:
        nums.findMiddle()
    if "removeMiddle" in input1:
        if(nums.size==-1):
            input1=input()
            continue
        else:
            nums.removeMiddle()
    if "pop" in input1:
        if (nums.size == -1):
            input1 = input()
            continue
        else:
            nums.pop()

    if "print" in input1:
        nums.display()
    input1=input()




