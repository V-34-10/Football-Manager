//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Transfer.h"
#include "MainPlayer.h"
#include "BD.h"
#include "Modification.h"
#include "DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTransfer *Transfer; int Item, kol_transfer;
extern AnsiString curpib;
//---------------------------------------------------------------------------
__fastcall TTransfer::TTransfer(TComponent* Owner)
	: TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TTransfer::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(CanClose == true){ MainPlayer->Visible = true;Image1->Picture->LoadFromFile("player\\human-error.jpg"); DateTimePicker1->Enabled=False;
	SpeedButton5->Enabled=False; DBListBox2->Clear(); StatusBar1->Panels->Items[0]->Text=" "; Label3->Caption = " ";}
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::DBGrid1CellClick(TColumn *Column)
{
	//image and more information for transfer
	TDateTime date_born = DataModule5->ADOQuery5->FieldByName("date")->AsDateTime;

	 AnsiString pib_trener = DataModule5->ADOQuery5->FieldByName("Pib_trener")->AsAnsiString;
	 Label3->Caption = "Тренер - " + pib_trener;

     AnsiString pib = DBGrid1->DataSource->DataSet->FieldByName("pib")->AsAnsiString;
	 Label1->Caption = pib;

	 AnsiString trip_player = DBGrid1->DataSource->DataSet->FieldByName("image")->AsAnsiString;
	 Image1->Picture->LoadFromFile("player\\"+trip_player);

	 DBListBox2->Clear();
	 DBListBox2->Items->Add("Вихованець " + DBGrid1->DataSource->DataSet->FieldByName("Name")->AsAnsiString+":");
	 DBListBox2->Items->Add("Вік - " + IntToStr(YearsBetween(Now(),DateToStr(date_born))));
	 DBListBox2->Items->Add("Початок контракту - " + DataModule5->ADOQuery5->FieldByName("date_1")->AsString);
	 DBListBox2->Items->Add("Кінець контракту - " + DataModule5->ADOQuery5->FieldByName("date_2")->AsString);

	 Item = DBGrid1->DataSource->DataSet->FieldByName("id_transfer")->AsInteger;

	 DateTimePicker1->Enabled=False;
	SpeedButton5->Enabled=False;
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::DBGrid1TitleClick(TColumn *Column)
{
	//sorting
	if (DataModule5->ADOQuery5->Active)
		if ((DataModule5->ADOQuery5->Sort.Pos(Column->FieldName) > 0) && (DataModule5->ADOQuery5->Sort.Pos("ASC") > 0)){DataModule5->ADOQuery5->Sort = Column->FieldName + " DESC";}
		else{DataModule5->ADOQuery5->Sort = Column->FieldName + " ASC";}
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::SpeedButton3Click(TObject *Sender)
{
	//select rows
	 DataModule5->ADOQuery5->Last();
	 DateTimePicker1->Enabled=False;
	SpeedButton5->Enabled=False;
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::SpeedButton4Click(TObject *Sender)
{
	//back rows
      DataModule5->ADOQuery5->First();
	 DateTimePicker1->Enabled=False;
	SpeedButton5->Enabled=False;
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::SpeedButton1Click(TObject *Sender)
{
	//add transfer
    Modification->Show();
	 Modification->DBLookupComboBox2->Visible=True; Modification->DateTimePicker2->Visible=True; Modification->DateTimePicker3->Visible=True; Modification->Edit1->Visible=True; Modification->Edit3->Visible=True;
	 Modification->BitBtn4->Enabled=True;  Modification->BitBtn4->Visible=True;  Modification->Label6->Visible=True;

	 Modification->MaskEdit1->Visible=False; Modification->ComboBox1->Visible=False; Modification->Edit2->Visible=False; Modification->DBLookupComboBox1->Visible=False;
	 Modification->CheckBox1->Visible=False; Modification->BitBtn2->Visible=False; Modification->BitBtn3->Visible=False;Modification->BitBtn1->Visible=False;  Modification->Label5->Visible=False;
	 Modification->Label1->Caption="Початок контр.: ",Modification->Label2->Caption="Кінець контр.: ", Modification->Label3->Caption="Термін: ", Modification->Label4->Caption="Ціна/в млн.: ";
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::SpeedButton2Click(TObject *Sender)
{
	//delete transfer
	if(DBGrid1->SelectedRows->Count == 0)
	{
		 if (Application->MessageBox(L"Не виділено жодного рядка в таблиці!!!", L"Попередження", MB_OK|MB_ICONEXCLAMATION)==IDOK)
		 {
		   return;
		 }
	}

	if(DBGrid1->SelectedRows->Count > 0) {

		DataModule5->ADOQuery5->Close();
		DataModule5->ADOQuery5->SQL->Clear();
		DataModule5->ADOQuery5->SQL->Add("SELECT * FROM football_manager.transfer;");
		DataModule5->ADOQuery5->ExecSQL();
		DataModule5->ADOQuery5->Open();

		DataModule5->ADOQuery6->Close();
		DataModule5->ADOQuery6->SQL->Clear();
		DataModule5->ADOQuery6->SQL->Add("DELETE FROM football_manager.transfer WHERE id_transfer =:Item;");

		DataModule5->ADOQuery6->Parameters->ParamByName("Item")->Value = Item;
		DataModule5->ADOQuery6->Prepared = true;
		DataModule5->ADOQuery6->ExecSQL();

        DataModule5->ADOQuery5->Close();
		DataModule5->ADOQuery5->SQL->Clear();
		DataModule5->ADOQuery5->SQL->Add("SELECT * FROM football_manager.transfer INNER JOIN football_manager.player ON `transfer`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `player`.Id_klub = `klub`.Id_klub;");
		DataModule5->ADOQuery5->ExecSQL();
		DataModule5->ADOQuery5->Open();
	}
	DateTimePicker1->Enabled=False;
	SpeedButton5->Enabled=False;

}
//---------------------------------------------------------------------------
void __fastcall TTransfer::DBListBox1DrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State)
{
    // alignment - center  DBListBox
    TListBox *box = static_cast<TListBox*>(Control);
    String s = box->Items->Strings[Index];
    box->Canvas->FillRect(Rect);
    box->Canvas->TextRect(Rect, Rect.Left + (Rect.Width() - box->Canvas->TextWidth(s)) / 2, Rect.Top, s);
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::FormCreate(TObject *Sender)
{
	//image
	Image1->Picture->LoadFromFile("player\\human-error.jpg");
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::GroupBox2Click(TObject *Sender)
{
	//Enabled
	DateTimePicker1->Enabled=True;
	SpeedButton5->Enabled=True;
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::SpeedButton5Click(TObject *Sender)
{
	///search date
	DataModule5->ADOQuery5->Close();
	DataModule5->ADOQuery5->SQL->Clear();
	DataModule5->ADOQuery5->SQL->Add("SELECT * FROM football_manager.transfer INNER JOIN football_manager.player ON `transfer`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `player`.Id_klub = `klub`.Id_klub WHERE `transfer`.date_1 =:date_1;");
	DataModule5->ADOQuery5->Parameters->ParamByName("date_1")->Value = DateTimePicker1->DateTime.FormatString("yyyy.mm.dd");
	DataModule5->ADOQuery5->Prepared = true;
	DataModule5->ADOQuery5->ExecSQL();
	DataModule5->ADOQuery5->Open();

    DateTimePicker1->Enabled=False;
	SpeedButton5->Enabled=False;
	kol_transfer = DataModule5->ADOQuery5->RecordCount;
	StatusBar1->Panels->Items[0]->Text="Кількість трансферів - "+IntToStr(kol_transfer);
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::SpeedButton6Click(TObject *Sender)
{
	//refresh
	DataModule5->ADOQuery5->Close();
	DataModule5->ADOQuery5->SQL->Clear();
	DataModule5->ADOQuery5->SQL->Add("SELECT * FROM football_manager.transfer INNER JOIN football_manager.player ON `transfer`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `player`.Id_klub = `klub`.Id_klub;");
	DataModule5->ADOQuery5->ExecSQL();
	DataModule5->ADOQuery5->Open();
    DateTimePicker1->Enabled=False;
	SpeedButton5->Enabled=False;
    kol_transfer = DataModule5->ADOQuery5->RecordCount;
	StatusBar1->Panels->Items[0]->Text="Кількість трансферів - "+IntToStr(kol_transfer);
}
//---------------------------------------------------------------------------
void __fastcall TTransfer::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
	//  Если игрок удален, то выделяем его трансфер красным типо трансфер не актуален
	TDataSet *dataset = Column->Field->DataSet;
		if(dataset->FieldByName("pib")->AsAnsiString == curpib)
		{
			DBGrid1->Canvas->Brush->Color = clRed;
		}
        DBGrid1->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}

