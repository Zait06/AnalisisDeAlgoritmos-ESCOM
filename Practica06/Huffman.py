class Node:
    def __init__(self,dato,freq):
        self.data = dato
        self.freq = freq
        self.sig = None
        self.izq = None
        self.der = None

class Huffman:
    def __init__(self):
        self.Front = None
        self.Back = None
        self.tam = 0
        self.stringTree = str()
        self.union = 0

    def isEmpty(self):
        if self.Front == None and self.Back == None:
            return True
        else:
            return False
    
    def add(self,newNodo):
        if self.isEmpty():
            self.Front = newNodo
            self.Back = newNodo
        else:
            if newNodo.freq <= self.Front.freq:
                newNodo.sig = self.Front
                self.Front = newNodo
            elif newNodo.freq >= self.Back.freq:
                self.Back.sig = newNodo
                self.Back = newNodo
            else:
                aux = self.Front
                while aux.sig != None:
                    if (newNodo.freq >= aux.freq) and (newNodo.freq <= aux.sig.freq):
                        newNodo.sig = aux.sig
                        aux.sig = newNodo
                        break
                    aux = aux.sig
        self.tam += 1

    def remove(self):
        if self.isEmpty():
            print("Error")
        else:
            nodoElem = self.Front
            self.Front = self.Front.sig
            if self.tam == 1:
                self.Back = None
                self.Front = None
            self.tam -= 1
            return nodoElem

    def remove_add(self):
        if self.tam == 1:
            print("No se puede eliminar más")
        else:
            no1 = self.remove()
            no2 = self.remove()
            self.union +=1
            hybNode = Node('u'+str(self.union),(no1.freq+no2.freq))
            hybNode.izq,hybNode.der = no1,no2
            self.add(hybNode)

    def showData(self):
        aux = self.Front
        while aux != None:
            print("{} - {}".format(aux.data,aux.freq))
            aux = aux.sig

    def showTree(self,level,rootTree):
        imprime = str()
        if rootTree != None:
            self.showTree(level+1,rootTree.der)
            imprime += '\n'
            for i in range(0,level):
                imprime += '\t'
            imprime += '('+str(rootTree.data)+','+str(rootTree.freq)+')'
            print(imprime)
            self.showTree(level+1,rootTree.izq)

    def printInorden(self,rootTree):
        if rootTree != None:
            self.printInorden(rootTree.izq);
            self.stringTree += str(rootTree.data)
            self.printInorden(rootTree.der);

# if __name__ == "__main__":
#     hf = Huffman()

#     hf.add(Node('A',20))
#     hf.add(Node('B',15))
#     hf.add(Node('C',25))
#     hf.add(Node('D',88))
#     hf.add(Node('F',33))
#     hf.add(Node('E',31))
#     hf.add(Node('G',8))

#     hf.showData()
#     print('\nTamanio: {}\n'.format(hf.tam))

#     while hf.tam > 1:
#         hf.remove_add()

#     hf.showData()
#     print('Tamanio: {}\n'.format(hf.tam))

#     print(hf.Front,hf.Front.data)
#     print(hf.Back,hf.Back.data)

#     hf.printInorden(hf.Front)
#     print(hf.stringTree)
#     print("\n")
#     hf.showTree(0,hf.Front)