/*******************************************************************************
* \file aCmdBase.h
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
#include "aFrame_def.h"
#include "aUtil_def.h"

#include "aString.h"
#include "aProgressMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aCmdBase
*******************************************************************************/
class aCmdBase : public aProgressMgr
{
    friend class aCmdMgr;
    friend class aCmdStack;

    private:
        aCmdMgr         *m_pCmdMgr          { nullptr };
        s32             m_s32Id             { 0 };
        aString         m_sName             { "?" };
        enumCmdType     m_eType;
        aString         m_sSnapshotName     { "?" };


    protected:
        aCmdBase(s32            _s32Id,
                 const aString  &_sName,
                 enumCmdType    _eType);

        void                setCmdMgr(aCmdMgr *_pCmdMgr);
        aCmdMgr*            cmdMgr() const;

    public:
        virtual ~aCmdBase();

        s32                 id() const;
        const aString&      name() const;

        enumCmdType         type() const;
        void                setType(enumCmdType _eType);

        bool                canUndo() const;

        virtual bool		prepare()           { return true; }
//            virtual bool				PrepareDone()   { return true; }

        virtual bool		execute() = 0;
//            virtual bool				DoDone()        { return true; }

        virtual bool		undo()              { return false; }		// CMD_TYPE_NO_UNDO commands can't Undo
//            virtual bool				UndoDone()      { return true; }

        virtual bool		redo()              { return false; }		// CMD_TYPE_NO_UNDO commands can't Redo
//            virtual bool				RedoDone()      { return true; }


//            virtual void                SetCmdName(const aString &_sName)       {  m_sCmdName = _sName; }
//            virtual aString             CmdName() const                         { return m_sCmdName; }

//            virtual void                SetSnapshotName(const aString &_sName)  {  m_sSnapshotName = _sName; }
//            virtual aString             SnapshotName() const                    { return m_sSnapshotName; }


    private:
        /*******************************************************************************
        * members called by the aCmdMgr/qCmdStack
        *******************************************************************************/
        virtual void        doPrepare() = 0;
        virtual void        doExecute() = 0;
        virtual void        doUndo() = 0;
        virtual void        doRedo() = 0;
}; // class aCmdBase


} // namespace aUtil
} // namespace aFrame
