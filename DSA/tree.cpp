class db_hash:
   hashTable=[]
   n=0
   def __init__(self):
       self.n= int(input("Enter Size"))
       self.hashTable=[None]*self.n
       print(self.hashTable) 


   def hashFunction1(self,key):
       return key%self.n
   def hashFunction2(self,key):
       return key%4
   def hashFunction(self,key):
       i=0
       while True:
               index=(self.hashFunction1(key)+i*self.hashFunction2(key))%self.n

               if self.hashTable[index]==None:
                   return index
               elif (i>self.n):
                   break
               else:
                  i+=1

       return  -1
   def hashFunctionSearch(self,key):
       i=0
       while True:
               index=(self.hashFunction1(key)+i*self.hashFunction2(key))%self.n

               if self.hashTable[index]==key:
                   return index
               elif (i>self.n):
                   break
               else:
                  i+=1

       return  -1




def menu():
        h = db_hash()
        while True:
                print("############Menu##############")
                print("1.Insert\n2.Search\nAny other key to exit .Exit")
                ch=int(input("Enter choice"))
                if ch==1:
                        key=int(input("Enter Number"))
                        index = h.hashFunction(key)
                        if index!=-1:
                                h.hashTable[index]=key
                        else:
                                print("table is full")
                elif ch==2:
                        key=int(input("Enter Number"))
                        index = h.hashFunctionSearch(key)
                        if index!=-1:
                                print("Element Found")
                        else:
                                print("ELement not found")



menu()

//111111111111