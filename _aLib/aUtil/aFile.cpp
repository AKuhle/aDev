/*******************************************************************************
* \file qFile.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qFile.h"
#include "qString16.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qFile::qFile
    *******************************************************************************/
    qFile::qFile()
    {
    } // qFile::qFile


    /*******************************************************************************
    * qFile::qFile
    *******************************************************************************/
    qFile::qFile(const qString16&           _sFilename,
                 const enumFileOperation    _eFileOperation)
    {
        Open(_sFilename, _eFileOperation);
    } // qFile::qFile


    /*******************************************************************************
    * qFile::~qFile
    *******************************************************************************/
    qFile::~qFile()
    {
        m_stream.close();
    } // qFile::~qFile


    /*******************************************************************************
    * qFile::Open
    *******************************************************************************/
    bool qFile::Open(const qString16&           _sFilename,
                     const enumFileOperation    _eFileOperation)
    {
        switch (_eFileOperation)
        {
            case enumFileOperation::Write:
                m_stream.open(_sFilename.ToStdString(), fstream::binary | fstream::out);
                break;

            case enumFileOperation::Read:
                m_stream.open(_sFilename.ToStdString(), fstream::binary | fstream::in);
                break;

            case enumFileOperation::ReadWrite:
                m_stream.open(_sFilename.ToStdString(), fstream::binary | fstream::in | fstream::out);
                break;

            case enumFileOperation::Append:
                m_stream.open(_sFilename.ToStdString(), fstream::binary | fstream::out | fstream::app);
                break;
        } // switch (_eRWOperation)

        return m_stream.is_open();
    } // qFile::Open


    /*******************************************************************************
    * qFile::Close
    *******************************************************************************/
    void qFile::Close()
    {
        m_stream.close();
    } // qFile::Close


    /*******************************************************************************
    * qFile::EoF
    *******************************************************************************/
    bool qFile::EoF() const
    {
        return m_stream.eof();
    } // qFile::EoF


