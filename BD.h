//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataModule5 : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TADOQuery *ADOQuery1;
	TADOQuery *ADOQuery2;
	TDataSource *DataSource2;
	TADOQuery *ADOQuery3;
	TDataSource *DataSource3;
	TADOQuery *ADOQuery4;
	TDataSource *DataSource4;
	TADOQuery *ADOQuery5;
	TDataSource *DataSource5;
	TADOQuery *ADOQuery6;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule5 *DataModule5;
//---------------------------------------------------------------------------
#endif
