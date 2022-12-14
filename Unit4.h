//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TDBGrid *DBGrid1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TPanel *Panel1;
	TGroupBox *GroupBox2;
	TSpeedButton *SpeedButton4;
	TLabel *Label3;
	TImage *Image1;
	TLabel *Label1;
	TStatusBar *StatusBar1;
	TGroupBox *GroupBox3;
	TDBListBox *DBListBox2;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label2;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall DBListBox1DrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall GroupBox2Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
