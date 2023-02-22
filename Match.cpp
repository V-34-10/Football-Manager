//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Match.h"
#include "MainPlayer.h"
#include "BD.h"
#include "Report.h"
#include "Modification.h"
//#include "qrexport.hpp"
//#include "QRCtrls.hpp"
//#include "QuickRpt.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMatch *Match;AnsiString trip =  "error1.jpg"; int item;
//---------------------------------------------------------------------------
__fastcall TMatch::TMatch(TComponent* Owner)
	: TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TMatch::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(CanClose == true){ MainPlayer->Visible = true;Image1->Picture->LoadFromFile("match\\error1.jpg");}
}
//---------------------------------------------------------------------------
void __fastcall TMatch::DBGrid1CellClick(TColumn *Column)
{
	//image match
	trip = DataModule5->ADOQuery4->FieldByName("image")->AsString;
	Image1->Picture->LoadFromFile("match\\"+trip);
	item = DBGrid1->DataSource->DataSet->FieldByName("id_match")->AsInteger;
}
//---------------------------------------------------------------------------
void __fastcall TMatch::FormCreate(TObject *Sender)
{
   Image1->Picture->LoadFromFile("match\\"+trip);
}
//---------------------------------------------------------------------------
void __fastcall TMatch::BitBtn1Click(TObject *Sender)
{
	//print
	//Report->QuickRep1->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TMatch::BitBtn2Click(TObject *Sender)
{
	 //save html document
     DataModule5->ADOQuery4->Close();
		DataModule5->ADOQuery4->SQL->Clear();
		DataModule5->ADOQuery4->SQL->Add("SELECT `klub`.Name, `match`.klub2, `match`.date_match, `plan`.name_plan, `match`.kol_ball, `match`.kol_gears, `match`.result, `match`.sezon, `match`.image FROM football_manager.match INNER JOIN football_manager.klub ON `match`.id_klub1 = `klub`.Id_klub  INNER JOIN football_manager.plan ON `match`.id_plan = `plan`.id_plan;");
		DataModule5->ADOQuery4->ExecSQL();
		DataModule5->ADOQuery4->Open();
	TStringList *list = new TStringList();
	  list->Clear();
	  TDataSet *dataset = DBGrid1->DataSource->DataSet;
	  list->Add("<html> <head> <title>Результати проведених матчів</title></head> <body> <table border=1>");
	  list->Add("<tr>");
	  for(int b=0; b<DBGrid1->Columns->Count; b++)
	   {

		 list->Add("<td>"+DBGrid1->Columns->Items[b]->Title->Caption+"</td>");

	   }
	  list->Add("</tr>");
	  dataset->DisableControls();
	  dataset->First();
	  while(!dataset->Eof)
		{
		 list->Add("<tr>");
		 for(int i=0; i<DBGrid1->Columns->Count;i++)
		  {
			 list->Add("<td>"+dataset->Fields->Fields[i]->AsString+"</td>");
		  }
		 list->Add("</tr>");
		  dataset->Next();
		}
	  dataset->EnableControls();
	  dataset->First();
	  list->Add("</table>");
	  list->Add("</body>");
	  list->Add("</html>");
	  String WayToBase = ExtractFilePath(Application->ExeName)+"1.html";
	  list->SaveToFile(WayToBase);
	  delete list;
	  list = NULL;
	  Application->MessageBox(L"Успішно створено таблицю з відповідними даними!", L"Повідомлення", MB_OK|MB_ICONEXCLAMATION);
	  DataModule5->ADOQuery4->Close();
		DataModule5->ADOQuery4->SQL->Clear();
		DataModule5->ADOQuery4->SQL->Add("SELECT * FROM football_manager.match INNER JOIN football_manager.klub ON `match`.id_klub1 = `klub`.Id_klub  INNER JOIN football_manager.plan ON `match`.id_plan = `plan`.id_plan;");
		DataModule5->ADOQuery4->ExecSQL();
		DataModule5->ADOQuery4->Open();
}
//---------------------------------------------------------------------------

void __fastcall TMatch::BitBtn3Click(TObject *Sender)
{
	//del
	if(DBGrid1->SelectedRows->Count == 0){if (Application->MessageBox(L"Не виділено жодного рядка в таблиці!!!", L"Попередження", MB_OK|MB_ICONEXCLAMATION)==IDOK){return;}}
	if(DBGrid1->SelectedRows->Count > 0) {

		DataModule5->ADOQuery4->Close();
		DataModule5->ADOQuery4->SQL->Clear();
		DataModule5->ADOQuery4->SQL->Add("SELECT * FROM football_manager.match;");
		DataModule5->ADOQuery4->ExecSQL();
		DataModule5->ADOQuery4->Open();
		DataModule5->ADOQuery6->Close();
		DataModule5->ADOQuery6->SQL->Clear();
		DataModule5->ADOQuery6->SQL->Add("DELETE FROM football_manager.match WHERE id_match =:item;");
		DataModule5->ADOQuery6->Parameters->ParamByName("item")->Value = item;
		DataModule5->ADOQuery6->Prepared = true;
		DataModule5->ADOQuery6->ExecSQL();
		 DataModule5->ADOQuery4->Close();
		DataModule5->ADOQuery4->SQL->Clear();
		DataModule5->ADOQuery4->SQL->Add("SELECT * FROM football_manager.match INNER JOIN football_manager.klub ON `match`.id_klub1 = `klub`.Id_klub  INNER JOIN football_manager.plan ON `match`.id_plan = `plan`.id_plan;");
		DataModule5->ADOQuery4->ExecSQL();
		DataModule5->ADOQuery4->Open();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMatch::BitBtn4Click(TObject *Sender)
{
	//add match
     Modification->Show();
	 Modification->DBLookupComboBox3->Visible=True; Modification->DateTimePicker4->Visible=True; Modification->DBLookupComboBox4->Visible=True; Modification->ComboBox2->Visible=True; Modification->ComboBox3->Visible=True; Modification->ComboBox3->ItemIndex=5; Modification->Label7->Visible=True;
	 Modification->MaskEdit2->Visible=True;Modification->BitBtn6->Enabled=True;  Modification->BitBtn6->Visible=True;  Modification->Label6->Visible=True; Modification->BitBtn5->Visible=True;
	 Modification->MaskEdit1->Visible=False; Modification->ComboBox1->Visible=False; Modification->Edit2->Visible=False; Modification->DBLookupComboBox1->Visible=False;
	 Modification->BitBtn2->Visible=False; Modification->BitBtn3->Visible=False;Modification->BitBtn1->Visible=False;
	 Modification->Label6->Caption="Клуб 1: ",Modification->Label1->Caption="Клуб 2: ",Modification->Label2->Caption="Дата матчу: ", Modification->Label3->Caption="Схема: ", Modification->Label4->Caption="Результат: ";
}
//---------------------------------------------------------------------------
void __fastcall TMatch::DBGrid1TitleClick(TColumn *Column)
{
	//sorting match
	if (DataModule5->ADOQuery4->Active)
		if ((DataModule5->ADOQuery4->Sort.Pos(Column->FieldName) > 0) && (DataModule5->ADOQuery4->Sort.Pos("ASC") > 0)){DataModule5->ADOQuery4->Sort = Column->FieldName + " DESC";}
		else{DataModule5->ADOQuery4->Sort = Column->FieldName + " ASC";}
}

