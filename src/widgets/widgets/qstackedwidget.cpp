begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstackedwidget.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STACKEDWIDGET
end_ifndef
begin_include
include|#
directive|include
file|<qstackedlayout.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<private/qframe_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/**    QStackedLayout does not support height for width (simply because it does not reimplement    heightForWidth() and hasHeightForWidth()). That is not possible to fix without breaking    binary compatibility. (QLayout is subject to multiple inheritance).    However, we can fix QStackedWidget by simply using a modified version of QStackedLayout    that reimplements the hfw-related functions:  */
end_comment
begin_class
DECL|class|QStackedLayoutHFW
class|class
name|QStackedLayoutHFW
super|:
specifier|public
name|QStackedLayout
block|{
public|public:
DECL|function|QStackedLayoutHFW
name|QStackedLayoutHFW
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QStackedLayout
argument_list|(
name|parent
argument_list|)
block|{}
name|bool
name|hasHeightForWidth
parameter_list|()
specifier|const
function_decl|;
name|int
name|heightForWidth
parameter_list|(
name|int
name|width
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|hasHeightForWidth
name|bool
name|QStackedLayoutHFW
operator|::
name|hasHeightForWidth
parameter_list|()
specifier|const
block|{
specifier|const
name|int
name|n
init|=
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QLayoutItem
modifier|*
name|item
init|=
name|itemAt
argument_list|(
name|i
argument_list|)
condition|)
block|{
if|if
condition|(
name|item
operator|->
name|hasHeightForWidth
argument_list|()
condition|)
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|heightForWidth
name|int
name|QStackedLayoutHFW
operator|::
name|heightForWidth
parameter_list|(
name|int
name|width
parameter_list|)
specifier|const
block|{
specifier|const
name|int
name|n
init|=
name|count
argument_list|()
decl_stmt|;
name|int
name|hfw
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QLayoutItem
modifier|*
name|item
init|=
name|itemAt
argument_list|(
name|i
argument_list|)
condition|)
block|{
name|hfw
operator|=
name|qMax
argument_list|(
name|hfw
argument_list|,
name|item
operator|->
name|heightForWidth
argument_list|(
name|width
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|hfw
return|;
block|}
end_function
begin_class
DECL|class|QStackedWidgetPrivate
class|class
name|QStackedWidgetPrivate
super|:
specifier|public
name|QFramePrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QStackedWidget
parameter_list|)
specifier|public
private|:
DECL|function|QStackedWidgetPrivate
name|QStackedWidgetPrivate
parameter_list|()
member_init_list|:
name|layout
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|layout
name|QStackedLayoutHFW
modifier|*
name|layout
decl_stmt|;
DECL|member|blockChildAdd
name|bool
name|blockChildAdd
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QStackedWidget     \brief The QStackedWidget class provides a stack of widgets where     only one widget is visible at a time.      \ingroup organizers     \ingroup geomanagement     \inmodule QtWidgets      QStackedWidget can be used to create a user interface similar to     the one provided by QTabWidget. It is a convenience layout widget     built on top of the QStackedLayout class.      Like QStackedLayout, QStackedWidget can be constructed and     populated with a number of child widgets ("pages"):      \snippet doc/src/snippets/qstackedwidget/main.cpp 0     \snippet doc/src/snippets/qstackedwidget/main.cpp 2     \snippet doc/src/snippets/qstackedwidget/main.cpp 3      QStackedWidget provides no intrinsic means for the user to switch     page. This is typically done through a QComboBox or a QListWidget     that stores the titles of the QStackedWidget's pages. For     example:      \snippet doc/src/snippets/qstackedwidget/main.cpp 1      When populating a stacked widget, the widgets are added to an     internal list. The indexOf() function returns the index of a     widget in that list. The widgets can either be added to the end of     the list using the addWidget() function, or inserted at a given     index using the insertWidget() function. The removeWidget()     function removes a widget from the stacked widget. The number of     widgets contained in the stacked widget, can     be obtained using the count() function.      The widget() function returns the widget at a given index     position. The index of the widget that is shown on screen is given     by currentIndex() and can be changed using setCurrentIndex(). In a     similar manner, the currently shown widget can be retrieved using     the currentWidget() function, and altered using the     setCurrentWidget() function.      Whenever the current widget in the stacked widget changes or a     widget is removed from the stacked widget, the currentChanged()     and widgetRemoved() signals are emitted respectively.      \sa QStackedLayout, QTabWidget, {Config Dialog Example} */
end_comment
begin_comment
comment|/*!     \fn void QStackedWidget::currentChanged(int index)      This signal is emitted whenever the current widget changes.      The parameter holds the \a index of the new current widget, or -1     if there isn't a new one (for example, if there are no widgets in     the QStackedWidget).      \sa currentWidget(), setCurrentWidget() */
end_comment
begin_comment
comment|/*!     \fn void QStackedWidget::widgetRemoved(int index)      This signal is emitted whenever a widget is removed. The widget's     \a index is passed as parameter.      \sa removeWidget() */
end_comment
begin_comment
comment|/*!     Constructs a QStackedWidget with the given \a parent.      \sa addWidget(), insertWidget() */
end_comment
begin_constructor
DECL|function|QStackedWidget
name|QStackedWidget
operator|::
name|QStackedWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFrame
argument_list|(
operator|*
operator|new
name|QStackedWidgetPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QStackedWidget
argument_list|)
expr_stmt|;
name|d
operator|->
name|layout
operator|=
operator|new
name|QStackedLayoutHFW
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|layout
argument_list|,
name|SIGNAL
argument_list|(
name|widgetRemoved
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|widgetRemoved
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|layout
argument_list|,
name|SIGNAL
argument_list|(
name|currentChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|currentChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys this stacked widget, and frees any allocated resources. */
end_comment
begin_destructor
DECL|function|~QStackedWidget
name|QStackedWidget
operator|::
name|~
name|QStackedWidget
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Appends the given \a widget to the QStackedWidget and returns the     index position. Ownership of \a widget is passed on to the     QStackedWidget.      If the QStackedWidget is empty before this function is called,     \a widget becomes the current widget.      \sa insertWidget(), removeWidget(), setCurrentWidget() */
end_comment
begin_function
DECL|function|addWidget
name|int
name|QStackedWidget
operator|::
name|addWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
return|return
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|addWidget
argument_list|(
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Inserts the given \a widget at the given \a index in the     QStackedWidget. Ownership of \a widget is passed on to the     QStackedWidget. If \a index is out of range, the \a widget is     appended (in which case it is the actual index of the \a widget     that is returned).      If the QStackedWidget was empty before this function is called,     the given \a widget becomes the current widget.      Inserting a new widget at an index less than or equal to the current index     will increment the current index, but keep the current widget.      \sa addWidget(), removeWidget(), setCurrentWidget() */
end_comment
begin_function
DECL|function|insertWidget
name|int
name|QStackedWidget
operator|::
name|insertWidget
parameter_list|(
name|int
name|index
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
return|return
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|insertWidget
argument_list|(
name|index
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Removes \a widget from the QStackedWidget. i.e., \a widget is \e     not deleted but simply removed from the stacked layout, causing it     to be hidden.      \bold{Note:} Ownership of \a widget reverts to the application.      \sa addWidget(), insertWidget(), currentWidget() */
end_comment
begin_function
DECL|function|removeWidget
name|void
name|QStackedWidget
operator|::
name|removeWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|removeWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QStackedWidget::currentIndex     \brief the index position of the widget that is visible      The current index is -1 if there is no current widget.      By default, this property contains a value of -1 because the stack     is initially empty.      \sa currentWidget(), indexOf() */
end_comment
begin_function
DECL|function|setCurrentIndex
name|void
name|QStackedWidget
operator|::
name|setCurrentIndex
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|setCurrentIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentIndex
name|int
name|QStackedWidget
operator|::
name|currentIndex
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|currentIndex
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the current widget, or 0 if there are no child widgets.      \sa currentIndex(), setCurrentWidget() */
end_comment
begin_function
DECL|function|currentWidget
name|QWidget
modifier|*
name|QStackedWidget
operator|::
name|currentWidget
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|currentWidget
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QStackedWidget::setCurrentWidget(QWidget *widget)      Sets the current widget to be the specified \a widget. The new     current widget must already be contained in this stacked widget.      \sa currentWidget(), setCurrentIndex()  */
end_comment
begin_function
DECL|function|setCurrentWidget
name|void
name|QStackedWidget
operator|::
name|setCurrentWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QStackedWidget
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|layout
operator|->
name|indexOf
argument_list|(
name|widget
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QStackedWidget::setCurrentWidget: widget %p not contained in stack"
argument_list|,
name|widget
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|layout
operator|->
name|setCurrentWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the index of the given \a widget, or -1 if the given \a     widget is not a child of the QStackedWidget.      \sa currentIndex(), widget() */
end_comment
begin_function
DECL|function|indexOf
name|int
name|QStackedWidget
operator|::
name|indexOf
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|indexOf
argument_list|(
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the widget at the given \a index, or 0 if there is no such     widget.      \sa currentWidget(), indexOf() */
end_comment
begin_function
DECL|function|widget
name|QWidget
modifier|*
name|QStackedWidget
operator|::
name|widget
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|widget
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \property QStackedWidget::count     \brief the number of widgets contained by this stacked widget      By default, this property contains a value of 0.      \sa currentIndex(), widget() */
end_comment
begin_function
DECL|function|count
name|int
name|QStackedWidget
operator|::
name|count
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|layout
operator|->
name|count
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QStackedWidget
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QFrame
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STACKEDWIDGET
end_comment
end_unit
