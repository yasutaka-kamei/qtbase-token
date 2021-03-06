begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|QStackedLayout
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
comment|/*!     \class QStackedWidget     \brief The QStackedWidget class provides a stack of widgets where     only one widget is visible at a time.      \ingroup organizers     \ingroup geomanagement     \inmodule QtWidgets      QStackedWidget can be used to create a user interface similar to     the one provided by QTabWidget. It is a convenience layout widget     built on top of the QStackedLayout class.      Like QStackedLayout, QStackedWidget can be constructed and     populated with a number of child widgets ("pages"):      \snippet qstackedwidget/main.cpp 0     \snippet qstackedwidget/main.cpp 2     \snippet qstackedwidget/main.cpp 3      QStackedWidget provides no intrinsic means for the user to switch     page. This is typically done through a QComboBox or a QListWidget     that stores the titles of the QStackedWidget's pages. For     example:      \snippet qstackedwidget/main.cpp 1      When populating a stacked widget, the widgets are added to an     internal list. The indexOf() function returns the index of a     widget in that list. The widgets can either be added to the end of     the list using the addWidget() function, or inserted at a given     index using the insertWidget() function. The removeWidget()     function removes a widget from the stacked widget. The number of     widgets contained in the stacked widget can     be obtained using the count() function.      The widget() function returns the widget at a given index     position. The index of the widget that is shown on screen is given     by currentIndex() and can be changed using setCurrentIndex(). In a     similar manner, the currently shown widget can be retrieved using     the currentWidget() function, and altered using the     setCurrentWidget() function.      Whenever the current widget in the stacked widget changes or a     widget is removed from the stacked widget, the currentChanged()     and widgetRemoved() signals are emitted respectively.      \sa QStackedLayout, QTabWidget, {Config Dialog Example} */
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
name|QStackedLayout
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
comment|/*!     Removes \a widget from the QStackedWidget. i.e., \a widget is \e     not deleted but simply removed from the stacked layout, causing it     to be hidden.      \note Parent object and parent widget of \a widget will remain the     QStackedWidget. If the application wants to reuse the removed     \a widget, then it is recommended to re-parent it.      \sa addWidget(), insertWidget(), currentWidget() */
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
name|Q_UNLIKELY
argument_list|(
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
argument_list|)
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
begin_include
include|#
directive|include
file|"moc_qstackedwidget.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STACKEDWIDGET
end_comment
end_unit
