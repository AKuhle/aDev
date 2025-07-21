/*******************************************************************************
* \file qUniquePtrList.inl
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
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* aUniquePtrDeque<T>::getAndPopBack
*******************************************************************************/
template <typename T>
std::unique_ptr<T> aUniquePtrDeque<T>::getAndPopBack()
{
    std::unique_ptr<T>  p = std::move(back());
    pop_back();

    return p;
} // aUniquePtrDeque<T>::getAndPopBack


/*******************************************************************************
* aUniquePtrDeque<T>::getAndPopFront
*******************************************************************************/
template <typename T>
std::unique_ptr<T> aUniquePtrDeque<T>::getAndPopFront()
{
    std::unique_ptr<T>  p = std::move(front());
    pop_front();

    return p;
} // aUniquePtrDeque<T>::getAndPopFront


} // namespace aUtil
} // namespace aFrame
