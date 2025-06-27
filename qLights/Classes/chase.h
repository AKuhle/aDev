/*******************************************************************************
* \file Chase.h
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
#include <QTimer>
#include <QObject>

#include "aString.h"
#include "aVector.h"

#include "qLights_defs.h"
#include "scene.h"

class Universe;

using namespace aLib::aUtil;



/*******************************************************************************
* class Chase
*******************************************************************************/
class Chase : public QObject
{
    Q_OBJECT

    // channel, startValie, endValue
    using StepChannelTuple = std::tuple<shared_ptr<Channel>, u8, u8>;

    // sceneStart, sceneEnd, channels, length_s
    using StepTuple = std::tuple<shared_ptr<Scene>, shared_ptr<Scene>, aVector<shared_ptr<StepChannelTuple>>, s32>;


    private:
        aString                     m_sName;
        aVector<channelValueTuple>  m_vValues;
        aVector<StepTuple>          m_vSteps;

        QTimer                      m_timer;

    public:
        Chase(const aString &_sName);
        ~Chase();

        const aString&                      name() const                    { return m_sName; }

        void                                setName(const aString &_sName)  { m_sName = _sName; }

        void                                addStep(const aString   &_sScene,
                                                    s32             _s32Length_s);

        void                                playChase();

        void                                add2Configuration(aJsonFile &_jf,
                                                              s32       _idx) const;

    private slots:
        void                                onTimeout();

}; // class Chase
