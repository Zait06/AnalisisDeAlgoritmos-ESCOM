import { Component, OnInit } from '@angular/core';
import { ChartDataSets, ChartOptions } from 'chart.js';
import { Color, Label } from 'ng2-charts';

class GraficaLineas{
  lineChartData: ChartDataSets[] = [
    { data: [85, 72, 78, 75, 77, 75], label: 'Función' },
  ];

  lineChartLabels = ['January', 'February', 'March', 'April', 'May', 'June'];

  lineChartOptions = {
    responsive: true,
  };

  lineChartColors: Color[] = [
    {
      borderColor: 'black',
    },
  ];

  lineChartLegend = true;
  lineChartPlugins = [];
  lineChartType = 'line';

  crearDatosFun1(a:number,b:number){
    this.lineChartData[0].data=[];
    this.lineChartLabels=[];
    for(let i=a;i<=b;i=i+0.1){
      this.lineChartData[0].data.push(Math.pow((1-Math.pow(i,2)),(3/2)));
      this.lineChartLabels.push(i.toString());
    }
    this.lineChartData[0].label="Función 1";
  }

  crearDatosFun2(a:number,b:number){
    this.lineChartData[0].data=[];
    this.lineChartLabels=[];
    for(let i=a;i<=b;i=i+0.1){
      this.lineChartData[0].data.push(Math.exp(i+Math.pow(i,2)));
      this.lineChartLabels.push(i.toString());
    }
    this.lineChartData[0].label="Función 2";
  }

  crearDatosFun3(a:number,b:number){
    this.lineChartData[0].data=[];
    this.lineChartLabels=[];
    for(let i=a;i<=b;i=i+0.1){
      this.lineChartData[0].data.push(Math.pow((1-Math.pow(i,2)),2));
      this.lineChartLabels.push(i.toString());
    }
    this.lineChartData[0].label="Función 3";
  }

  crearDatosFun4(a:number,b:number){
    this.lineChartData[0].data=[];
    this.lineChartLabels=[];
    for(let i=a;i<=b*Math.PI;i=i+0.1){
      this.lineChartData[0].data.push(1/(Math.cos(i)+2));
      this.lineChartLabels.push((i).toString());
    }
    this.lineChartData[0].label="Función 4";
  }

  crearDatosFun5(a:number,b:number){
    this.lineChartData[0].data=[];
    this.lineChartLabels=[];
    for(let i=a;i<=b;i=i+0.1){
      if(i!=0){
        this.lineChartData[0].data.push(Math.log(i));
        this.lineChartLabels.push(i.toString());
      }
    }
    this.lineChartData[0].label="Función 5";
  }
}

class Integrales{
  a:number;
  b:number;
  n:number;
  suma:number;
  resultado:number;
  datos:Array<number>

  funcion1(x:number){
    return Math.pow((1-Math.pow(x,2)),(3/2))
  }

  aproxFun1(i:number=0,ui:number=0,ent:number=0){
    ent=0; this.suma=0; this.datos=[];
    for(i=0;i<this.n;i++){
      ui=Math.random()*(1-0)+0
      ent=this.funcion1((ui*(this.b-this.a) + this.a));
      this.datos.push(ent);
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
  ff:any;
  grafica:GraficaLineas=new GraficaLineas();
  
  constructor() {
  }

  ngOnInit() {
  }

  elegirFun(){
    switch(+this.indice){   // +data = pasa de un string a un tipo number
      case 1:
        this.funcionIntegral.aproxFun1();
        this.grafica.crearDatosFun1(this.funcionIntegral.a,this.funcionIntegral.b)
        this.hecho=true;
        break;
      case 2:
        this.funcionIntegral.aproxFun2();
        this.grafica.crearDatosFun2(this.funcionIntegral.a,this.funcionIntegral.b)
        this.hecho=true;
        break;
      case 3:
        this.funcionIntegral.aproxFun3();
        this.grafica.crearDatosFun3(this.funcionIntegral.a,this.funcionIntegral.b)
        this.hecho=true;
        break;
      case 4:
        this.funcionIntegral.aproxFun4();
        this.grafica.crearDatosFun4(this.funcionIntegral.a,this.funcionIntegral.b)
        this.hecho=true;
        break;
      case 5:
        this.funcionIntegral.aproxFun5();
        this.grafica.crearDatosFun5(this.funcionIntegral.a,this.funcionIntegral.b)
        this.hecho=true;
        break;
      default:
        alert("Algo anda mal :c")
        this.hecho=false;
        break;
    }
  }
}
