#include "StdAfx.h"
#include "DataBaseAide.h"
#include "DataBase.h"

//构造函数
CDataBaseAide::CDataBaseAide(IUnknownEx * pIUnknownEx)
{
	m_pIDataBase = NULL;
}
//析构函数
CDataBaseAide::~CDataBaseAide()
{
}

bool CDataBaseAide::SetDataBase(IUnknownEx *pIUnKnownEx)
{
	m_pIDataBase = (IDataBase *)pIUnKnownEx;
	if (m_pIDataBase != NULL)
		return true;
	else
		return false;
}

VOID *CDataBaseAide::GetDataBase(REFGUID Guid, DWORD dwQueryVer)
{
	if (m_pIDataBase != NULL)
		return m_pIDataBase;
	return NULL;
}
/////////////////////////////////
////取数据

INT CDataBaseAide::GetValue_INT(LPCTSTR pszItem)
{
	INT nValue;
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, nValue);
		return nValue;
	}
	return 0;
}

UINT CDataBaseAide::GetValue_UINT(LPCTSTR pszItem)
{
	UINT ulValue;
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, ulValue);
		return ulValue;

	}
	return 0;
}

DOUBLE CDataBaseAide::GetValue_DOUBLE(LPCTSTR pszItem)
{
	DOUBLE  dbValue;
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, dbValue);
		return dbValue;

	}
	return 0;
}

BYTE CDataBaseAide::GetValue_BYTE(LPCTSTR pszItem)
{
	BYTE  bValue;
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, bValue);
		return bValue;
	}

	return 0;
}

LONG CDataBaseAide::GetValue_LONG(LPCTSTR pszItem)
{
	LONG  lValue;
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, lValue);
		return lValue;

	}
	return 0;

}

WORD CDataBaseAide::GetValue_WORD(LPCTSTR pszItem)
{
	WORD  wValue;
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, wValue);
		return wValue;

	}
	return 0;

}

DWORD CDataBaseAide::GetValue_DWORD(LPCTSTR pszItem)
{
	DWORD  ulValue;
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, ulValue);
		return ulValue;

	}
	return 0;
}

FLOAT CDataBaseAide::GetValue_FLOAT(LPCTSTR pszItem)
{

	return 0;

}

LONGLONG CDataBaseAide::GetValue_LONGLONG(LPCTSTR pszItem)
{
	__int64 llValue;
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, llValue);
		return llValue;

	}
	return 0;
}

VOID CDataBaseAide::GetValue_VarValue(LPCTSTR pszItem, CDBVarValue & DBVarValue)
{
	return;

}

VOID CDataBaseAide::GetValue_SystemTime(LPCTSTR pszItem, SYSTEMTIME & SystemTime)
{
	return;
}


//获取参数雨杰高科www.cnyjwl.com
VOID CDataBaseAide::GetParameter(LPCTSTR pszItem, CDBVarValue & DBVarValue)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetParameter(pszItem, DBVarValue);
	}

}
//获取参数
//linjs
VOID CDataBaseAide::GetParameter(LPCTSTR pszItem, LPSTR pszString, UINT uSize)
{
	if (m_pIDataBase != NULL)
	{
		CDBVarValue DBVarValue;
		((CDataBase*)m_pIDataBase)->GetParameter(pszItem, DBVarValue);
		strncpy(pszString,_bstr_t(DBVarValue.bstrVal),uSize/*CountArray(pszString)*/);
	}
}
//获取参数
VOID CDataBaseAide::GetParameter(LPCTSTR pszItem, LPWSTR pszString, UINT uSize)
{
	if (m_pIDataBase != NULL)
	{
		CDBVarValue DBVarValue;
		((CDataBase*)m_pIDataBase)->GetParameter(pszItem, DBVarValue);
		wcsncpy(pszString, _bstr_t(DBVarValue), uSize);
	}
}
//重置雨杰高科www.cnyjwl.com参数
VOID CDataBaseAide::ResetParameter()
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->ClearParameters();
		((CDataBase*)m_pIDataBase)->AddParameter(TEXT("RETURN_VALUE"), adInteger, adParamReturnValue, sizeof(long), _variant_t((long)0));
	}

}

