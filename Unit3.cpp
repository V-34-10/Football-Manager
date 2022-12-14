//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#include "Unit1.h"
#include "Unit5.h"
#include "Unit9.h"
#include "Unit7.h"
#include "qrexport.hpp"
#include "QRCtrls.hpp"
#include "QuickRpt.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;AnsiString trip =  "error1.jpg"; int item;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(CanClose == true){ Form1->Visible = true;Image1->Picture->LoadFromFile("match\\error1.jpg");}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::DBGrid1CellClick(TColumn *Column)
{
	//image match
	trip = DataModule5->ADOQuery4->FieldByName("image")->AsString;
	Image1->Picture->LoadFromFile("match\\"+trip);
	item = DBGrid1->DataSource->DataSet->FieldByName("id_match")->AsInteger;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
   Image1->Picture->LoadFromFile("match\\"+trip);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BitBtn1Click(TObject *Sender)
{
	//print
	Form9->QuickRep1->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BitBtn2Click(TObject *Sender)
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

void __fastcall TForm3::BitBtn3Click(TObject *Sender)
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
void __fastcall TForm3::BitBtn4Click(TObject *Sender)
{
	//add match
     Form7->Show();
	 Form7->DBLookupComboBox3->Visible=True; Form7->DateTimePicker4->Visible=True; Form7->DBLookupComboBox4->Visible=True; Form7->ComboBox2->Visible=True; Form7->ComboBox3->Visible=True; Form7->ComboBox3->ItemIndex=5; Form7->Label7->Visible=True;
	 Form7->MaskEdit2->Visible=True;Form7->BitBtn6->Enabled=True;  Form7->BitBtn6->Visible=True;  Form7->Label6->Visible=True; Form7->BitBtn5->Visible=True;
	 Form7->MaskEdit1->Visible=False; Form7->ComboBox1->Visible=False; Form7->Edit2->Visible=False; Form7->DBLookupComboBox1->Visible=False;
	 Form7->BitBtn2->Visible=False; Form7->BitBtn3->Visible=False;Form7->BitBtn1->Visible=False;
	 Form7->Label6->Caption="Клуб 1: ",Form7->Label1->Caption="Клуб 2: ",Form7->Label2->Caption="Дата матчу: ", Form7->Label3->Caption="Схема: ", Form7->Label4->Caption="Результат: ";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::DBGrid1TitleClick(TColumn *Column)
{
	//sorting match
	if (DataModule5->ADOQuery4->Active)
		if ((DataModule5->ADOQuery4->Sort.Pos(Column->FieldName) > 0) && (DataModule5->ADOQuery4->Sort.Pos("ASC") > 0)){DataModule5->ADOQuery4->Sort = Column->FieldName + " DESC";}
		else{DataModule5->ADOQuery4->Sort = Column->FieldName + " ASC";}
}