//	////////////////////////////////////////////////////////////////////////////
//	//// qFile::ReadBuffer
//	////////////////////////////////////////////////////////////////////////////
//	//bool qFile::ReadBuffer(c8			*_pBuf,
//	//					   const s32	_s32Count)
//	//{
//	//	memset(_pBuf, 0, _s32Count);
//
//	//	try
//	//	{
//	//		m_stream.read(_pBuf, _s32Count);
//	//		return true;
//	//	}
//
//	//	catch (...)
//	//	{
//	//		throw;
//	//	}
//
//	//	return false;
//	//} // qFile::ReadBuffer
//
//
//	////////////////////////////////////////////////////////////////////////////
//	//// qFile::WriteBuffer
//	////////////////////////////////////////////////////////////////////////////
//	//bool qFile::WriteBuffer(const c8	*_pBuf,
//	//						const s32	_s32Count)
//	//{
//	//	try
//	//	{
//	//		m_stream.write(_pBuf, _s32Count);
//	//		return true;
//	//	}
//
//	//	catch (...)
//	//	{
//	//		throw;
//	//	}
//
//	//	return false;
//	//} // qFile::WriteBuffer
//
//
//	//////////////////////////////////////////////////////////////////////////
//	// qFile::ReadLine
//	//////////////////////////////////////////////////////////////////////////
//	bool qFile::ReadLine(qString	&_sLine)
//	{
//		try
//		{
//			if (ReadLine_wo_EOL(_sLine))
//			{
//				_sLine += Txt("\n");
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		catch (...)
//		{
//			return false;
//		}
//
//		return false;
//	} // qFile::ReadLine
//
//
//	//////////////////////////////////////////////////////////////////////////
//	// qFile::ReadLine
//	//////////////////////////////////////////////////////////////////////////
//	bool qFile::ReadLine(qlString8	&_sLine)
//	{
//		try
//		{
//			if (ReadLine_wo_EOL(_sLine))
//			{
//				_sLine += "\n";
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		catch (...)
//		{
//			return false;
//		}
//
//		return false;
//	} // qFile::ReadLine
//
//
//	//////////////////////////////////////////////////////////////////////////
//	// qFile::ReadLine_wo_EOL
//	//////////////////////////////////////////////////////////////////////////
//	bool qFile::ReadLine_wo_EOL(qString	&_sLine)
//	{
//		try
//		{
//			char	pBuf[10000];
//
//			m_stream.getline(pBuf, 10000);
//
//			while (strlen(pBuf) > 0 &&
//				   (pBuf[strlen(pBuf)-1] == '\r' || pBuf[strlen(pBuf)-1] == '\n'))
//			{
//				pBuf[strlen(pBuf)-1] = 0;
//			}
//			_sLine = pBuf;
//			return true;
//		}
//
//		catch (...)
//		{
//			//throw;
//		}
//
//		return false;
//	} // qFile::ReadLine_wo_EOL
//
//
//	//////////////////////////////////////////////////////qlBase////////////////////
//	// qFile::ReadLine_wo_EOL
//	//////////////////////////////////////////////////////////////////////////
//	bool qFile::ReadLine_wo_EOL(qlString8	&_sLine)
//	{
//		try
//		{
//			char	pBuf[10000];
//
//			m_stream.getline(pBuf, 10000);
//
//			while (strlen(pBuf) > 0 &&
//				   (pBuf[strlen(pBuf)-1] == '\r' || pBuf[strlen(pBuf)-1] == '\n'))
//			{
//				pBuf[strlen(pBuf)-1] = 0;
//			}
//			_sLine = pBuf;
//			return true;
//		}
//
//		catch (...)
//		{
//			//throw;
//		}
//
//		return false;
//	} // qFile::ReadLine_wo_EOL
//
//
//	//////////////////////////////////////////////////////////////////////////
//	// qFile::ReadLine_wo_EOL_InBuffer
//	//////////////////////////////////////////////////////////////////////////
//	bool qFile::ReadLine_wo_EOL_InBuffer(c8		*_pBuf)
//	{
//		try
//		{
//			m_stream.getline(_pBuf, 1000000);
//
//			while (strlen(_pBuf) > 0 &&
//				   (_pBuf[strlen(_pBuf)-1] == '\r' || _pBuf[strlen(_pBuf)-1] == '\n'))
//			{
//				_pBuf[strlen(_pBuf)-1] = 0;
//			}
//			return true;
//		}
//
//		catch (...)
//		{
//			//throw;
//		}
//
//		return false;
//	} // qFile::ReadLine_wo_EOL_InBuffer
//
//
//	//////////////////////////////////////////////////////////////////////////
//	// qFile::WriteLine
//	//////////////////////////////////////////////////////////////////////////
//	bool qFile::WriteLine(const qlString8	&_sLine)		// include EOL
//	{
//		try
//		{
//			m_stream.write(_sLine.c_str(), _sLine.length());
//			return true;
//		}
//
//		catch (...)
//		{
//			throw;
//		}
//
//		return false;
//	} // qFile::WriteLine
//
//
//	//////////////////////////////////////////////////////////////////////////
//	// qFile::WriteLine
//	//////////////////////////////////////////////////////////////////////////
//	bool qFile::WriteLine(const qString	&_sLine)		// include EOL
//	{
//		try
//		{
//			// convert to 8 bit char
//			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>	converter;
//			std::string s8 = converter.to_bytes(_sLine.c_str());
//
//			m_stream.write(s8.c_str(), s8.length());
//			return true;
//		}
//
//		catch (...)
//		{
//			throw;
//		}
//
//		return false;
//	} // qFile::WriteLine


//	///////////////////////////////////////////////////////////////////
//	// qFile::RenameFile
//	///////////////////////////////////////////////////////////////////
//	bool qFile::RenameFile(const qString	&_sOldName,
//						   const qString	&_sNewName)
//	{
//		// convert to 8 bit
//		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>	converter;
//		std::string		s8Old = converter.to_bytes(_sOldName.c_str());
//		std::string		s8New = converter.to_bytes(_sNewName.c_str());
//
//		// true => rename success
//		return (rename(s8Old.c_str(), s8New.c_str()) == 0);
//	} // qFile::RenameFile
//
//
//	///////////////////////////////////////////////////////////////////
//	// qFile::EraseFile
//	///////////////////////////////////////////////////////////////////
//	bool qFile::EraseFile(const qString	&_sName)
//	{
//		// convert to 8 bit
//		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>	converter;
//		std::string		s8Name = converter.to_bytes(_sName.c_str());
//
//		// true => rename success
//		return (remove (s8Name.c_str()) == 0);
//	} // qFile::EraseFile
//
//
//	///////////////////////////////////////////////////////////////////
//	// qFile::GetActDirectory
//	///////////////////////////////////////////////////////////////////
////	qString qFile::GetActDirectory()
////	{
////		return string (getcwd(NULL,0));
////	} // qFile::GetActDirectory

} // namespace qLib
