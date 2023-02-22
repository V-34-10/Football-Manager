#include <vcl.h>
#pragma hdrstop
#include "Loading.h"
#include "MainPlayer.h"
#include <ctime>
#include <mmsystem.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoading *Loading;
//---------------------------------------------------------------------------
__fastcall TLoading::TLoading(TComponent* Owner): TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TLoading::FormCreate(TObject *Sender)
{
    //image
	Image1->Picture->LoadFromFile("Loading\\Frame 2.png");
    PlaySoundA("Music\\gimn 1.wav", NULL, SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TLoading::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	//loading
	Sleep(6500);
	MainPlayer->Visible = true;
	Loading->Visible = false;
}
