#pragma hdrstop
#include "BD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule5 *DataModule5;
//---------------------------------------------------------------------------
__fastcall TDataModule5::TDataModule5(TComponent* Owner)
	: TDataModule(Owner){}
//---------------------------------------------------------------------------
void __fastcall TDataModule5::DataModuleCreate(TObject *Sender)
{
	// begin work
    ADOConnection1->Connected=True;
	ADOQuery1->Active=True;
	ADOQuery2->Active=True;
	ADOQuery3->Active=True;
	ADOQuery4->Active=True;
	ADOQuery5->Active=True;
    ADOQuery6->Active=True;
}
//---------------------------------------------------------------------------
void __fastcall TDataModule5::DataModuleDestroy(TObject *Sender){// end work
ADOConnection1->Connected=False;}
