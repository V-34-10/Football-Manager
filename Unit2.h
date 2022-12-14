//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <jpeg.hpp>
#include <System.Net.HttpClient.hpp>
#include <System.Net.HttpClientComponent.hpp>
#include <System.Net.URLClient.hpp>
#include "cspin.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.Mask.hpp>



//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TComboBox *ComboBox1;
	TImage *Image1;
	TStatusBar *StatusBar1;
	TDBListBox *DBListBox1;
	TNetHTTPClient *HTTP;
	TGroupBox *GroupBox1;
	TBitBtn *BitBtn1;
	TGroupBox *GroupBox2;
	TLabel *Label3;
	TLabel *Label4;
	TCSpinEdit *CSpinEdit3;
	TCSpinEdit *CSpinEdit4;
	TLabeledEdit *LabeledEdit1;
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall DBListBox1DrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall GroupBox2Click(TObject *Sender);
	void __fastcall GroupBox1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
