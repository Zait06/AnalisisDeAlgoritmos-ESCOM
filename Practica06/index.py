import copy
import json
import pickle
import bitstring
import numpy as np
from array import *
from sys import argv
from Huffman import *

class HuffmanCode(Huffman):
    def __init__(self):
        Huffman.__init__(self)
        self.nameFile = str()
        self.ADN_letters = ['A','C','G','T']     # Letras de ADN
        self.strCode = np.zeros(256,dtype=np.int32)
        self.frequence = dict()
        self.__code00 = dict()

    def adnRead(self,nameFile):
        print("Leyendo ADN")
        self.nameFile = nameFile
        with open(nameFile,'r') as file:
            for line in file.readlines():
                for letter in self.ADN_letters:
                    self.frequence[letter] = line.count(letter)

    def textRead(self,nameFile):
        print("Leyendo Texto")
        self.nameFile = nameFile
        with open(nameFile,'r') as file:
            for line in file.readlines():
                for caracter in line:
                    if caracter in self.frequence.keys():
                        self.frequence[caracter] += 1
                    else:
                        self.frequence[caracter] = 1

    def imageRead(self,nameFile):
        print("Leyendo Imagen")
        self.nameFile = nameFile

    def __createList(self):
        for dato in self.frequence.keys():
            self.add(Node(dato,self.frequence[dato]))
        # self.showData()

    def __createTree(self):
        while self.tam > 1:
            self.remove_add()
        # self.showTree(0,self.Front)

    def __encode(self,rootTree,n):
        if (rootTree.izq == None) and (rootTree.der == None):
            strFin = str()
            if self.strCode[0] == 0:
                strFin = '1'
            for bit in range(0,n):
                strFin += str(self.strCode[bit])
            self.__code00[rootTree.data] = copy.copy(strFin)
            print("Codigo de {}: {}".format(rootTree.data,strFin))
        else:
            self.strCode[n] = 0
            n += 1
            self.__encode(rootTree.izq,n)
            self.strCode[n-1] = 1
            self.__encode(rootTree.der,n)

    def makeHuffman(self):
        self.__createList()
        self.__createTree()
        self.__encode(self.Front,0)

    def __makeJSON(self):
        nameJSON = self.nameFile.split('.')
        nameJSON = nameJSON[0]+'.json'
        with open(nameJSON,'w') as file:
            json.dump(self.__code00,file,indent=2)
        
        print('\nCabezera guardada en '+nameJSON)

    def __makeCompress(self):
        newName = self.nameFile.split('.')
        newName = newName[0]+'_compress.txt'
        outf = open(newName,'wb')
        bitsave = bitstring.BitArray(bin='0')
        with open(self.nameFile,'r') as file:
            for line in file.readlines():
                for caracter in line:
                    bits = self.__code00[caracter]
                    bitsave = bitstring.BitArray(bin=bits)
                    bitsave.tofile(outf)
        outf.close()
        print("Compresion en "+newName)

    def compress(self):
        self.__makeJSON()
        self.__makeCompress()
        print("Compresion realizada")

def compressFunction(hfc):
    print("Comprimiendo archivo")
    try:
        if name.find("txt") > -1:
            if name.find("ADN") > -1:
                hfc.adnRead(name)
            else:
                hfc.textRead(name)
        else:
            hfc.imageRead(name)
        hfc.makeHuffman()
        hfc.compress()
    except NameError:
        print(NameError)
        print('Error en el programa')

def decompressFunction(hfc):
    print("Descomprimiendo archivo")

if __name__ == "__main__":
    hfc = HuffmanCode()
    name = argv[1]
    action = argv[2]

    if action == 'c':
        compressFunction(hfc)
    elif action == 'd':
        decompressFunction(hfc)
    else:
        print("Error, algun parametro es incorrecto")