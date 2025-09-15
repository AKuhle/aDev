#include <QLineEdit>
#include <QWidget>

#include "dlgAddChase.h"
#include "ui_DlgAddChase.h"

#include "mainWin.h"
#include "ctrlPanel.h"
#include "chase.h"


/*******************************************************************************
* LineEditDelegate
*******************************************************************************/
class LineEditDelegate : public QStyledItemDelegate
{
    public:
        using QStyledItemDelegate::QStyledItemDelegate;

        QWidget* createEditor(QWidget                      *_pParent,
                              const QStyleOptionViewItem   &,
                              const QModelIndex            &) const override
        {
            return new QLineEdit(_pParent);
        }
}; // class LineEditDelegate


/*******************************************************************************
* DlgAddChase::DlgAddChase
*******************************************************************************/
DlgAddChase::DlgAddChase(QWidget        *_pParent,
                         s32            _s32ChaseBtnIdx,
                         const aString  &_sChaseName)
: aDialog(_pParent),
  m_s32ChaseBtnIdx(_s32ChaseBtnIdx),
  m_sChaseName(_sChaseName)
{
    #ifdef _USE_QT_
        m_pUi = new Ui::DlgAddChase;
        m_pUi->setupUi(this);
    #endif
} // DlgAddChase::DlgAddChase


/*******************************************************************************
* DlgAddChase::~DlgAddChase
*******************************************************************************/
DlgAddChase::~DlgAddChase()
{
    #ifdef _USE_QT_
        delete m_pUi;
    #endif
} // DlgAddChase::~DlgAddChase


/*******************************************************************************
* DlgAddChase::onCreateWin
*******************************************************************************/
bool DlgAddChase::onCreateWin()
{
    setWinTitle("Add Chase");
    m_pUi->m_pChaseName->setText(m_sChaseName.toQString());

    m_pUi->m_pChaseList->setModel(&m_model);
    m_pUi->m_pChaseList->setItemDelegate(new LineEditDelegate(m_pUi->m_pChaseList));
    m_pUi->m_pChaseList->setEditTriggers(QAbstractItemView::AllEditTriggers); // direct edible

    return true;
} // DlgAddChase::onCreateWin


/*******************************************************************************
* DlgAddChase::onAccepted
*******************************************************************************/
void DlgAddChase::onAccepted()
{
    CtrlPanel   &ctrlPanel = getCtrlPanel();

    aString sChaseName = m_pUi->m_pChaseName->editText();

    // create the new chase
    shared_ptr<Chase> pChase = make_shared<Chase> (sChaseName);

    QStringList lstValues = m_model.stringList();
    for (const QString &str : lstValues)
    {
        aVector<aString>    vecToken;
        aString             sToken = aString::fromQString(str);

        sToken.splitString("|", vecToken);

        switch (vecToken.size())
        {
            case 0:
            break;

            case 1:
                pChase->addStep(vecToken.at(0), 0);
                break;

            case 2:
                pChase->addStep(vecToken.at(0), vecToken.at(1).to_s32());
                break;
        } // switch (vecToken.size())
    }

    // set the new chase
    ctrlPanel.setChase(m_s32ChaseBtnIdx, pChase);
} // DlgAddChase::onAccepted


/*******************************************************************************
* DlgAddChase::onRegisterCtrl
*******************************************************************************/
void DlgAddChase::onRegisterCtrl()
{
    //registerCtrl(m_pUi->m)
} // DlgAddChase::onRegisterCtrl


/*******************************************************************************
* DlgAddChase::onUpdateCtrl
*******************************************************************************/
void DlgAddChase::onUpdateCtrl(aCtrlI */*_pCtrl*/)
{
} // DlgAddChase::onUpdateCtrl
