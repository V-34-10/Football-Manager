//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Mask.hpp>

//---------------------------------------------------------------------------
class TModification : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TDateTimePicker *DateTimePicker1;
	TDBLookupComboBox *DBLookupComboBox1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TLabel *Label5;
	TCheckBox *CheckBox1;
	TOpenPictureDialog *OpenPictureDialog1;
	TComboBox *ComboBox1;
	TDBLookupComboBox *DBLookupComboBox2;
	TEdit *Edit1;
	TEdit *Edit3;
	TDateTimePicker *DateTimePicker2;
	TDateTimePicker *DateTimePicker3;
	TBitBtn *BitBtn4;
	TLabel *Label6;
	TDBLookupComboBox *DBLookupComboBox3;
	TDBLookupComboBox *DBLookupComboBox4;
	TComboBox *ComboBox2;
	TComboBox *ComboBox3;
	TLabel *Label7;
	TDateTimePicker *DateTimePicker4;
	TBitBtn *BitBtn5;
	TBitBtn *BitBtn6;
	TMaskEdit *MaskEdit1;
	TMaskEdit *MaskEdit2;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall MaskEdit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall MaskEdit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall DBLookupComboBox2CloseUp(TObject *Sender);
	void __fastcall BitBtn6Click(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall DBLookupComboBox3CloseUp(TObject *Sender);
	void __fastcall DBLookupComboBox4CloseUp(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TModification(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TModification *Modification;
//---------------------------------------------------------------------------
#endif
