begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qradiobutton.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qbuttongroup.h"
end_include
begin_include
include|#
directive|include
file|"qstylepainter.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractbutton_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QRadioButtonPrivate
class|class
name|QRadioButtonPrivate
super|:
specifier|public
name|QAbstractButtonPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QRadioButton
parameter_list|)
specifier|public
private|:
DECL|function|QRadioButtonPrivate
name|QRadioButtonPrivate
parameter_list|()
member_init_list|:
name|QAbstractButtonPrivate
argument_list|(
name|QSizePolicy
operator|::
name|RadioButton
argument_list|)
member_init_list|,
name|hovering
argument_list|(
literal|true
argument_list|)
block|{}
name|void
name|init
parameter_list|()
function_decl|;
name|uint
name|hovering
range|:
literal|1
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*     Initializes the radio button. */
end_comment
begin_function
DECL|function|init
name|void
name|QRadioButtonPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QRadioButton
argument_list|)
expr_stmt|;
name|q
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAutoExclusive
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setForegroundRole
argument_list|(
name|QPalette
operator|::
name|WindowText
argument_list|)
expr_stmt|;
name|setLayoutItemMargins
argument_list|(
name|QStyle
operator|::
name|SE_RadioButtonLayoutItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QRadioButton     \brief The QRadioButton widget provides a radio button with a text label.      \ingroup basicwidgets     \inmodule QtWidgets      A QRadioButton is an option button that can be switched on (checked) or     off (unchecked). Radio buttons typically present the user with a "one     of many" choice. In a group of radio buttons, only one radio button at     a time can be checked; if the user selects another button, the     previously selected button is switched off.      Radio buttons are autoExclusive by default. If auto-exclusive is     enabled, radio buttons that belong to the same parent widget     behave as if they were part of the same exclusive button group. If     you need multiple exclusive button groups for radio buttons that     belong to the same parent widget, put them into a QButtonGroup.      Whenever a button is switched on or off, it emits the toggled() signal.     Connect to this signal if you want to trigger an action each time the     button changes state. Use isChecked() to see if a particular button is     selected.      Just like QPushButton, a radio button displays text, and     optionally a small icon. The icon is set with setIcon(). The text     can be set in the constructor or with setText(). A shortcut key     can be specified by preceding the preferred character with an     ampersand in the text. For example:      \snippet code/src_gui_widgets_qradiobutton.cpp 0      In this example the shortcut is \e{Alt+c}. See the \l     {QShortcut#mnemonic}{QShortcut} documentation for details. To     display an actual ampersand, use '&&'.      Important inherited members: text(), setText(), text(),     setDown(), isDown(), autoRepeat(), group(), setAutoRepeat(),     toggle(), pressed(), released(), clicked(), and toggled().      \table 100%     \row \li \inlineimage fusion-radiobutton.png Screenshot of a Fusion radio button          \li A radio button shown in the \l{Fusion Style Widget Gallery}{Fusion widget style}.     \row \li \inlineimage windows-radiobutton.png Screenshot of a Windows XP radio button          \li A radio button shown in the \l{Windows XP Style Widget Gallery}{Windows XP widget style}.     \row \li \inlineimage macintosh-radiobutton.png Screenshot of a Macintosh radio button          \li A radio button shown in the \l{Macintosh Style Widget Gallery}{Macintosh widget style}.     \endtable      \sa QPushButton, QToolButton, QCheckBox, {fowler}{GUI Design Handbook: Radio Button},         {Group Box Example} */
end_comment
begin_comment
comment|/*!     Constructs a radio button with the given \a parent, but with no text or     pixmap.      The \a parent argument is passed on to the QAbstractButton constructor. */
end_comment
begin_constructor
DECL|function|QRadioButton
name|QRadioButton
operator|::
name|QRadioButton
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractButton
argument_list|(
operator|*
operator|new
name|QRadioButtonPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QRadioButton
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destructor. */
end_comment
begin_destructor
DECL|function|~QRadioButton
name|QRadioButton
operator|::
name|~
name|QRadioButton
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Constructs a radio button with the given \a parent and \a text string.      The \a parent argument is passed on to the QAbstractButton constructor. */
end_comment
begin_constructor
DECL|function|QRadioButton
name|QRadioButton
operator|::
name|QRadioButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractButton
argument_list|(
operator|*
operator|new
name|QRadioButtonPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QRadioButton
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Initialize \a option with the values from this QRadioButton. This method is useful     for subclasses when they need a QStyleOptionButton, but don't want to fill     in all the information themselves.      \sa QStyleOption::initFrom() */
end_comment
begin_function
DECL|function|initStyleOption
name|void
name|QRadioButton
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOptionButton
modifier|*
name|option
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|option
condition|)
return|return;
name|Q_D
argument_list|(
specifier|const
name|QRadioButton
argument_list|)
expr_stmt|;
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|option
operator|->
name|text
operator|=
name|d
operator|->
name|text
expr_stmt|;
name|option
operator|->
name|icon
operator|=
name|d
operator|->
name|icon
expr_stmt|;
name|option
operator|->
name|iconSize
operator|=
name|iconSize
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|down
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_Sunken
expr_stmt|;
name|option
operator|->
name|state
operator||=
operator|(
name|d
operator|->
name|checked
operator|)
condition|?
name|QStyle
operator|::
name|State_On
else|:
name|QStyle
operator|::
name|State_Off
expr_stmt|;
if|if
condition|(
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|)
operator|&&
name|underMouse
argument_list|()
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|hovering
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_MouseOver
expr_stmt|;
else|else
name|option
operator|->
name|state
operator|&=
operator|~
name|QStyle
operator|::
name|State_MouseOver
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QRadioButton
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QRadioButton
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|sizeHint
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|d
operator|->
name|sizeHint
return|;
name|ensurePolished
argument_list|()
expr_stmt|;
name|QStyleOptionButton
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|QSize
name|sz
init|=
name|style
argument_list|()
operator|->
name|itemTextRect
argument_list|(
name|fontMetrics
argument_list|()
argument_list|,
name|QRect
argument_list|()
argument_list|,
name|Qt
operator|::
name|TextShowMnemonic
argument_list|,
literal|false
argument_list|,
name|text
argument_list|()
argument_list|)
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|opt
operator|.
name|icon
operator|.
name|isNull
argument_list|()
condition|)
name|sz
operator|=
name|QSize
argument_list|(
name|sz
operator|.
name|width
argument_list|()
operator|+
name|opt
operator|.
name|iconSize
operator|.
name|width
argument_list|()
operator|+
literal|4
argument_list|,
name|qMax
argument_list|(
name|sz
operator|.
name|height
argument_list|()
argument_list|,
name|opt
operator|.
name|iconSize
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|sizeHint
operator|=
operator|(
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_RadioButton
argument_list|,
operator|&
name|opt
argument_list|,
name|sz
argument_list|,
name|this
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QApplication
operator|::
name|globalStrut
argument_list|()
argument_list|)
operator|)
expr_stmt|;
return|return
name|d
operator|->
name|sizeHint
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|QRadioButton
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
return|return
name|sizeHint
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|hitButton
name|bool
name|QRadioButton
operator|::
name|hitButton
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
specifier|const
block|{
name|QStyleOptionButton
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
return|return
name|style
argument_list|()
operator|->
name|subElementRect
argument_list|(
name|QStyle
operator|::
name|SE_RadioButtonClickRect
argument_list|,
operator|&
name|opt
argument_list|,
name|this
argument_list|)
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|QRadioButton
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QRadioButton
argument_list|)
expr_stmt|;
if|if
condition|(
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|)
condition|)
block|{
name|bool
name|hit
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|underMouse
argument_list|()
condition|)
name|hit
operator|=
name|hitButton
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|hit
operator|!=
name|d
operator|->
name|hovering
condition|)
block|{
name|update
argument_list|()
expr_stmt|;
name|d
operator|->
name|hovering
operator|=
name|hit
expr_stmt|;
block|}
block|}
name|QAbstractButton
operator|::
name|mouseMoveEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!\reimp  */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QRadioButton
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QStylePainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOptionButton
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_RadioButton
argument_list|,
name|opt
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QRadioButton
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QRadioButton
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|StyleChange
ifdef|#
directive|ifdef
name|Q_OS_MAC
operator|||
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MacSizeChange
endif|#
directive|endif
condition|)
name|d
operator|->
name|setLayoutItemMargins
argument_list|(
name|QStyle
operator|::
name|SE_RadioButtonLayoutItem
argument_list|)
expr_stmt|;
return|return
name|QAbstractButton
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
end_unit
