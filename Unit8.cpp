#include <vcl.h>
#pragma hdrstop
#include "Unit8.h"
#include "Unit1.h"
#include <ctime>
#include <mmsystem.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner): TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormCreate(TObject *Sender)
{
    //image
	Image1->Picture->LoadFromFile("Loading\\Frame 2.png");
    PlaySoundA("Music\\gimn 1.wav", NULL, SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	//loading
	Sleep(6500);
	Form1->Visible = true;
	Form8->Visible = false;
}
