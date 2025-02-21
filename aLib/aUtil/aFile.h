/*******************************************************************************
* \file qFile.h
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qBaseDefs.h"
#include "qIoDevice.h"
#include "qList.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qString16;


    /*******************************************************************************
    * enumFileOperation
    *******************************************************************************/
    enum class enumFileOperation
    {
        Write,          ///< open for writing
        Read,           ///< open for reading
        ReadWrite,      ///< open for read and write
        Append          ///< open for read and append
    }; // enum class enumFileOperation


    /*******************************************************************************
    * \class qFile
    *******************************************************************************/
    class qFile : public qIoDevice
	{
        private:
            std::fstream		m_stream;

		public:
            qFile();
            qFile(const qString16			&_sFilename,
                  const enumFileOperation	_eFileOperation);
            virtual ~qFile();

            bool                    Open(const qString16&           _sFilename,
                                         const enumFileOperation    _eFileOperation);

            void                    Close();

            bool                    EoF() const;

			//virtual bool			ReadBuffer(c8			*_pBuf,
			//								   const s32	_s32Count);

			//virtual bool			WriteBuffer(const c8	*_pBuf,
			//									const s32	_s32Count);

			//virtual bool			ReadLine(qString	&_sLine);				// include EOL
            //virtual bool			ReadLine(qlqString16	&_sLine);				// include EOL
			//virtual bool			ReadLine_wo_EOL(qString	&_sLine);			// exclude EOL
            //virtual bool			ReadLine_wo_EOL(qlqString16	&_sLine);		// exclude EOL
			//virtual bool			ReadLine_wo_EOL_InBuffer(c8		*_pBuf);

            //virtual bool			WriteLine(const qlqString16	&_sLine);		// include EOL
			//virtual bool			WriteLine(const qString	&_sLine);			// include EOL

            static void				SplitPath(const qString16&  _sFilename,	// full path, eg: "c:\temp\out\test.txt"
                                              qString16&        _sPath,		// _spath, eg: "\temp\out\"
                                              qString16&        _sName,		// _sname, eg: "test"
                                              qString16&        _sExt, 		// _sext, eg: ".txt"
                                              qString16&        _sFullName);   // _sFullName, eg: "test.txt"

//			static void				SplitPath(const qlqString16	&_sFilename,	// full path, eg: "c:\temp\out\test.txt"
//											  qlqString16			&_sPath,		// _spath, eg: "c:\temp\out\"
//											  qlqString16			&_sName,		// _sname, eg: "test"
//											  qlqString16			&_sSuffix);		// _sext, eg: ".txt"

			//static bool				RenameFile(const qString	&_sOldName,
			//								   const qString	&_sNewName);

			//static bool				EraseFile(const qString	&_sName);

			//static qString			GetActDirectory();

            static void					GetFilesInDirectory(const qString16&        _sDir,
                                                            const qList<qString16>& _lstPattern,
                                                            qList<qString16>&       _lstFiles,
                                                            bool                    _bFullPath    = true
                                                            /*bool                    _bRecursive   = false*/);
    }; // class qFile

} // namespace qLib
