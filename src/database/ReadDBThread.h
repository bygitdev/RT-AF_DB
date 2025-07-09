#ifndef ReadDBThreadH
#define ReadDBThreadH

#include <System.Classes.hpp>
#include <Vcl.Forms.hpp> // <-- 명시적으로 추가!
#include "CppSQLite3.h"

class TReadDBThread : public TThread
{
private:
	String FDBPath;
	String FStartTime;
	String FEndTime;
	String FTableName;
	String FDateColumnName;
	TForm* FTargetForm;
	CppSQLite3Table FTable;

	void __fastcall UpdateUI();

protected:
	void __fastcall Execute();

public:
	__fastcall TReadDBThread(String dbPath, String start, String end, String tableName, String dateColumnName);
};

#endif
