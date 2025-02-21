/*******************************************************************************
* \file qIoDevice.h
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


namespace qLib
{
    /*******************************************************************************
    * \class qIoDevice
    *******************************************************************************/
    class qIoDevice
	{
		public:
            qIoDevice();
            virtual ~qIoDevice();

			//virtual bool			ReadBuffer(c8			*_pBuf,
			//								   const s32	_s32Count)		{ return false; }

			//virtual bool			WriteBuffer(const c8	*_pBuf,
			//									const s32	_s32Count)		{ return false; }

			//virtual bool			ReadLine(qString8	&_sLine)				{ return false; }	// include EOL
			//virtual bool			ReadLine_wo_EOL(qString8	&_sLine)		{ return false; }	// exclude EOL
			//virtual bool			ReadLine_wo_EOL_InBuffer(c8		*_pBuf)		{ return false; }

			//virtual bool			WriteLine(const qString8	&_sLine)		{ return false; }	// include EOL
			//virtual bool			WriteLine(const qString	&_sLine)			{ return false; }	// include EOL

            //virtual void			Close() = 0;

            //virtual bool			EoF() const = 0;										// true => EoF reached
    }; // class qIoDevice

} // namespace qLib
