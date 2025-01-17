/*******************************************************************************
* \file aPixmapQt.h
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QPixmap>

#include "aGraphic/aPixmap_i.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {
namespace SysQt {


/*******************************************************************************
* class aPixmapQt
*******************************************************************************/
class aPixmapQt : private QPixmap,
                  public aPixmapI
{
    friend class aPainterQt;

    public:
        aPixmapQt(const aString &_rscName);
        aPixmapQt(const char *_rscName);

        virtual ~aPixmapQt();

        virtual aPixmap         scale(const aDimension2D<s32>  &_d) override;

        virtual void            fill(const aColor &_col) override;

    private:
        aPixmapQt(const QPixmap &_pixmap);
}; // class aPixmapQt


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
