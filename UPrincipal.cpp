//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrincipal.h"
#include "Nodo.cpp"
#include <stdlib.h>
//---------------------------------------------------------------------------
//#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Puntero L;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{    //codigo para cargar
	int n, val;
	Puntero Aux;
	Puntero ult;

	n = StrToInt(InputBox("Entrada ","Ingrese Cantidad de valores a mostrar: ","0"));
	L = TIERRA;
	for (int i = 1; i <= n; i++) {
		val= 1+(rand()%2000);
		CrearNodo(Aux);
		PonerData(Aux,val);
		PonerLink(Aux,L);
		L=Aux;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{   String CADE="";
	Puntero p;
	p=L;
	while(p!=TIERRA){
		if(Data(p) %2==0)
		ShowMessage(Data(p));
		p=Link(p);
	}
}
//---------------------------------------------------------------------------

void eliminar(int dato){
	Puntero p = L;
	Puntero ant=TIERRA;

	while((p!=TIERRA)&&(Data(p)!=dato)){
		ant = p;
		p=Link(p);
	}
	if(ant ==TIERRA){
		L=Link(L);
		Retornar(p);
	}
	else
		if(p!=TIERRA){
			PonerLink(ant,Link(p));
			Retornar(p);
		}
}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int val;
	val = StrToInt(InputBox("Entrada ","Ingrese Valor a Eliminar: ","0"));
	eliminar(val);
}
//---------------------------------------------------------------------------
Nodo *l, *Aux, *ult;
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int N, val;
	N = StrToInt(InputBox("Entrada de datos","Ingrese Cantidad de Valores: ","0"));
	l=NULL;

	for (int i=1;i<= N;i++) {
		val = StrToInt(InputBox("Entrada de datos","Ingrese Valor: ","0"));
		Aux = new Nodo;
		(*Aux).Data = val;
		(*Aux).Link = NULL;
		if(l==NULL)
			l=ult=Aux;
		else{
			(*ult).Link = Aux;
			ult=Aux;
		}
	}Edit2->Clear();
	//mostrar
	Nodo *p;
	p = l;
	String cxd="";
	while(p!=NULL){
		cxd=cxd + IntToStr((*p).Data)+" , ";
		p=(*p).Link;
	}
	Edit1->Text=cxd;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Puntero p;
	p=l;
	while(p!=TIERRA){
		if(Data(p) %2==0)
		ShowMessage(Data(p));
		p=Link(p);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	//Codigo para mostrar valores
	String ca="";
	Puntero p= L;

	while(p!=TIERRA){
		ca = ca + IntToStr(Data(p))+" , ";
		p=Link(p);
	}
	Edit1->Text = ca;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
Edit1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int n, val;
	Puntero Aux;
	Puntero ult;

	n = StrToInt(InputBox("Entrada ","Ingrese Cantidad de valores a mostrar: ","0"));
	L = TIERRA;
	for (int i = 1; i <= n; i++) 
	{
		val= 1+(rand()%9999);
			if (val%2==0)
			{
			CrearNodo(Aux);
			PonerData(Aux,val);
			PonerLink(Aux,L);
			L=Aux;
			}
	}
}

//---------------------------------------------------------------------------



void __fastcall TForm1::Button9Click(TObject *Sender)
{
	String ca="";
	Puntero p= L;

	while(p!=TIERRA){
		ca =IntToStr(Data(p));
		p=Link(p);
	ShowMessage(ca);
	}
}
//---------------------------------------------------------------------------
 void invertir(Puntero &l){
	Puntero p; //*r

	Aux=TIERRA;
	while(l!=TIERRA){
		p = l;
		l = Link(l);
		PonerLink(p, Aux);    //(*p).Link= Aux;
		Aux=p;

	}
	l=Aux;
 }
