from Huffman import *
from sys import argv
import numpy as np

class HuffmanCode(Huffman):
    def __init__(self):
        Huffman.__init__(self)
        self.ADN_letters = ['A','C','G','T']     # Letras de ADN
        self.frequence = dict()
        self.code = dict()        

    def adnRead(self,nameFile):
        print("Leyendo ADN")
        with open(nameFile,'r') as file:
            for line in file.readlines():
                for letter in self.ADN_letters:
                    self.frequence[letter] = line.count(letter)

    def textRead(self,nameFile):
        print("Leyendo Texto")
        with open(nameFile,'r') as file:
            for line in file.readlines():
                for caracter in line:
                    if caracter in self.frequence.keys():
                        self.frequence[caracter] += 1
                    else:
                        self.frequence[caracter] = 1

    def imageRead(self,nameFile):
        print("Leyendo Imagen")

    def createList(self):
        for dato in self.frequence.keys():
            self.add(Node(dato,self.frequence[dato]))
        # self.showData()

if __name__ == "__main__":
    hfc = HuffmanCode()
    name = argv[1]

    try:
        if name.find("txt") > -1:
            if name.find("ADN") > -1:
                hfc.adnRead(name)
            else:
                hfc.textRead(name)
        else:
            hfc.imageRead(name)
        hfc.createList()
    except:
        print('Error en el programa')
    
    # hf.add(Node('A',20))
    # hf.add(Node('B',15))
    # hf.add(Node('C',25))
    # hf.add(Node('D',88))
    # hf.add(Node('F',33))
    # hf.add(Node('E',31))
    # hf.add(Node('G',8))

    # hf.showData()
    # print('\nTamanio: {}'.format(hf.tam))