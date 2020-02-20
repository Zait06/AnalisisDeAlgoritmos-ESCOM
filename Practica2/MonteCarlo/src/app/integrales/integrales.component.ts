import { Component, OnInit } from '@angular/core';
import { NumberSymbol } from '@angular/common';

class Integrales{
  a:number;
  b:number;
  n:number;
  suma:number;
  resultado:number;
  datos:Array<number>

  constructor(){
    this.a=this.a;
    this.b=this.b;
    this.n=this.n;
    this.datos=[];
    this.suma=0
    this.resultado=0
  }

  funcion1(x:number){
    return Math.pow((1-Math.pow(x,2)),3)
  }

  aproxFun1(i:number=0,ui:number=0,ent:number=0){
    ent=0; this.suma=0;
    for(i=0;i<this.n;i++){
      ui=Math.random()*(1-0)+0
      ent=this.funcion1((ui*(this.b-this.a) + this.a));
      this.datos.push(ent)
      this.suma+=ent;
    }
    this.resultado=((this.b-this.a)/this.n)*this.suma
  }

  funcion2(x:number){
    return Math.exp(x+Math.pow(x,2))
  }

  aproxFun2(i:number=0,ui:number=0,ent:number=0){
    ent=0; this.suma=0; this.datos=[];
    for(i=0;i<this.n;i++){
      ui=Math.random()*(1-0)+0
      ent=this.funcion2((ui*(this.b-this.a) + this.a));
      this.datos.push(ent)
      this.suma+=ent;
    }
    this.resultado=((this.b-this.a)/this.n)*this.suma
  }

  funcion3(x:number){
    return Math.pow((1-Math.pow(x,2)),2)
  }

  aproxFun3(i:number=0,ui:number=0,ent:number=0){
    ent=0; this.suma=0; this.datos=[];
    for(i=0;i<this.n;i++){
      ui=Math.random()*(1-0)+0
      ent=this.funcion3((ui*(this.b-this.a) + this.a));
      this.datos.push(ent)
      this.suma+=ent;
    }
    this.resultado=((this.b-this.a)/this.n)*this.suma
  }

  funcion4(x:number){
    return 1/(Math.cos(x)+2)
  }

  aproxFun4(i:number=0,ui:number=0,ent:number=0){
    ent=0; this.suma=0; this.datos=[];
    for(i=0;i<this.n;i++){
      ui=Math.random()*(1-0)+0
      ent=this.funcion4((ui*(this.b-this.a) + this.a));
      this.datos.push(ent)
      this.suma+=ent;
    }
    this.resultado=((this.b-this.a)/this.n)*this.suma
  }

  funcion5(x:number){
    return Math.log(x)
  }

  aproxFun5(i:number=0,ui:number=0,ent:number=0){
    ent=0; this.suma=0; this.datos=[];
    for(i=0;i<this.n;i++){
      ui=Math.random()*(1-0)+0
      ent=this.funcion5((ui*(this.b-this.a) + this.a));
      this.datos.push(ent)
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
  hecho:boolean=false;
  indice:number;
  
  constructor() {
  }

  ngOnInit() {
  }

  elegirFun(){
    console.log(this.indice)

    switch(this.indice){
      case 1:
        console.log("Si entro");
        this.funcionIntegral.aproxFun1();
        this.hecho=true;
        break;
      case 2:
        this.funcionIntegral.aproxFun2();
        this.hecho=false;
        break;
      case 3:
        this.funcionIntegral.aproxFun3();
        this.hecho=true;
        break;
      case 4:
        this.funcionIntegral.aproxFun4();
        this.hecho=true;
        break;
      case 5:
        this.funcionIntegral.aproxFun5();
        this.hecho=true;
        break;
      default:
        alert("Algo anda mal :c")
        this.hecho=false;
        break;
    }
  }
}