//获取字符
VOID CDataBaseAide::GetValue_String(LPCTSTR pszItem, LPSTR pszString, UINT uMaxCount)
{
	if (m_pIDataBase != NULL)
	{ 
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, (TCHAR *)pszString, uMaxCount);
	}
}

//获取字符
VOID CDataBaseAide::GetValue_String(LPCTSTR pszItem, LPWSTR pszString, UINT uMaxCount)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->GetFieldValue(pszItem, /*(char *)*/(TCHAR *)pszString, uMaxCount);
	}
}

//存储过程
LONG CDataBaseAide::ExecuteProcess(LPCTSTR pszSPName, bool bRecordset)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->ExecuteProcess(pszSPName, bRecordset);
		return ((CDataBase*)m_pIDataBase)->GetReturnValue();
	}
	return -1;

}

//插入雨杰高科www.cnyjwl.com参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, INT nValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adInteger, adParamInput, sizeof(long), _variant_t((long)nValue));
	}
}

//插入参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, UINT uValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adInteger, adParamInput, sizeof(long), _variant_t((long)uValue));
	}

}

//插入雨杰高科www.cnyjwl.com参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, LONG lValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adInteger, adParamInput, sizeof(long), _variant_t((long)lValue));
	}
}

//插入参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, LONGLONG lValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		_variant_t vtVal;
		vtVal.vt = VT_I8;
		vtVal.llVal = lValue;
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adBigInt, adParamInput, sizeof(LONGLONG), vtVal);
	}
}

//插入参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, BYTE cbValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adInteger, adParamInput, sizeof(long), _variant_t((long)cbValue));
	}
}

//插入雨杰高科www.cnyjwl.com参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, WORD wValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adInteger, adParamInput, sizeof(long), _variant_t((long)wValue));
	}
}

//插入参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, DWORD dwValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adInteger, adParamInput, sizeof(long), _variant_t((long)dwValue));
	}
}

//插入参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, FLOAT fValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adInteger, adParamInput, sizeof(long), _variant_t((long)fValue));
	}
}

//插入雨杰高科www.cnyjwl.com参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, DOUBLE dValue, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adInteger, adParamInput, sizeof(long), _variant_t((long)dValue));
	}
}

//插入参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, LPCTSTR pszString, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		if (lstrlen(pszString) != 0)
		{
			((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adChar, adParamInput, lstrlen(pszString), _variant_t(pszString));
		}
		else
		{
			//TCHAR szString[64]=" ";
			((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adChar, adParamInput, lstrlen(pszString) + 1, _variant_t(pszString));
		}
	}
}
//插入参数
//linjs
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, SYSTEMTIME & SystemTime, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		TCHAR szTimeBuffer[64] = {0};
		_sntprintf(szTimeBuffer, CountArray(szTimeBuffer), TEXT("%04d-%02d-%02d %02d:%02d:%02d"), SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay, SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond);
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adChar, adParamInput, sizeof(szTimeBuffer)+1, _variant_t(szTimeBuffer));
	}
}

#if 0  //
//插入参数
VOID CDataBaseAide::AddParameter(LPCTSTR pszItem, LPCWSTR pszString, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adParamInput, adVarChar, lstrlen(pszString), _variant_t(pszString));
	}
}
#endif

//插入参数
VOID CDataBaseAide::AddParameterOutput(LPCTSTR pszItem, LPSTR pszString, UINT uSize, ParameterDirectionEnum ParameterDirection)
{
	if (m_pIDataBase != NULL)
	{
		((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adChar, ParameterDirection, uSize/*sizeof(pszString)+1*/, _variant_t(pszString));
	}
}
//插入参数
VOID CDataBaseAide::AddParameterOutput(LPCTSTR pszItem, LPWSTR pszString, UINT uSize, ParameterDirectionEnum ParameterDirection)
{

	if (m_pIDataBase != NULL)
	{
		if (m_pIDataBase != NULL)
		{
			((CDataBase*)m_pIDataBase)->AddParameter(pszItem, adWChar, ParameterDirection, uSize/*sizeof(pszString)+1*/, _variant_t(pszString));
		}
		return;
	}
}
//返回数值
LONG CDataBaseAide::GetReturnValue()
{
	return m_pIDataBase->GetReturnValue();
}