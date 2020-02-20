import { Component, OnInit } from '@angular/core';
import { NumberSymbol } from '@angular/common';

class Integrales{
  a:number;
  b:number;
  n:number;
  suma:number;
  indice:number;
  resultado:number;
  datos:Array<number>

  constructor(){
    this.a=this.a;
    this.b=this.b;
    this.n=this.n;
    this.suma=0
    this.resultado=0
  }

  funcion1(x:number){
    return Math.pow((1-Math.pow(x,2)),3)
  }

  aproxFun1(i:number=0,s:number=0,ui:number=0,ent:number=0){
    s=0; ent=0; this.suma=0;
    for(i=0;i<this.n;i++){
      ui=Math.random()*(1-0)+0
      ent=this.funcion1((ui*(this.b-this.a) + this.a));
      //this.datos.push(ent)
      this.suma+=ent;
    }
    this.resultado=((this.b-this.a)/this.n)*this.suma
  }
}

@Component({
  selector: 'app-integrales',
  templateUrl: './integrales.component.html',
  styleUrls: ['./integrales.component.scss']
})
export class IntegralesComponent implements OnInit {
  
  funcionIntegral:Integrales=new Integrales();
  
  constructor() {
  }

  ngOnInit() {
  }

  elegirFun(){
    this.funcionIntegral.aproxFun1()
    console.log(this.funcionIntegral.resultado)
  }

}
