//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Report.h"
#include "ExtCtrls.hpp"
//#include "QRCtrls.hpp"
//#include "QuickRpt.hpp"
//#include "QRPDFFilt.hpp"
//---------------------------------------------------------------------------
class TReport : public TForm
{
__published:	// IDE-managed Components
	/*TQuickRep *QuickRep1;
	TQRBand *DetailBand1;
	TQRBand *PageHeaderBand1;
	TQRBand *TitleBand1;
	TQRDBText *QRDBText1;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel3;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
	TQRSysData *QRSysData1;   */
private:	// User declarations
public:		// User declarations
	__fastcall TReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TReport *Report;
//---------------------------------------------------------------------------
#endif