void __fastcall TForm1::Button10Click(TObject *Sender)
{
    invertir(l);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{   Edit2->Clear();
	Nodo *p;
	p = l;
	String cad="";
	while(p!=NULL){
		cad=cad + IntToStr((*p).Data)+" , ";
		p=(*p).Link;
	}
	Edit1->Text=cad;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	Edit1->Clear();
	Nodo *p;
	p = l;
	String c="";
	while(p!=NULL){
		c=c + IntToStr((*p).Data)+" , ";
		p=(*p).Link;
	}
	Edit2->Text=c;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	int u;
	Puntero p;
	p=l;
	while(p!=TIERRA){
		if(Data(p)%2==0)
		u=u+Data(p);
		p=Link(p);
	} Edit1->Text=u;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button15Click(TObject *Sender)
{
	Nodo *p;
	p = l;
	String ced="";
	while(p!=NULL){
		ced=ced + IntToStr((*p).Data)+" , ";
		p=(*p).Link;
	}
	Edit1->Text=ced;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
	int u;
	Puntero p;
	p=l;
	while(p!=TIERRA){
		if(Data(p)%2==0)
		u=u+Data(p);
		p=Link(p);
	}Edit2->Text= u;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
		int h;
	Puntero p;
	p=l;
	while(p!=TIERRA){
		if(Data(p)%2==1)
		h=h+Data(p);
		p=Link(p);
	}Edit2->Text=h;
}
//---------------------------------------------------------------------------
void InsertarOrdenadamente (int dato){
Puntero AAux;
	Puntero AAnt = NULL;
	Puntero ssig =  l;
	while ((ssig!=TIERRA)&&(Data(ssig)< dato))
			{
				AAnt = ssig;
				ssig = Link(ssig);
			}
			if(AAnt == NULL){//El dato ocupara el primer lugar
				CrearNodo(AAux);
				PonerData(AAux,dato);
				PonerLink(AAux,l);
				l = AAux;
			}
			else{
				if (Data(AAnt)==dato) {

				}
				else{
					CrearNodo(AAux);
					PonerData(AAux,dato);
					PonerLink(AAnt,AAux);
					PonerLink(AAux,ssig);
				}
			}
}
void __fastcall TForm1::Button18Click(TObject *Sender)
{
	int gg;
	gg = StrToInt(InputBox("Entrada ","Ingrese Valor a Insertar:","0"));
	InsertarOrdenadamente(gg);
	Nodo *p;
	p = l;
	String can="";
	while(p!=NULL){
		can=can + IntToStr((*p).Data)+" , ";
		p=(*p).Link;
	}
	Edit1->Text=can;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
	Edit3->Text=Edit1->Text*Edit2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
	Edit2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
 	int N, val;
	N = StrToInt(InputBox("Entrada de datos","Ingrese Cantidad de Valores: ","0"));
	l=NULL;

	for (int i=1;i<= N;i++) {
		val = StrToInt(InputBox("Entrada de datos","Ingrese Valor: ","0"));
		Aux = new Nodo;
		(*Aux).Data = val;
		(*Aux).Link = NULL;
		if(l==NULL)
			l=ult=Aux;
		else{
			(*ult).Link = Aux;
			ult=Aux;
		}
	}Edit2->Clear();
	//mostrar
	Nodo *p;
	p = l;
	String ced="";
	while(p!=NULL){
		ced=ced + IntToStr((*p).Data)+" , ";
		p=(*p).Link;
	}
	Edit2->Text=ced;

}
//---------------------------------------------------------------------------
void ElimRepe(int dato){
Puntero AAux;
	Puntero AAnt = NULL;
	Puntero ssig =  l;
	while ((ssig!=TIERRA)&&(Data(ssig)!=dato))
			{
				AAnt = ssig;
				ssig = Link(ssig);
			}
			if(AAnt == NULL){//El dato ocupara el primer lugar


				PonerLink(l,Link(l));
				delete ssig;
			}
			else{
				if (Data(AAnt)==dato) {
				   PonerLink(AAnt,Link(ssig));
				   delete ssig;
				}
				else{

				}
			}
	}



void __fastcall TForm1::Button20Click(TObject *Sender)
{
int h=StrToInt(InputBox("Entrada","Ingrese Valor: ","0"));
ElimRepe(h);
	Nodo *p;
	p = l;
	String ced="";
	while(p!=NULL){
		ced=ced + IntToStr((*p).Data)+" , ";
		p=(*p).Link;
	}
	Edit1->Text=ced;
}
//---------------------------------------------------------------------------

