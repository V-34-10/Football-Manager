//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.MPlayer.hpp>
//---------------------------------------------------------------------------
class TLoading : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);

private:	// User declarations
public:		// User declarations
	__fastcall TLoading(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoading *Loading;
//---------------------------------------------------------------------------
#endif
