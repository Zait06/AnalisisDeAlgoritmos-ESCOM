import { Component, OnInit } from '@angular/core';
import { ChartDataSets, ChartOptions } from 'chart.js';
import { Color, Label } from 'ng2-charts';

class GraficaLineas{        // Clase para crear gráficas
  lineChartData: ChartDataSets[] = [    // Inicialización de la grafica con datos y un numbre de los datos
    { data: [85, 72, 78, 75, 77, 75], label: 'Función' }, 
    { data: [
              {x:0,y:0},
              {x:.85,y:.72},
              {x:.78,y:.75},
              {x:.85,y:.72}
            ], label: 'Aproximación de la función'}
  ];

  lineChartLabels = [];   // Eje x de los datos que se imprimiran

  lineChartOptions = {
    responsive: true,
  };

  lineChartColors: Color[] = [    // Colores para cada una de las graficas
    {
      borderColor: 'black',
    },
    {
      borderColor: 'red',
    }
  ];

  lineChartLegend = true;   // Valor verdadero para que salgan las leyendas
  lineChartType = 'line';   // tipo de grafica

  crearDatosFun1(a:number,b:number,d:Array<number>){
    this.lineChartData[0].data=[];
    this.lineChartData[1].data=[];
    this.lineChartLabels=[];
    for(let i=a,j=0;i<=b;i=i+0.1,j++){
      this.lineChartData[0].data.push(Math.pow((1-Math.pow(i,2)),(3/2)));
      this.lineChartData[1].data.push(d[j],Math.pow((1-Math.pow(d[j],2)),(3/2)));
      this.lineChartLabels.push(i.toString());
    }
    this.lineChartData[0].label="Función 1";
  }

  crearDatosFun2(a:number,b:number,d:Array<number>){
    this.lineChartData[0].data=[];
    this.lineChartData[1].data=[];
    this.lineChartLabels=[];
    for(let i=a,j=0;i<=b;i=i+0.1,j++){
      this.lineChartData[0].data.push(Math.exp(i+Math.pow(i,2)));
      this.lineChartData[1].data.push(d[j],Math.exp(d[j]+Math.pow(d[j],2)));
      this.lineChartLabels.push(i.toString());
    }
    this.lineChartData[0].label="Función 2";
  }

  crearDatosFun3(a:number,b:number,d:Array<number>){
    this.lineChartData[0].data=[];
    this.lineChartData[1].data=[];
    this.lineChartLabels=[];
    for(let i=a,j=0;i<=b;i=i+0.1,j++){
      this.lineChartData[0].data.push(Math.pow((1-Math.pow(i,2)),2));
      this.lineChartData[1].data.push(d[j],Math.pow((1-Math.pow(d[j],2)),2));
      this.lineChartLabels.push(i.toString());
    }
    this.lineChartData[0].label="Función 3";
  }

  crearDatosFun4(a:number,b:number,d:Array<number>){
    this.lineChartData[0].data=[];
    this.lineChartData[1].data=[];
    this.lineChartLabels=[];
    for(let i=a,j=0;i<=b*Math.PI;i=i+0.1,j++){
      this.lineChartData[0].data.push(1/(Math.cos(i)+2));
      this.lineChartData[1].data.push(d[j],1/(Math.cos(d[j])+2));
      this.lineChartLabels.push((i).toString());
    }
    this.lineChartData[0].label="Función 4";
  }

  crearDatosFun5(a:number,b:number,d:Array<number>){
    this.lineChartData[0].data=[];
    this.lineChartData[1].data=[];
    this.lineChartLabels=[];
    for(let i=a,j=0;i<=b;i=i+0.1,j++){
      if(i!=0){
        this.lineChartData[0].data.push(Math.log(i));
        this.lineChartData[1].data.push(d[j],Math.log(d[j]));
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
    ent=0; this.suma=0;
    this.datos=[];
    for(i=0;i<this.n;i++){
      ui=Math.random()*(1-0)+0
      ent=this.funcion1((ui*(this.b-this.a) + this.a));
      this.datos.push((ui*(this.b-this.a) + this.a));
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
      this.datos.push((ui*(this.b-this.a) + this.a))
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
      this.datos.push((ui*(this.b-this.a) + this.a))
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
      this.datos.push((ui*(this.b-this.a) + this.a))
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
      ent=this.funcion5((ui*(this.b-this.a) + this.a)*Math.PI);
      this.datos.push((ui*(this.b-this.a) + this.a))
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
  grafica:GraficaLineas=new GraficaLineas();
  ff:any=this.funcionIntegral;
  
  constructor() {
  }

  ngOnInit() {
  }

  elegirFun(){
    switch(+this.indice){   // +data = pasa de un string a un tipo number
      case 1:
        this.ff.aproxFun1();
        this.grafica.crearDatosFun1(this.ff.a,this.ff.b,this.ff.datos);
        this.hecho=true;
        break;
      case 2:
        this.ff.aproxFun2();
        this.grafica.crearDatosFun2(this.ff.a,this.ff.b,this.ff.datos)
        this.hecho=true;
        break;
      case 3:
        this.ff.aproxFun3();
        this.grafica.crearDatosFun3(this.ff.a,this.ff.b,this.ff.datos)
        this.hecho=true;
        break;
      case 4:
        this.ff.aproxFun4();
        this.grafica.crearDatosFun4(this.ff.a,this.ff.b,this.ff.datos)
        this.hecho=true;
        break;
      case 5:
        this.ff.aproxFun5();
        this.grafica.crearDatosFun5(this.ff.a,this.ff.b,this.ff.datos)
        this.hecho=true;
        break;
      default:
        alert("Algo anda mal :c")
        this.hecho=false;
        break;
    }
  }
}
