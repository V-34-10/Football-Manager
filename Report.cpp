//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Report.h"
#include "BD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "QRCtrls"
#pragma link "QuickRpt"
#pragma link "QRCtrls"
#pragma link "QuickRpt"
#pragma link "QRCtrls"
#pragma link "QuickRpt"
#pragma link "QRCtrls"
#pragma link "QuickRpt"
#pragma link "QRPDFFilt"
#pragma link "QRPDFFilt"
#pragma resource "*.dfm"
TReport *Report;
//---------------------------------------------------------------------------
__fastcall TReport::TReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
