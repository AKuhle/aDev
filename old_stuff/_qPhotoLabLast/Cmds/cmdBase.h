/*******************************************************************************
* \file cmdBase .h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLib.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace qLib;


/*******************************************************************************
* class CmdBase
*******************************************************************************/
class CmdBase  : public qCmdThread
{
    protected:
        shared_ptr<qLayerStack> m_pPreLS;       // layer stack before processing
        shared_ptr<qLayerStack> m_pPostLS;      // layer stack after processing
        qProgress               *m_pProgress;

    public:
        CmdBase(const u32               _u32CmdID,
                const qString16         &_sCmdName,
                const enumCmdType       _eCmdType,
                shared_ptr<qLayerStack> _pPreLS,
                qProgress               *_pProgress);

        virtual ~CmdBase();

        shared_ptr<qLayerStack>&        PreLS();
        shared_ptr<qLayerStack>&        PostLS();

        const shared_ptr<qLayerStack>&  PreLS() const;
        const shared_ptr<qLayerStack>&  PostLS()const;

//        Dimension2D<s32>                Dimension() const       { return (m_pPostLayerStack != nullptr)?   m_pPostLayerStack->GetDimension() : qlMath::qlSize2D<s32>(0, 0); }
//        s32                             W() const               { return (m_pPostLayerStack != nullptr)?   m_pPostLayerStack->GetW() : 0; }
//        s32                             H() const               { return (m_pPostLayerStack != nullptr)?   m_pPostLayerStack->GetH() : 0; }

        // updates the given Image, creates a new one if neccessary or leaves it
        // unchanged if no changes done
//        void                            GetPreviewQImage(s32        _s32W,
//                              s32        _s32H,
//                              QImage     *&_pImage) const;

    protected:
        // void                        OpenProgressDisplay(const qString16& _sInfoText) const;

        // void                        OpenProgressDisplay(const qString16&    _sInfoText,
        //                                                 s64                 _s64MinValue,
        //                                                 s64                 _s64MaxValue) const;

        // void                        ChangeProgressValues(s64   _s64MinValue,
        //                                                  s64   _s64MaxValue,
        //                                                  s64   _s64CurrentValue) const;

        // void                        SetProgressValue(s64 _s64CurrentValue) const;

        // void                        IncrementProgressValue(s64 _s64Step = 1) const;

        // void                        CloseProgressDisplay() const;

    /*******************************************************************************
    * interface of Cmd
    *******************************************************************************/
    public:
        virtual bool                    Prepare() override;
        virtual bool                    Undo() override;
        virtual bool                    Redo() override;
}; // class CmdBase
