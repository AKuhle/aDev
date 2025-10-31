#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>
#include "aFrame_def.h"
#include "qLights_def.h"
#include "chaseStep.h"

using namespace std;
using namespace aFrame;


namespace Ui {
class DlgChase;
}


/*******************************************************************************
* class DlgChase
*******************************************************************************/
class Chase;


/*******************************************************************************
* class DlgChase
*******************************************************************************/
class DlgChase : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgChase           *m_pUi;
        shared_ptr<Chase>      m_pChase;

    public:
        explicit DlgChase(QWidget           *_pParent,
                          shared_ptr<Chase> _pChase);
        ~DlgChase();

        QString                         name() const;

        vector<shared_ptr<ChaseStep>>   chaseSteps() const;

    private:
        void                            setCtrls(const shared_ptr<Chase> _pChase);

        virtual void                    accept();
        virtual void                    reject();

    private slots:
        void                            onAddScene(bool _bChecked);
        void                            onRemoveScene(bool _bChecked);
}; // class DlgChase
