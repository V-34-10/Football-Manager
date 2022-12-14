//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm2 *Form2; int Count; AnsiString trip_plan =  "error.jpg";
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TForm2::ComboBox1Change(TObject *Sender)
{
	if(ComboBox1->ItemIndex==0)
	{
		if(FileExists("schemes\\4-3-3(1).jpg")){Image1->Picture->LoadFromFile("schemes\\4-3-3(1).jpg");}
		else{
            TMemoryStream *str = new TMemoryStream;
		   HTTP->Get("https://football-esthete.ru/wp-content/uploads/2020/08/rasstanovka-4-3-3.jpg", str);//тут загружаем
		   TJPEGImage *jpg = new TJPEGImage;
		   jpg->LoadFromStream(str);
		   Image1->Picture->Assign(jpg);
		   delete jpg;
		   delete str;
		}
		DataModule5->ADOQuery2->Close();
		DataModule5->ADOQuery2->SQL->Clear();
		DataModule5->ADOQuery2->SQL->Add("SELECT * FROM football_manager.plan INNER JOIN football_manager.list_player ON `plan`.id_plan = `list_player`.id_plan INNER JOIN football_manager.player ON `list_player`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `klub`.Id_klub = `player`.Id_klub WHERE plan.name_plan = '4-3-3';");
		DataModule5->ADOQuery2->ExecSQL();
		DataModule5->ADOQuery2->Open();
		DBListBox1->Clear();
		Count = DataModule5->ADOQuery2->RecordCount;
		DataModule5->ADOQuery2->First();
		if(Count > 0){DBListBox1->Items->Add("Використовує - " + DataModule5->ADOQuery2->FieldByName("Name")->AsString+ ":"); }
		for(int i=1; i<=Count; i++)
		{
			DBListBox1->Items->Add(" - " + DataModule5->ADOQuery2->FieldByName("pib")->AsString +": "+ DataModule5->ADOQuery2->FieldByName("position")->AsString+ ", " + DataModule5->ADOQuery2->FieldByName("number")->AsString);
			DataModule5->ADOQuery2->Next();
		}
		StatusBar1->Panels->Items[0]->Text="Кількість гравців - "+IntToStr(Count);
	}
	if(ComboBox1->ItemIndex==1)
	{
	   if(FileExists("schemes\\4-1-2-1-2(1).jpg")){Image1->Picture->LoadFromFile("schemes\\4-1-2-1-2(1).jpg");}
	   else{
			TMemoryStream *str = new TMemoryStream;
		   HTTP->Get("https://images2.minutemediacdn.com/image/upload/c_fill,w_720,ar_16:9,f_auto,q_auto,g_auto/shape/cover/sport/A1896-6a-696x345-00206256ffa8b2a36de652905af3f900.jpg", str);//тут загружаем
		   TJPEGImage *jpg = new TJPEGImage;
		   jpg->LoadFromStream(str);
		   Image1->Picture->Assign(jpg);
		   delete jpg;
		   delete str;
	   }
	   DataModule5->ADOQuery2->Close();
		DataModule5->ADOQuery2->SQL->Clear();
		DataModule5->ADOQuery2->SQL->Add("SELECT * FROM football_manager.plan INNER JOIN football_manager.list_player ON `plan`.id_plan = `list_player`.id_plan INNER JOIN football_manager.player ON `list_player`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `klub`.Id_klub = `player`.Id_klub WHERE plan.name_plan = '4-1-2-1-2';");
		DataModule5->ADOQuery2->ExecSQL();
		DataModule5->ADOQuery2->Open();
		DBListBox1->Clear();
		Count = DataModule5->ADOQuery2->RecordCount;
		DataModule5->ADOQuery2->First();
		if(Count > 0){DBListBox1->Items->Add("Використовує - " + DataModule5->ADOQuery2->FieldByName("Name")->AsString+ ":"); }
		for(int i=1; i<=Count; i++)
		{
			DBListBox1->Items->Add(" - " + DataModule5->ADOQuery2->FieldByName("pib")->AsString +": "+ DataModule5->ADOQuery2->FieldByName("position")->AsString+ ", " + DataModule5->ADOQuery2->FieldByName("number")->AsString);
			DataModule5->ADOQuery2->Next();

		}
		StatusBar1->Panels->Items[0]->Text="Кількість гравців - "+IntToStr(Count);
	}
	if(ComboBox1->ItemIndex==2)
	{
		if(FileExists("schemes\\4-3-2-1.jpg")){Image1->Picture->LoadFromFile("schemes\\4-3-2-1.jpg");}
		else{
            TMemoryStream *str = new TMemoryStream;
		   HTTP->Get("https://images2.minutemediacdn.com/image/upload/c_fill,w_720,ar_16:9,f_auto,q_auto,g_auto/shape/cover/sport/A1896-15a-696x345-829d3e8b2e7c4c32bb3c0c14f05ef616.jpg", str);//тут загружаем
		   TJPEGImage *jpg = new TJPEGImage;
		   jpg->LoadFromStream(str);
		   Image1->Picture->Assign(jpg);
		   delete jpg;
		   delete str;
		}
		DataModule5->ADOQuery2->Close();
		DataModule5->ADOQuery2->SQL->Clear();
		DataModule5->ADOQuery2->SQL->Add("SELECT * FROM football_manager.plan INNER JOIN football_manager.list_player ON `plan`.id_plan = `list_player`.id_plan INNER JOIN football_manager.player ON `list_player`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `klub`.Id_klub = `player`.Id_klub WHERE plan.name_plan = '4-3-2-1';");
		DataModule5->ADOQuery2->ExecSQL();
		DataModule5->ADOQuery2->Open();
		DBListBox1->Clear();
		Count = DataModule5->ADOQuery2->RecordCount;
		DataModule5->ADOQuery2->First();
        if(Count > 0){DBListBox1->Items->Add("Використовує - " + DataModule5->ADOQuery2->FieldByName("Name")->AsString+ ":"); }
		for(int i=1; i<=Count; i++)
		{
			DBListBox1->Items->Add(" - " + DataModule5->ADOQuery2->FieldByName("pib")->AsString +": "+ DataModule5->ADOQuery2->FieldByName("position")->AsString+ ", " + DataModule5->ADOQuery2->FieldByName("number")->AsString);
			DataModule5->ADOQuery2->Next();
		}
		StatusBar1->Panels->Items[0]->Text="Кількість гравців - "+IntToStr(Count);
	}
	if(ComboBox1->ItemIndex==3)
	{
		if(FileExists("schemes\\4-4-2.jpg")){Image1->Picture->LoadFromFile("schemes\\4-4-2.jpg");}
		else{
			 TMemoryStream *str = new TMemoryStream;
		   HTTP->Get("https://images2.minutemediacdn.com/image/upload/c_fill,w_720,ar_16:9,f_auto,q_auto,g_auto/shape/cover/sport/A1896-23a-696x345-840240817c2c5194bf529a5256504c56.jpg", str);//тут загружаем
		   TJPEGImage *jpg = new TJPEGImage;
		   jpg->LoadFromStream(str);
		   Image1->Picture->Assign(jpg);
		   delete jpg;
		   delete str;
		}
		DataModule5->ADOQuery2->Close();
		DataModule5->ADOQuery2->SQL->Clear();
		DataModule5->ADOQuery2->SQL->Add("SELECT * FROM football_manager.plan INNER JOIN football_manager.list_player ON `plan`.id_plan = `list_player`.id_plan INNER JOIN football_manager.player ON `list_player`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `klub`.Id_klub = `player`.Id_klub WHERE plan.name_plan = '4-4-2';");
		DataModule5->ADOQuery2->ExecSQL();
		DataModule5->ADOQuery2->Open();
		DBListBox1->Clear();
		Count = DataModule5->ADOQuery2->RecordCount;
		DataModule5->ADOQuery2->First();
        if(Count > 0){DBListBox1->Items->Add("Використовує - " + DataModule5->ADOQuery2->FieldByName("Name")->AsString+ ":"); }
		for(int i=1; i<=Count; i++)
		{
			DBListBox1->Items->Add(" - " + DataModule5->ADOQuery2->FieldByName("pib")->AsString +": "+ DataModule5->ADOQuery2->FieldByName("position")->AsString+ ", " + DataModule5->ADOQuery2->FieldByName("number")->AsString);
			DataModule5->ADOQuery2->Next();
		}
		StatusBar1->Panels->Items[0]->Text="Кількість гравців - "+IntToStr(Count);
	}
	if(ComboBox1->ItemIndex==4)
	{
		if(FileExists("schemes\\4-5-1.jpg")){Image1->Picture->LoadFromFile("schemes\\4-5-1.jpg");}
		else{
			 TMemoryStream *str = new TMemoryStream;
		   HTTP->Get("https://images2.minutemediacdn.com/image/upload/c_fill,w_720,ar_16:9,f_auto,q_auto,g_auto/shape/cover/sport/A1896-25a-696x345-591461483e89122998cda6d0efbcf2de.jpg", str);//тут загружаем
		   TJPEGImage *jpg = new TJPEGImage;
		   jpg->LoadFromStream(str);
		   Image1->Picture->Assign(jpg);
		   delete jpg;
		   delete str;
		}
		DataModule5->ADOQuery2->Close();
		DataModule5->ADOQuery2->SQL->Clear();
		DataModule5->ADOQuery2->SQL->Add("SELECT * FROM football_manager.plan INNER JOIN football_manager.list_player ON `plan`.id_plan = `list_player`.id_plan INNER JOIN football_manager.player ON `list_player`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `klub`.Id_klub = `player`.Id_klub WHERE plan.name_plan = '4-5-1';");
		DataModule5->ADOQuery2->ExecSQL();
		DataModule5->ADOQuery2->Open();
		DBListBox1->Clear();
		Count = DataModule5->ADOQuery2->RecordCount;
		DataModule5->ADOQuery2->First();
        if(Count > 0){DBListBox1->Items->Add("Використовує - " + DataModule5->ADOQuery2->FieldByName("Name")->AsString+ ":"); }
		for(int i=1; i<=Count; i++)
		{
			DBListBox1->Items->Add(" - " + DataModule5->ADOQuery2->FieldByName("pib")->AsString +": "+ DataModule5->ADOQuery2->FieldByName("position")->AsString+ ", " + DataModule5->ADOQuery2->FieldByName("number")->AsString);
			DataModule5->ADOQuery2->Next();
		}
		StatusBar1->Panels->Items[0]->Text="Кількість гравців - "+IntToStr(Count);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose) //form close
{
	if(CanClose == true){
		Form1->Visible = true; CSpinEdit3->Enabled=False; CSpinEdit4->Enabled=False;BitBtn1->Enabled=False;
		LabeledEdit1->Enabled=False;DBListBox1->Clear();ComboBox1->ItemIndex=-1;Image1->Picture->LoadFromFile("schemes\\"+trip_plan);
		LabeledEdit1->Clear();CSpinEdit3->Value=0; CSpinEdit4->Value=0;
        StatusBar1->Panels->Items[0]->Text=" ";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBListBox1DrawItem(TWinControl *Control, int Index, TRect &Rect,  //listbox alignment center
		  TOwnerDrawState State){
    TListBox *box = static_cast<TListBox*>(Control);
    String s = box->Items->Strings[Index];
    box->Canvas->FillRect(Rect);
    box->Canvas->TextRect(Rect, Rect.Left + (Rect.Width() - box->Canvas->TextWidth(s)) / 2, Rect.Top, s);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
	 //search number
	 if(CSpinEdit3->Enabled==True && CSpinEdit4->Enabled==True)
	 {
		int int1 = StrToInt(CSpinEdit3->Value), int2 = StrToInt(CSpinEdit4->Value);
		DataModule5->ADOQuery2->Close();
		DataModule5->ADOQuery2->SQL->Clear();
		DataModule5->ADOQuery2->SQL->Add("SELECT * FROM football_manager.plan INNER JOIN football_manager.list_player ON `plan`.id_plan = `list_player`.id_plan INNER JOIN football_manager.player ON `list_player`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `klub`.Id_klub = `player`.Id_klub WHERE (`player`.number >= :int1 AND `player`.number <= :int2) AND (plan.name_plan = '"+ComboBox1->Items->Strings[ComboBox1->ItemIndex]+"');");
		DataModule5->ADOQuery2->Parameters->ParamByName("int1")->Value = int1;
		DataModule5->ADOQuery2->Parameters->ParamByName("int2")->Value = int2;
		DataModule5->ADOQuery2->Prepared = true;
		DataModule5->ADOQuery2->ExecSQL();
		DataModule5->ADOQuery2->Open();
		DBListBox1->Clear();
			Count = DataModule5->ADOQuery2->RecordCount;
			DataModule5->ADOQuery2->First();
             if(Count > 0){DBListBox1->Items->Add("Використовує - " + DataModule5->ADOQuery2->FieldByName("Name")->AsString+ ":"); }
			for(int i=1; i<=Count; i++)
			{
				DBListBox1->Items->Add(" - " + DataModule5->ADOQuery2->FieldByName("pib")->AsString +": "+ DataModule5->ADOQuery2->FieldByName("position")->AsString+ ", " + DataModule5->ADOQuery2->FieldByName("number")->AsString);
				DataModule5->ADOQuery2->Next();
			}

			StatusBar1->Panels->Items[0]->Text="Кількість гравців - "+IntToStr(Count);
			CSpinEdit3->Value=0; CSpinEdit4->Value=0; CSpinEdit3->Enabled=False; CSpinEdit4->Enabled=False; BitBtn1->Enabled=False;
	 }
     //search pib
	 if(LabeledEdit1->Enabled==True)
	 {
		DataModule5->ADOQuery2->Close();
		DataModule5->ADOQuery2->SQL->Clear();
		DataModule5->ADOQuery2->SQL->Add("SELECT * FROM football_manager.plan INNER JOIN football_manager.list_player ON `plan`.id_plan = `list_player`.id_plan INNER JOIN football_manager.player ON `list_player`.id_player = `player`.id_player INNER JOIN football_manager.klub ON `klub`.Id_klub = `player`.Id_klub WHERE `player`.pib LIKE '%"+LabeledEdit1->Text+"%' AND plan.name_plan = '"+ComboBox1->Items->Strings[ComboBox1->ItemIndex]+"';");
		DataModule5->ADOQuery2->Prepared = true;
		DataModule5->ADOQuery2->ExecSQL();
		DataModule5->ADOQuery2->Open();
        DBListBox1->Clear();
			Count = DataModule5->ADOQuery2->RecordCount;
			DataModule5->ADOQuery2->First();
             if(Count > 0){DBListBox1->Items->Add("Використовує - " + DataModule5->ADOQuery2->FieldByName("Name")->AsString+ ":"); }
			for(int i=1; i<=Count; i++)
			{
				DBListBox1->Items->Add(" - " + DataModule5->ADOQuery2->FieldByName("pib")->AsString +": "+ DataModule5->ADOQuery2->FieldByName("position")->AsString+ ", " + DataModule5->ADOQuery2->FieldByName("number")->AsString);
				DataModule5->ADOQuery2->Next();
			}
			StatusBar1->Panels->Items[0]->Text="Кількість гравців - "+IntToStr(Count);
			LabeledEdit1->Clear(); LabeledEdit1->Enabled=False; BitBtn1->Enabled=False;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::GroupBox2Click(TObject *Sender)
{
	CSpinEdit3->Enabled=True; CSpinEdit4->Enabled=True; BitBtn1->Enabled=True;
	LabeledEdit1->Enabled=False;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::GroupBox1Click(TObject *Sender)
{
	CSpinEdit3->Enabled=False; CSpinEdit4->Enabled=False;
	BitBtn1->Enabled=True;
	LabeledEdit1->Enabled=True;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    Image1->Picture->LoadFromFile("schemes\\"+trip_plan);
}

