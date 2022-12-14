//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit7.h"
#include "Unit8.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1; int curItem;
AnsiString curpib;
 //контейнер для своих названий кнопок
class MessageButtons
{
    public:
        String OK,
                YES,
                NO,
                CANCEL,
                ABORT,
                RETRY;
};
 MessageButtons buttons;
HHOOK hook;
LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
        HWND hwnd;
        HWND hwndButton;

        if(nCode < 0)
                return CallNextHookEx(hook, nCode, wParam, lParam);

        switch(nCode)
        {
            case HCBT_ACTIVATE:
                hwnd = (HWND)wParam;
                //присваимаем текст, кнопке
                hwndButton = GetDlgItem(hwnd, IDOK);
                SetWindowText(hwndButton, buttons.OK.c_str());

                hwndButton = GetDlgItem(hwnd, IDCANCEL);
                SetWindowText(hwndButton, buttons.CANCEL.c_str());

                hwndButton = GetDlgItem(hwnd, IDCANCEL);
                SetWindowText(hwndButton, buttons.NO.c_str());

                hwndButton = GetDlgItem(hwnd, IDYES);
                SetWindowText(hwndButton, buttons.YES.c_str());

                hwndButton = GetDlgItem(hwnd, IDABORT);
                SetWindowText(hwndButton, buttons.ABORT.c_str());

                hwndButton = GetDlgItem(hwnd, IDRETRY);
                SetWindowText(hwndButton, buttons.RETRY.c_str());
                break;
        }

        return CallNextHookEx(hook, nCode, wParam, lParam);
}
//перегружаем функцию MessageBox
int MessageBox(String message, String title, UINT type)
{
    int messageRes;
    hook = SetWindowsHookEx(
                WH_CBT,
                (HOOKPROC)HookProc,
                NULL,
                GetCurrentThreadId()
                );
    MessageBox(NULL, message.c_str(), title.c_str(), type);
    UnhookWindowsHookEx(hook);
	return messageRes;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
	///Plan
	Form2->Show();
	Form1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
	///Match
	Form3->Show();
	Form1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
	///Transfer
	Form4->Show();
	Form1->Visible = false;
    int kol = DataModule5->ADOQuery5->RecordCount;
	Form4->StatusBar1->Panels->Items[0]->Text="Кількість трансферів - "+IntToStr(kol);
    Form4->StatusBar1->Panels->Items[1]->Text="Не актуальний трансфер - червоне поле";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	 //loading aplication
      Form8->Show();
	Form1->Visible = false;
	//default image
	Image2->Picture->LoadFromFile("emblems\\error1.jpg");
	Image1->Picture->LoadFromFile("player\\human-error.jpg");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose){Form8->Close();}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1CellClick(TColumn *Column)      // show image
{

			//player
			AnsiString trip_player = DBGrid1->DataSource->DataSet->FieldByName("image")->AsAnsiString;
			Image1->Picture->LoadFromFile("player\\"+trip_player);
            AnsiString pib = DBGrid1->DataSource->DataSet->FieldByName("pib")->AsAnsiString;
			Label2->Caption = pib;

			DBListBox1->Clear();
			DBListBox1->Items->Add("Дата народження - " + DataModule5->ADOQuery1->FieldByName("date")->AsString);
			DBListBox1->Items->Add("Позиція - " + DataModule5->ADOQuery1->FieldByName("position")->AsString);
			DBListBox1->Items->Add("Номер на полі - " + DataModule5->ADOQuery1->FieldByName("number")->AsString);

			AnsiString pib_trener = DataModule5->ADOQuery1->FieldByName("Pib_trener")->AsString;
			AnsiString liga = DataModule5->ADOQuery1->FieldByName("Liga")->AsString;
			Label3->Caption = "Тренер: " + pib_trener;Label4->Caption = liga;

            //emblems
			AnsiString trip = DBGrid1->DataSource->DataSet->FieldByName("Image_1")->AsAnsiString;
			Image2->Picture->LoadFromFile("emblems\\"+trip);

			curItem = DBGrid1->DataSource->DataSet->FieldByName("id_player")->AsInteger;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBLookupComboBox1CloseUp(TObject *Sender)// filter for team
{
	// cancel preveiw filter
		DataModule5->ADOQuery1->SQL->Clear();
		DataModule5->ADOQuery1->SQL->Add("SELECT * FROM football_manager.player INNER JOIN football_manager.klub ON player.Id_klub = klub.Id_klub;");
		DataModule5->ADOQuery1->ExecSQL();
		DataModule5->ADOQuery1->Open();
	 //apply   filter for team
	if(DBLookupComboBox1->Text != " ")
	{
		DataModule5->ADOQuery1->Filtered = false;
		DataModule5->ADOQuery1->Filter = "(Id_klub="+DBLookupComboBox1->ListSource->DataSet->FieldByName(DBLookupComboBox1->KeyField)->AsString+")";
		DataModule5->ADOQuery1->Filtered = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBListBox1DrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State)
{
    // alignment - center  DBListBox
    TListBox *box = static_cast<TListBox*>(Control);
    String s = box->Items->Strings[Index];
    box->Canvas->FillRect(Rect);
    box->Canvas->TextRect(Rect, Rect.Left + (Rect.Width() - box->Canvas->TextWidth(s)) / 2, Rect.Top, s);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1TitleClick(TColumn *Column)
{
    //sorting
		if (DataModule5->ADOQuery1->Active)
		if ((DataModule5->ADOQuery1->Sort.Pos(Column->FieldName) > 0) && (DataModule5->ADOQuery1->Sort.Pos("ASC") > 0)){DataModule5->ADOQuery1->Sort = Column->FieldName + " DESC";}
		else{DataModule5->ADOQuery1->Sort = Column->FieldName + " ASC";}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N11Click(TObject *Sender)               //not filter
{
	DataModule5->ADOQuery1->Filtered = false;
		DataModule5->ADOQuery1->Filter = "";
		DataModule5->ADOQuery1->Filtered = true;
		DBLookupComboBox1->KeyValue = -1;
		RadioGroup1->ItemIndex=0;
        DBLookupComboBox1->ListSource->DataSet->Close();
		DBLookupComboBox1->ListSource->DataSet->Open();
		DataModule5->ADOQuery1->Close();
		DataModule5->ADOQuery1->SQL->Clear();
		DataModule5->ADOQuery1->SQL->Add("SELECT * FROM football_manager.player INNER JOIN football_manager.klub ON player.Id_klub = klub.Id_klub;");
		DataModule5->ADOQuery1->ExecSQL();
		DataModule5->ADOQuery1->Open();
        Image2->Picture->LoadFromFile("emblems\\error1.jpg");Image1->Picture->LoadFromFile("player\\human-error.jpg");
		Label2->Caption=" ";Label3->Caption=" "; Label4->Caption=" ";DBListBox1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)  // filter  position
{
   DataModule5->ADOQuery1->Filtered=false; // cancel preveiw filter
   DBLookupComboBox1->KeyValue = -1;
	if(RadioGroup1->ItemIndex==0)
	{
		DataModule5->ADOQuery1->Close();
		DataModule5->ADOQuery1->SQL->Clear();
		DataModule5->ADOQuery1->SQL->Add("SELECT * FROM football_manager.player INNER JOIN football_manager.klub ON player.Id_klub = klub.Id_klub WHERE position = 'ВР';");
		DataModule5->ADOQuery1->ExecSQL();
		DataModule5->ADOQuery1->Open();
	}
	if(RadioGroup1->ItemIndex==1)
	{
       DataModule5->ADOQuery1->Close();
		DataModule5->ADOQuery1->SQL->Clear();
		DataModule5->ADOQuery1->SQL->Add("SELECT * FROM football_manager.player INNER JOIN football_manager.klub ON player.Id_klub = klub.Id_klub WHERE position = 'ПЗ';");
		DataModule5->ADOQuery1->ExecSQL();
		DataModule5->ADOQuery1->Open();
	}
	if(RadioGroup1->ItemIndex==2)
	{
        DataModule5->ADOQuery1->Close();
		DataModule5->ADOQuery1->SQL->Clear();
		DataModule5->ADOQuery1->SQL->Add("SELECT * FROM football_manager.player INNER JOIN football_manager.klub ON player.Id_klub = klub.Id_klub WHERE position = 'АПЗ';");
		DataModule5->ADOQuery1->ExecSQL();
		DataModule5->ADOQuery1->Open();
	}
	if(RadioGroup1->ItemIndex==3)
	{
		DataModule5->ADOQuery1->Close();
		DataModule5->ADOQuery1->SQL->Clear();
		DataModule5->ADOQuery1->SQL->Add("SELECT * FROM football_manager.player INNER JOIN football_manager.klub ON player.Id_klub = klub.Id_klub WHERE position = 'ЦЗ';");
		DataModule5->ADOQuery1->ExecSQL();
		DataModule5->ADOQuery1->Open();
	}
		
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    //time
	TDateTime NowTime = Now();
	StatusBar1->Panels->Items[0]->Text=NowTime;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
	//add
	Form7->Show();
	Form7->BitBtn1->Enabled=True;
    Image2->Picture->LoadFromFile("emblems\\error1.jpg");Image1->Picture->LoadFromFile("player\\human-error.jpg");
	Label2->Caption=" ";Label3->Caption=" "; Label4->Caption=" ";DBListBox1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
   //edit
   Form7->Show();Form7->BitBtn2->Enabled=True;
   TDataSet  *ds;
	ds = DBGrid1->DataSource->DataSet;
	Form7->MaskEdit1->Text = ds->Fields->FieldByName("pib")->AsString;
	Form7->Edit2->Text = ds->Fields->FieldByName("number")->AsString;
	Form7->DBLookupComboBox1->KeyValue = ds->Fields->FieldByName("Id_klub")->AsInteger;
	Form7->DateTimePicker1->Date = ds->Fields->FieldByName("date")->AsDateTime;
	DBGrid1->EditorMode=True;
    Image2->Picture->LoadFromFile("emblems\\error1.jpg");Image1->Picture->LoadFromFile("player\\human-error.jpg");
	Label2->Caption=" ";Label3->Caption=" "; Label4->Caption=" ";DBListBox1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
	//del
	buttons.OK = "Добре!";
	buttons.NO = "Ні!";
	buttons.CANCEL = "Відміна!";
	if(DBGrid1->SelectedRows->Count == 0)
	{
		 if (MessageBox("Не виділено жодного рядка в таблиці!!!", "Попередження", MB_OK|MB_ICONINFORMATION)==IDOK){return;}
	}
	if(DBGrid1->SelectedRows->Count > 0) {

		curpib = DBGrid1->DataSource->DataSet->FieldByName("pib")->AsAnsiString;
		DataModule5->ADOQuery1->Close();
		DataModule5->ADOQuery1->SQL->Clear();
		DataModule5->ADOQuery1->SQL->Add("SELECT * FROM football_manager.player;");
		DataModule5->ADOQuery1->ExecSQL();
		DataModule5->ADOQuery1->Open();
		DataModule5->ADOQuery6->Close();
		DataModule5->ADOQuery6->SQL->Clear();
		DataModule5->ADOQuery6->SQL->Add("DELETE FROM football_manager.player WHERE id_player =:curItem;");
		DataModule5->ADOQuery6->Parameters->ParamByName("curItem")->Value = curItem;
		DataModule5->ADOQuery6->Prepared = true;
		DataModule5->ADOQuery6->ExecSQL();
		DataModule5->ADOQuery1->Close();
		DataModule5->ADOQuery1->SQL->Clear();
		DataModule5->ADOQuery1->SQL->Add("SELECT * FROM football_manager.player INNER JOIN football_manager.klub ON player.Id_klub = klub.Id_klub;");
		DataModule5->ADOQuery1->ExecSQL();
		DataModule5->ADOQuery1->Open();
		Image2->Picture->LoadFromFile("emblems\\error1.jpg");Image1->Picture->LoadFromFile("player\\human-error.jpg");
		Label2->Caption=" ";Label3->Caption=" "; Label4->Caption=" ";DBListBox1->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N12Click(TObject *Sender)
{
	//save player in fail.txt
	TStringList *s=new TStringList;
	DataModule5->ADOQuery1->First();
	while(!DataModule5->ADOQuery1->Eof)
	{
		s->Add("|"+DataModule5->ADOQuery1->FieldByName("id_player")->AsString +"|"+ DataModule5->ADOQuery1->FieldByName("pib")->AsString +"|"+ DataModule5->ADOQuery1->FieldByName("date")->AsDateTime +"|"+ DataModule5->ADOQuery1->FieldByName("position")->AsString +"|"+ DataModule5->ADOQuery1->FieldByName("number")->AsInteger +"|"+ DataModule5->ADOQuery1->FieldByName("Name")->AsString +"|");
		s->Add(" ");
		DataModule5->ADOQuery1->Next();
	}
	if(SaveDialog1->Execute())
	s->SaveToFile(SaveDialog1->FileName+".txt");
	delete s;
	s = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N14Click(TObject *Sender)
{
	//change color
	if(ColorDialog1->Execute()){
	 Form1->Color=ColorDialog1->Color; Form2->Color=ColorDialog1->Color; Form3->Color=ColorDialog1->Color; Form4->Color=ColorDialog1->Color; Form7->Color=ColorDialog1->Color;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N15Click(TObject *Sender)
{
	//change font
	if(FontDialog1->Execute()){
	 Form1->Font=FontDialog1->Font; Form2->Font=FontDialog1->Font; Form3->Font=FontDialog1->Font; Form4->Font=FontDialog1->Font; Form7->Font=FontDialog1->Font;
	}
}
