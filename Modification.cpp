#include <vcl.h>
#pragma hdrstop
#include "Modification.h"
#include "BD.h"
#include "MainPlayer.h"
#include "Transfer.h"
#include "Match.h"
#include <regex>
#include <System.RegularExpressions.hpp>
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TModification *Modification;
AnsiString image_match = "error1.jpg", pib, position, image_player = "human-error.jpg";
int number, Nom_Tek_Zap, id_klub, term;
int id_klub1;
AnsiString klub2,  klub1;
//---------------------------------------------------------------------------
__fastcall TModification::TModification(TComponent* Owner): TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TModification::BitBtn1Click(TObject *Sender)
{
	//add player
	if (MaskEdit1->Text.Length() != 0 && Edit2->Text.Length() != 0 &&  DBLookupComboBox1->KeyValue != -1 && ComboBox1->ItemIndex != -1)
	{
			pib =  MaskEdit1->Text;
			position = ComboBox1->Items->Strings[ComboBox1->ItemIndex];    id_klub = DBLookupComboBox1->KeyValue;
			bool flag=false, flag1=true;

			if(StrToInt(Edit2->Text) >=0 && StrToInt(Edit2->Text) <= 100){
				number = StrToInt(Edit2->Text); flag1=false;
			}
			else{Application->MessageBox(L"Номер не повинен перевищувати діапазон значень від 0 до 100!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);Edit2->Clear();}

			for(MainPlayer->DBGrid1->DataSource->DataSet->First(); !MainPlayer->DBGrid1->DataSource->DataSet->Eof; MainPlayer->DBGrid1->DataSource->DataSet->Next())
			{
				if(pib == MainPlayer->DBGrid1->DataSource->DataSet->FieldByName("pib")->AsAnsiString)
				{
					Application->MessageBox(L"Такий гравець присутній в базі!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);
					MaskEdit1->Clear(); flag = true;
				}
			}

			if(flag==false && flag1==false)
			{
				  DataModule5->ADOQuery1->Insert();
				  DataModule5->ADOQuery1->FieldByName("Id_klub")->Value = id_klub;
				  DataModule5->ADOQuery1->FieldByName("pib")->Value = pib;
				  DataModule5->ADOQuery1->FieldByName("date")->Value = DateTimePicker1->Date;
				  DataModule5->ADOQuery1->FieldByName("position")->Value = position;
				  DataModule5->ADOQuery1->FieldByName("number")->Value = number;
				  DataModule5->ADOQuery1->FieldByName("image")->Value = image_player;
				  DataModule5->ADOQuery1->Post();
				  Close(); MaskEdit1->Clear(); ComboBox1->ItemIndex=0; Edit2->Clear(); DBLookupComboBox1->KeyValue=-1;

				  DataModule5->ADOQuery1->Close();
				  DataModule5->ADOQuery1->Open();
			}
	}
	else
	{
		Application->MessageBox(L"Заповніть поля!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);
	}
}
//---------------------------------------------------------------------------
void __fastcall TModification::CheckBox1Click(TObject *Sender) //true/false image
{
	if(CheckBox1->Checked){BitBtn3->Enabled=true;}
	else{BitBtn3->Enabled=false; image_player = "human-error.jpg";}
	if(BitBtn5->Visible)
	{
		if(CheckBox1->Checked){BitBtn5->Enabled=true;}
		else{BitBtn5->Enabled=false; image_match = "error1.jpg";}
	}
}
//---------------------------------------------------------------------------
void __fastcall TModification::BitBtn3Click(TObject *Sender)//open image player
{
	if (OpenPictureDialog1->Execute())
	{
		 image_player = ExtractFileName(OpenPictureDialog1->FileName);
	}
	else {  Application->MessageBox(L"Помилка! Необхідний формат не обрано!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);}
}
//---------------------------------------------------------------------------
void __fastcall TModification::BitBtn2Click(TObject *Sender)
{
	 //edit player

	if (MaskEdit1->Text.Length() != 0  && Edit2->Text.Length() != 0 &&  DBLookupComboBox1->KeyValue != -1 && ComboBox1->ItemIndex != -1)
	{
					pib =  MaskEdit1->Text; position = ComboBox1->Items->Strings[ComboBox1->ItemIndex];  id_klub = DBLookupComboBox1->KeyValue; AnsiString date = FormatDateTime("yyyy.mm.dd", DateTimePicker1->Date);
					int id_player = MainPlayer->DBGrid1->DataSource->DataSet->FieldByName("id_player")->AsInteger;
						  bool flag1=true;

                    	if(StrToInt(Edit2->Text) >=0 && StrToInt(Edit2->Text) <= 100){
							number = StrToInt(Edit2->Text); flag1=false;
						}
						else{Application->MessageBox(L"Номер не повинен перевищувати діапазон значень від 0 до 100!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);Edit2->Clear();}

                  if(flag1==false)
				  {
					  DataModule5->ADOQuery2->Close();
					  DataModule5->ADOQuery2->SQL->Clear();
					  DataModule5->ADOQuery2->SQL->Add("UPDATE player SET Id_klub = :id_klub, pib = :pib, date = :date, position = :position, number = :number, image = :image where id_player = :id_player");

					  DataModule5->ADOQuery2->Parameters->ParamByName("id_player")->Value = id_player;
					  DataModule5->ADOQuery2->Parameters->ParamByName("Id_klub")->Value = id_klub;
					 DataModule5->ADOQuery2->Parameters->ParamByName("pib")->Value = pib;
					 DataModule5->ADOQuery2->Parameters->ParamByName("date")->Value = date;
					 DataModule5->ADOQuery2->Parameters->ParamByName("position")->Value = position;
					 DataModule5->ADOQuery2->Parameters->ParamByName("number")->Value = number;
					 DataModule5->ADOQuery2->Parameters->ParamByName("image")->Value = image_player;
					 DataModule5->ADOQuery2->Prepared = true;
					 DataModule5->ADOQuery2->ExecSQL();

					  Close(); MaskEdit1->Clear(); ComboBox1->ItemIndex=0; Edit2->Clear(); DBLookupComboBox1->KeyValue=-1;

					  DataModule5->ADOQuery1->Close();
					  DataModule5->ADOQuery1->Open();
				  }
	}
	else
	{
		Application->MessageBox(L"Заповніть поля!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);
	}
}
//---------------------------------------------------------------------------
void __fastcall TModification::FormCloseQuery(TObject *Sender, bool &CanClose)//close
{
	if(CanClose == true)
	{
		MaskEdit1->Clear(); Edit2->Clear(); DBLookupComboBox1->KeyValue=-1; ComboBox1->ItemIndex=-1; BitBtn1->Enabled=false; BitBtn2->Enabled=false;
		DBLookupComboBox3->KeyValue=-1;DBLookupComboBox4->KeyValue=-1;  ComboBox2->ItemIndex=-1; ComboBox3->ItemIndex=5;  MaskEdit2->Clear();

		 DBLookupComboBox2->Visible=false; DateTimePicker2->Visible=false; DateTimePicker3->Visible=false; Edit1->Visible=false; Edit3->Visible=false;
		BitBtn4->Enabled=false;  BitBtn4->Visible=false; //Label6->Visible=false;
		Edit3->Clear(); Edit1->Clear(); DBLookupComboBox2->KeyValue=-1;

	 MaskEdit1->Visible=true; ComboBox1->Visible=true; Modification->Edit2->Visible=true; DBLookupComboBox1->Visible=true;
	 CheckBox1->Visible=true; BitBtn2->Visible=true; BitBtn3->Visible=true;BitBtn1->Visible=true;  Label5->Visible=true;
	 Label6->Caption="ПІБ гравця - ", Label1->Caption="Команда - ",Label2->Caption="Дата народження - ", Label3->Caption="Позиція - ", Label4->Caption="Номер на полі - ";


	 DBLookupComboBox3->Visible=false; DateTimePicker4->Visible=false; DBLookupComboBox4->Visible=false; ComboBox2->Visible=false; ComboBox3->Visible=false; Label7->Visible=false;
	 MaskEdit2->Visible=false;BitBtn6->Enabled=false;  BitBtn6->Visible=false; /*Label6->Visible=false;*/ BitBtn5->Visible=false;

      BitBtn2->Visible=true; BitBtn3->Visible=true;BitBtn1->Visible=true;

	}
}
//---------------------------------------------------------------------------
void __fastcall TModification::MaskEdit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key == VK_RETURN)
  if (MaskEdit1->Text.SubString(1,1)!=" ") MaskEdit1->SetFocus();
  else {Application->MessageBox(L"Введення не вірне!", L"Помилка!", MB_OK|MB_ICONWARNING);}
}
//---------------------------------------------------------------------------
void __fastcall TModification::MaskEdit1KeyPress(TObject *Sender, System::WideChar &Key)

{
	if ( (WideChar(Key)>='A' && WideChar(Key)<='z')) Key=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TModification::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key >= '0' && Key <= '9') {
	}
	else if (Key == VK_BACK){}
	else{Key = NULL;  }
}
//---------------------------------------------------------------------------
void __fastcall TModification::BitBtn4Click(TObject *Sender)
{
	//add tranfer
	if (Edit1->Text.Length() != 0 && Edit3->Text.Length() != 0 &&  DBLookupComboBox2->KeyValue != -1)
	{

			 int  price = StrToInt(Edit1->Text);  int id_player = DBLookupComboBox2->KeyValue; bool flag=true;

			 if(StrToInt(Edit3->Text) >= 12 && StrToInt(Edit3->Text) <= 60){
				 term = StrToInt(Edit3->Text);flag=false;
			 }
             else{Application->MessageBox(L"Термін не повинен перевищувати діапазон значень від 12 до 60!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);Edit3->Clear();}

			 if(flag==false){
				  DataModule5->ADOQuery5->Insert();
					DataModule5->ADOQuery5->FieldByName("id_player")->Value = id_player;
				  DataModule5->ADOQuery5->FieldByName("date_1")->Value = DateTimePicker3->Date;
				  DataModule5->ADOQuery5->FieldByName("term")->Value = term;
				  DataModule5->ADOQuery5->FieldByName("date_2")->Value = IncMonth(DateTimePicker3->Date, term);
				  DataModule5->ADOQuery5->FieldByName("price")->Value = price;

				  DataModule5->ADOQuery5->Post(); DateTimePicker2->Date = IncMonth(DateTimePicker3->Date, term);
				  Close(); Edit3->Clear(); Edit1->Clear(); DBLookupComboBox2->KeyValue=-1;

				  DataModule5->ADOQuery5->Close();
				  DataModule5->ADOQuery5->Open();
				  int kol_transfer = DataModule5->ADOQuery5->RecordCount;
				  Transfer->StatusBar1->Panels->Items[0]->Text="Кількість трансферів - "+IntToStr(kol_transfer);
             }
	}
	else
	{
		Application->MessageBox(L"Заповніть поля!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);
	}
}
//---------------------------------------------------------------------------
void __fastcall TModification::Edit3Change(TObject *Sender)
{
	//change date tranfer
     DateTimePicker2->Date = IncMonth(DateTimePicker3->Date, term);
}
//---------------------------------------------------------------------------
void __fastcall TModification::DBLookupComboBox2CloseUp(TObject *Sender)
{
	//perevirka
	AnsiString pib = DBLookupComboBox2->ListSource->DataSet->FieldByName(DBLookupComboBox2->ListField)->AsString;
	TDateTime date_1 = Transfer->DBGrid1->DataSource->DataSet->FieldByName("date_1")->AsDateTime; bool flag=false;
	for(Transfer->DBGrid1->DataSource->DataSet->First(); !Transfer->DBGrid1->DataSource->DataSet->Eof; Transfer->DBGrid1->DataSource->DataSet->Next())
	{
				if(pib == Transfer->DBGrid1->DataSource->DataSet->FieldByName("pib")->AsAnsiString)
				{
					Application->MessageBox(L"Такий трансфер присутній в базі, тому створення трансферу можливе тільки на подальшу дату!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);
					DateTimePicker3->MinDate = date_1; flag=true;
				}
	}
	if(flag==false){DateTimePicker3->MinDate = StrToDate("01.01.2010");}
}
//---------------------------------------------------------------------------
void __fastcall TModification::BitBtn6Click(TObject *Sender)
{
	//add match
	if ( MaskEdit2->Text.Length() != 0 &&  DBLookupComboBox3->KeyValue != -1 &&  DBLookupComboBox4->KeyValue != -1 &&  ComboBox2->ItemIndex != -1 &&  ComboBox3->ItemIndex != -1)
	{
			AnsiString result = MaskEdit2->Text;
			  int id_plan = ComboBox2->ItemIndex; AnsiString sezon = ComboBox3->Items->Strings[ComboBox3->ItemIndex];
			  bool flag=false, flag_klub=false;

			  if(klub1 == klub2){flag_klub=true;DBLookupComboBox3->KeyValue=-1; DBLookupComboBox4->KeyValue=-1; Application->MessageBox(L"Було обрано ідентичні клуби!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);}

			 // search number regular
			int kol_left_ball, kol_right_ball; UnicodeString result1 = result;
			TMatchCollection match = TRegEx::Matches(result1, "\\d+");
			for(int i = 0; i < match.Count; i++)
			{
				if(i==0){kol_left_ball = match.Item[i].Value.ToInt(); }
				if(i==1){kol_right_ball = match.Item[i].Value.ToInt(); }
			}
			int sum_ball = kol_left_ball + kol_right_ball;

			for(Match->DBGrid1->DataSource->DataSet->First(); !Match->DBGrid1->DataSource->DataSet->Eof; Match->DBGrid1->DataSource->DataSet->Next())
			{
				if(result == Match->DBGrid1->DataSource->DataSet->FieldByName("result")->AsAnsiString && klub2 == Match->DBGrid1->DataSource->DataSet->FieldByName("klub2")->AsAnsiString &&
				DateTimePicker4->Date == Match->DBGrid1->DataSource->DataSet->FieldByName("date_match")->AsDateTime && id_plan+1 == Match->DBGrid1->DataSource->DataSet->FieldByName("id_plan")->AsInteger &&
				sezon == Match->DBGrid1->DataSource->DataSet->FieldByName("sezon")->AsAnsiString)
				{
					Application->MessageBox(L"Такий результат матчу присутній в базі!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);
					MaskEdit2->Clear(); DBLookupComboBox3->KeyValue=-1; DBLookupComboBox4->KeyValue=-1; ComboBox2->ItemIndex = -1; ComboBox3->ItemIndex = 5; flag = true;
				}
			}
			if(flag==false && flag_klub==false){
				  DataModule5->ADOQuery4->Insert();
					DataModule5->ADOQuery4->FieldByName("id_klub1")->Value = id_klub1;
					DataModule5->ADOQuery4->FieldByName("klub2")->Value = klub2;
				  DataModule5->ADOQuery4->FieldByName("date_match")->Value = DateTimePicker4->Date;
				  DataModule5->ADOQuery4->FieldByName("id_plan")->Value = id_plan+1;
				  DataModule5->ADOQuery4->FieldByName("kol_ball")->Value = 	sum_ball;
				   DataModule5->ADOQuery4->FieldByName("kol_gears")->Value =  kol_right_ball;
				  DataModule5->ADOQuery4->FieldByName("result")->Value = result;
				  DataModule5->ADOQuery4->FieldByName("sezon")->Value = sezon;
				  DataModule5->ADOQuery4->FieldByName("image")->Value = image_match;

				  DataModule5->ADOQuery4->Post();

				  Close(); MaskEdit2->Clear(); DBLookupComboBox3->KeyValue=-1; DBLookupComboBox4->KeyValue=-1; ComboBox2->ItemIndex = -1; ComboBox3->ItemIndex = 5;

				  DataModule5->ADOQuery4->Close();
				  DataModule5->ADOQuery4->Open();
            }
	}
	else
	{
		Application->MessageBox(L"Заповніть поля!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);
	}
}
//---------------------------------------------------------------------------
void __fastcall TModification::BitBtn5Click(TObject *Sender)
{
	//image download match
	if (OpenPictureDialog1->Execute()){image_match = ExtractFileName(OpenPictureDialog1->FileName);}
	else {  Application->MessageBox(L"Помилка! Необхідний формат не обрано!", L"Помилка!", MB_OK|MB_ICONEXCLAMATION);}
}
//---------------------------------------------------------------------------
void __fastcall TModification::DBLookupComboBox3CloseUp(TObject *Sender)
{
	//change klub1
	id_klub1 = DBLookupComboBox3->KeyValue;
    klub1 = DBLookupComboBox3->ListSource->DataSet->FieldByName(DBLookupComboBox3->ListField)->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TModification::DBLookupComboBox4CloseUp(TObject *Sender)
{
	//change klub2
     klub2 = DBLookupComboBox4->ListSource->DataSet->FieldByName(DBLookupComboBox4->ListField)->AsString;
}
