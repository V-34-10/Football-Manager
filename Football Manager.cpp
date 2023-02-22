//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Transfer.cpp", Transfer);
USEFORM("BD.cpp", DataModule5); /* TDataModule: File Type */
USEFORM("Modification.cpp", Modification);
USEFORM("Loading.cpp", Loading);
USEFORM("Match.cpp", Match);
USEFORM("MainPlayer.cpp", MainPlayer);
USEFORM("Plan.cpp", Plan);
USEFORM("Report.cpp", Report);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TLoading), &Loading);
		Application->CreateForm(__classid(TMainPlayer), &MainPlayer);
		Application->CreateForm(__classid(TPlan), &Plan);
		Application->CreateForm(__classid(TMatch), &Match);
		Application->CreateForm(__classid(TTransfer), &Transfer);
		Application->CreateForm(__classid(TDataModule5), &DataModule5);
		Application->CreateForm(__classid(TModification), &Modification);
		Application->CreateForm(__classid(TReport), &Report);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
