begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessiblewidgets.h"
end_include
begin_include
include|#
directive|include
file|"qaccessiblemenu.h"
end_include
begin_include
include|#
directive|include
file|"simplewidgets.h"
end_include
begin_include
include|#
directive|include
file|"rangecontrols.h"
end_include
begin_include
include|#
directive|include
file|"complexwidgets.h"
end_include
begin_include
include|#
directive|include
file|"itemviews.h"
end_include
begin_include
include|#
directive|include
file|<qaccessibleplugin.h>
end_include
begin_include
include|#
directive|include
file|<qplugin.h>
end_include
begin_include
include|#
directive|include
file|<qpushbutton.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbutton.h>
end_include
begin_include
include|#
directive|include
file|<qtreeview.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_include
include|#
directive|include
file|<qaccessible.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|AccessibleFactory
class|class
name|AccessibleFactory
super|:
specifier|public
name|QAccessiblePlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QAccessibleFactoryInterface"
name|FILE
literal|"widgets.json"
argument_list|)
decl|public
range|:
name|AccessibleFactory
argument_list|()
decl_stmt|;
name|QAccessibleInterface
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|classname
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|AccessibleFactory
name|AccessibleFactory
operator|::
name|AccessibleFactory
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|create
name|QAccessibleInterface
modifier|*
name|AccessibleFactory
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|classname
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|QAccessibleInterface
modifier|*
name|iface
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|object
operator|||
operator|!
name|object
operator|->
name|isWidgetType
argument_list|()
condition|)
return|return
name|iface
return|;
name|QWidget
modifier|*
name|widget
init|=
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
literal|false
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QLineEdit"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleLineEdit
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_COMBOBOX
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QComboBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleComboBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QAbstractSpinBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleAbstractSpinBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QSpinBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleSpinBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QDoubleSpinBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleDoubleSpinBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SCROLLBAR
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QScrollBar"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleScrollBar
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QAbstractSlider"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleAbstractSlider
argument_list|(
name|widget
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SLIDER
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QSlider"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleSlider
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TOOLBUTTON
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QToolButton"
argument_list|)
condition|)
block|{
name|QAccessible
operator|::
name|Role
name|role
init|=
name|QAccessible
operator|::
name|NoRole
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MENU
name|QToolButton
modifier|*
name|tb
init|=
name|qobject_cast
argument_list|<
name|QToolButton
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|tb
operator|->
name|menu
argument_list|()
condition|)
name|role
operator|=
name|tb
operator|->
name|isCheckable
argument_list|()
condition|?
name|QAccessible
operator|::
name|CheckBox
else|:
name|QAccessible
operator|::
name|PushButton
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|tb
operator|->
name|popupMode
argument_list|()
operator|!=
name|QToolButton
operator|::
name|DelayedPopup
condition|)
name|role
operator|=
name|QAccessible
operator|::
name|ButtonDropDown
expr_stmt|;
else|else
endif|#
directive|endif
name|role
operator|=
name|QAccessible
operator|::
name|ButtonMenu
expr_stmt|;
name|iface
operator|=
operator|new
name|QAccessibleToolButton
argument_list|(
name|widget
argument_list|,
name|role
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_TOOLBUTTON
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QCheckBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleButton
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|CheckBox
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QRadioButton"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleButton
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|RadioButton
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QPushButton"
argument_list|)
condition|)
block|{
name|QAccessible
operator|::
name|Role
name|role
init|=
name|QAccessible
operator|::
name|NoRole
decl_stmt|;
name|QPushButton
modifier|*
name|pb
init|=
name|qobject_cast
argument_list|<
name|QPushButton
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MENU
if|if
condition|(
name|pb
operator|->
name|menu
argument_list|()
condition|)
name|role
operator|=
name|QAccessible
operator|::
name|ButtonMenu
expr_stmt|;
elseif|else
endif|#
directive|endif
if|if
condition|(
name|pb
operator|->
name|isCheckable
argument_list|()
condition|)
name|role
operator|=
name|QAccessible
operator|::
name|CheckBox
expr_stmt|;
else|else
name|role
operator|=
name|QAccessible
operator|::
name|PushButton
expr_stmt|;
name|iface
operator|=
operator|new
name|QAccessibleButton
argument_list|(
name|widget
argument_list|,
name|role
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QAbstractButton"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleButton
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|PushButton
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QDialog"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|Dialog
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QMessageBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|AlertMessage
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MAINWINDOW
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QMainWindow"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleMainWindow
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QLabel"
argument_list|)
operator|||
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QLCDNumber"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleDisplay
argument_list|(
name|widget
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_GROUPBOX
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QGroupBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleGroupBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QStatusBar"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleDisplay
argument_list|(
name|widget
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_PROGRESSBAR
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QProgressBar"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleProgressBar
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QToolBar"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|ToolBar
argument_list|,
name|widget
operator|->
name|windowTitle
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_MENUBAR
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QMenuBar"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleMenuBar
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_MENU
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QMenu"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleMenu
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QAbstractItemView"
argument_list|)
condition|)
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
specifier|const
name|QTreeView
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleTree
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|iface
operator|=
operator|new
name|QAccessibleTable
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QWidget"
argument_list|)
operator|&&
name|widget
operator|->
name|objectName
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"qt_scrollarea_viewport"
argument_list|)
operator|&&
name|qobject_cast
argument_list|<
name|QAbstractItemView
operator|*
argument_list|>
argument_list|(
name|widget
operator|->
name|parentWidget
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
specifier|const
name|QTreeView
operator|*
argument_list|>
argument_list|(
name|widget
operator|->
name|parentWidget
argument_list|()
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleTree
argument_list|(
name|widget
operator|->
name|parentWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|iface
operator|=
operator|new
name|QAccessibleTable
argument_list|(
name|widget
operator|->
name|parentWidget
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_NO_ITEMVIEWS
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QTabBar"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleTabBar
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QSizeGrip"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|Grip
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SPLITTER
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QSplitter"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|Splitter
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QSplitterHandle"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|Grip
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QTextEdit"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleTextEdit
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QTipLabel"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleDisplay
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|ToolTip
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QFrame"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|Border
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_STACKEDWIDGET
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QStackedWidget"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleStackedWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TOOLBOX
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QToolBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleToolBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_MDIAREA
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QMdiArea"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleMdiArea
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QMdiSubWindow"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleMdiSubWindow
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QDialogButtonBox"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleDialogButtonBox
argument_list|(
name|widget
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DIAL
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QDial"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleDial
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QRubberBand"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|,
name|QAccessible
operator|::
name|Border
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_TEXTBROWSER
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QTextBrowser"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleTextBrowser
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QAbstractScrollArea"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleAbstractScrollArea
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QScrollArea"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleScrollArea
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_CALENDARWIDGET
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QCalendarWidget"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleCalendarWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
block|}
elseif|else
if|if
condition|(
name|classname
operator|==
name|QLatin1String
argument_list|(
literal|"QDockWidget"
argument_list|)
condition|)
block|{
name|iface
operator|=
operator|new
name|QAccessibleDockWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
name|iface
operator|=
operator|new
name|QAccessibleWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
return|return
name|iface
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
end_unit
