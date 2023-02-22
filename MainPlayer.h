//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <ctime>
//---------------------------------------------------------------------------
class TMainPlayer : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TPanel *Panel1;
	TStatusBar *StatusBar1;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TImage *Image2;
	TImage *Image1;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TDBListBox *DBListBox1;
	TDBGrid *DBGrid1;
	TDBLookupComboBox *DBLookupComboBox1;
	TLabel *Label1;
	TMenuItem *N9;
	TMenuItem *N10;
	TLabel *Label2;
	TGroupBox *GroupBox3;
	TPanel *Panel2;
	TLabel *Label3;
	TLabel *Label4;
	TMenuItem *N11;
	TRadioGroup *RadioGroup1;
	TMenuItem *N12;
	TSaveDialog *SaveDialog1;
	TColorDialog *ColorDialog1;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TFontDialog *FontDialog1;
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall DBLookupComboBox1CloseUp(TObject *Sender);
	void __fastcall DBListBox1DrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainPlayer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainPlayer *MainPlayer;
//---------------------------------------------------------------------------
#endif
