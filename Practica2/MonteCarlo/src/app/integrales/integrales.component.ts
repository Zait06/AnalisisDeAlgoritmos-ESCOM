import { Component, OnInit } from '@angular/core';
import { NumberSymbol } from '@angular/common';

class Integrales{
  a:string;
  b:number;
  n:number;
  indice:boolean;

  constructor(){
    this.a=this.a;
    this.b=this.b;
    this.n=this.n;
    this.indice=this.indice;
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
    console.log(this.funcionIntegral.indice);
  }

}
