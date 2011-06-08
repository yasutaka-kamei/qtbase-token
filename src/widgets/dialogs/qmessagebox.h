begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMESSAGEBOX_H
end_ifndef
begin_define
DECL|macro|QMESSAGEBOX_H
define|#
directive|define
name|QMESSAGEBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qdialog.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_MESSAGEBOX
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMessageBoxPrivate
name|class
name|QMessageBoxPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMessageBox
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|Icon
argument_list|)
name|Q_FLAGS
argument_list|(
argument|StandardButtons
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString text READ text WRITE setText
argument_list|)
comment|// ### Qt 5: Rename 'icon' 'standardIcon' and 'iconPixmap' 'icon' (and use QIcon?)
name|Q_PROPERTY
argument_list|(
argument|Icon icon READ icon WRITE setIcon
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QPixmap iconPixmap READ iconPixmap WRITE setIconPixmap
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TextFormat textFormat READ textFormat WRITE setTextFormat
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|StandardButtons standardButtons READ standardButtons WRITE setStandardButtons
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
name|Q_PROPERTY
argument_list|(
argument|QString detailedText READ detailedText WRITE setDetailedText
argument_list|)
endif|#
directive|endif
name|Q_PROPERTY
argument_list|(
argument|QString informativeText READ informativeText WRITE setInformativeText
argument_list|)
name|public
operator|:
expr|enum
name|Icon
block|{
name|NoIcon
operator|=
literal|0
block|,
name|Information
operator|=
literal|1
block|,
name|Warning
operator|=
literal|2
block|,
name|Critical
operator|=
literal|3
block|,
name|Question
operator|=
literal|4
block|}
block|;      enum
name|ButtonRole
block|{
comment|// keep this in sync with QDialogButtonBox::ButtonRole
name|InvalidRole
operator|=
operator|-
literal|1
block|,
name|AcceptRole
block|,
name|RejectRole
block|,
name|DestructiveRole
block|,
name|ActionRole
block|,
name|HelpRole
block|,
name|YesRole
block|,
name|NoRole
block|,
name|ResetRole
block|,
name|ApplyRole
block|,
name|NRoles
block|}
block|;      enum
name|StandardButton
block|{
comment|// keep this in sync with QDialogButtonBox::StandardButton
name|NoButton
operator|=
literal|0x00000000
block|,
name|Ok
operator|=
literal|0x00000400
block|,
name|Save
operator|=
literal|0x00000800
block|,
name|SaveAll
operator|=
literal|0x00001000
block|,
name|Open
operator|=
literal|0x00002000
block|,
name|Yes
operator|=
literal|0x00004000
block|,
name|YesToAll
operator|=
literal|0x00008000
block|,
name|No
operator|=
literal|0x00010000
block|,
name|NoToAll
operator|=
literal|0x00020000
block|,
name|Abort
operator|=
literal|0x00040000
block|,
name|Retry
operator|=
literal|0x00080000
block|,
name|Ignore
operator|=
literal|0x00100000
block|,
name|Close
operator|=
literal|0x00200000
block|,
name|Cancel
operator|=
literal|0x00400000
block|,
name|Discard
operator|=
literal|0x00800000
block|,
name|Help
operator|=
literal|0x01000000
block|,
name|Apply
operator|=
literal|0x02000000
block|,
name|Reset
operator|=
literal|0x04000000
block|,
name|RestoreDefaults
operator|=
literal|0x08000000
block|,
name|FirstButton
operator|=
name|Ok
block|,
comment|// internal
name|LastButton
operator|=
name|RestoreDefaults
block|,
comment|// internal
name|YesAll
operator|=
name|YesToAll
block|,
comment|// obsolete
name|NoAll
operator|=
name|NoToAll
block|,
comment|// obsolete
name|Default
operator|=
literal|0x00000100
block|,
comment|// obsolete
name|Escape
operator|=
literal|0x00000200
block|,
comment|// obsolete
name|FlagMask
operator|=
literal|0x00000300
block|,
comment|// obsolete
name|ButtonMask
operator|=
operator|~
name|FlagMask
comment|// obsolete
block|}
block|;
typedef|typedef
name|StandardButton
name|Button
typedef|;
comment|// obsolete
name|Q_DECLARE_FLAGS
argument_list|(
argument|StandardButtons
argument_list|,
argument|StandardButton
argument_list|)
name|explicit
name|QMessageBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|QMessageBox
argument_list|(
argument|Icon icon
argument_list|,
argument|const QString&title
argument_list|,
argument|const QString&text
argument_list|,
argument|StandardButtons buttons = NoButton
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QMessageBox
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|addButton
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|,
name|ButtonRole
name|role
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QPushButton
modifier|*
name|addButton
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|ButtonRole
name|role
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QPushButton
modifier|*
name|addButton
parameter_list|(
name|StandardButton
name|button
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|removeButton
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WINCE
end_ifdef
begin_function_decl
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|Q_QDOC
end_ifndef
begin_function
name|void
name|open
parameter_list|()
block|{
name|QDialog
operator|::
name|open
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|using
name|QDialog
operator|::
name|open
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|open
parameter_list|(
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QList
operator|<
name|QAbstractButton
operator|*
operator|>
name|buttons
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|ButtonRole
name|buttonRole
argument_list|(
name|QAbstractButton
operator|*
name|button
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setStandardButtons
parameter_list|(
name|StandardButtons
name|buttons
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|StandardButtons
name|standardButtons
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|StandardButton
name|standardButton
argument_list|(
name|QAbstractButton
operator|*
name|button
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAbstractButton
modifier|*
name|button
argument_list|(
name|StandardButton
name|which
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPushButton
operator|*
name|defaultButton
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDefaultButton
parameter_list|(
name|QPushButton
modifier|*
name|button
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setDefaultButton
parameter_list|(
name|StandardButton
name|button
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QAbstractButton
operator|*
name|escapeButton
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEscapeButton
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setEscapeButton
parameter_list|(
name|StandardButton
name|button
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QAbstractButton
operator|*
name|clickedButton
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Icon
name|icon
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setIcon
parameter_list|(
name|Icon
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QPixmap
name|iconPixmap
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setIconPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Qt
operator|::
name|TextFormat
name|textFormat
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|void
name|setTextFormat
argument_list|(
name|Qt
operator|::
name|TextFormat
name|format
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|StandardButton
name|information
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|StandardButtons
name|buttons
init|=
name|Ok
parameter_list|,
name|StandardButton
name|defaultButton
init|=
name|NoButton
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// ### Qt 5: Replace Ok with Yes|No in question() function.
end_comment
begin_comment
comment|//     Also consider if Ok == Yes and Cancel == No.
end_comment
begin_function_decl
specifier|static
name|StandardButton
name|question
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|StandardButtons
name|buttons
init|=
name|Ok
parameter_list|,
name|StandardButton
name|defaultButton
init|=
name|NoButton
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|StandardButton
name|warning
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|StandardButtons
name|buttons
init|=
name|Ok
parameter_list|,
name|StandardButton
name|defaultButton
init|=
name|NoButton
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|StandardButton
name|critical
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|StandardButtons
name|buttons
init|=
name|Ok
parameter_list|,
name|StandardButton
name|defaultButton
init|=
name|NoButton
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|about
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|aboutQt
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QSize
name|sizeHint
parameter_list|()
function_decl|const;
end_function_decl
begin_comment
comment|// the following functions are obsolete:
end_comment
begin_macro
name|QMessageBox
argument_list|(
argument|const QString&title
argument_list|,
argument|const QString&text
argument_list|,
argument|Icon icon
argument_list|,
argument|int button0
argument_list|,
argument|int button1
argument_list|,
argument|int button2
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags f = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
specifier|static
name|int
name|information
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|button0
parameter_list|,
name|int
name|button1
init|=
literal|0
parameter_list|,
name|int
name|button2
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|information
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
name|button0Text
parameter_list|,
specifier|const
name|QString
modifier|&
name|button1Text
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|button2Text
init|=
name|QString
argument_list|()
parameter_list|,
name|int
name|defaultButtonNumber
init|=
literal|0
parameter_list|,
name|int
name|escapeButtonNumber
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
specifier|static
name|StandardButton
name|information
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|StandardButton
name|button0
parameter_list|,
name|StandardButton
name|button1
init|=
name|NoButton
parameter_list|)
block|{
return|return
name|information
argument_list|(
name|parent
argument_list|,
name|title
argument_list|,
name|text
argument_list|,
name|StandardButtons
argument_list|(
name|button0
argument_list|)
argument_list|,
name|button1
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|int
name|question
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|button0
parameter_list|,
name|int
name|button1
init|=
literal|0
parameter_list|,
name|int
name|button2
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|question
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
name|button0Text
parameter_list|,
specifier|const
name|QString
modifier|&
name|button1Text
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|button2Text
init|=
name|QString
argument_list|()
parameter_list|,
name|int
name|defaultButtonNumber
init|=
literal|0
parameter_list|,
name|int
name|escapeButtonNumber
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
specifier|static
name|int
name|question
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|StandardButton
name|button0
parameter_list|,
name|StandardButton
name|button1
parameter_list|)
block|{
return|return
name|question
argument_list|(
name|parent
argument_list|,
name|title
argument_list|,
name|text
argument_list|,
name|StandardButtons
argument_list|(
name|button0
argument_list|)
argument_list|,
name|button1
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|int
name|warning
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|button0
parameter_list|,
name|int
name|button1
parameter_list|,
name|int
name|button2
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|warning
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
name|button0Text
parameter_list|,
specifier|const
name|QString
modifier|&
name|button1Text
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|button2Text
init|=
name|QString
argument_list|()
parameter_list|,
name|int
name|defaultButtonNumber
init|=
literal|0
parameter_list|,
name|int
name|escapeButtonNumber
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
specifier|static
name|int
name|warning
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|StandardButton
name|button0
parameter_list|,
name|StandardButton
name|button1
parameter_list|)
block|{
return|return
name|warning
argument_list|(
name|parent
argument_list|,
name|title
argument_list|,
name|text
argument_list|,
name|StandardButtons
argument_list|(
name|button0
argument_list|)
argument_list|,
name|button1
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|int
name|critical
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|int
name|button0
parameter_list|,
name|int
name|button1
parameter_list|,
name|int
name|button2
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|critical
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
name|button0Text
parameter_list|,
specifier|const
name|QString
modifier|&
name|button1Text
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|button2Text
init|=
name|QString
argument_list|()
parameter_list|,
name|int
name|defaultButtonNumber
init|=
literal|0
parameter_list|,
name|int
name|escapeButtonNumber
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
specifier|static
name|int
name|critical
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|StandardButton
name|button0
parameter_list|,
name|StandardButton
name|button1
parameter_list|)
block|{
return|return
name|critical
argument_list|(
name|parent
argument_list|,
name|title
argument_list|,
name|text
argument_list|,
name|StandardButtons
argument_list|(
name|button0
argument_list|)
argument_list|,
name|button1
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|QString
name|buttonText
argument_list|(
name|int
name|button
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setButtonText
parameter_list|(
name|int
name|button
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|informativeText
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setInformativeText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
end_ifndef
begin_expr_stmt
name|QString
name|detailedText
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDetailedText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|setWindowModality
argument_list|(
name|Qt
operator|::
name|WindowModality
name|windowModality
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_decl_stmt
name|QT3_SUPPORT_CONSTRUCTOR
name|QMessageBox
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|,
name|Icon
name|icon
argument_list|,
name|int
name|button0
argument_list|,
name|int
name|button1
argument_list|,
name|int
name|button2
argument_list|,
name|QWidget
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
name|bool
name|modal
argument_list|,
name|Qt
operator|::
name|WindowFlags
name|f
operator|=
name|Qt
operator|::
name|Dialog
operator||
name|Qt
operator|::
name|MSWindowsFixedSizeDialogHint
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QT3_SUPPORT_CONSTRUCTOR
name|QMessageBox
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|QT3_SUPPORT
name|QPixmap
name|standardIcon
argument_list|(
name|Icon
name|icon
argument_list|,
name|Qt
operator|::
name|GUIStyle
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|QT3_SUPPORT
name|int
name|message
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
name|buttonText
init|=
name|QString
argument_list|()
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
init|=
literal|0
parameter_list|)
block|{
return|return
name|QMessageBox
operator|::
name|information
argument_list|(
name|parent
argument_list|,
name|title
argument_list|,
name|text
argument_list|,
name|buttonText
operator|.
name|isEmpty
argument_list|()
condition|?
name|tr
argument_list|(
literal|"OK"
argument_list|)
else|:
name|buttonText
argument_list|)
operator|==
literal|0
return|;
block|}
end_function
begin_function
specifier|static
name|QT3_SUPPORT
name|bool
name|query
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
name|yesButtonText
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|noButtonText
init|=
name|QString
argument_list|()
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
init|=
literal|0
parameter_list|)
block|{
return|return
name|QMessageBox
operator|::
name|information
argument_list|(
name|parent
argument_list|,
name|title
argument_list|,
name|text
argument_list|,
name|yesButtonText
operator|.
name|isEmpty
argument_list|()
condition|?
name|tr
argument_list|(
literal|"OK"
argument_list|)
else|:
name|yesButtonText
argument_list|,
name|noButtonText
argument_list|)
operator|==
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|QPixmap
name|standardIcon
parameter_list|(
name|Icon
name|icon
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|void
name|buttonClicked
parameter_list|(
name|QAbstractButton
modifier|*
name|button
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|qdoc
end_ifdef
begin_decl_stmt
name|public
name|Q_SLOTS
range|:
name|int
name|exec
argument_list|()
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_label
name|protected
label|:
end_label
begin_function_decl
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|changeEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_buttonClicked(QAbstractButton *)
argument_list|)
end_macro
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QMessageBox
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMessageBox
argument_list|)
end_macro
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QMessageBox::StandardButtons
argument_list|)
end_macro
begin_define
DECL|macro|QT_REQUIRE_VERSION
define|#
directive|define
name|QT_REQUIRE_VERSION
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|str
parameter_list|)
value|{ QString s = QString::fromLatin1(str);\ QString sq = QString::fromLatin1(qVersion()); \ if ((sq.section(QChar::fromLatin1('.'),0,0).toInt()<<16)+\ (sq.section(QChar::fromLatin1('.'),1,1).toInt()<<8)+\ sq.section(QChar::fromLatin1('.'),2,2).toInt()<(s.section(QChar::fromLatin1('.'),0,0).toInt()<<16)+\ (s.section(QChar::fromLatin1('.'),1,1).toInt()<<8)+\ s.section(QChar::fromLatin1('.'),2,2).toInt()) { \ if (!qApp){ \     new QApplication(argc,argv); \ } \ QString s = QApplication::tr("Executable '%1' requires Qt "\  "%2, found Qt %3.").arg(qAppName()).arg(QString::fromLatin1(\ str)).arg(QString::fromLatin1(qVersion())); QMessageBox::critical(0, QApplication::tr(\ "Incompatible Qt Library Error"), s, QMessageBox::Abort, 0); qFatal("%s", s.toLatin1().data()); }}
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MESSAGEBOX
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMESSAGEBOX_H
end_comment
end_unit
